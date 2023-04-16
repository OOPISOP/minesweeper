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
    //init the originBoard class
    originBoard = new OriginBoard(this);
    assignBoard = new AssignBoard(this);
    //add originBoard to stackedWidget
    ui->stackedWidget->addWidget(originBoard);
    //add assignBoard to stackedWidget
    ui->stackedWidget->addWidget(assignBoard);
    //set stackedWidget currentWidget is originBoard class
    ui->stackedWidget->setCurrentWidget(originBoard);

}

MainWindow::~MainWindow()
{
    delete ui;
}
//Intent:when the comboBox current index changed ,changed the model
//Pre:tarnsform into index
//Post:save the index to boardIndex
void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    this->boardIndex = index;
    if(boardIndex == 0)
    {
        //set stackedWidget currentWidget is originBoard class
        ui->stackedWidget->setCurrentWidget(originBoard);
    }
    else if(boardIndex == 1)
    {
        //set stackedWidget currentWidget is assignBoard class
        ui->stackedWidget->setCurrentWidget(assignBoard);
        assignBoard->changeBoard(boardIndex);
    }
}
//Intent:when the comboBox current index changed ,changed the model
//Pre:tarnsform into index
//Post:save the text
void MainWindow::on_gameBoardButon_clicked()
{
    this->originBoard->printGameBoard();
}

//Intent:print the answer board
//Pre:need originBoard class answer board
//Post:print answer board
void MainWindow::on_gameAnswerButton_clicked()
{
    this->originBoard->printAnswer();
}

//Intent:print the game state
//Pre:state
//Post:print state
void MainWindow::on_gameStateButton_clicked()
{
    QString gameState = ui->gameState->text();
    qDebug().nospace().noquote()<<"<Print GameState> : "<<gameState;
}

