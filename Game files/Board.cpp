#include "Board.h"

// Constructor
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Board::Board(int boardSize)
{
	_boardSize = boardSize;
	_initialise_player_1_pieces();
	_initialise_player_2_pieces();
}

// Private methods
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Board::_initialise_player_1_pieces()
{
	_pieces1.clear();
	int rowDepth = (_boardSize / 2) - 1;

	for (int rowIndex = 0; rowIndex < rowDepth; rowIndex++)
	{
		_place_pieces(rowIndex, &_pieces1);
	}
}

void Board::_initialise_player_2_pieces()
{
	_pieces2.clear();
	int rowDepth = _boardSize - ((_boardSize / 2) - 1);

	for (int rowIndex = rowDepth; rowIndex < _boardSize; rowIndex++)
	{
		_place_pieces(rowIndex, &_pieces2);
	}
}

void Board::_place_pieces(const int& rowIndex, vector<Piece>* pieces)
{
	int colIndex = 0;
	int colDepth = _boardSize / 2;
	if (rowIndex % 2 == 1)
		colIndex = 1;

	for (int j = 0; j < colDepth; j++)
	{
		Piece piece = Piece(rowIndex, colIndex);
		pieces->push_back(piece);
		colIndex += 2;
	}
}

void Board::_move_piece(const coordinates& piece, const int index,
	vector<Piece>& pieces)
{
	pieces.at(index).set_x_coordinate(piece.x);
	pieces.at(index).set_y_coordinate(piece.y);
}

void Board::_delete_piece(const int& index, vector<Piece>& pieces)
{
	pieces.at(index).kill_piece();
}

bool Board::_does_piece_exist(const coordinates& piece,
	const vector<Piece>& pieces) const
{
	for (int i = 0; i < pieces.size(); i++)
	{
		if (pieces.at(i).get_x_coordinate() == piece.x
			&& pieces.at(i).get_y_coordinate() == piece.y)
			return true;
	}

	return false;
}

int Board::_find_piece(const coordinates& piece,
	const vector<Piece>& pieces) const
{
	int index = -1;
	for (int i = 0; i < pieces.size(); i++)
	{
		if (pieces.at(i).get_x_coordinate() == piece.x
			&& pieces.at(i).get_y_coordinate() == piece.y)
		{
			index = i;
			break;
		}
	}

	return index;
}

coordinates Board::_extract_coordinates(const Piece& piece) const
{
	coordinates coord;
	coord.x = piece.get_x_coordinate();
	coord.y = piece.get_y_coordinate();
	return coord;
}

void Board::_clean_board(vector<Piece>& pieces)
{
	vector<Piece> tempPieces;

	for (int i = 0; i < pieces.size(); i++)
	{
		if (pieces.at(i).is_piece_alive() == true)
			tempPieces.push_back(pieces.at(i));
	}

	pieces = tempPieces;
}

// Public methods
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Board::is_player_1_piece(const coordinates piece) const
{
	bool found = _does_piece_exist(piece, _pieces1);
	return found;
}

bool Board::is_player_2_piece(const coordinates piece) const
{
	bool found = _does_piece_exist(piece, _pieces2);
	return found;
}

bool Board::is_empty(const coordinates piece) const
{
	bool found1 = is_player_1_piece(piece);
	bool found2 = is_player_2_piece(piece);

	if (found1 || found2)
		return false;

	return true;
}

bool Board::is_valid_coordinate(const coordinates coord) const
{
	if (coord.x < 0 || coord.y < 0)
		return false;
	if (coord.x >= _boardSize || coord.y >= _boardSize)
		return false;
	if (coord.x % 2 == 0 && coord.y % 2 == 1)
		return false;
	if (coord.x % 2 == 1 && coord.y % 2 == 0)
		return false;

	return true;
}

vector<coordinates> Board::player_1_pieces() const
{
	vector<coordinates> coords;
	for (int i = 0; i < _pieces1.size(); i++)
	{
		coordinates coord = _extract_coordinates(_pieces1.at(i));
		coords.push_back(coord);
	}

	return coords;
}

vector<coordinates> Board::player_2_pieces() const
{
	vector<coordinates> coords;
	for (int i = 0; i < _pieces2.size(); i++)
	{
		coordinates coord = _extract_coordinates(_pieces2.at(i));
		coords.push_back(coord);
	}

	return coords;
}

void Board::move_player1_piece(const coordinates before,
	const coordinates after)
{
	int index = _find_piece(before, _pieces1);
	if (index != -1)
		_move_piece(after, index, _pieces1);
}

void Board::move_player2_piece(const coordinates before,
	const coordinates after)
{
	int index = _find_piece(before, _pieces2);
	if (index != -1)
		_move_piece(after, index, _pieces2);
}

void Board::remove_player1_piece(const coordinates piece)
{
	int index = _find_piece(piece, _pieces1);
	if (index != -1)
	{
		_delete_piece(index, _pieces1);
		_clean_board(_pieces1);
	}
}

void Board::remove_player2_piece(const coordinates piece)
{
	int index = _find_piece(piece, _pieces2);
	if (index != -1)
	{
		_delete_piece(index, _pieces2);
		_clean_board(_pieces2);
	}
}