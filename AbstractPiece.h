#pragma once
// Including Required Libraries
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace std;
using namespace sf;

// Global Constants used through out the Code
int windowWidth = 800, windowHeight = 800;
const int boardSquares = 8;
int perSquareSize = windowWidth / boardSquares;
int EMPTY = 0, PAWN = 1, KNIGHT = 2, BISHOP = 3, ROOK = 4, QUEEN = 5, KING = 6;

// Abstract Base Class Including the Required Functions
class Piece
{
protected: // Access Specifier Protected as these Vars will be used in Derived Classes
    bool isWhite;
    int type;

public:
    string name;
    Piece(bool isWhite, int type, string name)
    { // Constructor
        this->isWhite = isWhite;
        this->type = type;
        this->name = name;
    }
    // Virtual Function for Derived Classes
    virtual bool isValidMove(Piece* board[boardSquares][boardSquares], int fromX, int fromY, int toX, int toY) = 0;

    // Function to distinguish between Black and White Piece
    bool isPieceWhite()
    {
        return isWhite;
    }

    // get Globally int value assigned to each Piece
    int getType()
    {
        return type;
    }
};
