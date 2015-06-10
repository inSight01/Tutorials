#include "Game.h"

Game::Game()
{
}

void Game::begin()
{
	while (_looping) {

		// Reset game, even if it's already reset
		_player1  = 'X';
		_player2  = 'O';
		_playerT  = 'X';
		_gameOver = false;
		_winner   = 0;
		for (int y = 0; y < 3; y++) {
			for (int x = 0; x < 3; x++) {
				data[y][x] = 0;
			}
		}
		
		mainMenu();

		if (_menuSelection == 1) {
			// Player vs Player

			while (_looping) {
				pvpMenu();

				if (_menuSelection == 1) {
					while (_looping) {
						updatePVP();
					}
				}
				else if (_menuSelection == -1) {
					// Return
					_looping = false;
				}
				else {
					// Incorrect input: Just loop this menu
				}
			}
			_looping = true;
		}
		else if (_menuSelection == 2) {
			// Player vs Computer

			while (_looping) {
				pvcMenu();

				if (_menuSelection == 1) {
					// Easy
					choosePlayerMenu();
					while (_looping) {
						updatePVCEasy();
					}
					if (!_gameOver) _looping = true;
				}
				else if (_menuSelection == 2) {
					// Medium
					choosePlayerMenu();
					while (_looping) {
						int decider = randomGenerator(0, 1);

						if (decider = 0) updatePVCEasy();
						if (decider = 1) updatePVCHard();
					}
					if (!_gameOver) _looping = true;
				}
				else if (_menuSelection == 3) {
					// Hard
					choosePlayerMenu();
					while (_looping) {
						updatePVCHard();
					}
					if (!_gameOver) _looping = true;
				}
				else if (_menuSelection == -1) {
					// Return
					_looping = false;
				}
				else {
					// Incorrect input: Just loop this menu
				}
			}
			_looping = true;
		}
		else if (_menuSelection == -1) {
			// Exit game
			exit();

			_looping = false;
		}
		else {
			// Incorrect input: Just loop this menu
		}
	}
}

void Game::title() {
	cout << "|============================================================================|" << endl;
	cout << "|= ||||||  ||||||    |||   ||||||    ||      |||   ||||||    |||    ||||||| =|" << endl;
	cout << "|=   ||      ||    ||   ||   ||     ||||   ||   ||   ||    ||   ||  ||      =|" << endl;
	cout << "|=   ||      ||    ||        ||    ||  ||  ||        ||    ||   ||  ||||||| =|" << endl;
	cout << "|=   ||      ||    ||   ||   ||    ||||||  ||   ||   ||    ||   ||  ||      =|" << endl;
	cout << "|=   ||    ||||||    |||     ||    ||  ||    |||     ||      |||    ||||||| =|" << endl;
	cout << "|============================================================================|" << endl;
	cout << "|=                   MakingGamesWithBen: Game Challenge 2                   =|" << endl;
	cout << "|=                       https://youtu.be/gm2yPC65X78                       =|" << endl;
	cout << "|=                                By: Mathew                                =|" << endl;
	cout << "|============================================================================|" << endl;
}

void Game::mainMenu()
{
	title();

	cout << "|=                                                                          =|" << endl;
	cout << "|=                                MAIN MENU                                 =|" << endl;
	cout << "|=                                                                          =|" << endl;
	cout << "|= Welcome to the second game challenge from MakingGamesWithBen. In this    =|" << endl;
	cout << "|= challenge we are to use everything we have learned from the tutorials to =|" << endl;
	cout << "|= make a TicTacToe game. This is my attempt.                               =|" << endl;
	cout << "|=                                                                          =|" << endl;
	cout << "|= [1] Player vs Player                                                     =|" << endl;
	cout << "|= [2] Player vs Computer                                                   =|" << endl;
	cout << "|=                                                                          =|" << endl;
	cout << "|= [-1] Exit Game                                                           =|" << endl;
	cout << "|=                                                                          =|" << endl;
	cout << "|=                                                                          =|" << endl;
	cout << "|= Please enter a number: ";

	cin >> _menuSelection;
}

