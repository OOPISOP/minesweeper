/***********************************************************************
 * File: mainwindows.cpp
 * Author: B11115033
 * Create Date: 2023/04/16
 * Editor: B11115033
 * Update Date: 2023/04/16
 * Description: define the mine rate board
***********************************************************************/
#ifndef MINERATEBOARD_H
#define MINERATEBOARD_H

#include <QWidget>
#include <vector>
#include <QFileInfo>
#include <iostream>
#include "Utils.h"
using namespace std;

class AssignBoard;

namespace Ui {
class MineRateBoard;
}

class MineRateBoard : public QWidget
{
    Q_OBJECT

public:
    explicit MineRateBoard(AssignBoard *parent = nullptr);
    ~MineRateBoard();
    struct gameInfo getGameInfo();
    void initBoard();
    //init answer board
    void initAnswer(double rate);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MineRateBoard *ui;
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

#endif // MINERATEBOARD_H
