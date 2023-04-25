#pragma once

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

void runCommandInput();

int runMap(vector<vector<char>>& map, char check, bool inOrOut, bool getDataOrRun);

void surroundBomb(vector<vector<char>>& map);

void printCommand(vector<vector<char>>& map, vector<vector<char>>& answer, string state, int* blankArray);

void spread(vector<vector<char>>& map, vector<vector<char>> answer, int inY, int inX);

void runCommandInput()
{
	while (true)
	{
		cout << "Please ipnut rows¡Bcols and mine, and minues number" << endl;

		// Set Mine rows cols and minenum
		int row, col;
		float mine;

		// Make sure rows cols and mines number can't be negative

		cout << "row : ";
		cin >> row;
		cout << "column : ";
		cin >> col;
		cout << "mine(If input value smaller than 1 will be seen as mine rate) : ";
		cin >> mine;

		// Make sure Map can exist
		if (row <= 0 || col <= 0)
		{
			cout << "Map can't be negative or zero" << endl;
		}
		// Mine number can't be negativor or zero
		else if (mine <= 0)
		{
			cout << "Mines number can't be negative or zero" << endl;
		}
		else if (mine >= row * col)
		{
			cout << "Over range allow" << endl;
		}
		else
		{
			cout << "Set map successfully" << endl;

			// Declare the map display array
			vector<vector<char>> mapBoard(row, vector<char>(col, '#'));

			// Declare the map answer array
			vector<vector<char>> mapAnswer(row, vector<char>(col, '0'));

			// Set the mine rate
			mine = (mine < 1) ? mine * row * col : mine;

			// Random set mines poistion
			for (int mP = 0; mP < mine; mP += 1)
			{
				int rowP = rand() % row;
				int colP = rand() % col;

				// Avoid bomb appear in same pistion
				(mapAnswer[rowP][colP] == 'X') ? mP -= 1 : mapAnswer[rowP][colP] = 'X';;
			}

			// Check bomb surround and store back to answer
			// Count each array surround mines number
			surroundBomb(mapAnswer);

			//Set gameState Standby
			string command, gameState = "Standby";

			// blankArray[0] is open blank
			// blankArray[1] is flag blank
			int blankArray[4] = { 0 };

			// blankArray[2] is bomb blank
			blankArray[2] = mine;

			// blankArray[3] is total blank
			blankArray[3] = row * col;


			//If GameState == Quit
			while (true)
			{
				if (runMap(mapBoard, '#', true, true) == 0)
				{
					cout << "Game Success" << endl;
					cout << "Command Reply to play it again, Quit to quit the game" << endl;

					cin >> command;

					if (command == "Quit")
					{
						break;
					}
					if (command == "Reply")
					{
						runMap(mapBoard, '#', true, false);
					}
				}


				cin >> command;

				//If mode Standby
				if (gameState == "Standby" && command == "StartGame")
				{
					gameState = "Playing";
					cout << "<StartGame> : Success" << endl;
				}
				//If mode StartGame
				else if (command == "StartGame")
				{
					cout << "<StartGame> : Already" << endl;
				}
				//If mode Print
				else if (command == "Print")
				{
					printCommand(mapBoard, mapAnswer, gameState, blankArray);
				}
				else if (command == "RightClick")
				{
					int inX, inY;
					cin >> inY >> inX;

					if (gameState != "Playing" || (mapBoard[inY][inX] >= '0' && mapBoard[inY][inX] <= '8'))
					{
						cout << "<RightClick " << inY << " " << inX << ">" << " : Failed" << endl;
					}
					else
					{
						cout << "<RightClick " << inY << " " << inX << ">" << " : Success" << endl;

						if (mapBoard[inY][inX] == '#')
						{
							mapBoard[inY][inX] = 'f';
							blankArray[1] += 1;
						}
						else
						{
							mapBoard[inY][inX] = (mapBoard[inY][inX] == 'f') ? '?' : '#';
							blankArray[1] -= 1;
						}
					}
				}
				else if (command == "LeftClick")
				{
					int inX, inY;
					cin >> inY >> inX;

					if (gameState != "Playing" || mapBoard[inY][inX] != '#' || mapBoard[inY][inX] == 'f')
					{
						cout << "<LeftClick " << inY << " " << inX << ">" << " : Failed" << endl;
					}
					else
					{
						cout << "<LeftClick " << inY << " " << inX << ">" << " : Success" << endl;
						spread(mapBoard, mapAnswer, inY, inX);
					}
					blankArray[0] = blankArray[3] - runMap(mapBoard, '#', true, true);
				}
			}

		}

	}
}


