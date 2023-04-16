#include "originboard.h"
#include "./ui_originboard.h"
#include <QMessageBox>
#include <QFileInfo>
#include<iostream>
#include<fstream>
#include <QDebug>
#include <string>
using namespace std;


OriginBoard::OriginBoard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OriginBoard)
{
    ui->setupUi(this);
}

OriginBoard::~OriginBoard()
{
    delete ui;
}

void OriginBoard::load(QTextStream in)
{
    in>>this->row;
    in>>this->column;
    initAnswer(in);
    initBoard();
}

void OriginBoard::initAnswer(QTextStream& in)
{

    this->gameAnswer.reserve(row);
    for(int i=0;i<row;i++)this->gameAnswer[i].reserve(column);
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


void OriginBoard::printAnswer()
{
    qDebug().nospace().noquote()<<"<Print GameAnswer> :";
    for(int i=0;i<row;i++)
    {
        QString row = "";
        for(int j=0;j<column;j++)
        {
            row += QString(this->gameAnswer[i][j]) + " ";
        }
        qDebug().nospace().noquote()<<row;
    }
}

void OriginBoard::initBoard()
{
    this->gameBoard.reserve(row);
    for(int i=0;i<row;i++)this->gameBoard[i].reserve(column);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            this->gameBoard[i][j] = '#';
        }
    }
}

void OriginBoard::printGameBoard()
{
    qDebug().nospace().noquote()<<"<Print GameBoard> :";
    for(int i=0;i<row;i++)
    {
        QString row = "";
        for(int j=0;j<column;j++)
        {
            row += QString(this->gameBoard[i][j]) + " ";
        }
        qDebug().nospace().noquote()<<row;
    }

}


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
            load(QTextStream(&fi));
            qDebug().nospace().noquote()<<"<Load BoardFile "+ QString(filePath) + "> : " + "Success";
        }
        else
        {
            qDebug().nospace().noquote()<<"<Load BoardFile "+ QString(filePath) + "> : " + "Failed";
        }
}

