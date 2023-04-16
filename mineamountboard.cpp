/***********************************************************************
 * File: mainwindows.cpp
 * Author: B11115033
 * Create Date: 2023/04/16
 * Editor: B11115033
 * Update Date: 2023/04/16
 * Description: Imp the Mine amount board
***********************************************************************/
#include "mineamountboard.h"
#include "ui_mineamountboard.h"

MineAmountBoard::MineAmountBoard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MineAmountBoard)
{
    ui->setupUi(this);
}

MineAmountBoard::~MineAmountBoard()
{
    delete ui;
}
