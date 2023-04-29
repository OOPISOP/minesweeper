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
#include "command.h"
#include <iostream>
#include <QApplication>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, char* argv[])
{
    cout << argc << endl;

    if (argc == 0)
    {
        std::cout << "arg error!" << std::endl;
        return 0;
    }
    else if (argc == 1)
    {
        QApplication a(argc, argv);
        //new the MainWindow class
        MainWindow w;
        //show the MainWindow
        w.show();
        return a.exec();
    }
    else if (std::string(argv[1]) == std::string("CommandFile") && argc == 4)
    {
        std::cout << "File" << std::endl;
        runCommandFile(argv[2], argv[3]);
    }
    else if (std::string(argv[1]) == std::string("CommandInput") && argc == 2)
    {
        std::cout << "Input" << std::endl;
        runCommandInput();
    }
    else if (std::string(argv[1]) == std::string("GUI") && argc == 2)
    {
        QApplication a(argc, argv);
        //new the MainWindow class
        MainWindow w;
        //show the MainWindow
        w.show();
        return a.exec();
    }
    else
    {
        std::cout << "arg error!" << std::endl;
        return 0;
    }

    return 0;
}