void Game::pvpMenu()
{
	title();
	
	cout << "|=                                                                          =|" << endl;
	cout << "|=                             Player VS Player                             =|" << endl;
	cout << "|=                                                                          =|" << endl;
	cout << "|= Welcome to Player VS Player. In this mode you can play by yourself or    =|" << endl;
	cout << "|= with someone else.                                                       =|" << endl;
	cout << "|=                                                                          =|" << endl;
	cout << "|=                                                                          =|" << endl;
	cout << "|= [1] Play                                                                 =|" << endl;
	cout << "|=                                                                          =|" << endl;
	cout << "|= [-1] Return                                                              =|" << endl;
	cout << "|=                                                                          =|" << endl;
	cout << "|=                                                                          =|" << endl;
	cout << "|=                                                                          =|" << endl;
	cout << "|= Please enter a number: ";

	cin >> _menuSelection;
}

void Game::pvcMenu()
{
	title();
	
	cout << "|=                                                                          =|" << endl;
	cout << "|=                             Player VS Computer                           =|" << endl;
	cout << "|=                                                                          =|" << endl;
	cout << "|= Welcome to Player VS Computer. In this mode you can play against a       =|" << endl;
	cout << "|= computer. Easy: Chooses each move randomly. Medium: Randomnly chooses    =|" << endl;
	cout << "|= between Easy and Hard. Hard: Will attempt to block your moves.           =|" << endl;
	cout << "|=                                                                          =|" << endl;
	cout << "|= [1] Easy    || Chooses each move randomnly.                              =|" << endl;
	cout << "|= [2] Medium  || Randomnly chooses between Easy and Hard with each move.   =|" << endl;
	cout << "|= [3] Hard    || Will attempt to block your moves or get three in a row.   =|" << endl;
	cout << "|=                                                                          =|" << endl;
	cout << "|= [-1] Return                                                              =|" << endl;
	cout << "|=                                                                          =|" << endl;
	cout << "|= Please enter a number: ";

	cin >> _menuSelection;
}

void Game::choosePlayerMenu()
{
	title();
	
	cout << "|=                                                                          =|" << endl;
	cout << "|=                             Player VS Computer                           =|" << endl;
	cout << "|=                                                                          =|" << endl;
	cout << "|= Choose who will be playing first.                                        =|" << endl;
	cout << "|=                                                                          =|" << endl;
	cout << "|=                                                                          =|" << endl;
	cout << "|=                                                                          =|" << endl;
	cout << "|= [1] Human                                                                =|" << endl;
	cout << "|= [2] Computer                                                             =|" << endl;
	cout << "|=                                                                          =|" << endl;
	cout << "|= [-1] Return                                                              =|" << endl;
	cout << "|=                                                                          =|" << endl;
	cout << "|=                                                                          =|" << endl;
	cout << "|= Please enter a number: ";

	cin >> _menuSelection;

	if (_menuSelection == 1) {
		_player1 = 'X';
		_player2 = 'O';
	}

	if (_menuSelection == 2) {
		_player1 = 'O';
		_player2 = 'X';
	}

	if (_menuSelection == -1) _looping = false;
}

void Game::endMenu(int &id)
{
	_gameOver = true;

	if (id = 3) _playerT = 'D';
	
	cout << "|=                                                                          =|" << endl;
	cout << "|============================================================================|" << endl;
	cout << "|=                                  Results                                 =|" << endl;
	cout << "|============================================================================|" << endl;
	cout << "|=                                                                          =|" << endl;

	renderBoard();

	cout << "|= [1] Return to Main Menu";
	cin >> _menuSelection;
	
	_looping = false;
}

void Game::exit()
{
	title();
	cout << "|=                                                                          =|" << endl;
	cout << "|= Thanks for playing.                                                      =|" << endl;
	cout << "|=                                                                          =|" << endl;
	cout << "|=                                                                          =|" << endl;
	cout << "|=                                                                          =|" << endl;
	cout << "|=                                                                          =|" << endl;
	cout << "|=                                                                          =|" << endl;
	cout << "|=                                                                          =|" << endl;
	cout << "|=                                                                          =|" << endl;
	cout << "|=                                                                          =|" << endl;
	cout << "|=                                                                          =|" << endl;
	cout << "|=                                                                          =|" << endl;
	cout << "|=                                                                          =|" << endl;
	cout << "|= ";
}

