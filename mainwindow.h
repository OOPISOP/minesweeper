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
#include "Utils.h"

class StartUI;
class Game;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //start game
    void startGame(struct gameInfo);
    //replay game
    void replayGame();

private slots:



private:
    // main window ui
    Ui::MainWindow *ui;
    StartUI *startUI;
    Game *game;
};
#endif // MAINWINDOW_H
