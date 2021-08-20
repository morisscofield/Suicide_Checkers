#include "Calculation.h"

// Private methods
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<coordinates> Calculation::_offset_coordinates(
	const coordinates coord) const
{
	vector<coordinates> coords;

	coordinates coordLeft;
	if (_player == '1')
		coordLeft.x = coord.x + 1;
	else if (_player == '2')
		coordLeft.x = coord.x - 1;

	coordLeft.y = coord.y - 1;
	coords.push_back(coordLeft);

	coordinates coordRight;
	if (_player == '1')
		coordRight.x = coord.x + 1;
	else if (_player == '2')
		coordRight.x = coord.x - 1;

	coordRight.y = coord.y + 1;
	coords.push_back(coordRight);

	return coords;
}

vector<coordinates> Calculation::_attack_coordinates(
	const coordinates coord) const
{
	vector<coordinates> coords;

	coordinates coordLeft;
	if (_player == '1')
		coordLeft.x = coord.x + 2;
	else if (_player == '2')
		coordLeft.x = coord.x - 2;

	coordLeft.y = coord.y - 2;
	coords.push_back(coordLeft);

	coordinates coordRight;
	if (_player == '1')
		coordRight.x = coord.x + 2;
	else if (_player == '2')
		coordRight.x = coord.x - 2;

	coordRight.y = coord.y + 2;
	coords.push_back(coordRight);

	return coords;
}

// Public methods
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<coordinates> Calculation::movable_pieces() const
{
	vector<coordinates> coords;
	vector<coordinates> pieces;
	if (_player == '1')
		pieces = _board->player_1_pieces();
	else if (_player == '2')
		pieces = _board->player_2_pieces();

	for (int i = 0; i < pieces.size(); i++)
	{
		vector<coordinates> possibleMoves = possible_empty_moves(pieces.at(i));
		if (possibleMoves.empty() == false)
			coords.push_back(pieces.at(i));
	}

	return coords;
}

vector<coordinates> Calculation::possible_empty_moves(
	const coordinates piece) const
{
	vector<coordinates> coords;
	vector<coordinates> offsetCoords = _offset_coordinates(piece);

	if (_board->is_valid_coordinate(offsetCoords.at(0))
		&& _board->is_empty(offsetCoords.at(0)))
		coords.push_back(offsetCoords.at(0));

	if (_board->is_valid_coordinate(offsetCoords.at(1))
		&& _board->is_empty(offsetCoords.at(1)))
		coords.push_back(offsetCoords.at(1));

	return coords;
}

vector<coordinates> Calculation::attack_pieces() const
{
	vector<coordinates> coords;
	vector<coordinates> pieces;
	if (_player == '1')
		pieces = _board->player_1_pieces();
	else if (_player == '2')
		pieces = _board->player_2_pieces();

	for (int i = 0; i < pieces.size(); i++)
	{
		vector<coordinates> possibleMoves = possible_attack_moves(pieces.at(i));
		if (possibleMoves.empty() == false)
			coords.push_back(pieces.at(i));
	}

	return coords;
}

vector<coordinates> Calculation::possible_attack_moves(coordinates piece) const
{
	vector<coordinates> coords;
	vector<coordinates> offsetCoords = _offset_coordinates(piece);
	vector<coordinates> attackCoords = _attack_coordinates(piece);

	if (_board->is_valid_coordinate(attackCoords.at(0))
		&& _board->is_valid_coordinate(offsetCoords.at(0)))
	{
		if (_player == '1' && _board->is_player_2_piece(offsetCoords.at(0))
			&& _board->is_empty(attackCoords.at(0)))
			coords.push_back(attackCoords.at(0));

		else if (_player == '2' && _board->is_player_1_piece(offsetCoords.at(0))
			&& _board->is_empty(attackCoords.at(0)))
			coords.push_back(attackCoords.at(0));
	}

	if (_board->is_valid_coordinate(attackCoords.at(1))
		&& _board->is_valid_coordinate(offsetCoords.at(1)))
	{
		if (_player == '1' && _board->is_player_2_piece(offsetCoords.at(1))
			&& _board->is_empty(attackCoords.at(1)))
			coords.push_back(attackCoords.at(1));

		else if (_player == '2' && _board->is_player_1_piece(offsetCoords.at(1))
			&& _board->is_empty(attackCoords.at(1)))
			coords.push_back(attackCoords.at(1));
	}

	return coords;
}

coordinates Calculation::vulnerable_position(const coordinates piece,
	coordinates jump) const
{
	coordinates coord;
	coord.x = (piece.x + jump.x) / 2;
	coord.y = (piece.y + jump.y) / 2;

	return coord;
}

int Calculation::pieces_left() const
{
	int result;
	vector<coordinates> pieces;

	if (_player == '1')
		pieces = _board->player_1_pieces();
	else if (_player == '2')
		pieces = _board->player_2_pieces();

	result = pieces.size();
	return result;
}