void Game::updatePVP()
{
	cout << "|=                                                                          =|" << endl;
	cout << "|============================================================================|" << endl;
	cout << "|=                              Player VS Player                            =|" << endl;
	cout << "|============================================================================|" << endl;
	cout << "|=                                                                          =|" << endl;

	renderBoard();

	if (_error) {
		cout << "|= ERROR: Incorrect user input or block already taken.                      =|" << endl;
		_error = false;
	}
	else {
		cout << "|=                                                                          =|" << endl;
	}
		
	cout << "|= Please select a row    : ";
	cin >> rowSelection;
	cout << "|= Please select a column : ";
	cin >> colSelection;

	processInput();
}

void Game::updatePVCEasy()
{
	cout << "|=                                                                          =|" << endl;
	cout << "|============================================================================|" << endl;
	cout << "|=                             Player VS Computer                           =|" << endl;
	cout << "|============================================================================|" << endl;
	cout << "|=                                                                          =|" << endl;

	renderBoard();

	if (_error) {
		cout << "|= ERROR: Incorrect user input or block already taken.                      =|" << endl;
		_error = false;
	}
	else {
		cout << "|=                                                                          =|" << endl;
	}

	if (_playerT == _player1) {
		cout << "|= Please select a row    : ";
		cin >> rowSelection;
		cout << "|= Please select a column : ";
		cin >> colSelection;
	}

	if (_playerT == _player2) {
		int yCor = randomGenerator(0, 2);
		int xCor = randomGenerator(1, 3);

		if (yCor == 0) rowSelection = 'a';
		if (yCor == 1) rowSelection = 'b';
		if (yCor == 2) rowSelection - 'c';

		colSelection = xCor;

		cout << "|= Please select a row    : " << rowSelection << "                                               =|" << endl;
		cout << "|= Please select a column : " << colSelection << "                                               =|" << endl;
	}

	processInput();
}

