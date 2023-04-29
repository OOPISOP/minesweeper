/***********************************************************************
 * File: assignboard.h
 * Author: B11115033
 * Create Date: 2023/04/18
 * Editor: B11115033
 * Update Date: 2023/04/24
 * Description: the game utils , have gameInfo struct to save the game info
***********************************************************************/
#ifndef UTILS_H
#define UTILS_H

#include <QWidget>
#include <vector>
using namespace std;

//Intent:gameInfo struct to save game info
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
