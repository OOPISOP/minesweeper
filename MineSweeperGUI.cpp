#include "MineSweeperGUI.h"
#include <vector>
#include <iostream>
using namespace std;

MineSweeperGUI::MineSweeperGUI(int rows, int cols, int mines, QWidget* parent)
	: QWidget(parent), rows(rows), cols(cols), mines(mines)
{
	QGridLayout* gridLayout = new QGridLayout(this);
	for (int row = 0; row < rows; ++row) 
	{
		for (int col = 0; col < cols; ++col) 
		{
			QPushButton* button = new QPushButton(this);
			button->setFixedSize(50, 50);
			//button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
			gridLayout->addWidget(button, row, col);
			connect(button, &QPushButton::clicked, [row, col]()
				{
					qDebug() << "Button clicked at row:" << row << "col:" << col;
				}
			);
			 
			

		}
	}

	vector<vector<int>> map(rows, vector<int>(cols, 0));

	for (int mine = 0; mine < mines; mine++)
	{
		int rowP = rand() % rows;
		int colP = rand() % cols;

		if (map[rowP][colP] == 9)
		{
			mine--;
		}
		else
		{
			map[rowP][colP] = 9;
		}
	}

	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			if (map[r][c] != 9)
			{
				if ((r + 1 < rows) && (c + 1 < cols) && map[r + 1][c + 1] == 9)
				{
					map[r][c]++;
				}
				if ((c + 1 < cols) && map[r][c + 1] == 9)
				{
					map[r][c]++;
				}
				if ((r - 1 >= 0) && (c + 1 < cols) && map[r - 1][c + 1] == 9)
				{
					map[r][c]++;
				}
				if ((r + 1 < rows) && map[r + 1][c] == 9)
				{
					map[r][c]++;
				}
				if ((r - 1 >= 0) && map[r - 1][c] == 9)
				{
					map[r][c]++;
				}
				if ((r + 1 < rows) && (c - 1 >= 0) && map[r + 1][c - 1] == 9)
				{
					map[r][c]++;
				}
				if ((c - 1 >= 0) && map[r][c - 1] == 9)
				{
					map[r][c]++;
				}
				if ((r - 1 >= 0) && (c - 1 >= 0) && map[r - 1][c - 1] == 9)
				{
					map[r][c]++;
				}
			}
		}
	}


	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			if (map[r][c] == 9)
			{
				cout << "*";
			}
			else if (map[r][c] == 0)
			{
				cout << "_";
			}
			else
			{
				cout << map[r][c];
			}
		}
		cout << endl;
	}
}

