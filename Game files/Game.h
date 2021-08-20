#ifndef GAME_H_
#define GAME_H_
#include <iostream>
#include <fstream>
#include "Algorithm1.h"
#include "Algorithm2.h"
#include "Board.h"
using namespace std;

class Game
{
public: // Constructor
	Game(int size, ofstream* outfile) : _outFile(outfile), _board(size), _alg1(&_board), _alg2(&_board), _counter(0), _size(size) {};

public: // Public set methods
	void play();

private: // Private member variables
	ofstream* _outFile;
	Board _board;
	Algorithm1 _alg1;
	Algorithm2 _alg2;
	int _counter;
	int _size;

private: // Private set methods
	void _player_1(); // Player 1 makes a move
	void _player_2(); // Player 2 makes a move
	void _print_player_move(const vector<coordinates>& moves); // Print latest move to file
	void _print_player_attack(const vector<coordinates>& moves); // Print latest attack move to file
	void _print_results(); // Output the results to file

	// Private get methods
	int _calculate_position(const coordinates coord) const; // Returns the proper index for outputting to file
	bool _valid_game() const; // Returns true if a valid game can be played
};

#endif
