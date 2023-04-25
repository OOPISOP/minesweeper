/***********************************************************************
 * File: game.cpp
 * Author: B11115033
 * Create Date: 2023/04/16
 * Editor: B11115033
 * Update Date: 2023/04/20
 * Description: Imp the game
***********************************************************************/
#include "game.h"
#include "ui_game.h"
#include "mainwindow.h"
#include <QMouseEvent>
#include <QAbstractButton>
#include <queue>
#include <QCoreApplication>
#include <QApplication>
#include <QAbstractEventDispatcher>
#include "mybutton.h"
#include <QDialog>
#include <QApplication>
#include <QProcess>
#include <QMovie>
#include <mydialog.h>
#include <QLabel>
#include <QStackedWidget>

//init the Game
Game::Game(MainWindow *parent) :
    QWidget(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
    mainWindow = parent;
}
//Intent:get the char times in the board
//Pre:need 2D vector board,int row and col,char check
//Pos:return the check char times
int getGameData(vector<vector<QChar>> &map, int row, int col, char check)
{
    int count = 0;
    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            if (map[r][c] == check)
            {
                count += 1;
            }
        }
    }
    return count;
}
//Intent:print the all game board in game end
//Pre:need board,row ,col
//Pos:print the game board,and set the button icon
void Game::printAllGameBoard()
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            QPushButton *button = qobject_cast<QPushButton *>(ui->gridLayout->itemAtPosition(i, j)->widget());
            //is bomb set bomb icon
            if(gameAnswer[i][j] == 'X')
            {
                button->setIcon(QIcon(":./images/bomb.png"));
            }
            //is 0 set down true
            else if(gameAnswer[i][j] == '0')
            {
                button->setDown(true);ui->gridLayout->itemAtPosition(i,j);
            }
            //is not bomb and not 0 set text
            else
            {
                button->setDown(true);ui->gridLayout->itemAtPosition(i,j);
                button->setText(gameAnswer[i][j]);
            }
        }
    }
}

