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

namespace Ui {
class MineRateBoard;
}

class MineRateBoard : public QWidget
{
    Q_OBJECT

public:
    explicit MineRateBoard(QWidget *parent = nullptr);
    ~MineRateBoard();

private:
    Ui::MineRateBoard *ui;
};

#endif // MINERATEBOARD_H
