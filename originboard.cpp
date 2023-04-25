/***********************************************************************
 * File: originboard.cpp
 * Author: B11115033
 * Create Date: 2023/04/16
 * Editor: B11115033
 * Update Date: 2023/04/16
 * Description: Imp the origin board
***********************************************************************/

#include "originboard.h"
#include "./ui_originboard.h"
#include <QMessageBox>
#include <QFileInfo>
#include<iostream>
#include<fstream>
#include <QDebug>
#include <string>
#include "startui.h"
using namespace std;

OriginBoard::OriginBoard(StartUI *parent) :
    QWidget(parent),
    ui(new Ui::OriginBoard)
{
    ui->setupUi(this);
    startUI = parent;
    adjustSize();
}

OriginBoard::~OriginBoard()
{
    delete ui;
}
//Intent:load the file data and init answer board and game board
//Pre:need QTextStream to input file data
//Post:init answer board and game board
void OriginBoard::load(QTextStream in)
{
    in>>this->row;
    in>>this->column;
    initAnswer(in);
    initBoard();
    startUI->setBoard(getGameInfo());
    startUI->setLoadState(true);
}


//Intent:init answer board
//Pre:need QTextStream to input file data
//Post:set mine and number of mine around
void OriginBoard::initAnswer(QTextStream& in)
{
    //init the board row and column size
    this->gameAnswer.resize(row);
    for(int i=0;i<row;i++)this->gameAnswer[i].resize(column);
    //get the file data and set the boar
    for(int i=0;!in.atEnd()&&i<row;i++)
    {
        QString line = in.readLine();
        if(line=="")
        {
            i--;
            continue;
        }
        for(int j=0;j<column&&j<line.size();j++)
        {
            if(line[j]=='O')this->gameAnswer[i][j] = '0';
            else this->gameAnswer[i][j] = 'X';
        }
    }
    //set number of mine around
    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < column; c++)
        {

            if (gameAnswer[r][c] != 'X')
            {
                int num = gameAnswer[r][c].unicode();
                if ((r + 1 < row) && (c + 1 < column) && gameAnswer[r + 1][c + 1] == 'X')
                {
                    num++;
                }
                if ((c + 1 < column) && gameAnswer[r][c + 1] == 'X')
                {
                    num++;
                }
                if ((r - 1 >= 0) && (c + 1 < column) && gameAnswer[r - 1][c + 1] == 'X')
                {
                    num++;
                }
                if ((r + 1 < row) && gameAnswer[r + 1][c] == 'X')
                {
                    num++;
                }
                if ((r - 1 >= 0) && gameAnswer[r - 1][c] == 'X')
                {
                    num++;
                }
                if ((r + 1 < row) && (c - 1 >= 0) && gameAnswer[r + 1][c - 1] == 'X')
                {
                    num++;
                }
                if ((c - 1 >= 0) && gameAnswer[r][c - 1] == 'X')
                {
                    num++;
                }
                if ((r - 1 >= 0) && (c - 1 >= 0) && gameAnswer[r - 1][c - 1] == 'X')
                {
                    num++;
                }
                gameAnswer[r][c] = QChar(num);
            }
        }
    }
}

//Intent:init game board
//Pre:need game board
//Post:init game boar
void OriginBoard::initBoard()
{
    this->gameBoard.resize(row);
    for(int i=0;i<row;i++)this->gameBoard[i].resize(column);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            this->gameBoard[i][j] = '#';
        }
    }
}


//Intent:when push the load button will load the board
//Pre:need board path
//Post:if board path is correct,load the board and print success,or print failed
void OriginBoard::on_loadButton_clicked()
{
        //fetch filePath from boardPath lineEdit
        QString filePath = ui->boardPath->text();
        //add filePath
        QFile fi(":"+filePath);
        fi.open(QIODevice::ReadOnly);
        //check file,if file exist output Success,or output Failed
        if(fi.isOpen())
        {
            this->isLoad = true;
            load(QTextStream(&fi));
            qDebug().nospace().noquote()<<"<Load BoardFile "+ QString(filePath) + "> : " + "Success";
        }
        else
        {
            this->isLoad = false;
            qDebug().nospace().noquote()<<"<Load BoardFile "+ QString(filePath) + "> : " + "Failed";
        }
}


struct gameInfo OriginBoard::getGameInfo()
{
        struct gameInfo GameInfo(this->row,this->column,this->gameBoard,this->gameAnswer);
        return GameInfo;
}
