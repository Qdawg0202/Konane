//
// Created by Yungs on 11/2/2022.
//
#include <vector>
#include <stdio.h>
#include <iostream>

using namespace std;

#ifndef KONANE_BOARD_HPP
#define KONANE_BOARD_HPP
class Board{
private:
    vector<vector<int>> board2D;
    int x_dimension;
    int y_dimension;

public:
    Board();
    Board(int xSize, int ySize);
    void printBoard();
    //bool removePiece();
};

Board::Board()
{
    vector<vector<int>> arr = board2D;
    x_dimension = 0;
    y_dimension = 0;
}
Board::Board(int xSize, int ySize)
{
    cout << "Input board x dimension: " << endl;
    int x_dimension;
    cin >> x_dimension;

    cout << "Input board y dimension: " << endl;
    int y_dimension;
    cin >> y_dimension;


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
        cout<< endl;
    }
}

void Board::printBoard()
{
    for(int i = 0; i < x_dimension; i++)
    {
        for(int j = 0; j < y_dimension; j++)
        {
            cout << board2D[i][j] << " ";
        }
        cout<< endl;
    }
}




#endif //KONANE_BOARD_HPP
