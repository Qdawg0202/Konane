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
    Player(char c)
    //bool MovesPossible();
    //bool makeMove(Board gameBoard, int x, int y);
};
Player::Player(char c)
{
    playerColor = c;
}
bool Player::MovesPossible()
{

}
bool MakeMove(Board &gameBoard, int xStart, int yStart, int xEnd, int yEnd)
{

}




#endif //KONANE_PLAYER_HPP
