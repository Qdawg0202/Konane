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

public:
    vector<vector<char>> board2D; //accessible to others boardName.board2D[row][column]
    int rows;
    int columns;
    Board();
    Board(int xSize, int ySize);
    void printBoard();
    bool removePiece(int x, int y);
    bool firstRemove(int x, int y);
};

Board::Board()
{
    vector<vector<char>> arr = board2D;
    rows = 0;
    columns = 0;
}
Board::Board(int xSize, int ySize)
{
    columns = xSize;
    rows = ySize;

    vector<vector<char>> vec( rows , vector<char> (columns, '0'));

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
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

    cout << "     ";
    for(int x = 0; x<columns; x++)
    {
        cout << x + 1 << " ";
    }
    cout << endl;
    //formatting function

    for(int i = 0; i < rows; i++)
    {
        cout << " " << i + 1 << "|  ";
        for(int j = 0; j < columns; j++)
        {
            cout << board2D[i][j] << " ";
        }
        cout<< endl;
    }
}

bool Board::removePiece(int x, int y)
{

    bool insideGrid = columns >= x && rows >= y &&  //is it inside the grid
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
            (x == columns && y == rows) ||
            (x == 1 && y == columns) ||
            (y == 1 && x == rows);

    int xEven = columns % 2;
    int yEven = rows % 2;

    if(isEdge)
    {
        removePiece(x, y);
        return true;
    }
    else
    {
        if(xEven == 0 && yEven == 0)
        {
            if(x == columns/2 && y == rows/2 || //checks the inside of the middle square if it exists
                    x == (columns/2+1) && y == (rows/2) ||
                    x == columns/2 && y == (rows/2)+1 ||
                    x == (columns/2+1) && y == (rows/2)+1)
            {
                removePiece(x, y);
                return true;
            }
        }
        else if(xEven == 0)
        {
            if(x == columns/2 && y == (rows/2) + 1 || //checks center columns pieces when rows is uneven
                    x == (columns/2) + 1 && y == (rows/2) + 1)
            {
                removePiece(x, y);
                return true;
            }
        }
        else if(yEven == 0)
        {
            if(x == (columns/2) + 1  && y == (rows/2)|| //checks center y pieces when x is uneven
               x == (columns/2) + 1 && y == (rows/2) + 1)
            {
                removePiece(x, y);
                return true;
            }
        }
    }
    return false;
}


#endif //KONANE_BOARD_HPP
