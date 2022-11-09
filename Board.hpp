//
// Created by Yungs on 11/2/2022.
//

/* PLAYER 1 = X SHOULD GO FIRST
 * PLAYER 2 = 0 SHOULD GO SECOND
 */

#include <vector>
#include <stdio.h>
#include <iostream>

using namespace std;

#ifndef KONANE_BOARD_HPP
#define KONANE_BOARD_HPP
class Board{
private:
    vector<vector<char>> board2D;
    int x_dimension;
    int y_dimension;

public:
    Board();
    Board(int xSize, int ySize);
    void printBoard();
    bool removePiece(int x, int y);
    bool firstRemove(int x, int y);
};

Board::Board()
{
    vector<vector<char>> arr = board2D;
    x_dimension = 0;
    y_dimension = 0;
}
Board::Board(int xSize, int ySize)
{
    x_dimension = xSize;
    y_dimension = ySize;

    vector<vector<char>> vec( x_dimension , vector<char> (y_dimension, '0'));

    for(int i = 0; i < x_dimension; i++)
    {
        for(int j = 0; j < y_dimension; j++)
        {
            if(i%2 == 0)
            {
                if(j%2 == 0)
                    vec[i][j] = 'X';
            }
            else
            {
                if(j%2 != 0)
                    vec[i][j] = 'X';
            }
        }
    }
    board2D = vec;
}

void Board::printBoard()
{
    cout << endl;
    for(int i = 0; i < x_dimension; i++)
    {
        for(int j = 0; j < y_dimension; j++)
        {
            cout << board2D[i][j] << " ";
        }
        cout<< endl;
    }
}

bool Board::removePiece(int x, int y)
{

    bool insideGrid = x_dimension >= x && y_dimension >= y &&  //is it inside the grid
            0 < x && 0 < y; //is it bigger than zero

    if(insideGrid)
    {
        board2D[x-1][y-1] = '_';
        printBoard();
        return true;
    }
    else
        return false;
}

bool Board::firstRemove(int x, int y)
{
    bool isEdge = (x == 1 && y == 1) || //checks to see if x or y are edge pieces
            (x == x_dimension && y == y_dimension) ||
            (x == 1 && y == y_dimension) ||
            (y == 1 && x == x_dimension);

    int xEven = x_dimension % 2;
    int yEven = y_dimension % 2;

    if(isEdge)
    {
        removePiece(x, y);
        return true;
    }
    else
    {
        if(xEven == 0 && yEven == 0)
        {
            if(x == x_dimension/2 && y == y_dimension/2 || //checks the inside of the middle square if it exists
                    x == (x_dimension/2+1) && y == (y_dimension/2) ||
                    x == x_dimension/2 && y == (y_dimension/2)+1 ||
                    x == (x_dimension/2+1) && y == (y_dimension/2)+1)
            {
                removePiece(x, y);
                return true;
            }
        }
        else if(xEven == 0)
        {
            if(x == x_dimension/2 && y == (y_dimension/2) + 1 || //checks center x pieces when y is uneven
                    x == (x_dimension/2) + 1 && y == (y_dimension/2) + 1)
            {
                removePiece(x, y);
                return true;
            }
        }
        else if(yEven == 0)
        {
            if(x == (x_dimension/2) + 1  && y == (y_dimension/2)|| //checks center y pieces when x is uneven
               x == (x_dimension/2) + 1 && y == (y_dimension/2) + 1)
            {
                removePiece(x, y);
                return true;
            }
        }
    }
    return false;
}


#endif //KONANE_BOARD_HPP
