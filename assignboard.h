#ifndef ASSIGNBOARD_H
#define ASSIGNBOARD_H

#include <QWidget>
#include "mineamountboard.h"
#include "minerateboard.h"
namespace Ui {
class AssignBoard;
}

class AssignBoard : public QWidget
{
    Q_OBJECT

public:
    explicit AssignBoard(QWidget *parent = nullptr);
    ~AssignBoard();
    void changeBoard(int);

private:
    Ui::AssignBoard *ui;
    MineAmountBoard * amountBoard;
    MineRateBoard *rateBoard;
};

#endif // ASSIGNBOARD_H
