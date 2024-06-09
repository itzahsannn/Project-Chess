#pragma once
#include "AbstractPiece.h"
#include"AllPieces.h"

class Board
{
    // Sound for Valid Moves
    SoundBuffer buffer;
    Sound sound;

public:
    // Whole Board
    Piece* pieces[boardSquares][boardSquares];
    Board()
    {
        if (!buffer.loadFromFile("Textures/move-check.wav"))
        {
            cout << "Failed to load sound file!" << endl;
            EXIT_FAILURE;
        }
        sound.setBuffer(buffer);

        // Assigning null Value on each Square
        for (int i = 0; i < boardSquares; ++i)
        {
            for (int j = 0; j < boardSquares; ++j)
            {
                pieces[i][j] = nullptr;
            }
        }

        // Assigning Valid Positions for each Piece
        for (int i = 0; i < boardSquares; ++i)
        {
            pieces[1][i] = new Pawn(false);
        }
        pieces[0][0] = new Rook(false);
        pieces[0][7] = new Rook(false);
        pieces[0][1] = new Knight(false);
        pieces[0][6] = new Knight(false);
        pieces[0][2] = new Bishop(false);
        pieces[0][5] = new Bishop(false);
        pieces[0][3] = new Queen(false);
        pieces[0][4] = new King(false);

        // Black Pieces
        for (int i = 0; i < boardSquares; ++i)
        {
            pieces[6][i] = new Pawn(true);
        }
        pieces[7][0] = new Rook(true);
        pieces[7][7] = new Rook(true);
        pieces[7][1] = new Knight(true);
        pieces[7][6] = new Knight(true);
        pieces[7][2] = new Bishop(true);
        pieces[7][5] = new Bishop(true);
        pieces[7][3] = new Queen(true);
        pieces[7][4] = new King(true);
    }

    // Piece Pointer at required Position
    Piece* getPiece(int x, int y)
    {
        return pieces[y][x];
    }

    bool movePiece(int fromX, int fromY, int toX, int toY) {
        Piece* fromPiece = pieces[fromY][fromX];
        if (fromPiece == nullptr) {
            return false;
        }

        if (!fromPiece->isValidMove(pieces, fromX, fromY, toX, toY)) {
            return false;
        }

        Piece* toPiece = pieces[toY][toX];
        if (toPiece != nullptr && toPiece->isPieceWhite() == fromPiece->isPieceWhite()) {
            return false;
        }
        cout << fromPiece->name <<" moved from ("<<fromX<<","<<fromY<<") to ("<<toX<<","<<toY<<")" << endl;
        sound.play();
        
        //Delete the elimintation Piece
        delete pieces[toY][toX];
        pieces[toY][toX] = fromPiece;
        pieces[fromY][fromX] = nullptr;


        //Pawn Promotion to auto-Queen
        if (fromPiece->getType() == PAWN) {
            if ((fromPiece->isPieceWhite() && toY == 0)) {
                pieces[toY][toX] = new Queen(fromPiece->isPieceWhite());
                cout << "White PAWN Promoted to Queen" << endl;
            }
            //Black Queen
            else if (!fromPiece->isPieceWhite() && toY == boardSquares - 1) {
                pieces[toY][toX] = new Queen(fromPiece->isPieceWhite());
                cout << "Black PAWN Promoted to Queen" << endl;
            }
        }
        return true;
    }

    // Destructor to delete Dynamic Pieces
    ~Board()
    {
        for (int i = 0; i < boardSquares; ++i)
        {
            for (int j = 0; j < boardSquares; ++j)
            {
                delete pieces[i][j];
            }
        }
    }
};
