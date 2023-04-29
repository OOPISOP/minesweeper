#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int getGameData(vector<vector<char>> map, int row, int col, char check);

void surroundBomb(vector<vector<char>>& map, int row, int col);

bool expandDig(vector<vector<char>>& map, vector<vector<char>> answer, int inY, int inX);

int main() 
{

	while (true)
	{
		cout << "Please ipnut the mine rows,cols, and minues number" << endl;

		// Set Mine rows cols and minenum
		int row, col, mine;

		// Make sure rows cols and mines number can't be negative
		cin >> row >> col >> mine;

		if (row <= 0 || col <= 0)
		{
			cout << "Map can't be negative or zero" << endl;
		}
		
		// Mine number can't be negativor or zero
		if (mine <= 0) 
		{
			cout << "Mines number can't be negative or zero" << endl;
		}
		if (mine >= row * col) 
		{
			cout << "Over range allow" << endl;
		}


		// Declare the map display array
		vector<vector<char>> mapBoard(row, vector<char>(col, '#'));

		// Declare the map answer array
		vector<vector<char>> mapAnswer(row, vector<char>(col, '0'));


		/*// Declare the map with two array ons is store char another store number
		vector<vector<char>> input(rows, vector<char>(cols, 'O'));

		// Declare the map with two array ons is store char another store number
		vector<vector<char>> map(rows, vector<char>(cols, '#'));

		// Declare the answer to save wheter bomb arround number
		vector<vector<int>> answer(rows, vector<int>(cols, 0));

		// Whether RightClick or LeftClick touch
		//RightClick click one time the variable will be one and map char will be f
		//RightClick clike tow time the variable will be two and map char will be ?
		//RightClick click three time the variable will be zero and map char will be return to #
		vector<vector<int>> click(rows, vector<int>(cols, 0));*/

		// Random set mines poistion
		for (int mP = 0; mP < mine; mP += 1)
		{
			int rowP = rand() % row;
			int colP = rand() % col;

			if (mapAnswer[rowP][colP] == 'X')
			{
				mP -= 1;
			}
			else
			{
				mapAnswer[rowP][colP] = 'X';
			}
		}

		// Check bomb surround and store back to answer
		// Count each array surround mines number
		for (int r = 0; r < row; r++)
		{
			for (int c = 0; c < col; c++)
			{
				surroundBomb(mapAnswer, r, c);
			}
		}

		//Set gameState Standby
		string command, gameState = "Standby";

		string fileName;


		int bombBlank = getGameData(mapBoard, row, col, 'X');
		int flagBlank = 0, openBlank = 0;

		int total = row * col;


		//If GameState == Quit
		while (true)
		{
			if (getGameData(mapBoard, row, col, '#') == 0)
			{
				cout << "Game Success" << endl;
				break;
			}

			cin >> command;

			if (command == "Quit") 
			{
				break;
			}


			//If mode Standby
			if (command == "Standby") 
			{
				if (command == "Load")
				{
					cout << "<Load BoardFile" << fileName << "> : Success" << endl;
				}
				if (command == "StartGame") 
				{
					gameState = "Playing";
					cout << "<StartGame> : Success" << endl;
				}
			}
			//If mode StartGame
			else if (command == "StartGame")
			{
				gameState = "Playing";
				cout << "<StartGame> : Success" << endl;
			}
			//If mode Print
			else if (command == "Print")
			{
				cin >> command;
				if (command == "GameBoard")
				{
					cout << "<Print GameBoard> :" << endl;
					for (int r = 0; r < row; r++)
					{
						for (int c = 0; c < col; c++)
						{
							cout << mapBoard[r][c];
						}
						cout << endl;
					}
				}
				if (command == "GameState")
				{
					cout << "<GameState> : " << gameState << endl;
				}
				if (command == "GameAnswer")
				{
					cout << "<Print GameAnswer> :" << endl;
					for (int r = 0; r < row; r++)
					{
						for (int c = 0; c < col; c++)
						{
							cout << mapAnswer[r][c];
						}
						cout << endl;
					}
				}
				if (command == "BombCount")
				{
					cout << "<BombCount> : " << bombBlank << endl;
				}
				if (command == "FlagCount")
				{
					cout << "<FlagCount> : " << flagBlank << endl;
				}
				if (command == "OpenBlankCount")
				{
					cout << "<OpenBlankCount> : " << openBlank << endl;
				}
				if (command == "RemainBlankCount")
				{
					cout << "<RemainBlankCount> : " << total - openBlank - flagBlank << endl;
				}
			}
			else if (command == "RightClick")
			{
				int inX, inY;
				cin >> inY >> inX;

				if (gameState != "Playing" || mapBoard[inY][inX] != '#' || mapBoard[inY][inX] != 'f' || mapBoard[inY][inX] != '?')
				{
					cout << "<RightClick " << inY << " " << inX << ">" << " : Failed" << endl;
				}
				else 
				{
					cout << "<RightClick " << inY << " " << inX << ">" << " : Success" << endl;
					

					if (mapBoard[inY][inX] == 'f')
					{
						mapBoard[inY][inX] = '?';
					}
					else if (mapBoard[inY][inX] == '?')
					{
						mapBoard[inY][inX] = '#';
					}
					else 
					{
						mapBoard[inY][inX] = 'f';
					}
				}
			}
			else if(command == "LeftClick")
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
					expandDig(mapBoard, mapAnswer, inY, inX);
				}
			}
		}
	}
}

