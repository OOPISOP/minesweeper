#include <iostream>
#include <vector>
#include <cstring>
#include "Click.h"

using namespace std;

int main() 
{

	while (true)
	{
		cout << "Please ipnut the mine rows,cols, and minues number" << endl;

		// Set Mine rows cols and minenum
		int rows, cols, mines;

		// Make sure rows cols and mines number can't be negative
		cin >> rows >> cols >> mines;
		if (rows <= 0 || cols <= 0)
		{
			cout << "Map can't be negative" << endl;
		}
		if (mines <= 0) 
		{
			cout << "Mines number can't be negative" << endl;
		}

		// Declare the map with two array ons is store char another store number
		vector<vector<char>> map(rows, vector<char>(cols, '#'));

		vector<vector<int>> board(rows, vector<int>(cols, 0));

		// Random set mines poistion
		for (int mine = 0; mine < mines; mine++)
		{
			int rowP = rand() % rows;
			int colP = rand() % cols;

			if (board[rowP][colP] == 9)
			{
				mine--;
			}
			else
			{
				board[rowP][colP] = 9;
			}
		}

		// The input surround poistion
		int dir[8][2] = { -1, -1, 0, -1, 1, -1, 1, 0, 1, 1, 0, 1, -1, 1, -1, 0 };

		// Count each array surround mines number
		for (int r = 0; r < rows; r++)
		{
			for (int c = 0; c < cols; c++)
			{
				if (board[r][c] != 9)
				{
					int boom = 0;
					for (int i = 0; i < 8; i++)
					{
						int nextx = c + dir[i][0];
						int nexty = r + dir[i][1];
						if (nextx < 0 || nexty < 0 || nexty >= rows || nextx >= cols)
							continue;
						if (board[nexty][nextx] == 9)
						{
							boom++;
						}
					}
					board[r][c] = boom;
				}
			}
		}

		string input, gameState = "Standby";

		while (gameState != "Quit")
		{
			cout << "Input the command to control" << endl;
			cin >> input;

			if (input == "StartGame")
			{
				gameState = "Playing";
				cout << "<StartGame> : Success" << endl;
			}
			else if (input == "Print")
			{
				cin >> input;
				if (input == "GameBoard")
				{
					for (int r = 0; r < rows; r++)
					{
						for (int c = 0; c < cols; c++)
						{
							cout << map[r][c];
						}
						cout << endl;
					}
				}
				if (input == "GameState")
				{

				}
				if (input == "GameAnswer")
				{
					for (int r = 0; r < rows; r++)
					{
						for (int c = 0; c < cols; c++)
						{
							cout << board[r][c];
						}
						cout << endl;
					}
				}
				if (input == "BombCount")
				{

				}
				if (input == "FlagCount")
				{

				}
				if (input == "OpenBlackCount")
				{

				}
				if (input == "RemainBlankCount")
				{

				}
			}
			else if(input == "LeftClick")
			{
				int inX, inY;
				cin >> inX >> inY;
				cout << "<LeftClick " << inX << " " << inY << ">" << " : Success" << endl;

				if (board[inY][inX] == 9)
				{
					cout << "Lose" << endl;
				}
				else if (board[inY][inX] == 0)
				{
					queue<pair<int, int>> que;
					que.push(pair<int, int>(inY, inX));
					while (!que.empty()) {
						int y = que.front().first;
						int x = que.front().second;
						que.pop();
						for (int i = 0; i < 8; i++) {
							int nexty = y + dir[i][0];
							int nextx = x + dir[i][1];
							if (nextx < 0 || nexty < 0 || nexty >= rows || nextx >= cols)
								continue;
							if (map[nexty][nextx] == '0')
								continue;
							int tot = board[nexty][nextx];
							if (tot != 0)
							{
								map[nexty][nextx] = tot + '0';
							}
							else
							{
								map[nexty][nextx] = '0';
								que.push(pair<int, int>(nexty, nextx));
							}
						}
					}
				}
				else
				{
					map[inY][inX] = board[inY][inX] + '0';
				}
			}
		}
	}
}