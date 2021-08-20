#include "Game.h"

void Game::_player_1()
{
	if (_alg1.can_capture() == true)
	{
		do
		{
			_alg1.capture();
			vector<coordinates> moves = _alg1.latest_move();
			_print_player_attack(moves);

		} while (_alg1.can_capture() == true);

	}
	else if (_alg1.can_move() == true)
	{
		_alg1.move();
		vector<coordinates> moves = _alg1.latest_move();
		_print_player_move(moves);
	}
}

void Game::_player_2()
{
	if (_alg2.can_capture() == true)
	{
		do
		{
			_alg2.capture();
			vector<coordinates> moves = _alg2.latest_move();
			_print_player_attack(moves);

		} while (_alg2.can_capture() == true);
	}

	else if (_alg2.can_move() == true)
	{
		_alg2.move();
		vector<coordinates> moves = _alg2.latest_move();
		_print_player_move(moves);
	}
}

void Game::_print_player_attack(const vector<coordinates>& moves)
{
	*_outFile << _calculate_position(moves.at(0)) << "x";
	*_outFile << _calculate_position(moves.at(1)) << "(";
	*_outFile << _calculate_position(moves.at(2)) << ")";
}

void Game::_print_player_move(const vector<coordinates>& moves)
{

	*_outFile << _calculate_position(moves.at(0)) << "-";
	*_outFile << _calculate_position(moves.at(1));
}

void Game::_print_results()
{
	int pieces1 = _alg1.pieces_left();
	int pieces2 = _alg2.pieces_left();
	*_outFile << "tp1 " << pieces1 << endl;
	*_outFile << "tp2 " << pieces2 << endl;

	if (pieces2 != 0 && pieces1 == 0)
		*_outFile << "wp1" << endl;
	else if (pieces1 != 0 && pieces2 == 0)
		*_outFile << "wp2" << endl;
	else
		*_outFile << "d" << endl;
}

int Game::_calculate_position(const coordinates coord) const
{
	int row = (_size - (coord.x + 1)) * (_size / 2);
	int col = (coord.y / 2) + 1;

	return row + col;
}
bool Game::_valid_game() const
{
	bool valid = false;
	bool attack = false;
	bool move = false;

	if (_counter % 2 == 0)
	{
		attack = _alg1.can_capture();
		move = _alg1.can_move();
	}
	else
	{
		attack = _alg2.can_capture();
		move = _alg2.can_move();
	}

	if (attack == true || move == true)
		valid = true;

	return valid;
}

void Game::play()
{
	*_outFile << _size << endl;

	while (_valid_game())
	{
		if (_counter % 2 == 0)
		{
			*_outFile << "p" << "1" << " ";
			_player_1();
		}
		else
		{
			*_outFile << "p" << "2" << " ";
			_player_2();
		}
		*_outFile << endl;

		_counter++;
	}
	_print_results();
	*_outFile << endl;

}