/***********************************************************************
 * File: game.h
 * Author: B11115033
 * Create Date: 2023/04/16
 * Editor: B11115033
 * Update Date: 2023/04/24
 * Description: define the game
***********************************************************************/
#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include "Utils.h"
#include <iostream>
#include <QGridLayout>
#include <QPushButton>
#include "QMouseEvent"
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
    //init game
    void initGame(struct gameInfo&);
    //init board
    void initBoard(vector<vector<QChar>>&);
    //init answer
    void initAnswer(vector<vector<QChar>>&);
    //set button
    void MineSweeperGUI();
    //init game state
    void initState();
    //bfs to spread button
    bool expandDig(int,int);
    //print all game board
    void printAllGameBoard();

private slots:
    //print game board
    void on_gameBoardButton_clicked();
    //print game answer
    void on_gameAnswerButton_clicked();
    //print game state
    void on_gameStateButton_clicked();
    //left click event
    void leftEnter(int i,int j);
    //right click event
    void rightEnter(int i,int j);
    //replay game
    void replayGame();



private:
    Ui::Game *ui;
    MainWindow* mainWindow;
    int row;
    int column;
    vector<vector<QChar>> gameBoard;
    vector<vector<QChar>> gameAnswer;
};

#endif // GAME_H