void Game::updatePVCHard()
{
	cout << "|=                                                                          =|" << endl;
	cout << "|============================================================================|" << endl;
	cout << "|=                             Player VS Computer                           =|" << endl;
	cout << "|============================================================================|" << endl;
	cout << "|=                                                                          =|" << endl;

	renderBoard();

	if (_error) {
		cout << "|= ERROR: Incorrect user input or block already taken.                      =|" << endl;
		_error = false;
	}
	else {
		cout << "|=                                                                          =|" << endl;
	}

	if (_playerT == _player1) {
		cout << "|= Please select a row    : ";
		cin >> rowSelection;
		cout << "|= Please select a column : ";
		cin >> colSelection;
	}

	if (_playerT == _player2) {
		int yCor = randomGenerator(0, 2);
		int xCor = randomGenerator(1, 3);

		if (yCor == 0) rowSelection = 'a';
		if (yCor == 1) rowSelection = 'b';
		if (yCor == 2) rowSelection - 'c';

		colSelection = xCor;

		// Override to block
		// Row 1
		if (data[0][1] == 1 && data[0][2] == 1 && data[0][0] != 2) {
			rowSelection = 'a';
			colSelection = 1;
		}
		if (data[0][0] == 1 && data[0][2] == 1 && data[0][1] != 2) {
			rowSelection = 'a';
			colSelection = 2;
		}
		if (data[0][0] == 1 && data[0][1] == 1 && data[0][2] != 2) {
			rowSelection = 'a';
			colSelection = 3;
		}
		// Row 2
		if (data[1][1] == 1 && data[1][2] == 1 && data[1][0] != 2) {
			rowSelection = 'b';
			colSelection = 1;
		}
		if (data[1][0] == 1 && data[1][2] == 1 && data[1][1] != 2) {
			rowSelection = 'b';
			colSelection = 2;
		}
		if (data[1][0] == 1 && data[1][1] == 1 && data[1][2] != 2) {
			rowSelection = 'b';
			colSelection = 3;
		}
		// Row 3
		if (data[2][1] == 1 && data[2][2] == 1 && data[2][0] != 2) {
			rowSelection = 'c';
			colSelection = 1;
		}
		if (data[2][0] == 1 && data[2][2] == 1 && data[2][1] != 2) {
			rowSelection = 'c';
			colSelection = 2;
		}
		if (data[2][0] == 1 && data[2][1] == 1 && data[2][2] != 2) {
			rowSelection = 'c';
			colSelection = 3;
		}
		// Column 1
		if (data[1][0] == 1 && data[2][0] == 1 && data[0][0] != 2) {
			rowSelection = 'a';
			colSelection = 1;
		}
		if (data[0][0] == 1 && data[2][0] == 1 && data[1][0] != 2) {
			rowSelection = 'b';
			colSelection = 1;
		}
		if (data[0][0] == 1 && data[1][0] == 1 && data[2][0] != 2) {
			rowSelection = 'c';
			colSelection = 1;
		}
		// Column 2
		if (data[1][1] == 1 && data[2][1] == 1 && data[0][1] != 2) {
			rowSelection = 'a';
			colSelection = 2;
		}
		if (data[0][1] == 1 && data[2][1] == 1 && data[1][1] != 2) {
			rowSelection = 'b';
			colSelection = 2;
		}
		if (data[0][1] == 1 && data[1][1] == 1 && data[2][1] != 2) {
			rowSelection = 'c';
			colSelection = 2;
		}
		// Column 3
		if (data[1][2] == 1 && data[2][2] == 1 && data[0][2] != 2) {
			rowSelection = 'a';
			colSelection = 3;
		}
		if (data[0][2] == 1 && data[2][2] == 1 && data[1][2] != 2) {
			rowSelection = 'b';
			colSelection = 3;
		}
		if (data[0][2] == 1 && data[1][2] == 1 && data[2][2] != 2) {
			rowSelection = 'c';
			colSelection = 3;
		}
		// Diagonal 1
		if (data[2][2] == 1 && data[1][1] == 1 && data[0][0] != 2) {
			rowSelection = 'a';
			colSelection = 1;
		}
		if (data[0][0] == 1 && data[2][2] == 1 && data[1][1] != 2) {
			rowSelection = 'b';
			colSelection = 2;
		}
		if (data[0][0] == 1 && data[1][1] == 1 && data[2][2] != 2) {
			rowSelection = 'c';
			colSelection = 3;
		}
		// Diagonal 2
		if (data[2][0] == 1 && data[1][1] == 1 && data[0][2] != 2) {
			rowSelection = 'a';
			colSelection = 3;
		}
		if (data[2][0] == 1 && data[0][2] == 1 && data[1][1] != 2) {
			rowSelection = 'b';
			colSelection = 2;
		}
		if (data[0][2] == 1 && data[1][1] == 1 && data[2][0] != 2) {
			rowSelection = 'c';
			colSelection = 1;
		}

		// Override to win
		// Row 1
		if (data[0][1] == 2 && data[0][2] == 2 && data[0][0] != 1) {
			rowSelection = 'a';
			colSelection = 1;
		}
		if (data[0][0] == 2 && data[0][2] == 2 && data[0][1] != 1) {
			rowSelection = 'a';
			colSelection = 2;
		}
		if (data[0][0] == 2 && data[0][1] == 2 && data[0][2] != 1) {
			rowSelection = 'a';
			colSelection = 3;
		}
		// Row 2
		if (data[1][1] == 2 && data[1][2] == 2 && data[1][0] != 1) {
			rowSelection = 'b';
			colSelection = 1;
		}
		if (data[1][0] == 2 && data[1][2] == 2 && data[1][1] != 1) {
			rowSelection = 'b';
			colSelection = 2;
		}
		if (data[1][0] == 2 && data[1][1] == 2 && data[1][2] != 1) {
			rowSelection = 'b';
			colSelection = 3;
		}
		// Row 3
		if (data[2][1] == 2 && data[2][2] == 2 && data[2][0] != 1) {
			rowSelection = 'c';
			colSelection = 1;
		}
		if (data[2][0] == 2 && data[2][2] == 2 && data[2][1] != 1) {
			rowSelection = 'c';
			colSelection = 2;
		}
		if (data[2][0] == 2 && data[2][1] == 2 && data[2][2] != 1) {
			rowSelection = 'c';
			colSelection = 3;
		}
		// Column 1
		if (data[1][0] == 2 && data[2][0] == 2 && data[0][0] != 1) {
			rowSelection = 'a';
			colSelection = 1;
		}
		if (data[0][0] == 2 && data[2][0] == 2 && data[1][0] != 1) {
			rowSelection = 'b';
			colSelection = 1;
		}
		if (data[0][0] == 2 && data[1][0] == 2 && data[2][0] != 1) {
			rowSelection = 'c';
			colSelection = 1;
		}
		// Column 2
		if (data[1][1] == 2 && data[2][1] == 2 && data[0][1] != 1) {
			rowSelection = 'a';
			colSelection = 2;
		}
		if (data[0][1] == 2 && data[2][1] == 2 && data[1][1] != 1) {
			rowSelection = 'b';
			colSelection = 2;
		}
		if (data[0][1] == 2 && data[1][1] == 2 && data[2][1] != 1) {
			rowSelection = 'c';
			colSelection = 2;
		}
		// Column 3
		if (data[1][2] == 2 && data[2][2] == 2 && data[0][2] != 1) {
			rowSelection = 'a';
			colSelection = 3;
		}
		if (data[0][2] == 2 && data[2][2] == 2 && data[1][2] != 1) {
			rowSelection = 'b';
			colSelection = 3;
		}
		if (data[0][2] == 2 && data[1][2] == 2 && data[2][2] != 1) {
			rowSelection = 'c';
			colSelection = 3;
		}
		// Diagonal 1
		if (data[2][2] == 2 && data[1][1] == 2 && data[0][0] != 1) {
			rowSelection = 'a';
			colSelection = 1;
		}
		if (data[0][0] == 2 && data[2][2] == 2 && data[1][1] != 1) {
			rowSelection = 'b';
			colSelection = 2;
		}
		if (data[0][0] == 2 && data[1][1] == 2 && data[2][2] != 1) {
			rowSelection = 'c';
			colSelection = 3;
		}
		// Diagonal 2
		if (data[2][0] == 2 && data[1][1] == 2 && data[0][2] != 1) {
			rowSelection = 'a';
			colSelection = 3;
		}
		if (data[2][0] == 2 && data[0][2] == 2 && data[1][1] != 1) {
			rowSelection = 'b';
			colSelection = 2;
		}
		if (data[0][2] == 2 && data[1][1] == 2 && data[2][0] != 1) {
			rowSelection = 'c';
			colSelection = 1;
		}
	}

	processInput();
}

