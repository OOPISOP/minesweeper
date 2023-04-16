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

namespace Ui {
class MineAmountBoard;
}

class MineAmountBoard : public QWidget
{
    Q_OBJECT

public:
    explicit MineAmountBoard(QWidget *parent = nullptr);
    ~MineAmountBoard();

private:
    Ui::MineAmountBoard *ui;
};

#endif // MINEAMOUNTBOARD_H
