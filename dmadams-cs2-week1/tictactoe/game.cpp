/**
* @file game.cpp
* @author David Adams
* @date 01/11/17
* 
* @brief Runs an instance of the board.
*/

#include "game.hpp"
#include <iostream>

using namespace std;

/**
* @brief Constructs a new game. 
*/
Game::Game()
{
    board = new Board;
    turn = -1;
}

/**
* @brief Deletes the game.
*/
Game::~Game()
{
    delete board;
}

/**
* @brief Runs the game.
*/
void Game::run()
{
    int coord;
    int currentPlayer;

    while (board->isWin() == 0 && !board->isTie()) //checks for win or tie
    {
        currentPlayer = 1;
        if (turn == 1)
        {
            currentPlayer = 2;
        }
        cout << "Player " << currentPlayer << " enter your move: " << endl;
        cin >> coord;
        board->setVal(coord, turn);
        board->printState();
        turn *= -1;
    }

    if(board->isTie()) //game ends in tie
    {
        cout << "You tied." << endl;
    }
    else //game ends in win
    {
        cout << "Congratulations Player " << currentPlayer << " you won." << 
        endl;
    }
}