#include "DigMine.h"

DigMine::DigMine(int rP, int cP, int mP)
{
	this->row = rP;
	this->col = cP;
	this->mine = mP;
}

int DigMine::surroundBomb(int inY, int inX)
{
	// Count each array surround mines number
	if (this->map[inY][inX] != 9)
	{
		int boom = 0;
		for (int i = 0; i < 8; i++)
		{
			int nextx = inX + this->dir[i][0];
			int nexty = inY + this->dir[i][1];
			if (nextx < 0 || nexty < 0 || nexty >= row || nextx >= col)
				continue;
			if (this->map[nexty][nextx] == 9)
			{
				boom++;
			}
		}
		return boom;
	}
	return 9;
}

void DigMine::explandDig(int inY, int inX)
{
	if ((this->answer[inY][inX]) == 9)
	{
		cout << "Lose Game" << endl;
	}
	else if (this->answer[inY][inX] == 0)
	{
		queue<pair<int, int>> que;
		que.push(pair<int, int>(inY, inX));

		while (!que.empty()) {
			int y = que.front().first;
			int x = que.front().second;
			que.pop();
			for (int i = 0; i < 8; i++) {
				int nexty = y + this->dir[i][0];
				int nextx = x + this->dir[i][1];
				if (nextx < 0 || nexty < 0 || nexty >= this->row || nextx >= this->col)
					continue;
				if (this->map[nexty][nextx] == '0')
				{
					continue;
				}
				int tot = this->answer[nexty][nextx];
				if (tot != 0)
				{
					this->map[nexty][nextx] = tot + '0';
				}
				else
				{
					this->map[nexty][nextx] = '0';
					que.push(pair<int, int>(nexty, nextx));
				}
			}
		}
	}
	else
	{
		this->map[inY][inX] = this->answer[inY][inX] + '0';
	}
}