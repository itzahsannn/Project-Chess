#pragma once
#include "AbstractPiece.h"
#include <SFML/Audio.hpp>
using namespace std;
using namespace sf;

class Pawn : public Piece
{ // Derived Piece Pawn
public:
    // Constructor calls for both Parent and derived Class
    Pawn(bool isWhite) : Piece(isWhite, PAWN, "Pawn") {}

    // function for Pawn's Valid Movement
    bool isValidMove(Piece* board[boardSquares][boardSquares], int fromX, int fromY, int toX, int toY)
    {
        int direction = 0, startRow = 0;
        if (isWhite)
        { // Different starting indexes for Both Sides, accordingly their Movements
            direction = -1, startRow = 6;
        }
        else
        {
            direction = 1, startRow = 1;
        }

        if (board[toY][toX] != nullptr && board[toY][toX]->isPieceWhite() == isWhite)
        { // Stop Movement towards same Side Piece
            return false;
        }

        // Starting Moves of Pawn (2 Squares)
        if (fromY == startRow && toY == fromY + 2 * direction && fromX == toX)
        {
            if (board[fromY + direction][fromX] == nullptr && board[fromY + 2 * direction][fromX] == nullptr)
            {
                return true;
            }
        }

        if (toY == fromY + direction && fromX == toX && board[toY][toX] == nullptr)
        {
            return true;
        }

        // Dioagonal Movement for Elimination of opposing Piece
        if ((toX == fromX + 1 || toX == fromX - 1) && toY == fromY + direction && board[toY][toX] != nullptr && board[toY][toX]->isPieceWhite() != isWhite)
        {
            return true;
        }

        return false;
    }
};

class King : public Piece
{
public:
    King(bool isWhite) : Piece(isWhite, KING, "King") {};

    bool isValidMove(Piece* board[boardSquares][boardSquares], int fromX, int fromY, int toX, int toY)
    {

        if (board[toY][toX] != nullptr && board[toY][toX]->isPieceWhite() == isWhite)
        {
            return false;
        }
        // Single Square Movement on Each Side
        if (toX >= fromX + 2 || toY >= fromY + 2 || toX <= fromX - 2 || toY <= fromY - 2)
        {
            return false;
        }
        return true;
    }
};

class Queen : public Piece
{
public:
    Queen(bool isWhite) : Piece(isWhite, QUEEN, "Queen") {};

    bool isValidMove(Piece* board[boardSquares][boardSquares], int fromX, int fromY, int toX, int toY)
    {

        if (board[toY][toX] != nullptr && board[toY][toX]->isPieceWhite() == isWhite)
        {
            return false;
        }

        // Calculating Differnce to Check movement Diagonally,Horizontally or Vertically
        int differenceX = toX - fromX, differenceY = toY - fromY;
        int moveDirection = 0;

        if (differenceX != 0 && differenceY == 0)
        {
            if (differenceX > 0)
            {
                moveDirection = 1;
            }
            else
            {
                moveDirection = -1;
            }
            for (int x = fromX + moveDirection; x != toX; x += moveDirection)
            {
                if (board[fromY][x] != nullptr)
                {
                    return false;
                }
            }
            return true;
        }

        if (differenceX == 0 && differenceY != 0)
        {
            if (differenceY > 0)
            {
                moveDirection = 1;
            }
            else
            {
                moveDirection = -1;
            }
            for (int y = fromY + moveDirection; y != toY; y += moveDirection)
            {
                if (board[y][fromX] != nullptr)
                    return false;
            }
            return true;
        }
        int stepX = 0, stepY = 0;

        // Diagonal Movement Check
        if (differenceX == differenceY || differenceX == -differenceY || differenceY == -differenceX)
        {
            if (differenceX > 0)
            {
                stepX = 1;
            }
            else
            {
                stepX = -1;
            }

            if (differenceY > 0)
            {
                stepY = 1;
            }
            else
            {
                stepY = -1;
            }

            // Iterate through Squared to Check any Piece Blocking its Path
            for (int x = fromX + stepX, y = fromY + stepY; x != toX; x += stepX, y += stepY)
            {
                if (board[y][x] != nullptr)
                    return false;
            }
            return true;
        }
        return false;
    }
};

class Bishop : public Piece
{
public:
    Bishop(bool isWhite) : Piece(isWhite, BISHOP, "Bishop") {}

    bool isValidMove(Piece* board[boardSquares][boardSquares], int fromX, int fromY, int toX, int toY)
    {
        if (board[toY][toX] != nullptr && board[toY][toX]->isPieceWhite() == isWhite)
        {
            return false;
        }

        // Same as in Queen (Diagonal Movement)
        int differenceX = toX - fromX, differenceY = toY - fromY;
        int stepX = 0, stepY = 0;

        if (differenceX == differenceY || differenceX == -differenceY || differenceY == -differenceX)
        {
            if (differenceX > 0)
            {
                stepX = 1;
            }
            else
            {
                stepX = -1;
            }

            if (differenceY > 0)
            {
                stepY = 1;
            }
            else
            {
                stepY = -1;
            }

            for (int x = fromX + stepX, y = fromY + stepY; x != toX || y != toY; x += stepX, y += stepY)
            {
                if (board[y][x] != nullptr)
                {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
};

class Rook : public Piece
{
public:
    Rook(bool isWhite) : Piece(isWhite, ROOK, "Rook") {};
    bool isValidMove(Piece* board[boardSquares][boardSquares], int fromX, int fromY, int toX, int toY)
    {

        if (board[toY][toX] != nullptr && board[toY][toX]->isPieceWhite() == isWhite)
        {
            return false;
        }
        //'+' Like Movement Validations
        if (fromX != toX && fromY != toY)
        {
            return false;
        }

        int directionX = 0, directionY = 0;
        if (fromX != toX)
        {
            if (fromX < toX)
            {
                directionX = 1;
            }
            else
            {
                directionX = -1;
            }
        }

        if (fromY != toY)
        {
            if (fromY < toY)
            {
                directionY = 1;
            }
            else
            {
                directionY = -1;
            }
        }

        // Piece Blocking its Path
        for (int x = fromX + directionX, y = fromY + directionY; x != toX || y != toY; x += directionX, y += directionY)
        {
            if (board[y][x] != nullptr)
                return false;
        }
        return true;
    }
};

class Knight : public Piece
{
public:
    Knight(bool isWhite) : Piece(isWhite, KNIGHT, "Knight") {}

    bool isValidMove(Piece* board[boardSquares][boardSquares], int fromX, int fromY, int toX, int toY)
    {

        if (board[toY][toX] != nullptr && board[toY][toX]->isPieceWhite() == isWhite)
        {
            return false;
        }

        // 2.5 Moves Validations
        int differenceX = toX - fromX;
        int differenceY = toY - fromY;
        bool isValid = (differenceX * differenceX + differenceY * differenceY == 5);
        return isValid;
    }
};