void Game::processInput()
{
	if (rowSelection != 'a' && rowSelection != 'A' && rowSelection != 'b' && rowSelection != 'B' && rowSelection != 'c' && rowSelection != 'C') {
		_error = true;
	}
	else if (colSelection < 1 || colSelection > 3) {
		_error = true;
	}

	if (!_error) {
		int user = 0;
		int yCor = 0;
		int xCor = 0;

		if (_playerT == 'X') user = 1;
		if (_playerT == 'O') user = 2;

		// Row
		if (rowSelection == 'a' || rowSelection == 'A') yCor = 0;
		if (rowSelection == 'b' || rowSelection == 'B') yCor = 1;
		if (rowSelection == 'c' || rowSelection == 'C') yCor = 2;

		// Column
		if (colSelection == 1) xCor = 0;
		if (colSelection == 2) xCor = 1;
		if (colSelection == 3) xCor = 2;

		if (data[yCor][xCor] > 0) _error = true;

		if (!_error) data[yCor][xCor] = user;

		// Check board data
		int id = checkData();

		if (id == 1 || id == 2 || id == 3) endMenu(id);

		// Switch players
		if (!_error && _playerT == 'X' && _looping) {
			_playerT = 'O';
		}
		else if (!_error && _playerT == 'O' && _looping) {
			_playerT = 'X';
		}
	}
}

