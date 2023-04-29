/***********************************************************************
 * File: assignboard.h
 * Author: B11115033
 * Create Date: 2023/04/18
 * Editor: B11115033
 * Update Date: 2023/04/24
 * Description: define the assignboard class ,it can change the board amountBoard and rateBoard
***********************************************************************/
#ifndef ASSIGNBOARD_H
#define ASSIGNBOARD_H

#include <QWidget>


class StartUI;
class MineAmountBoard;
class MineRateBoard;
namespace Ui {
class AssignBoard;
}

class AssignBoard : public QWidget
{
    Q_OBJECT

public:
    explicit AssignBoard(StartUI *parent = nullptr);
    ~AssignBoard();
    //chage board
    void changeBoard(int);
    //load game
    void load(struct gameInfo );
    //get row
    int getRow();
    //get col
    int getCol();
private:
    Ui::AssignBoard *ui;
    MineAmountBoard * amountBoard;
    MineRateBoard *rateBoard;
    StartUI *startUI;
};

#endif // ASSIGNBOARD_H
