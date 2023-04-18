#ifndef UTILS_H
#define UTILS_H

#include <QWidget>
#include <vector>
using namespace std;


struct gameInfo
{
    int row;
    int column;
    vector<vector<QChar>>& gameBoard;
    vector<vector<QChar>>& gameAnswer;
    gameInfo(int r,int c,vector<vector<QChar>>& b,vector<vector<QChar>>& a):gameBoard(b),gameAnswer(a)
    {
        row = r;
        column = c;
    }
};


#endif // UTILS_H
