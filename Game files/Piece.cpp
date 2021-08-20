#include "Piece.h"

// Constructor
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Piece::Piece(int x, int y)
{
	_x = x;
	_y = y;
	_exists = true;
}
// Public methods
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Piece::set_x_coordinate(int x)
{
	if (x >= 0)
		_x = x;
}

void Piece::set_y_coordinate(int y)
{
	if (y >= 0)
		_y = y;
}

void Piece::kill_piece()
{
	_exists = false;
}

int Piece::get_x_coordinate() const
{
	return _x;
}

int Piece::get_y_coordinate() const
{
	return _y;
}

bool Piece::is_piece_alive() const
{
	return _exists;
}