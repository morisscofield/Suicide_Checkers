// Kanya Game (Checkers).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include "Game.h"
using namespace std;

int main()
{
	ifstream inFile("input.txt");
	ofstream outFile("results.txt");
	int size = 0;

	while (inFile >> size)
	{
		if (size >= 6 && size <= 12 && size % 2 == 0)
		{
			Game checkers(size, &outFile);
			checkers.play();
		}
		else NULL;
	}
}