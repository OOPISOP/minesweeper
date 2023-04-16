/***********************************************************************
 * File: mainwindo.h
 * Author: B11115033
 * Create Date: 2023/04/16
 * Editor: B11115033
 * Update Date: 2023/04/16
 * Description: Imp the main window
***********************************************************************/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QWidget>
#include <QMainWindow>
#include "originboard.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    //get thecurrent index,when the comboBox index change
    void on_comboBox_currentIndexChanged(int index);
    //print the game board
    void on_gameBoardButon_clicked();
    //print the answer board
    void on_gameAnswerButton_clicked();
    //print the game state
    void on_gameStateButton_clicked();

private:
    // main window ui
    Ui::MainWindow *ui;
    // current board index
    int boardIndex;
    // OriginBoard class
    OriginBoard *originBoard;

};
#endif // MAINWINDOW_H
