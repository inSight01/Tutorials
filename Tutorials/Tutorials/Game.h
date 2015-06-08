#pragma once

#include <iostream>
#include <string>

using namespace std;

class Game
{
public:
	Game();

	void begin();

private:
	bool playing = true;

	// Variables
	const static int numRows = 3;
	const static int numCols = 3;
	const static int numSubs = 5;
	
	// Blocks
	string blocks[3][numSubs] = { { "         ", "         ", "         ", "         ", "         " },
	                              { " ##   ## ", "  ## ##  ", "   ###   ", "  ## ##  ", " ##   ## " },
								  { "   ###   ", "  ## ##  ", " ##   ## ", "  ## ##  ", "   ###   " } 
	                            };

	// Database
	int data[numRows][numCols] = { { 1, 0, 1 }, { 0, 2, 0 }, { 1, 0, 1 } };

	string block(int y, int x, int z);
	void update();
	void render();
};

