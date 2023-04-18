#ifndef ASSIGNBOARD_H
#define ASSIGNBOARD_H

#include <QWidget>
#include "minerateboard.h"

class StartUI;
class MineAmountBoard;
namespace Ui {
class AssignBoard;
}

class AssignBoard : public QWidget
{
    Q_OBJECT

public:
    explicit AssignBoard(StartUI *parent = nullptr);
    ~AssignBoard();
    void changeBoard(int);
    void load(struct gameInfo );
    int getRow();
    int getCol();
private:
    Ui::AssignBoard *ui;
    MineAmountBoard * amountBoard;
    MineRateBoard *rateBoard;
    StartUI *startUI;
};

#endif // ASSIGNBOARD_H
