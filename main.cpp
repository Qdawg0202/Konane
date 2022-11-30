#include <iostream>
#include <stdio.h>
#include <stdexcept>
#include "Board.hpp"
#include "Player.hpp"
#include <vector>

using namespace std;

int main() {

    cout << "Input board x dimension: " << endl;
    int x_dimension;
    cin >> x_dimension;

    cout << "Input board y dimension: " << endl;
    int y_dimension;
    cin >> y_dimension;

    //checks for if at least one dimension is even
    if (y_dimension % 2 == 0 || x_dimension % 2 == 0) \
    {
        cout << "Game will start with a " << x_dimension << "x" << y_dimension << " dimension board." << endl;
        //create board function here
    }
    else
    {
        cout << "Error encountered, invalid board size." << endl;
        cout << "At least one dimension of the board must be an even number" << endl;
        return 1; //ends main function returns error code 1
    }

    //Players get to choose color here, p1 should get to make first move, alternating each time

    //Creates game board and prints out values
    Board gameBoard(x_dimension, y_dimension);
    gameBoard.printBoard();

    Player pBlack('X');
    Player pWhite('0');

    int firstX;
    int firstY;

    cout << "Player 1 please choose the first move " << endl;
    cout << "select the column#: " << endl;
    cin >> firstX;
    cout << "select the row#: " << endl;
    cin >> firstY;


    bool firstMove = pBlack.firstMove(gameBoard, firstX, firstY);
    while (!firstMove) //asks for a valid move if not given
    {
        cout << "Invalid first move, please select an 'X' piece from either the center or the edges" << endl;
        cout << "select the column#: " << endl;
        cin >> firstX;
        cout << "select the row#: " << endl;
        cin >> firstY;
        firstMove = pBlack.firstMove(gameBoard, firstX, firstY);
    }


    int pLost = 0; //will change if a player has no more moves

    while(pLost == 0)
    {
        //check if black no moves, will break and change pLost
        if(!pBlack.MovePossible(gameBoard))
        {
            pLost = 1;
            break;
        }
        cout << "It is now Black's turn" << endl;
        bool moveBlack = pBlack.makeMove(gameBoard); // !!! THIS SHIT IS BROKY NEED FIX!!!!
//        while(!moveBlack)
//        {
//            moveBlack = pBlack.makeMove(gameBoard);
//        }
        //check if black no moves, will break and change pLost
        if(!pWhite.MovePossible(gameBoard))
        {
            pLost = 2;
            break;
        }
        cout << "It is now White's turn" << endl;
        bool moveWhite = pWhite.makeMove(gameBoard);
//        while(!moveWhite)
//        {
//            moveWhite = pWhite.makeMove(gameBoard); // !!! THIS SHIT IS BROKY NEED FIX!!!!
//        }
    }

    if(pLost == 2)
    {
        cout << "Black has won" << endl;
    }
    else if(pLost == 1)
    {
        cout << "White has won" << endl;
    }

    //while loop to determine when game is over
    //p1 goes, updates/checks win condition, then p2 goes, repeat check/update
    //if either wins during the process break out
    return 0;
}
