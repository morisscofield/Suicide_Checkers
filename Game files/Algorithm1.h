#ifndef ALGORITHM1_H_
#define ALGORITHM1_H_
#include "Board.h"
#include "Calculation.h"

// This algorithm is the first of two that will play on the checkers board
// It progressively cycles through the available moves and alternates between
// moving the piece either left or right
class Algorithm1
{
public: // Constructor
	Algorithm1(Board* board) : _calculate(board, '2'), _board(board), _counter(0) {};

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
	int _counter;
	vector<coordinates> _move;
};

#endif
