#include "assignboard.h"
#include "ui_assignboard.h"

AssignBoard::AssignBoard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AssignBoard)
{
    ui->setupUi(this);
    //init the amountBoard class
    amountBoard = new MineAmountBoard(this);
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
    }
}
