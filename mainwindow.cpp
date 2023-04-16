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

    originBoard = new OriginBoard(this);
    ui->stackedWidget->addWidget(originBoard);
    ui->stackedWidget->setCurrentWidget(originBoard);
}

MainWindow::~MainWindow()
{
    delete ui;
}
//Intent:when the comboBox current index changed ,changed the model
//Pre:tarnsform into index
void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    QString text = ui->comboBox->currentText();
}

void MainWindow::on_gameBoardButon_clicked()
{
    this->originBoard->printGameBoard();
}


void MainWindow::on_gameAnswerButton_clicked()
{
    this->originBoard->printAnswer();
}


void MainWindow::on_gameStateButton_clicked()
{
    QString gameState = ui->gameState->text();
    qDebug().nospace().noquote()<<"<Print GameState> : "<<gameState;
}

