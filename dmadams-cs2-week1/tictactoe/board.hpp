/**
* @file board.hpp
* @author David Adams
* @date 01/11/17
* 
* @brief Represents a 3 x 3 Tic-Tac-Toe board.
*/

class Board
{
private:
	int *boardArr; // Begins with the value at the top left corner
public:
	Board();
	~Board();
	void setVal(int coord, int val);
	int getVal(int coord);
    char repVal(int coord);
    void printState();
    int isWin();
    bool anyMoves();
    bool isTie();
};