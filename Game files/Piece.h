#ifndef PIECE_H_
#define PIECE_H_

class Piece
{
public:
	Piece(int x, int y);
	void set_x_coordinate(int x); // Change the x coordinate of the piece
	void set_y_coordinate(int y); // Change the y coordinate of the piece
	void kill_piece(); // Set the piece as invalid

	int get_x_coordinate() const; // Returns the x coordinate of the piece
	int get_y_coordinate() const; // Returns the y coordinate of the piece
	bool is_piece_alive() const; // Returns whether the piece is valid or not

private: // Private members
	int _x; // Store the piece's x coordinate
	int _y; // Store the piece's y coordinate
	bool _exists; // Store the piece's validity flag
};

#endif
