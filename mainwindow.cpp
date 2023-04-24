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
    resize(500,350);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Intent:start the game
//Pre:need GameInfo,need to load the game,need click the start button
//Pos:turn to game
void MainWindow::startGame(struct gameInfo GameInfo)
{
    game = new Game(this);
    game->initGame(GameInfo);
    ui->stackedWidget->addWidget(game);
    ui->stackedWidget->setCurrentWidget(game);
}
//Intent: replay the game
//Pre:need push the replay button
//Pos:turn to  startUI and set the window size
void MainWindow::replayGame()
{
    game->deleteLater();
    startUI->deleteLater();
    ui->setupUi(this);
    startUI = new StartUI(this);
    ui->stackedWidget->addWidget(startUI);
    ui->stackedWidget->setCurrentWidget(startUI);
    adjustSize();
    resize(500,350);
}