//Intent:bfs to spread to board,and check lose or win
//Pre:need button y and x pos
//Pos:spread board and check lose or win
bool Game::expandDig(int inY, int inX)
{
    //if click the bomb button,lose the game,and creat a dialog window ,have replay button and quit button
    if (gameAnswer[inY][inX] == 'X')
    {
         QPushButton *button = qobject_cast<QPushButton *>(ui->gridLayout->itemAtPosition(inY, inX)->widget());
        //play the gif
        QMovie *movie = new QMovie(":./animations/BombExplosion.gif");
         button->setIcon(QIcon(movie->currentPixmap()));

         connect(movie, &QMovie::frameChanged, this, [=]() {
             button->setIcon(QIcon(movie->currentPixmap()));
         });
         movie->start();
         //print the all game board
        printAllGameBoard();
         //print lose message
        qDebug() << "You lose the game";
        //quit button and replay button
        QDialog dialog;
        //if quit the dialog will quit the game
        QObject::connect(&dialog, &QDialog::finished, qApp, &QApplication::quit);
        QVBoxLayout layout(&dialog);
        QHBoxLayout buttonLayout;
        QLabel label("You lose the game", &dialog);
        layout.addWidget(&label);
        //replay button to replay the game
        QPushButton okButton("Replay", &dialog);
        buttonLayout.addWidget(&okButton);
       // QObject::connect(&okButton, &QPushButton::clicked, this, &Game::replayGame);
        // 連接按鈕的 clicked() 信號到一個槽函式
        QObject::connect(&okButton, &QPushButton::clicked, [&dialog, this]() {
            // 關閉 QDialog
            dialog.hide();
            // 執行您想要執行的函式
            replayGame();
        });
        //quit button to quit the game
        QPushButton cancelButton("Quit", &dialog);
        buttonLayout.addWidget(&cancelButton);
        QObject::connect(&cancelButton, &QPushButton::clicked, qApp, &QApplication::quit);
        layout.addLayout(&buttonLayout);
        dialog.exec();

        return false;
    }
    else if (gameAnswer[inY][inX] == '0' && gameBoard[inY][inX] != 'f')//not 0 and not f , bfs
    {
        // The input surround poistion
        int dir[8][2] = { {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0} };

        queue<pair<int, int>> que;
        que.push(pair<int, int>(inY, inX));
        while (!que.empty()) {
            int y = que.front().first;
            int x = que.front().second;
            que.pop();
            for (int i = 0; i < 8; i++) {
                int nextY = y + dir[i][0];
                int nextX = x + dir[i][1];
                if (nextX < 0 || nextY < 0 || nextY >= row || nextX >= column)
                    continue;
                if (gameBoard[nextY][nextX] == '0' || gameBoard[nextY][nextX] == 'f')
                {
                    continue;
                }
                //set button state
                QChar tot = gameAnswer[nextY][nextX];
                QPushButton *button = qobject_cast<QPushButton *>(ui->gridLayout->itemAtPosition(nextY, nextX)->widget());
                button->setDown(true);ui->gridLayout->itemAtPosition(nextY,nextX);
                button->setIcon(QIcon());
                if (tot != '0')
                {
                        //set game board and button text
                        gameBoard[nextY][nextX] = tot;
                        button->setText(tot);
                }
                else
                {
                        //set game board and button text
                        gameBoard[nextY][nextX] = '0';
                        button->setText("");
                        que.push(pair<int, int>(nextY, nextX));
                }
            }
        }
            //set game board and button text icon
            gameBoard[inY][inX] = '0';
            QPushButton *button = qobject_cast<QPushButton *>(ui->gridLayout->itemAtPosition(inY, inX)->widget());
            button->setDown(true);ui->gridLayout->itemAtPosition(inY,inX);
            button->setIcon(QIcon());
    }
    else if(gameBoard[inY][inX] != 'f')
    {
             //set game board and button text icon
        gameBoard[inY][inX] = gameAnswer[inY][inX];
        QPushButton *button = qobject_cast<QPushButton *>(ui->gridLayout->itemAtPosition(inY, inX)->widget());
        button->setText(gameBoard[inY][inX]);
        button->setDown(true);ui->gridLayout->itemAtPosition(inY,inX);
        button->setIcon(QIcon());
    }
    //set the openBlankCount
    ui->openBlankCount->setText(QString::number(row*column-getGameData(gameBoard,row,column,'#')  - getGameData(gameBoard,row,column,'f') - getGameData(gameBoard,row,column,'?')));
    //set the remainBlankCount
    ui->remainBlankCount->setText(QString::number(row*column - ui->bombCount->text().toInt() - ui->openBlankCount->text().toInt()));
    //win game
    if(ui->remainBlankCount->text().toInt() ==  0 )
    {
        //print all game board
        printAllGameBoard();
        //print win message
        qDebug() << "You win the game";
        //creat dialog window
        QDialog dialog;
        //if quit dialog window, quit gmae
        QObject::connect(&dialog, &QDialog::finished, qApp, &QApplication::quit);
        QVBoxLayout layout(&dialog);
        QHBoxLayout buttonLayout;
        QLabel label("You win the game", &dialog);
        layout.addWidget(&label);
        //replay button
        QPushButton okButton("Replay", &dialog);
        buttonLayout.addWidget(&okButton);
        // 連接按鈕的 clicked() 信號到一個槽函式
        QObject::connect(&okButton, &QPushButton::clicked, [&dialog, this]() {
            // 關閉 QDialog
            dialog.hide();
            // 執行您想要執行的函式
            replayGame();
        });
        //quit button
        QPushButton cancelButton("Quit", &dialog);
        buttonLayout.addWidget(&cancelButton);
        QObject::connect(&cancelButton, &QPushButton::clicked, qApp, &QApplication::quit);
        layout.addLayout(&buttonLayout);
        dialog.exec();

        return false;
    }
    return true;
}

//Intent:init game
//Pre:need game info
//Pos:init  game
void Game::initGame(struct gameInfo &GameInfo)
{
    this->row = GameInfo.row;
    this->column = GameInfo.column;
    initBoard(GameInfo.gameBoard);
    initAnswer(GameInfo.gameAnswer);
    MineSweeperGUI();
    initState();
    adjustSize();
}
//Intent:init state
//Pre:need game state
//Pos:init the game state
void Game::initState()
{
    ui->bombCount->setText(QString::number(getGameData(gameAnswer,row,column,'X')));
    ui->flagCount->setText(QString::number(0));
    ui->openBlankCount->setText(QString::number(0));
    ui->remainBlankCount->setText(QString::number(row*column - ui->openBlankCount->text().toInt() - ui->bombCount->text().toInt()) );
}
//Intent:init the game  board
//Pre:need game board
//Pos:init the game  board
void Game::initBoard(vector<vector<QChar>> &board)
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
//Intent:init the game answer board
//Pre:need game answer
//Pos:init the game answer board
void Game::initAnswer(vector<vector<QChar>> &answer)
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

