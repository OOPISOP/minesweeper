#include "game.h"
#include "ui_game.h"
#include "mainwindow.h"

Game::Game(MainWindow *parent) :
    QWidget(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
    mainWindow = parent;
}

void Game::initGame(struct gameInfo &GameInfo)
{
    this->row = GameInfo.row;
    this->column = GameInfo.column;
    initBoard(GameInfo.gameBoard);
    initAnswer(GameInfo.gameAnswer);
}


void Game::initBoard(vector<vector<QChar>> &board)
{
    this->gameBoard.reserve(row);
    for(int i=0;i<row;i++)this->gameBoard[i].reserve(column);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            this->gameBoard[i][j] = board[i][j];
        }
    }
}

void Game::initAnswer(vector<vector<QChar>> &answer)
{
    this->gameAnswer.reserve(row);
    for(int i=0;i<row;i++)this->gameAnswer[i].reserve(column);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            this->gameAnswer[i][j] = answer[i][j];
        }
    }
}

Game::~Game()
{
    delete ui;
}

void Game::on_gameBoardButon_clicked()
{
    qDebug().nospace().noquote()<<"<Print GameBoard> :";
    for(int i=0;i<row;i++)
    {
        QString rowString = "";
        for(int j=0;j<column;j++)
        {
            rowString += QString(this->gameBoard[i][j]) + " ";
        }
        qDebug().nospace().noquote()<<rowString;
    }
}


void Game::on_gameAnswerButton_clicked()
{
    qDebug().nospace().noquote()<<"<Print GameAnswer> :";
    for(int i=0;i<row;i++)
    {
        QString rowString = "";
        for(int j=0;j<column;j++)
        {
            rowString += QString(this->gameAnswer[i][j]) + " ";
        }
        qDebug().nospace().noquote()<<rowString;
    }
}


void Game::on_gameStateButton_clicked()
{

}

