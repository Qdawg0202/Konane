#include <iostream>
#include <stdio.h>
#include <stdexcept>
#include <vector>

using namespace std;

/*
    populate board alternatively
    allow creation with their own board dimensions (one side must be even)
    allow player to take a piece out of the center or out of the corner

void printBoard();

using namespace std;

bool createBoard() {

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
        int board[x_dimension][y_dimension];
        vector<vector<int>> vec;
        for (int a = 0; a < x_dimension; a++) {
            for (int b = 0; b < y_dimension; b++) {
                cout << board[a][b] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "Error encountered, invalid board size." << endl;
        cout << "At least one dimension of the board must be an even number" << endl;
        return false; //return false for error
    }
}

void printBoard()
{
    for(int a = 0; a < x_dimension; a++)
    {
        for(int b = 0; b < y_dimension; b++)
        {
            cout << board[a][b] << " ";
        }
        cout << endl;
    }
}
*/

int main()
{
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


    for(int i = 0; i < x_dimension; i++)
    {
        for(int j = 0; j < y_dimension; j++)
        {
            cout << vec[i][j] << " ";
        }
        cout<< endl;
    }
}