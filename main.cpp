#include "mainwindow.h"
#include<iostream>
#include <QApplication>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
