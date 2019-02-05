/**
* @file game.hpp
* @author David Adams
* @date 01/11/17
* 
* @brief Runs an instance of the board.
*/

#include "board.hpp"

class Game
{
private:
    Board *board;
    int turn;
public:
    Game();
    ~Game();
    void run();
};