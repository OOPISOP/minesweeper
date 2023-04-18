#ifndef STARTUI_H
#define STARTUI_H

#include <QWidget>
#include<QWidget>
#include <QMainWindow>
#include "originboard.h"
#include "assignboard.h"
#include "Utils.h"

class MainWindow;

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
