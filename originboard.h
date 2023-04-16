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
};

#endif // ORIGINBOARD_H