Game::~Game()
{
    delete ui;
}
//Intent:print game board if click the game board button
//Pre:need click the game board button and need gameBoard
//Pos:print the game  board
void Game::on_gameBoardButton_clicked()
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

//Intent:print game Answer if click the game answer button
//Pre:need click the game answer button and need gameAnswerBoard
//Pos:print the game answer board
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

//Intent:print game state
//Pre:need game state
//Pos:print game state
void Game::on_gameStateButton_clicked()
{
    QString gameState = ui->gameState->text();
    qDebug().nospace().noquote()<<"<Print GameState> : "<<gameState;
}

//Intent:set the button layout
//Pre:need row and column
//Pos:set the button layout
void Game::MineSweeperGUI()
{

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            //new button object
            MyButton* button = new MyButton(this);
            //set button size
            button->setFixedSize(30, 30);
            //add button to gridLayout
            ui->gridLayout->addWidget(button,i,j);
            //connect button to leftEnter and rightEnter function
            connect(button, &MyButton::leftButtonClicked, this, [this, i,j]() { leftEnter(i, j); });
            connect(button, &MyButton::rightButtonClicked, this, [this, i,j]() { rightEnter(i, j); });
        }
    }
    adjustSize();
}

//Intent:set the left enter event
//Pre:need click button left and button y x pos
//Pos:if is f ,not to set button down,and if is not # and is not ? print failed,or bfs
void Game::leftEnter(int i,int j)
{
    if(gameBoard[i][j]=='f')
    {
        //set button no down
        QPushButton *button = qobject_cast<QPushButton *>(ui->gridLayout->itemAtPosition(i, j)->widget());
        button->setDown(false);ui->gridLayout->itemAtPosition(i,j);
    }
    if (gameBoard[i][j] != '#' && gameBoard[i][j] != '?')
    {
        //print failed
        cout << "<LeftClick " << i << " " << j << ">" << " : Failed" << endl;
    }
    else
    {
      //print success
      cout << "<LeftClick " << i << " " << j << ">" << " : Success" << endl;
      //bfs
      expandDig(i,j);
    }
}
//Intent:set the right enter event
//Pre:need click button  right and button y and x pos
//Pos:if not # and not f and not ? failed,or if f set gameBoard to ? and set icon, if ? set gameBoard to # and set icon
void Game::rightEnter(int i,int j)
{
    if (gameBoard[i][j] != '#' && gameBoard[i][j] != 'f' && gameBoard[i][j] != '?')
    {
        cout << "<RightClick " << i << " " << j << ">" << " : Failed" << endl;
    }
    else
    {
        cout << "<RightClick " << i << " " << j << ">" << " : Success" << endl;
        QPushButton *button = qobject_cast<QPushButton *>(ui->gridLayout->itemAtPosition(i, j)->widget());
       // button->setDown(true);ui->gridLayout->itemAtPosition(i,j);
         button->setText("");
        if (gameBoard[i][j] == 'f')
        {
            gameBoard[i][j] = '?';
            ui->flagCount->setText(QString::number(ui->flagCount->text().toInt()-1));
        }
        else if (gameBoard[i][j] == '?')
        {
            gameBoard[i][j] = '#';
        }
        else
        {
            gameBoard[i][j] = 'f';
            ui->flagCount->setText(QString::number(ui->flagCount->text().toInt()+1));
        }
        if(gameBoard[i][j] == '#')
        {
            button->setChecked(false);ui->gridLayout->itemAtPosition(i,j);
            button->setIcon(QIcon());
        }
        else if(gameBoard[i][j] == 'f')
        {
            button->setIcon(QIcon(":./images/flag.png"));
        }
        else if(gameBoard[i][j] == '?')
        {
            button->setIcon(QIcon(":./images/question_mark.png"));
        }
    }
}
//Intent:replay the game
//Pre:need to push the replay button
//Pos:turn to mainWindow
void Game::replayGame()
{
    qDebug().noquote().nospace()<<"<Replay> : Success";
    // 重頭開始的按鈕事件處理函式
    mainWindow->replayGame();
}





