#include "Algorithm2.h"

// Public methods
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Algorithm2::can_move() const
{
	vector<coordinates> movable = _calculate.movable_pieces();

	if (movable.empty() == true)
		return false;

	return true;
}

bool Algorithm2::can_capture() const
{
	vector<coordinates> attack = _calculate.attack_pieces();

	if (attack.empty() == true)
		return false;

	return true;
}

vector<coordinates> Algorithm2::latest_move() const
{
	return _move;
}

int Algorithm2::pieces_left() const
{
	return _calculate.pieces_left();
}

void Algorithm2::capture()
{
	vector<coordinates> pieces = _calculate.attack_pieces(); // Calculate which pieces can attack

	// Pick a random piece among those available
	int random = rand() % pieces.size();
	coordinates piece = pieces.at(random);

	// Calculate what moves are available
	vector<coordinates> moves = _calculate.possible_attack_moves(piece);

	// Pick a random move among those available
	random = rand() % moves.size();
	coordinates jump = moves.at(random);

	// Make the move
	_board->move_player1_piece(piece, jump);

	// Remove the opponent's piece from the board
	coordinates opponent = _calculate.vulnerable_position(piece, jump);
	_board->remove_player2_piece(opponent);

	// Store the latest move made
	_move.clear();
	_move.push_back(piece);
	_move.push_back(jump);
	_move.push_back(opponent);
}

void Algorithm2::move()
{
	vector<coordinates> pieces = _calculate.movable_pieces(); // Calculate which pieces can be moved

	// Pick a random piece among those available
	int random = rand() % pieces.size();
	coordinates piece = pieces.at(random);

	// Calculate what moves are available
	vector<coordinates> moves = _calculate.possible_empty_moves(piece);

	// Pick a random move among those available
	random = rand() % moves.size();
	coordinates move = moves.at(random);

	// Make the move
	_board->move_player1_piece(piece, move);

	// Store the latest move made
	_move.clear();
	_move.push_back(piece);
	_move.push_back(move);
}