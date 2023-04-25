/***********************************************************************
 * File: startui.cpp
 * Author: B11115033
 * Create Date: 2023/04/18
 * Editor: B11115033
 * Update Date: 2023/04/24
 * Description: Imp the startui class ,it is the first ui we  see
***********************************************************************/

#include "startui.h"
#include "ui_startui.h"
#include "mainwindow.h"


StartUI::StartUI(MainWindow *parent) :
    QWidget(parent),
    ui(new Ui::StartUI)
{
    ui->setupUi(this);
    mainWindow = parent;
    originBoard = new OriginBoard(this);
    assignBoard = new AssignBoard(this);
    ui->stackedWidget->addWidget(originBoard);
    ui->stackedWidget->addWidget(assignBoard);
    ui->stackedWidget->setCurrentWidget(originBoard);
    adjustSize();
}

StartUI::~StartUI()
{
    delete ui;
}
//Intent:when the comboBox current index changed ,changed the model
//Pre:tarnsform into index
//Post:save the index to boardIndex
void StartUI::on_comboBox_currentIndexChanged(int index)
{
    this->boardIndex = index;
    if(boardIndex == 0)
    {
        //set stackedWidget currentWidget is originBoard class
        ui->stackedWidget->setCurrentWidget(originBoard);
    }
    else if(boardIndex > 0)
    {
        //set stackedWidget currentWidget is assignBoard class
        ui->stackedWidget->setCurrentWidget(assignBoard);
        assignBoard->changeBoard(boardIndex);
    }
}
//Intent:when the comboBox current index changed ,changed the model
//Pre:tarnsform into index
//Post:save the text
void StartUI::on_gameBoardButon_clicked()
{
   printGameBoard();
}

//Intent:print the answer board
//Pre:need originBoard class answer board
//Post:print answer board
void StartUI::on_gameAnswerButton_clicked()
{
   printAnswer();
}

//Intent:print the game state
//Pre:state
//Post:print state
void StartUI::on_gameStateButton_clicked()
{
    QString gameState = ui->gameState->text();
    qDebug().nospace().noquote()<<"<Print GameState> : "<<gameState;
}

void StartUI::on_startGameButton_clicked()
{
    if(loadState)
    {
        qDebug().nospace().noquote()<<"<StartGame> : Success";
        mainWindow->startGame(getGameInfo());
    }
    else
    {
        qDebug().nospace().noquote()<<"<StartGame> : Failed";
    }

}
//Intent:get game info
//Pre:need game info
//Pos:return GameInfo
struct gameInfo StartUI::getGameInfo()
{
    struct gameInfo GameInfo(this->row,this->column,this->gameBoard,this->gameAnswer);
    return GameInfo;
}

//Intent:set board
//Pre:need gameinfo
//Post init board init answer
void StartUI::setBoard(struct gameInfo GameInfo)
{
    this->row = GameInfo.row;
    this->column = GameInfo.column;
    initBoard(GameInfo.gameBoard);
    initAnswer(GameInfo.gameAnswer);
}

//Intent:init board
//Pre:need board
//Pos:init board
void StartUI::initBoard(vector<vector<QChar>> &board)
{
    this->gameBoard.resize(row);
    for(int i=0;i<row;i++)this->gameBoard[i].resize(column);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            this->gameBoard[i][j] = board[i][j];
        }
    }
}
//Intent:init answer
//Pre:need answer
//Pos:init answer
void StartUI::initAnswer(vector<vector<QChar>> &answer)
{
    this->gameAnswer.resize(row);
    for(int i=0;i<row;i++)this->gameAnswer[i].resize(column);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            this->gameAnswer[i][j] = answer[i][j];
        }
    }
}


//Intent:print gmae board
//Pre:need game board
//Post:print game board
void StartUI::printGameBoard()
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

//Intent:print answer board
//Pre:need answer board
//Post:print answer board
void StartUI::printAnswer()
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
//Intent:set load state
//Pre:need state
//Post:set load state
void StartUI::setLoadState(bool state)
{
    this->loadState = state;
}


