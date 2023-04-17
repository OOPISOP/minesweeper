/***********************************************************************
 * File: originboard.h
 * Author: B11115033
 * Create Date: 2023/04/16
 * Editor: B11115033
 * Update Date: 2023/04/16
 * Description: define the origin board
***********************************************************************/
#ifndef ORIGINBOARD_H
#define ORIGINBOARD_H

#include <QWidget>
#include <vector>
#include <QFileInfo>
#include <iostream>
using namespace std;
namespace Ui {
class OriginBoard;
}

class OriginBoard : public QWidget
{
    Q_OBJECT

public:
    explicit OriginBoard(QWidget *parent = nullptr);
    ~OriginBoard();
    //load the file data
    void load(QTextStream);
    //init game board
    void initBoard();
    //print game board
    void printGameBoard();
    //print answer board
    void printAnswer();
    //init answer board
    void initAnswer(QTextStream&);
    // Print the amount of bomb inserted in map.
    void printBombCount();
    // Print the number of flags inserted in map.
    void printFlagCount();
    // Print the number of blanks opened in map.
    void printOpenBlankCount();
    // Print the number of blanks remaind in map.
    void printRemainBlankCount();

private slots:
    //when push will load file data ,and init game and answer board
    void on_loadButton_clicked();

private:
    //get ui
    Ui::OriginBoard *ui;
    //game board vector
    vector<vector<QChar>> gameBoard;
    //answer board vector
    vector<vector<QChar>> gameAnswer;
    //board row
    int row;
    //board column
    int column;
    // The amount of bomb inserted in map.
    unsigned int bombCount = 0;
    // The number of flags inserted in map.
    unsigned int flagCount = 0;
    // The number of blanks opened in map.
    unsigned int openBlankCount = 0;
    // The number of blanks remaind in map.
    unsigned int remainBlankCount = 0;
};

#endif // ORIGINBOARD_H
