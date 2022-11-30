//
// Created by Yungs on 11/9/2022.
//
#include <iostream>
#include <stdio.h>
#include <stdexcept>
#include "Board.hpp"
#include <vector>

using namespace std;

#ifndef KONANE_PLAYER_HPP
#define KONANE_PLAYER_HPP
class Player{
private:
    char playerColor; //player 1 = black = X, player 2 = white = 0
public:
    Player(char c);
    bool MovePossible(Board game);
    bool makeMove(Board &gameBoard);
    bool firstMove(Board &gameBoard, int row, int column);
};
Player::Player(char c)
{
    playerColor = c;
}
bool Player::MovePossible(Board gameBoard)
{
    for(int x = 1; x < gameBoard.rows; x++)
    {
        for(int y = 1; y < gameBoard.columns; y++)
        {
            if(playerColor == gameBoard.board2D[x][y])
            {
                bool canMoveDown = x <= gameBoard.rows-2 && gameBoard.board2D[x][y-1] != playerColor && gameBoard.board2D[x+1][y-1] == '_';
                bool canMoveUp = x >= 3 && gameBoard.board2D[x-2][y-1] != playerColor && gameBoard.board2D[x-3][y-1] == '_';
                bool canMoveLeft = y <= gameBoard.columns-2 && gameBoard.board2D[x-1][y] != playerColor && gameBoard.board2D[x-1][y+1] == '_';
                bool canMoveRight = y >= 3 && gameBoard.board2D[x-1][y-2] != playerColor && gameBoard.board2D[x-1][y-3] == '_';

                bool canMakeMove = canMoveRight || canMoveDown || canMoveLeft || canMoveUp;
                if(canMakeMove)
                    return true;
            }
        }
    }
    return false;

}
bool Player::makeMove(Board &gameBoard) { // !!! SOMEWHERE IN HERE IS THE SUSPECTED CAUSE OF THE BROKY !!!

    int x,y;

    cout << "Select a piece to move: " << endl;
    cout << "select the column#: " << endl;
    cin >> y;
    cout << "select the row#: " << endl;
    cin >> x;


    if (x > gameBoard.rows || y > gameBoard.columns || x < 1 || y < 1 || playerColor != gameBoard.board2D[x-1][y-1])
    {
        cout << "Invalid piece selected, you must choose a " << playerColor << " piece. " << endl;
        makeMove(gameBoard);
//        return false;
    }

    bool canMoveDown = x <= gameBoard.rows-2 && gameBoard.board2D[x][y-1] != playerColor && gameBoard.board2D[x+1][y-1] == '_';
    bool canMoveUp = x >= 3 && gameBoard.board2D[x-2][y-1] != playerColor && gameBoard.board2D[x-3][y-1] == '_';
    bool canMoveLeft = y <= gameBoard.columns-2 && gameBoard.board2D[x-1][y] != playerColor && gameBoard.board2D[x-1][y+1] == '_';
    bool canMoveRight = y >= 3 && gameBoard.board2D[x-1][y-2] != playerColor && gameBoard.board2D[x-1][y-3] == '_';
    bool canMakeMove = canMoveRight || canMoveDown || canMoveLeft || canMoveUp;
    //checks if can move in a cardinal direction

    if(!canMakeMove)
    {
        cout << "Selected piece has no available moves." << endl;
        makeMove(gameBoard);
//        return false;
    }


    gameBoard.removePiece(x,y);

    char card;
    cout << "Choose a direction to move: U, D, L, R" << endl;
    cin >> card;
    card = tolower(card);


    switch (card)
    {
        case 'u':
            if(canMoveUp)
            {
                gameBoard.removePiece(x-1, y);
                gameBoard.board2D[x-3][y-1] = playerColor;
                gameBoard.printBoard();
                return true;
            }
            else
            {
                gameBoard.board2D[x-1][y-1] = playerColor;
                cout << "Selected piece cannot move up" << endl;
                gameBoard.printBoard();
                makeMove(gameBoard);
//                return false;
            }
            //make check about it and make the move
            break;
        case 'd':
            if(canMoveDown)
            {
                gameBoard.removePiece(x+1, y);
                gameBoard.board2D[x+1][y-1] = playerColor;
                gameBoard.printBoard();
                return true;
            }
            else
            {
                gameBoard.board2D[x-1][y-1] = playerColor;
                cout << "Selected piece cannot move down" << endl;
                gameBoard.printBoard();
                makeMove(gameBoard);
//                return false;
            }
            //make check about it and make the move
            break;
        case 'l':
            if(canMoveLeft)
            {
                gameBoard.removePiece(x, y+1);
                gameBoard.board2D[x-1][y+1] = playerColor;
                gameBoard.printBoard();
                return true;
            }
            else
            {
                gameBoard.board2D[x-1][y-1] = playerColor;
                cout << "Selected piece cannot move left" << endl;
                gameBoard.printBoard();
                makeMove(gameBoard);
//                return false;
            }
            //make check about it and make the move
            break;
        case 'r':
            if(canMoveRight)
            {
                gameBoard.removePiece(x, y-1);
                gameBoard.board2D[x-1][y-3] = playerColor;
                gameBoard.printBoard();
                return true;
            }
            else
            {
                gameBoard.board2D[x-1][y-1] = playerColor;
                cout << "Selected piece cannot move right" << endl;
                gameBoard.printBoard();
                makeMove(gameBoard);
//                return false;
            }
            //make check about it and make the move
            break;
        default:
            gameBoard.board2D[x-1][y-1] = playerColor;
            cout << "input error, please choose a direction: U, D, L, R " << endl;
            gameBoard.printBoard();
            makeMove(gameBoard);
            //return false;
    }
}
bool Player::firstMove(Board &gameBoard, int column, int row)
{
    if(playerColor == gameBoard.board2D[row-1][column-1])
    {
        return gameBoard.firstRemove(row, column);
    }
    return false;
}
#endif //KONANE_PLAYER_HPP
