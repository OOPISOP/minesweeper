/***********************************************************************
 * File: mainwindows.cpp
 * Author: B11115033
 * Create Date: 2023/04/16
 * Editor: B11115033
 * Update Date: 2023/04/16
 * Description: Imp the mine rate board
***********************************************************************/
#include "minerateboard.h"
#include "assignboard.h"
#include "ui_minerateboard.h"
#include "QDebug"
MineRateBoard::MineRateBoard(AssignBoard *parent) :
    QWidget(parent),
    ui(new Ui::MineRateBoard)
{
    ui->setupUi(this);
    assignBoard = parent;
    ui->rate->setMinimum(0.00);
    ui->rate->setMaximum(1);
    ui->rate->setValue(0.02);
    ui->rate->setSingleStep(0.01);
}

MineRateBoard::~MineRateBoard()
{
    delete ui;
}
//Intent:init and load the game
//Pre:need rate row and column and click the laod button
//Post load the game
void MineRateBoard::on_pushButton_clicked()
{
    double rate = ui->rate->value();
    this->row = assignBoard->getRow();
    this->column = assignBoard->getCol();
    initBoard();
    initAnswer(rate);
    assignBoard->load(getGameInfo());
}

//Intent:init answer board
//Pre:need QTextStream to input file data
//Post:set mine and number of mine around
void MineRateBoard::initAnswer(double rate)
{
    int totaCells = row * column;
    double bombs = totaCells * rate;
    qDebug().noquote().nospace()<<"<Load Rate "<<row<<" "<<column<<" "<<bombs<<"> : Success";
    //init the board row and column size
    this->gameAnswer.resize(row);
    for(int i=0;i<row;i++)this->gameAnswer[i].resize(column);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            this->gameAnswer[i][j] = '0';
        }
    }
    // Random set mines poistion
    for (int mine = 0; mine < bombs; mine++)
    {
        int rowP = rand()%row;
        int colP = rand()%column;

        if (gameAnswer[rowP][colP] == 'X')
        {
            mine--;
        }
        else
        {
            gameAnswer[rowP][colP] = 'X';
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
void MineRateBoard::initBoard()
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


//Intent:set the game Info
//Pre:need row column gameBoard gameAnswer
//Pos:return GameInfo
struct gameInfo MineRateBoard::getGameInfo()
{
    struct gameInfo GameInfo(this->row,this->column,this->gameBoard,this->gameAnswer);
    return GameInfo;
}
