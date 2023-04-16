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

    void on_comboBox_currentIndexChanged(int index);


    void on_gameBoardButon_clicked();

    void on_gameAnswerButton_clicked();

    void on_gameStateButton_clicked();

private:
    Ui::MainWindow *ui;

    OriginBoard *originBoard;

};
#endif // MAINWINDOW_H