int Game::checkData()
{
	// Process Player X
	// Rows
	if (data[0][0] == 1 && data[0][1] == 1 && data[0][2] == 1) {
		data[0][0] = 3;
		data[0][1] = 3;
		data[0][2] = 3;
		return 1;
	}
	if (data[1][0] == 1 && data[1][1] == 1 && data[1][2] == 1) {
		data[1][0] = 3;
		data[1][1] = 3;
		data[1][2] = 3;
		return 1;
	}
	if (data[2][0] == 1 && data[2][1] == 1 && data[2][2] == 1) {
		data[2][0] = 3;
		data[2][1] = 3;
		data[2][2] = 3;
		return 1;
	}
	// Columns
	if (data[0][0] == 1 && data[1][0] == 1 && data[2][0] == 1) {
		data[0][0] = 3;
		data[1][0] = 3;
		data[2][0] = 3;
		return 1;
	}
	if (data[0][1] == 1 && data[1][1] == 1 && data[2][1] == 1) {
		data[0][1] = 3;
		data[1][1] = 3;
		data[2][1] = 3;
		return 1;
	}
	if (data[0][2] == 1 && data[1][2] == 1 && data[2][2] == 1) {
		data[0][2] = 3;
		data[1][2] = 3;
		data[2][2] = 3;
		return 1;
	}
	// Diagonals
	if (data[0][0] == 1 && data[1][1] == 1 && data[2][2] == 1) {
		data[0][0] = 3;
		data[1][1] = 3;
		data[2][2] = 3;
		return 1;
	}
	if (data[0][2] == 1 && data[1][1] == 1 && data[2][0] == 1) {
		data[0][2] = 3;
		data[1][1] = 3;
		data[2][0] = 3;
		return 1;
	}

	// Process Player O
	// Rows
	if (data[0][0] == 2 && data[0][1] == 2 && data[0][2] == 2) {
		data[0][0] = 4;
		data[0][1] = 4;
		data[0][2] = 4;
		return 2;
	}
	if (data[1][0] == 2 && data[1][1] == 2 && data[1][2] == 2) {
		data[1][0] = 4;
		data[1][1] = 4;
		data[1][2] = 4;
		return 2;
	}
	if (data[2][0] == 2 && data[2][1] == 2 && data[2][2] == 2) {
		data[2][0] = 4;
		data[2][1] = 4;
		data[2][2] = 4;
		return 2;
	}
	// Columns
	if (data[0][0] == 2 && data[1][0] == 2 && data[2][0] == 2) {
		data[0][0] = 4;
		data[1][0] = 4;
		data[2][0] = 4;
		return 2;
	}
	if (data[0][1] == 2 && data[1][1] == 2 && data[2][1] == 2) {
		data[0][1] = 4;
		data[1][1] = 4;
		data[2][1] = 4;
		return 2;
	}
	if (data[0][2] == 2 && data[1][2] == 2 && data[2][2] == 2) {
		data[0][2] = 4;
		data[1][2] = 4;
		data[2][2] = 4;
		return 2;
	}
	// Diagonals
	if (data[0][0] == 2 && data[1][1] == 2 && data[2][2] == 2) {
		data[0][0] = 4;
		data[1][1] = 4;
		data[2][2] = 4;
		return 2;
	}
	if (data[0][2] == 2 && data[1][1] == 2 && data[2][0] == 2) {
		data[0][2] = 4;
		data[1][1] = 4;
		data[2][0] = 4;
		return 2;
	}

	// Run through board to see if if any spaces left
	int acc = 0;
	int com = 9;
	
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			if (data[y][x] > 0) acc++;
		}
	}

	if (acc == com) return 3;

	return 0;
}

int Game::randomGenerator(int min, int max)
{
	// Random generator
	static default_random_engine randomGenerator(time(NULL));

	uniform_int_distribution<int> integer(min, max);

	int result = integer(randomGenerator);

	return result;
}

