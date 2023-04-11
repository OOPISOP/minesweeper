#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QFileInfo>
#include<iostream>
#include <QDebug>

using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
//Intent:when the comboBox current index changed ,changed the model
//Pre:tarnsform into index
void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    QString text = ui->comboBox->currentText();
}
//Intent:when clicked the loadButton,check  filepath ,and output Load BoardFile Success,or not
void MainWindow::on_loadButton_clicked()
{
    //fetch filePath from boardPath lineEdit
    QString filePath = ui->boardPath->text();
    //add filePath
    QFileInfo fi(":"+filePath);
    //check file,if file exist output Success,or output Failed
    if(fi.isFile())
    {
        qDebug().nospace().noquote()<<"<Load BoardFile "+ QString(filePath) + "> : " + "Success";
    }
    else
    {
        qDebug().nospace().noquote()<<"<Load BoardFile "+ QString(filePath) + "> : " + "Failed";
    }
}

