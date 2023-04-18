/***********************************************************************
 * File: mainwindows.cpp
 * Author: B11115033
 * Create Date: 2023/04/16
 * Editor: B11115033
 * Update Date: 2023/04/16
 * Description: Imp the main window
***********************************************************************/

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "startui.h"
#include "game.h"
#include <QMessageBox>
#include <QFileInfo>
#include<iostream>
#include <QDebug>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    startUI = new StartUI(this);
    ui->stackedWidget->addWidget(startUI);
    ui->stackedWidget->setCurrentWidget(startUI);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startGame(struct gameInfo GameInfo)
{
    game = new Game(this);
    game->initGame(GameInfo);
    ui->stackedWidget->addWidget(game);
    ui->stackedWidget->setCurrentWidget(game);
}
