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
#include "assignboard.h"
#include "QDebug"
MineAmountBoard::MineAmountBoard(AssignBoard *parent) :
    QWidget(parent),
    ui(new Ui::MineAmountBoard)
{
    ui->setupUi(this);
    assignBoard = parent;
    ui->bomb->setMinimum(1);
    ui->bomb->setMaximum(std::numeric_limits<int>::max());
    ui->bomb->setValue(1);
}

MineAmountBoard::~MineAmountBoard()
{
    delete ui;
}

//Intent:load the game
//Pre:need bombs,row,column,click the load button
//Pos:if success print sucess or print failed
void MineAmountBoard::on_pushButton_clicked()
{
    int bombs = ui->bomb->value();
    this->row = assignBoard->getRow();
    this->column = assignBoard->getCol();
    if(row*column<bombs)
    {
        qDebug().noquote().nospace()<<"<Load RandomCount "<<row<<" "<<column<<" "<<bombs<<"> : Failed";
        return;
    }
    qDebug().noquote().nospace()<<"<Load RandomCount "<<row<<" "<<column<<" "<<bombs<<"> : Success";
    initBoard();
    initAnswer(bombs);
    assignBoard->load(getGameInfo());
}

//Intent:init answer board
//Pre:need QTextStream to input file data
//Post:set mine and number of mine around
void MineAmountBoard::initAnswer(int bombs)
{
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
void MineAmountBoard::initBoard()
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
struct gameInfo MineAmountBoard::getGameInfo()
{
    struct gameInfo GameInfo(this->row,this->column,this->gameBoard,this->gameAnswer);
    return GameInfo;
}