string Game::block(int y, int x, int z)
{
	if (data[y][x] == 0) {
		return blocks[0][z];
	}
	else if (data[y][x] == 1) {
		return blocks[1][z];
	}
	else if (data[y][x] == 2) {
		return blocks[2][z];
	}
	else if (data[y][x] == 3) {
		return blocks[3][z];
	}
	else if (data[y][x] == 4) {
		return blocks[4][z];
	}
}

void Game::renderBoard()
{
	cout << rowSelection << ":" << colSelection << endl;
	// Awesome triple for loop
	for (int row = 0; row < _numRows; row++) {
		if (row == 0) {
			cout << "|=                          1          2          3                         =|" << endl;
		}
		for (int sub = 0; sub < _numSubs; sub++) {
			if (sub == 2 && row == 0) {
				cout << "|=                     A";
			}
			else if (sub == 3 && row == 0) {
				cout << "|=    |===========|     ";
			}
			else if (sub == 4 && row == 0) {
				cout << "|=    |= Player  =|     ";
			}
			else if (sub == 0 && row == 1) {
				if (_playerT == 'X') {
					cout << "|=    |=" << blocks[1][0] << "=|     ";
				}
				if (_playerT == 'O') {
					cout << "|=    |=" << blocks[2][0] << "=|     ";
				}
				if (_playerT == 'D') {
					cout << "|=    |=" << blocks[5][0] << "=|     ";
				}
			}
			else if (sub == 1 && row == 1) {
				if (_playerT == 'X') {
					cout << "|=    |=" << blocks[1][1] << "=|     ";
				}
				if (_playerT == 'O') {
					cout << "|=    |=" << blocks[2][1] << "=|     ";
				}
				if (_playerT == 'D') {
					cout << "|=    |=" << blocks[5][1] << "=|     ";
				}
			}
			else if (sub == 2 && row == 1) {
				if (_playerT == 'X') {
					cout << "|=    |=" << blocks[1][2] << "=|    B";
				}
				if (_playerT == 'O') {
					cout << "|=    |=" << blocks[2][2] << "=|    B";
				}
				if (_playerT == 'D') {
					cout << "|=    |=" << blocks[5][2] << "=|     ";
				}
			}
			else if (sub == 3 && row == 1) {
				if (_playerT == 'X') {
					cout << "|=    |=" << blocks[1][3] << "=|     ";
				}
				if (_playerT == 'O') {
					cout << "|=    |=" << blocks[2][3] << "=|     ";
				}
				if (_playerT == 'D') {
					cout << "|=    |=" << blocks[5][3] << "=|     ";
				}
			}
			else if (sub == 4 && row == 1) {
				if (_playerT == 'X') {
					cout << "|=    |=" << blocks[1][4] << "=|     ";
				}
				if (_playerT == 'O') {
					cout << "|=    |=" << blocks[2][4] << "=|     ";
				}
				if (_playerT == 'D') {
					cout << "|=    |=" << blocks[5][4] << "=|     ";
				}
			}
			else if (sub == 0 && row == 2) {
				if (_gameOver && _playerT != 'D') {
					cout << "|=    |=  Wins   =|     ";
				}
				else if (_gameOver && _playerT == 'D') {
					cout << "|=    |=  Draw   =|     ";
				}
				else {
					cout << "|=    |=  Turn   =|     ";
				}
			}
			else if (sub == 1 && row == 2) {
				cout << "|=    |===========|     ";
			}
			else if (sub == 2 && row == 2) {
				cout << "|=                     C";
			}
			else {
				cout << "|=                      ";
			}
			for (int col = 0; col < _numCols; col++) {
				
				cout << block(row, col, sub);

				if (col == 0 || col == 1) {
					cout << "||";
				}
			}
			cout << "                     =|";
			cout << endl;
		}
		if (row == 0 || row == 1) {
			cout << "|=    |===========|     ==============================                      =|";
			cout << endl;
		}
	}
	cout << "|=                                                                          =|" << endl;
}
