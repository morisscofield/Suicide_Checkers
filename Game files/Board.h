#ifndef BOARD_H_
#define BOARD_H_
#include <vector>
#include "Piece.h"
using namespace std;

// This struct stores the x and y coordinates of a piece on the board
struct coordinates
{
	int x; // x coordinate
	int y; // y coordinate
};

// This class stores information about all pieces on the checkers board
// It allows the algorithms to query the board (get methods) or manipulate the board (set methods)
class Board
{
public: // Constructor
	Board(int boardSize);

public: // Public get methods (For Calculation objects)
	bool is_player_1_piece(const coordinates piece) const; // Returns true if the piece at the coordinates given belongs to player 1
	bool is_player_2_piece(const coordinates piece) const; // Returns true if the piece at the coordinates given belongs to player 2
	bool is_empty(const coordinates piece) const; // Returns true if there is no piece at the coordinates given
	bool is_valid_coordinate(const coordinates coord) const; // Returns true if the coordinate given is on the board
	vector<coordinates> player_1_pieces() const; // Returns the coordinates of all of player 1's pieces
	vector<coordinates> player_2_pieces() const; // Returns the coordinates of all of player 2's pieces

	// Public set methods (For Algorithm objects)
	void move_player1_piece(const coordinates before, const coordinates after); // Move a piece on the board if it belongs to player 1
	void move_player2_piece(const coordinates before, const coordinates after); // Move a piece on the board if it belongs to player 2
	void remove_player1_piece(const coordinates piece); // Remove a piece belonging to player 1 at the coordinate given
	void remove_player2_piece(const coordinates piece); // Remove a piece belonging to player 2 at the coordinate given

private: // Private member variables
	int _boardSize; // Store the game board size
	vector<Piece> _pieces1; // An array of all of player 1's living pieces on the board
	vector<Piece> _pieces2; // An array of all of player 2's living pieces on the board

private: // Private set methods
	void _initialise_player_1_pieces(); // Places pieces for player 1 in the correct positions
	void _initialise_player_2_pieces(); // Places pieces for player 2 in the correct positions
	void _place_pieces(const int& rowIndex, vector<Piece>* pieces); // Common for loop for initialization functions
	void _clean_board(vector<Piece>& pieces); // Remove dead pieces from the board
	void _move_piece(const coordinates& piece, const int index, vector<Piece>& pieces); // Change the coordinates of a piece on the board
	void _delete_piece(const int& index, vector<Piece>& pieces); // Remove a piece on the board

	// Private get methods
	int _find_piece(const coordinates& piece, const vector<Piece>& pieces) const; // Returns the index of the piece at the given coordinates
	bool _does_piece_exist(const coordinates& piece, const vector<Piece>& pieces) const; // Returns true if there is piece at the coordinates given
	coordinates _extract_coordinates(const Piece& piece) const; // Extracts and returns the coordinates from a piece object
};

#endif
