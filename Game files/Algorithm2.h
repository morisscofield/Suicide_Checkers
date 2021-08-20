#ifndef ALGORITHM2_H_
#define ALGORITHM2_H_
#include <cstdlib>
#include <ctime>
#include "Board.h"
#include "Calculation.h"

// This algorithm is the second of two what will play on the checkers board
// It picks a random move from the available moves offered by the calculate object
// This class will never directly query the board. It will only manipulate the board
class Algorithm2
{
public: // Constructor
	Algorithm2(Board* board) : _calculate(board, '1'), _board(board) { srand(time(0)); };

public: // Public get methods
	bool can_move() const; // Returns true if the player can move
	bool can_capture() const; // Returns true if a player can capture a piece
	vector<coordinates> latest_move() const; // Returns a vector of coordinates showing the last move made
	int pieces_left() const; // Returns the number of pieces that player 1 has left on the board

	// Public set methods
	void move(); // Make a move
	void capture(); // Capture an opponent's piece and jump

private: // Private member variables
	Calculation _calculate;
	Board* _board;
	vector<coordinates> _move;
};

#endif
