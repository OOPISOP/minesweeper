/***********************************************************************
 * File: assignboard.cpp
 * Author: B11115033
 * Create Date: 2023/04/18
 * Editor: B11115033
 * Update Date: 2023/04/20
 * Description: Imp the assignboard class ,it can change the board amountBoard and rateBoard
***********************************************************************/
#include "assignboard.h"
#include "mineamountboard.h"
#include "minerateboard.h"
#include "ui_assignboard.h"
#include "startui.h"
AssignBoard::AssignBoard(StartUI *parent) :
    QWidget(parent),
    ui(new Ui::AssignBoard)
{
    ui->setupUi(this);
    startUI = parent;
    ui->rows->setRange(1,10);
    ui->rows->setValue(9);
    ui->cols->setRange(1,10);
    ui->cols->setValue(9);
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
