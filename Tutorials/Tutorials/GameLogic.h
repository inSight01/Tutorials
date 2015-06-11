#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <random>

using namespace std;

class GameLogic
{
public:
	GameLogic();

private:
	// Variables
	const static int _numRows = 3;
	const static int _numCols = 3;
	const static int _numSubs = 5;

	// Blocks
	string blocks[6][_numSubs] = { { "         ", "         ", "         ", "         ", "         " },
	                               { " ##   ## ", "  ## ##  ", "   ###   ", "  ## ##  ", " ##   ## " },
	                               { "   ###   ", "  ## ##  ", " ##   ## ", "  ## ##  ", "   ###   " },
	                               { ".##...##.", "..##.##..", "...###...", "..##.##..", ".##...##." },
	                               { "...###...", "..##.##..", ".##...##.", "..##.##..", "...###..." },
	                               { " #####   ", " ##  ##  ", " ##   ## ", " ##  ##  ", " #####   " }
	                              };
	
	// Database
	char rowSelection = 0;
	int colSelection  = 0;
	int data[_numRows][_numCols] = { { 0, 0, 0 },{ 0, 0, 0 },{ 0, 0, 0 } };
	
	// Update functions
	void updatePVP();
	void updatePVCEasy();
	void updatePVCHard();
	void processInput();
	int checkData();
	int randomGenerator(int min, int max);
};

