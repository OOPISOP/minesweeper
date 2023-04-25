/***********************************************************************
 * File: startui.h
 * Author: B11115033
 * Create Date: 2023/04/18
 * Editor: B11115033
 * Update Date: 2023/04/20
 * Description: define the startui class ,it is the first ui we  see
***********************************************************************/
#ifndef STARTUI_H
#define STARTUI_H

#include <QWidget>
#include<QWidget>
#include <QMainWindow>
#include "originboard.h"
#include "assignboard.h"
#include <QGridLayout>
#include <QPushButton>
#include "Utils.h"

class MainWindow;
class AssignBoard;

namespace Ui {
class StartUI;
}

class StartUI : public QWidget
{
    Q_OBJECT

public:
    explicit StartUI(MainWindow *parent = nullptr);
    ~StartUI();
    void setBoard(struct gameInfo);
    void initBoard(vector<vector<QChar>>&);
    void initAnswer(vector<vector<QChar>>&);
    struct gameInfo getGameInfo();
    //print game board
    void printGameBoard();
    //print answer board
    void printAnswer();
    void setLoadState(bool state);

private slots:

    //get thecurrent index,when the comboBox index change
    void on_comboBox_currentIndexChanged(int index);
    //print the game board
    void on_gameBoardButon_clicked();
    //print the answer board
    void on_gameAnswerButton_clicked();
    //print the game state
    void on_gameStateButton_clicked();
    void on_startGameButton_clicked();

private:
    Ui::StartUI *ui;
    MainWindow *mainWindow;
    // current board index
    int boardIndex;
    // OriginBoard class
    OriginBoard *originBoard;
    AssignBoard *assignBoard;
    int row;
    int column;
    vector<vector<QChar>> gameBoard;
    vector<vector<QChar>> gameAnswer;
    bool loadState = false;
};

#endif // STARTUI_H
