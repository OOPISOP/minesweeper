/***********************************************************************
 * File: mainwindows.cpp
 * Author: B11115033
 * Create Date: 2023/04/16
 * Editor: B11115033
 * Update Date: 2023/04/16
 * Description: define the mine amount board
***********************************************************************/
#ifndef MINEAMOUNTBOARD_H
#define MINEAMOUNTBOARD_H

#include <QWidget>
#include <vector>
#include <QFileInfo>
#include <iostream>
#include "Utils.h"
using namespace std;

class AssignBoard;

namespace Ui {
class MineAmountBoard;
}

class MineAmountBoard : public QWidget
{
    Q_OBJECT

public:
    explicit MineAmountBoard(AssignBoard *parent = nullptr);
    ~MineAmountBoard();
    //get game info
    struct gameInfo getGameInfo();
    //init game board
    void initBoard();
    //init answer board
    void initAnswer(int bombs);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MineAmountBoard *ui;
    AssignBoard *assignBoard;
    //game board vector
    vector<vector<QChar>> gameBoard;
    //answer board vector
    vector<vector<QChar>> gameAnswer;
    //board row
    int row;
    //board column
    int column;
    bool isLoad = false;
};

#endif // MINEAMOUNTBOARD_H
