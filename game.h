#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include "Utils.h"
#include <iostream>
using namespace std;

class MainWindow;

namespace Ui {
class Game;
}

class Game : public QWidget
{
    Q_OBJECT

public:
    explicit Game(MainWindow *parent = nullptr);
    ~Game();
    void initGame(struct gameInfo&);
    void initBoard(vector<vector<QChar>>&);
    void initAnswer(vector<vector<QChar>>&);


private slots:
    void on_gameBoardButon_clicked();

    void on_gameAnswerButton_clicked();

    void on_gameStateButton_clicked();


private:
    Ui::Game *ui;
    MainWindow* mainWindow;
    int row;
    int column;
    vector<vector<QChar>> gameBoard;
    vector<vector<QChar>> gameAnswer;
};

#endif // GAME_H
