#include "assignboard.h"
#include "mineamountboard.h"
#include "ui_assignboard.h"
#include "startui.h"
AssignBoard::AssignBoard(StartUI *parent) :
    QWidget(parent),
    ui(new Ui::AssignBoard)
{
    ui->setupUi(this);
    startUI = parent;
    //init the amountBoard class
    amountBoard  = new MineAmountBoard(this);
    //init the rateBoard class
    rateBoard = new MineRateBoard(this);
    //add amountBoard to stackedWidget
    ui->stackedWidget->addWidget(amountBoard);
    //add rateBoard to stackedWidget
    ui->stackedWidget->addWidget(rateBoard);
}

AssignBoard::~AssignBoard()
{
    delete ui;
}

void AssignBoard::changeBoard(int index)
{
    if(index == 1)
    {
        ui->stackedWidget->setCurrentWidget(amountBoard);
    }
    else if(index == 2)
    {
        ui->stackedWidget->setCurrentWidget(rateBoard);
        //rateBoard->setRowCol(row,col);
    }
}

int AssignBoard::getRow()
{
    int row = ui->rows->value();
    return row;
}

int AssignBoard::getCol()
{
    int col = ui->cols->value();
    return col;
}

void AssignBoard::load(struct gameInfo GameInfo)
{
    startUI->setBoard(GameInfo);
    startUI->setLoadState(true);
}
