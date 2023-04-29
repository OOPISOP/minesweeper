/***********************************************************************
 * File: main.cpp
 * Author: B11115033
 * Create Date: 2023/04/16
 * Editor: B11115033
 * Update Date: 2023/04/20
 * Description: main
***********************************************************************/

//Include GUI function
//#include "MineSweeperGUI.h"
#include "mainwindow.h"
#include<iostream>
#include <QApplication>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    //new the MainWindow class
   MainWindow w;

    //show the MainWindow
    w.show();

    return a.exec();
}
