#include "Algorithm1.h"

// Public methods
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Algorithm1::can_move() const
{
	vector<coordinates> movable = _calculate.movable_pieces();

	if (movable.empty() == true)
		return false;

	return true;
}

bool Algorithm1::can_capture() const
{
	vector<coordinates> attack = _calculate.attack_pieces();

	if (attack.empty() == true)
		return false;

	return true;
}

vector<coordinates> Algorithm1::latest_move() const
{
	return _move;
}

int Algorithm1::pieces_left() const
{
	return _calculate.pieces_left();
}

void Algorithm1::capture()
{
	vector<coordinates> pieces = _calculate.attack_pieces(); // Calculate which pieces can attack

	// Cycle through available pieces and pick one
	int choice = _counter % pieces.size();
	coordinates piece = pieces.at(choice);

	// Calculate what moves are available
	vector<coordinates> moves = _calculate.possible_attack_moves(piece);

	// Pick a move based on the position of the counter
	choice = _counter % moves.size();
	coordinates jump = moves.at(choice);

	// Make the move
	_board->move_player2_piece(piece, jump);

	// Remove the opponent's piece from the board
	coordinates opponent = _calculate.vulnerable_position(piece, jump);
	_board->remove_player1_piece(opponent);

	// Increment the counter for the next move
	_counter++;

	// Store the latest move made
	_move.clear();
	_move.push_back(piece);
	_move.push_back(jump);
	_move.push_back(opponent);
}


void Algorithm1::move()
{
	vector<coordinates> pieces = _calculate.movable_pieces(); // Calculate which pieces can be moved

	// Cycle through available pieces and pick one
	int choice = _counter % pieces.size();
	coordinates piece = pieces.at(choice);

	// Calculate what moves are available
	vector<coordinates> moves = _calculate.possible_empty_moves(piece);

	// Pick a move based on the position of the counter
	choice = _counter % moves.size();
	coordinates move = moves.at(choice);

	// Make the move
	_board->move_player2_piece(piece, move);

	// Increment the counter for the next move
	_counter++;

	// Store the latest move made
	_move.clear();
	_move.push_back(piece);
	_move.push_back(move);
}