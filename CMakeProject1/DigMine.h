#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

class DigMine
{
public:
	DigMine(int row, int col, int mine);

	void explandDig(int inY, int inX);

	int surroundBomb(int inY, int inX);

private:

	// The input surround poistion
	int dir[8][2] = { -1, -1, 0, -1, 1, -1, 1, 0, 1, 1, 0, 1, -1, 1, -1, 0 };

	int row, col, mine;

	// Declare the map with two array ons is store char another store number
	vector<vector<char>> input;

	// Declare the map with two array ons is store char another store number
	vector<vector<char>> map;

	// Declare the answer
	vector<vector<int>> answer;

	// Whether RightClick touch or LeftClick touch
	vector<vector<int>> click;
};