int runMap(vector<vector<char>>& map, char check, bool inOrOut, bool getDataOrRun)
{
	int count = 0;
	for (int r = 0; r < map.size(); r++)
	{
		for (int c = 0; c < map[0].size(); c++)
		{
			if (getDataOrRun)
			{
				count = (map[r][c] == check) ? count + 1 : count;
			}
			else
			{
				if (inOrOut)
				{
					map[r][c] = check;
				}
				else
				{
					cout << map[r][c] << " ";
				}
			}
		}
		if (!inOrOut)
		{
			cout << endl;
		}
	}

	return count;
}

void surroundBomb(vector<vector<char>>& map)
{
	// The input surround poistion
	int dir[8][2] = { -1, -1, 0, -1, 1, -1, 1, 0, 1, 1, 0, 1, -1, 1, -1, 0 };

	for (int r = 0; r < map.size(); r++)
	{
		for (int c = 0; c < map[0].size(); c++)
		{
			if (map[r][c] != 'X')
			{
				int boom = 0;
				for (int i = 0; i < 8; i++)
				{
					int nextx = c + dir[i][0];
					int nexty = r + dir[i][1];
					if (nextx < 0 || nexty < 0 || nexty >= map.size() || nextx >= map[0].size())
						continue;
					if (map[nexty][nextx] == 'X')
						boom += 1;
				}

				map[r][c] = ('0' + boom);
			}
		}
	}
}

void printCommand(vector<vector<char>>& map, vector<vector<char>>& answer, string state, int* blankArray)
{
	// blankArray[0] is open blank
	// blankArray[1] is flag blank
	// blankArray[2] is bomb blank
	// blankArray[3] is total blank

	string command;

	cin >> command;

	if (command == "GameBoard")
	{
		cout << "<Print GameBoard> :" << endl;
		runMap(map, '#', false, false);
	}
	if (command == "GameState")
	{
		cout << "<GameState> : " << state << endl;
	}
	if (command == "GameAnswer")
	{
		cout << "<Print GameAnswer> :" << endl;
		runMap(answer, '#', false, false);
	}
	if (command == "BombCount")
	{
		cout << "<BombCount> : " << blankArray[2] << endl;
	}
	if (command == "FlagCount")
	{
		cout << "<FlagCount> : " << blankArray[1] << endl;
	}
	if (command == "OpenBlankCount")
	{
		cout << "<OpenBlankCount> : " << blankArray[0] << endl;
	}
	if (command == "RemainBlankCount")
	{
		cout << "<RemainBlankCount> : " << blankArray[3] - blankArray[0] - blankArray[1] - blankArray[2] << endl;
	}
}

// Intent:to spread the blank if the answerboard[inY][inX] ='0'
// Pre: the input must be two int
// Post:the function return nothing
void spread(vector<vector<char>>& map, vector<vector<char>> answer, int inY, int inX)
{
	// check if the input coordinates are within the board boundaries
	if (inY >= map.size() || inY < 0 || inX >= map[0].size() || inX < 0)
	{
		return;
	}

	// if the current cell is hidden, reveal it and recursively call the function on adjacent cells
	if (answer[inY][inX] == '0' && map[inY][inX] == '#')
	{
		map[inY][inX] = '0';
		spread(map, answer, inY - 1, inX + 1);
		spread(map, answer, inY + 1, inX - 1);
		spread(map, answer, inY, inX + 1);
		spread(map, answer, inY, inX - 1);
		spread(map, answer, inY + 1, inX);
		spread(map, answer, inY - 1, inX);
		spread(map, answer, inY + 1, inX + 1);
		spread(map, answer, inY - 1, inX - 1);
	}
	// if the current cell is not hidden, reveal it
	else if (map[inY][inX] != 'f' && map[inY][inX] != '?')
	{
		map[inY][inX] = answer[inY][inX];
	}
}