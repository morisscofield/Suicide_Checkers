#ifndef CALCULATION_H_
#define CALCULATION_H_
#include "Board.h"

// This class queries the board and calculates all the valid moves that an algorithm can make
// This class will never change what is on the board
class Calculation
{
public: // Constructor
	Calculation(Board* board, char player) : _board(board), _player(player) {};

public: // Public get methods (For Algorithm class)
	vector<coordinates> movable_pieces() const; // Returns the coordinates of all movable pieces
	vector<coordinates> possible_empty_moves(const coordinates piece) const; // Returns the possible coordinates a piece can move to
	vector<coordinates> attack_pieces() const; // Returns the coordinates of pieces in the position to take enemy pieces
	vector<coordinates> possible_attack_moves(const coordinates piece) const; // Returns the possible coordinates a piece can jump to
	coordinates vulnerable_position(const coordinates piece, const coordinates jump) const; // Returns the position of a vulnerable enemy piece
	int pieces_left() const; // Returns the number of pieces remaining on the board

private: // Private member variables
	Board* _board; // Stores a pointer to shared board (This class will not change the state of the board hence the 'const' keyword)
	const char _player; // Stores which player is being calculated for

private: // Private get methods
	vector<coordinates> _offset_coordinates(const coordinates coord) const; // Returns the left and right coordinates relative to a piece's position
	vector<coordinates> _attack_coordinates(const coordinates coord) const; // Returns the left and right jump coordinates relative to a piece's position
};

#endif
