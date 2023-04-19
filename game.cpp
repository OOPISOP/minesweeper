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
#include <QLabel>


Game::Game(MainWindow *parent) :
    QWidget(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
    mainWindow = parent;
}
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

void Game::printAllGameBoard()
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
             QPushButton *button = qobject_cast<QPushButton *>(ui->gridLayout->itemAtPosition(i, j)->widget());
            if(gameAnswer[i][j] == 'X')
            {
                QMovie *movie = new QMovie(":./animations/BombExplosion.gif");
                connect(movie, &QMovie::frameChanged, [=]{
                    button->setIcon(movie->currentPixmap());
                });
                movie->start();

            }
            else if(gameAnswer[i][j] == '0')
            {
                button->setDown(true);ui->gridLayout->itemAtPosition(i,j);
            }
            else
            {
                button->setDown(true);ui->gridLayout->itemAtPosition(i,j);
                button->setText(gameAnswer[i][j]);
            }
        }
    }
}


bool Game::expandDig(int inY, int inX)
{
    if (gameAnswer[inY][inX] == 'X')
    {
        printAllGameBoard();
        qDebug() << "Lose game";
        QDialog dialog;
        QVBoxLayout layout(&dialog);
        QHBoxLayout buttonLayout;
        QLabel label("You lose the game!", &dialog);
        layout.addWidget(&label);

        QPushButton okButton("Replay", &dialog);
        buttonLayout.addWidget(&okButton);
        QObject::connect(&okButton, &QPushButton::clicked, this, &Game::replayGame);

        QPushButton cancelButton("Quit", &dialog);
        buttonLayout.addWidget(&cancelButton);
        QObject::connect(&cancelButton, &QPushButton::clicked, qApp, &QApplication::quit);
        layout.addLayout(&buttonLayout);
        dialog.exec();

        return false;
    }
    else if (gameAnswer[inY][inX] == '0')
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
                if (gameBoard[nextY][nextX] == '0')
                {
                    continue;
                }
                QChar tot = gameAnswer[nextY][nextX];
                QPushButton *button = qobject_cast<QPushButton *>(ui->gridLayout->itemAtPosition(nextY, nextX)->widget());
                button->setDown(true);ui->gridLayout->itemAtPosition(nextY,nextX);
                if (tot != '0')
                {
                    gameBoard[nextY][nextX] = tot;
                    button->setText(tot);
                }
                else
                {
                    if(gameBoard[nextY][nextX] != 'f' && gameBoard[nextY][nextX] != '?' )
                    {
                        gameBoard[nextY][nextX] = '0';
                        que.push(pair<int, int>(nextY, nextX));
                    }
                }
            }
            if(gameBoard[y][x] != 'f' && gameBoard[y][x] != '?' )
            {
                gameBoard[y][x] = '0';
            }
            QPushButton *button = qobject_cast<QPushButton *>(ui->gridLayout->itemAtPosition(y, x)->widget());
            button->setDown(true);ui->gridLayout->itemAtPosition(y,x);
        }
    }
    else
    {
        gameBoard[inY][inX] = gameAnswer[inY][inX];
        QPushButton *button = qobject_cast<QPushButton *>(ui->gridLayout->itemAtPosition(inY, inX)->widget());
        button->setText(gameBoard[inY][inX]);
    }
    ui->remainBlankCount->setText(QString::number(getGameData(gameBoard,row,column,'#') - ui->bombCount->text().toInt()));
    ui->openBlankCount->setText(QString::number(row*column-getGameData(gameBoard,row,column,'#')));
    if(ui->remainBlankCount->text().toInt() == 0)
    {
        printAllGameBoard();
        qDebug() << "You win the game";
        QDialog dialog;
        QVBoxLayout layout(&dialog);
        QHBoxLayout buttonLayout;
        QLabel label("You win the game", &dialog);
        layout.addWidget(&label);

        QPushButton okButton("Replay", &dialog);
        buttonLayout.addWidget(&okButton);
        QObject::connect(&okButton, &QPushButton::clicked, this, &Game::replayGame);

        QPushButton cancelButton("Quit", &dialog);
        buttonLayout.addWidget(&cancelButton);
        QObject::connect(&cancelButton, &QPushButton::clicked, qApp, &QApplication::quit);
        layout.addLayout(&buttonLayout);
        dialog.exec();

        return false;
    }
    return true;
}



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

void Game::initState()
{
    ui->bombCount->setText(QString::number(getGameData(gameAnswer,row,column,'X')));
    ui->flagCount->setText(QString::number(0));
    ui->openBlankCount->setText(QString::number(0));
    ui->remainBlankCount->setText(QString::number(row*column - ui->openBlankCount->text().toInt() - ui->bombCount->text().toInt()) );
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
    QString gameState = ui->gameState->text();
    qDebug().nospace().noquote()<<"<Print GameState> : "<<gameState;
}



void Game::MineSweeperGUI()
{

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            MyButton* button = new MyButton(this);
            button->setFixedSize(50, 50);
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            ui->gridLayout->addWidget(button,i,j);
            connect(button, &MyButton::leftButtonClicked, this, [this, i,j]() { leftEnter(i, j); });
            connect(button, &MyButton::rightButtonClicked, this, [this, i,j]() { rightEnter(i, j); });
        }
    }

    adjustSize();
}


void Game::leftEnter(int i,int j)
{
    if (gameBoard[i][j] != '#' || gameBoard[i][j] == 'f')
    {
        cout << "<LeftClick " << i << " " << j << ">" << " : Failed" << endl;
    }
    else
    {
        cout << "<LeftClick " << i << " " << j << ">" << " : Success" << endl;
        expandDig(i, j);
    }
}

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
        button->setDown(true);ui->gridLayout->itemAtPosition(i,j);
        if (gameBoard[i][j] == 'f')
        {
            gameBoard[i][j] = '?';
        }
        else if (gameBoard[i][j] == '?')
        {
            gameBoard[i][j] = '#';
            ui->flagCount->setText(QString::number(ui->flagCount->text().toInt()-1));
        }
        else
        {
            gameBoard[i][j] = 'f';
            ui->flagCount->setText(QString::number(ui->flagCount->text().toInt()+1));
        }
        if(gameBoard[i][j] == '#')
        {
            button->setChecked(false);ui->gridLayout->itemAtPosition(i,j);
            button->setText("");
        }
        else
        {
            button->setText(gameBoard[i][j]);
        }
    }
}


void Game::replayGame()
{
    // 重頭開始的按鈕事件處理函式

        QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
        qApp->quit();

}