int getGameData(vector<vector<char>> map, int row, int col, char check)
{
	int count = 0;
	for (int r = 0; r < row; r++)
	{
		for (int c = 0; c < col; c++)
		{
			if (map[r][c] == check)
			{
				count += 1;
			}
		}
	}
	return count;
}

void surroundBomb(vector<vector<char>>& map, int row, int col) 
{
	// The input surround poistion
	int dir[8][2] = { -1, -1, 0, -1, 1, -1, 1, 0, 1, 1, 0, 1, -1, 1, -1, 0 };

	if (map[row][col] != 'X')
	{
		int boom = 0;
		for (int i = 0; i < 8; i++)
		{
			int nextx = col + dir[i][0];
			int nexty = row + dir[i][1];
			if (nextx < 0 || nexty < 0 || nexty >= map.size() || nextx >= map[0].size())
				continue;
			if (map[nexty][nextx] == 'X')
			{
				boom += 1;
			}
		}

		map[row][col] = ('0' + boom);
	}
}


bool expandDig(vector<vector<char>>& map, vector<vector<char>> answer, int inY, int inX)
{
	if (answer[inY][inX] == 'X')
	{
		cout << "Lose game" << endl;
		return false;
	}
	else if (answer[inY][inX] == '0')
	{
		// The input surround poistion
		int dir[8][2] = { -1, -1, 0, -1, 1, -1, 1, 0, 1, 1, 0, 1, -1, 1, -1, 0 };

		queue<pair<int, int>> que;
		que.push(pair<int, int>(inY, inX));
		while (!que.empty()) {
			int y = que.front().first;
			int x = que.front().second;
			que.pop();
			for (int i = 0; i < 8; i++) {
				int nextY = y + dir[i][0];
				int nextX = x + dir[i][1];
				if (nextX < 0 || nextY < 0 || nextY >= answer.size() || nextX >= answer[0].size())
					continue;
				if (map[nextY][nextX] == '0')
				{
					continue;
				}
				char tot = answer[nextY][nextX];
				if (tot != '0')
				{
					map[nextY][nextX] = tot;
				}
				else
				{
					map[nextY][nextX] = '0';
					que.push(pair<int, int>(nextY, nextX));
					
				}
			}
		}
	}
	else
	{
		map[inY][inX] = answer[inY][inX];
	}
	return true;
}
