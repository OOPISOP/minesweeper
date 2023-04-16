/***********************************************************************
 * File: mainwindows.cpp
 * Author: B11115033
 * Create Date: 2023/04/16
 * Editor: B11115033
 * Update Date: 2023/04/16
 * Description: Imp the mine rate board
***********************************************************************/
#include "minerateboard.h"
#include "ui_minerateboard.h"

MineRateBoard::MineRateBoard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MineRateBoard)
{
    ui->setupUi(this);
}

MineRateBoard::~MineRateBoard()
{
    delete ui;
}
