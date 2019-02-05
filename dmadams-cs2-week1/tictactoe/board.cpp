/**
* @file board.cpp
* @author David Adams
* @date 01/11/17
* 
* @brief Represents a 3 x 3 Tic-Tac-Toe board.
*/

#include "board.hpp"
#include <iostream>

using namespace std;

/**
* @brief Constructs a new board.
*/
Board::Board()
{
    boardArr = new int[9];
    for (int i = 0; i < 9; i ++)
    {
        *(boardArr + i) = 0;
    }
}

/**
* @brief Deletes the board.
*/
Board::~Board()
{
    delete[] boardArr;
}

/**
* @brief Sets the value at a board position from 1 - 9 to -1, 0, or 1. -1 is 
* Player 1, 1 is Player 2, and 0 means the space is empty.
* 
* The board positions are below:
* 
* 1 | 2 | 3
* ---------
* 4 | 5 | 6
* ---------
* 7 | 8 | 9
*/
void Board::setVal(int coord, int val)
{
    *(boardArr + coord - 1) = val;
}

/**
* @brief Gets the value at a board position from 1 - 9.
* The board positions are below:
* 
* 1 | 2 | 3
* ---------
* 4 | 5 | 6
* ---------
* 7 | 8 | 9
*/
int Board::getVal(int coord)
{
    return *(boardArr + coord - 1);
}

/**
* @brief Represents the value at a board position from 1 - 9. The value -1
* is represented as 'X', 1 as '0', and 0 as ' '.
* The board positions are below:
* 
* 1 | 2 | 3
* ---------
* 4 | 5 | 6
* ---------
* 7 | 8 | 9
*/
char Board::repVal(int coord)
{
    if (getVal(coord) == -1)
    {
        return 'X';
    }
    else if (getVal(coord) == 1)
    {
        return 'O';
    }
    return ' ';
}

/**
* @brief Prints out the current state of the board.
*/
void Board::printState()
{
    cout << repVal(1) << " | " << repVal(2) << " | " << repVal(3) << endl;
    cout << "---------" << endl;
    cout << repVal(4) << " | " << repVal(5) << " | " << repVal(6) << endl;
    cout << "---------" << endl;
    cout << repVal(7) << " | " << repVal(8) << " | " << repVal(9) << endl;
    cout << endl;
}

/**
* @brief Checks if anyone won. Returns 0 if nobody won, -1 if Player 1 won, and
* 1 if Player 2 won. 
*/
int Board::isWin()
{
    // checking for row wins
    for (int i = 1; i <= 7; i += 3)
    {
        if (getVal(i) == -1 && getVal(i + 1) == -1 && getVal(i + 2) == -1)
        {
            return -1;
        }
        else if (getVal(i) == 1 && getVal(i + 1) == 1 && getVal(i + 2) == 1)
        {
            return 1;
        }
    }

    // checking for column wins
    for (int j = 1; j <= 3; j ++)
    {
        if (getVal(j) == -1 && getVal(j + 3) == -1 && getVal(j+ 6) == -1)
        {
            return -1;
        }
        else if(getVal(j) == 1 && getVal(j + 3) == 1 && getVal(j + 6) == 1)
        {
            return 1;
        }
    }

    // checking for downwards diagonal wins
    if (getVal(1) == -1 && getVal(5) == -1 && getVal(9) == -1)
    {
        return -1;
    }
    else if (getVal(1) == 1 && getVal(5) == 1 && getVal(9) == 1)
    {
        return 1;
    }

    // checking for upwards diagonal wins
    if (getVal(7) == -1 && getVal(5) == -1 && getVal(3) == -1)
    {
        return -1;
    }
    else if (getVal(7) == 1 && getVal(5) == 1 && getVal(3) == 1)
    {
        return 1;
    }

    return 0; // nobody won
}

/**
* @brief Checks if there are any possible moves to be made. Returns true if 
* there are remaining moves and false if there are not.
*/
bool Board::anyMoves()
{
    for (int i = 1; i <= 9; i ++)
    {
        if (getVal(i) == 0)
        {
            return true;
        }
    }
    return false;
}

/**
* @brief Checks if there is a tie. Returns true if there is a tie and false if
* not.
*/
bool Board::isTie()
{
    //checking if anyone won and if any moves are remaining
    if (isWin() == 0 && !anyMoves())
    {
        return true;
    }
    return false;
}
