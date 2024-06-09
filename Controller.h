#pragma once
#include "AbstractPiece.h"
#include "AllPieces.h"
#include "Board.h"

class Controller
{
private:
    //Displays menu
    bool displayMenu(RenderWindow& window)
    {
        Image icon;
        if (!icon.loadFromFile("Textures/b_pawn.png"))
        {
            cout << "Failed to load icon!" << endl;
            return EXIT_FAILURE;
        }
        window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

        Texture menuBackgroundTexture;
        if (!menuBackgroundTexture.loadFromFile("Textures/menuBackground.jpg"))
        {
            cout << "Failed to load Menu Background" << endl;
            EXIT_FAILURE;
        }
        Sprite menuBackgroundSprite(menuBackgroundTexture);
        static SoundBuffer menuBuffer;
        static Sound menuSound;
        if (!menuBuffer.loadFromFile("Textures/playSound.wav"))
        {
            cout << "Failed to load Play sound file!" << endl;
            EXIT_FAILURE;
        }
        menuSound.setBuffer(menuBuffer);
        Font font;
        if (!font.loadFromFile("Textures/triforce.ttf"))
        {
            cout << "Failed to load Menu font!" << endl;
            EXIT_FAILURE;
        }

        Text playButton, exitButton;
        playButton.setFont(font);
        playButton.setString("PLAY");
        playButton.setCharacterSize(80);
        playButton.setFillColor(Color(255, 215, 0));
        playButton.setStyle(Text::Bold);
        playButton.setPosition(((windowWidth / 2) - 115), (windowHeight / 2) - 97);

        exitButton.setFont(font);
        exitButton.setString("eXit");
        exitButton.setCharacterSize(100);
        exitButton.setFillColor(Color(255, 140, 0));
        exitButton.setStyle(Text::Bold);
        exitButton.setPosition(windowWidth / 2 - 95, windowHeight / 2 - 20);

        while (window.isOpen())
        {
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    window.close();
                if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
                {
                    Vector2i mousePos = Mouse::getPosition(window);
                    if (playButton.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    {
                        cout << "Play button clicked!" << endl;
                        menuSound.play();
                        window.close(); // Close the menu window when PLAY is clicked
                        return false;
                    }
                    else if (exitButton.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    {
                        cout << "Exit button clicked!" << endl;
                        menuSound.play();
                        window.close();
                        return true;
                    }
                }
            }

            window.clear(Color::Black);
            window.draw(menuBackgroundSprite);
            window.draw(playButton);
            window.draw(exitButton);
            window.display();
        }
    }

    void loadAllTextures(Sprite whitePieceSprites[], Sprite blackPieceSprites[], Texture& whitePawnTexture, Texture& blackPawnTexture, Texture& whiteKnightTexture, Texture& blackKnightTexture, Texture& whiteBishopTexture, Texture& blackBishopTexture, Texture& whiteRookTexture, Texture& blackRookTexture, Texture& whiteQueenTexture, Texture& blackQueenTexture, Texture& whiteKingTexture, Texture& blackKingTexture)
    {
        if (!whitePawnTexture.loadFromFile("Textures/w_pawn.png") ||
            !blackPawnTexture.loadFromFile("Textures/b_pawn.png") ||
            !whiteKnightTexture.loadFromFile("Textures/w_knight.png") ||
            !blackKnightTexture.loadFromFile("Textures/b_knight.png") ||
            !whiteRookTexture.loadFromFile("Textures/w_rook.png") ||
            !blackRookTexture.loadFromFile("Textures/b_rook.png") ||
            !whiteBishopTexture.loadFromFile("Textures/w_bishop.png") ||
            !blackBishopTexture.loadFromFile("Textures/b_bishop.png") ||
            !whiteQueenTexture.loadFromFile("Textures/w_queen.png") ||
            !blackQueenTexture.loadFromFile("Textures/b_queen.png") ||
            !whiteKingTexture.loadFromFile("Textures/w_king.png") ||
            !blackKingTexture.loadFromFile("Textures/b_king.png")
/*            !whitePawnTexture.loadFromFile("Textures/wP.png") ||
            !blackPawnTexture.loadFromFile("Textures/bP.png") ||
            !whiteKnightTexture.loadFromFile("Textures/wN.png") ||
            !blackKnightTexture.loadFromFile("Textures/bN.png") ||
            !whiteRookTexture.loadFromFile("Textures/wR.png") ||
            !blackRookTexture.loadFromFile("Textures/bR.png") ||
            !whiteBishopTexture.loadFromFile("Textures/wB.png") ||
            !blackBishopTexture.loadFromFile("Textures/bB.png") ||
            !whiteQueenTexture.loadFromFile("Textures/wQ.png") ||
            !blackQueenTexture.loadFromFile("Textures/bQ.png") ||
            !whiteKingTexture.loadFromFile("Textures/wK.png") ||
            !blackKingTexture.loadFromFile("Textures/bK.png")*/)
        {
            cout << "Failed to load textures." << endl;
            EXIT_FAILURE;
        }
        Sprite whitePawnSprite(whitePawnTexture), blackPawnSprite(blackPawnTexture);
        Sprite whiteKnightSprite(whiteKnightTexture), blackKnightSprite(blackKnightTexture);
        Sprite whiteRookSprite(whiteRookTexture), blackRookSprite(blackRookTexture);
        Sprite whiteBishopSprite(whiteBishopTexture), blackBishopSprite(blackBishopTexture);
        Sprite whiteQueenSprite(whiteQueenTexture), blackQueenSprite(blackQueenTexture);
        Sprite whiteKingSprite(whiteKingTexture), blackKingSprite(blackKingTexture);

        float spriteScale = 0.65f;
        whitePawnSprite.setScale(spriteScale, spriteScale);
        blackPawnSprite.setScale(spriteScale, spriteScale);
        whiteKnightSprite.setScale(spriteScale, spriteScale);
        blackKnightSprite.setScale(spriteScale, spriteScale);
        whiteRookSprite.setScale(spriteScale, spriteScale);
        blackRookSprite.setScale(spriteScale, spriteScale);
        whiteBishopSprite.setScale(spriteScale, spriteScale);
        blackBishopSprite.setScale(spriteScale, spriteScale);
        whiteQueenSprite.setScale(spriteScale, spriteScale);
        blackQueenSprite.setScale(spriteScale, spriteScale);
        whiteKingSprite.setScale(spriteScale, spriteScale);
        blackKingSprite.setScale(spriteScale, spriteScale);

        whitePieceSprites[PAWN] = whitePawnSprite;
        whitePieceSprites[KNIGHT] = whiteKnightSprite;
        whitePieceSprites[ROOK] = whiteRookSprite;
        whitePieceSprites[BISHOP] = whiteBishopSprite;
        whitePieceSprites[QUEEN] = whiteQueenSprite;
        whitePieceSprites[KING] = whiteKingSprite;
        blackPieceSprites[KING] = blackKingSprite;

        blackPieceSprites[PAWN] = blackPawnSprite;
        blackPieceSprites[KNIGHT] = blackKnightSprite;
        blackPieceSprites[ROOK] = blackRookSprite;
        blackPieceSprites[BISHOP] = blackBishopSprite;
        blackPieceSprites[QUEEN] = blackQueenSprite;
    }

    void displayWhichSideTurn(RenderWindow& window, bool isWhiteTurn)
    {
        Font font;
        if (!font.loadFromFile("Textures/arial.ttf"))
        {
            cout << "Failed to load font." << endl;
            EXIT_FAILURE;
        }
        Text text;
        text.setFont(font);
        text.setCharacterSize(24);
        text.setFillColor(Color::White);
        text.setStyle(Text::Bold);
        text.setFillColor(Color(64, 64, 64));
        text.setRotation(90);
        if (isWhiteTurn)
        {
            text.setString("White's Turn");
        }
        else
        {
            text.setString("Black's Turn");
        }
        text.setPosition(27, windowHeight - 470);
        window.draw(text);
    }

    void drawOnBoard(RenderWindow& window, Board& board, Sprite whitePieceSprites[], Sprite blackPieceSprites[])
    {
        // Drawing Chess Board
        for (int i = 0; i < boardSquares; ++i)
        {
            for (int j = 0; j < boardSquares; ++j)
            {
                RectangleShape square(Vector2f(perSquareSize, perSquareSize));
                square.setPosition((j * perSquareSize), i * perSquareSize);
                if ((i + j) % 2 == 0)
                {
                    square.setFillColor(Color(234, 233, 210)); //White
                }
                else
                {
                    square.setFillColor(Color(75, 115, 153)); //Blue
                }
                window.draw(square);
            }
        }

        // Drawing Piece Sprite on each Square through Polymorphism
        for (int i = 0; i < boardSquares; ++i)
        {
            for (int j = 0; j < boardSquares; ++j)
            {
                
                Piece* piece = board.getPiece(j, i);
                if (piece != nullptr)
                {
                    int type = piece->getType();
                    if (type >= 0 && type < 7)
                    {
                        Sprite sprite;
                        if (piece->isPieceWhite())
                        {
                            sprite = whitePieceSprites[type];
                        }
                        else
                        {
                            sprite = blackPieceSprites[type];
                        }
                        sprite.setPosition((j * perSquareSize) + 10, i * perSquareSize + 10);
                        window.draw(sprite);
                    }
                }
            }
        }
    }

    void pieceSelection(Board& board, int column, int row, bool& isWhiteTurn, bool& pieceSelected, int& selectedX, int& selectedY)
    {
        // Select Piece
        Piece* piece = board.getPiece(column, row);
        if (piece != nullptr && piece->isPieceWhite() == isWhiteTurn)
        {
            pieceSelected = true;
            selectedX = column;
            selectedY = row;
        }
        else if (pieceSelected)
        {
            if (board.movePiece(selectedX, selectedY, column, row))
            {
                isWhiteTurn = !isWhiteTurn; // Changing Turn
            }
            // Clearing
            pieceSelected = false;
            selectedX = -1, selectedY = -1;
        }
    }

    bool isCheck(Piece* pieces[boardSquares][boardSquares], bool isWhite)
    {
        // King Current Index
        int kingX = -99, kingY = -99;
        for (int i = 0; i < boardSquares; ++i)
        {
            for (int j = 0; j < boardSquares; ++j)
            {
                Piece* piece = pieces[i][j];
                if (piece != nullptr && piece->getType() == KING && piece->isPieceWhite() == isWhite)
                {
                    kingX = j;
                    kingY = i;
                    break;
                }
            }
        }

        // Check: Opposing Piece can eliminate King
        for (int i = 0; i < boardSquares; ++i)
        {
            for (int j = 0; j < boardSquares; ++j)
            {
                Piece* piece = pieces[i][j];
                if (piece != nullptr && piece->isPieceWhite() != isWhite)
                {
                    if (piece->isValidMove(pieces, j, i, kingX, kingY))
                    {
                        return true;
                    }
                }
            }
        }

        // Not in Check
        return false;
    }

    bool isCheckmate(Piece* pieces[boardSquares][boardSquares], bool isWhite)
    {
        if (!isCheck(pieces, isWhite))
        {
            return false;
        }

        // King Current Position
        int kingX = -1, kingY = -1;
        for (int i = 0; i < boardSquares; ++i)
        {
            for (int j = 0; j < boardSquares; ++j)
            {
                Piece* piece = pieces[i][j];
                if (piece != nullptr && piece->getType() == KING && piece->isPieceWhite() == isWhite)
                {
                    kingX = j;
                    kingY = i;
                    break;
                }
            }
        }

        // King Path Movement Blocked Check
        for (int dy = -1; dy <= 1; ++dy)
        { // Valid Square Movement for King
            for (int dx = -1; dx <= 1; ++dx)
            {
                int newX = kingX + dx;
                int newY = kingY + dy;
                if (newX >= 0 && newX < boardSquares && newY >= 0 && newY < boardSquares)
                {
                    if (!isCheck(pieces, isWhite) && pieces[newY][newX] == nullptr)
                    {
                        // Can be Saved in a new Position
                        return false;
                    }
                }
            }
        }

        // Check if any piece can Block the Check and capture the attacking Piece.
        for (int i = 0; i < boardSquares; ++i)
        {
            for (int j = 0; j < boardSquares; ++j)
            {
                Piece* piece = pieces[i][j];
                if (piece != nullptr && piece->isPieceWhite() == isWhite)
                {
                    for (int y = 0; y < boardSquares; ++y)
                    {
                        for (int x = 0; x < boardSquares; ++x)
                        {
                            if (piece->isValidMove(pieces, j, i, x, y))
                            {
                                Piece* originalPiece = pieces[y][x];
                                // Eliminating Piece
                                pieces[y][x] = piece;
                                pieces[i][j] = nullptr;
                                bool stillInCheck = isCheck(pieces, isWhite);
                                pieces[i][j] = piece;
                                pieces[y][x] = originalPiece;
                                if (!stillInCheck)
                                {
                                    return false;
                                }
                            }
                        }
                    }
                }
            }
        }

        return true;
    }

    void displayCheckmate(RenderWindow& window, bool isWhiteWinner)
    {
        Font font;
        if (!font.loadFromFile("Textures/taberna.ttf"))
        {
            cout << "Failed to load font." << endl;
            return;
        }
        Text text;
        text.setFont(font);
        text.setCharacterSize(80);
        if (isWhiteWinner)
        {
            text.setString("'WHITE Wins'\n Checkmate!");
            text.setFillColor(Color::White);
        }
        else
        {
            text.setString("'BLACK Wins'\n Checkmate!");
            text.setFillColor(Color::Black);
        }

        Font closeFont;
        if (!closeFont.loadFromFile("Textures/Tabernalight.ttf"))
        {
            cout << "Error loading closeFont" << endl;
            EXIT_FAILURE;
        }
        Text closeGameText;
        closeGameText.setFont(closeFont);
        closeGameText.setString("Close the Game");
        closeGameText.setCharacterSize(24);
        closeGameText.setFillColor(Color::Black);
        closeGameText.setStyle(Text::Bold);
        closeGameText.setPosition(windowWidth - 490, windowHeight - 320);
     

        text.setPosition((windowWidth - text.getLocalBounds().width) / 2, (windowHeight - text.getLocalBounds().height) / 2 - 20);
        RectangleShape background(Vector2f(text.getLocalBounds().width + 40, text.getLocalBounds().height + 20));
        background.setFillColor(Color(100,130,170, 200));
        background.setPosition((windowWidth - background.getLocalBounds().width) / 2, (windowHeight - background.getLocalBounds().height) / 2);
        window.draw(background);
        window.draw(text);
        window.draw(closeGameText);
    }

    bool declareWinner(bool& isWhiteKingRemoved, bool& isBlackKingRemoved, Piece* pieces[boardSquares][boardSquares], Board& board, bool& blackInCheck, bool& whiteInCheck, RenderWindow& window)
    {
        isWhiteKingRemoved = true, isBlackKingRemoved = true;
        static SoundBuffer checkMateBuffer; // Static as CheckMate sound is Played in main
        static Sound checkMateSound;
        if (!checkMateBuffer.loadFromFile("Textures/checkMate.wav"))
        {
            cout << "Failed to load sound file!" << endl;
        }
        checkMateSound.setBuffer(checkMateBuffer);
        for (int i = 0; i < boardSquares; ++i)
        {
            for (int j = 0; j < boardSquares; ++j)
            {
                Piece* piece = pieces[i][j];
                if (piece != nullptr)
                {
                    if (piece->getType() == KING && piece->isPieceWhite())
                    {
                        isWhiteKingRemoved = false;
                    }
                    if (piece->getType() == KING && !piece->isPieceWhite())
                    {
                        isBlackKingRemoved = false;
                    }
                }
            }
        }
        if (isWhiteKingRemoved)
        {
            cout << "Black wins! White king has been removed." << endl;
            checkMateSound.play();
            return true;
        }
        else if (isBlackKingRemoved)
        {
            cout << "White wins! Black king has been removed." << endl;
            checkMateSound.play();
            return true;
        }
        if (isCheck(board.pieces, true))
        {
            if (!whiteInCheck)
            {
                whiteInCheck = true;
                cout << "White is in Check!" << endl;
            }
        }
        else
        {
            whiteInCheck = false;
        }

        if (isCheck(board.pieces, false))
        {
            if (!blackInCheck)
            {
                blackInCheck = true;
                cout << "Black is in Check!" << endl;
            }
        }
        else
        {
            blackInCheck = false;
        }

        if (isCheckmate(board.pieces, true))
        {
            cout << "BLACK Wins by Checkmate!" << endl;
            checkMateSound.play();
            return true;
        }
        if (isCheckmate(board.pieces, false))
        {
            cout << "WHITE Wins by Checkmate!" << endl;
            checkMateSound.play();
            return true;
        }
        return false;
    }

    void drawValidMoves(RenderWindow& window, Board& board, int fromX, int fromY)
    {
        Piece* piece = board.getPiece(fromX, fromY);
        if (piece != nullptr)
        {
            for (int y = 0; y < boardSquares; ++y)
            {
                for (int x = 0; x < boardSquares; ++x)
                {
                    if (piece->isValidMove(board.pieces, fromX, fromY, x, y))
                    {
                        // Draw Circle
                        CircleShape circle(20);
                        circle.setFillColor(Color(0, 0, 0, 400));
                        circle.setOutlineThickness(1);
                        circle.setPosition(x * perSquareSize + perSquareSize / 2 - circle.getRadius(), y * perSquareSize + perSquareSize / 2 - circle.getRadius()); // Centralized
                        window.draw(circle);
                    }
                }
            }
        }
    }

public:
    //Main Function to Control all functions
    int play()
    {
        // Display Window
        RenderWindow menuWindow(VideoMode(windowWidth, windowHeight), "Menu", Style::Titlebar | Style::Close);

        if (displayMenu(menuWindow))
        {
            return 0;
        }

        RenderWindow window(VideoMode(windowWidth, windowHeight), "Real Chess", Style::Titlebar | Style::Close);
        window.setFramerateLimit(60);

        Texture whitePawnTexture, whiteRookTexture, whiteKnightTexture, whiteBishopTexture, whiteQueenTexture, whiteKingTexture;
        Texture blackPawnTexture, blackRookTexture, blackKnightTexture, blackBishopTexture, blackQueenTexture, blackKingTexture;
        Board board;

        bool blackInCheck = false, whiteInCheck = false, isWhiteKingRemoved = true, isBlackKingRemoved = true;
        bool isWhiteTurn = true, pieceSelected = false;
        int selectedX = -99, selectedY = -99;

        // Sprites Arrays for Pieces
        Sprite whitePieceSprites[7], blackPieceSprites[7];
        loadAllTextures(whitePieceSprites, blackPieceSprites, whitePawnTexture, blackPawnTexture, whiteKnightTexture, blackKnightTexture, whiteBishopTexture, blackBishopTexture, whiteRookTexture, blackRookTexture, whiteQueenTexture, blackQueenTexture, whiteKingTexture, blackKingTexture);

        bool gameEnded = false;

        Image icon;
        if (!icon.loadFromFile("Textures/w_pawn.png"))
        {
            cout << "Failed to load icon!" << endl;
            return EXIT_FAILURE;
        }
        window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
        // Main Loop
        while (window.isOpen())
        {
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    window.close();
                else if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
                {
                    if (!gameEnded)
                    {
                        Vector2i mousePos(Mouse::getPosition(window));
                        int column = mousePos.x / perSquareSize, row = mousePos.y / perSquareSize;
                        if (!pieceSelected)
                        {
                            pieceSelection(board, column, row, isWhiteTurn, pieceSelected, selectedX, selectedY);
                            if (pieceSelected)
                            {
                                drawValidMoves(window, board, selectedX, selectedY);
                            }
                        }
                        else
                        {
                            if (column == selectedX && row == selectedY)
                            {
                                pieceSelected = false;
                                selectedX = -99, selectedY = -99;
                            }
                            else
                            {
                                pieceSelection(board, column, row, isWhiteTurn, pieceSelected, selectedX, selectedY);
                                if (pieceSelected)
                                {
                                    drawValidMoves(window, board, selectedX, selectedY);
                                }
                            }
                        }
                    }
                }
            }
            window.clear();

            drawOnBoard(window, board, whitePieceSprites, blackPieceSprites);
            displayWhichSideTurn(window, isWhiteTurn);
            if (pieceSelected)
            {
                drawValidMoves(window, board, selectedX, selectedY);
            }
            // Displaying Winner
            if (!gameEnded)
            {
                if (declareWinner(isWhiteKingRemoved, isBlackKingRemoved, board.pieces, board, blackInCheck, whiteInCheck, window))
                {
                    gameEnded = true;
                }
            }
            else
            {
                if (isWhiteKingRemoved)
                {
                    displayCheckmate(window, false);
                }
                else if (isBlackKingRemoved)
                {
                    displayCheckmate(window, true);
                }
                else if (isCheckmate(board.pieces, true))
                {
                    displayCheckmate(window, false);
                }
                else if (isCheckmate(board.pieces, false))
                {
                    displayCheckmate(window, true);
                }
            }
            window.display();
        }
    } 
};
