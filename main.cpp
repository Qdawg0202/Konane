#include <iostream>
#include <stdio.h>
#include <stdexcept>
#include "Board.hpp"
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

    //Creates game board and prints out values
    Board gameBoard(x_dimension, y_dimension);
    gameBoard.printBoard();

    int firstX;
    int firstY;

    cout << "Choose the first move " << endl;
    cout << "select the row: " << endl;
    cin >> firstX;
    cout << "select the column: " << endl;
    cin >> firstY;
    bool firstMove = gameBoard.firstRemove(firstX, firstY);

    while (!firstMove) //asks for a valid move if not given
    {
        cout << "Invalid first move, please select a piece from either the center or the edges" << endl;
        cout << "select the row: " << endl;
        cin >> firstX;
        cout << "select the column: " << endl;
        cin >> firstY;
        firstMove = gameBoard.firstRemove(firstX, firstY);
    }

    //gameBoard.printBoard();
}