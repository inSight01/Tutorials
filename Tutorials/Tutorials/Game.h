#pragma once

#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

class Game
{
public:
	Game();

	void begin();

private:
	// This will be true for running while loops
	bool _looping = false;

	// This will store an integer for menu selections
	int _menuSelection = 0;

	// If user input incorrect
	bool _error = false;
	
	// Who's turn is it (X or O)?
	char _player1 = 'X';
	char _player2 = 'O';
	char _playerT = 'X';

	// Game status
	bool _gameOver = false;

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
	int data[_numRows][_numCols] = { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } };

	// Menu function
	void title();
	void mainMenu();
	void pvpMenu();
	void pvcMenu();
	void choosePlayerMenu();
	void endMenu(int &id);
	void exit();

	// Update functions
	void updatePVP();
	void updatePVCEasy();
	void updatePVCHard();
	void processInput();
	int checkData();
	int randomGenerator(int min, int max);

	// Render functions
	string block(int y, int x, int z);
	void renderBoard();
};

