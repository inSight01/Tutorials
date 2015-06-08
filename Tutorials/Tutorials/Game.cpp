#include "Game.h"

Game::Game()
{
}

void Game::begin()
{
	while (playing) {

		
		update();
		render();

		playing = false;
	}
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
}

void Game::update()
{

}

void Game::render()
{
	// Awesome triple for loop
	for (int row = 0; row < numRows; row++) {
		for (int sub = 0; sub < numSubs; sub++) {
			for (int col = 0; col < numCols; col++) {
				cout << block(row, col, sub);

				if (col == 0 || col == 1) {
					cout << "||";
				}
			}
			cout << endl;
		}
		if (row == 0 || row == 1) {
			cout << "==============================";
			cout << endl;
		}
	}

	cout << endl;
}
