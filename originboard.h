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
    void load(QTextStream);
    void initBoard();
    void printGameBoard();
    void printAnswer();
    void initAnswer(QTextStream&);

private slots:
    void on_loadButton_clicked();

private:
    Ui::OriginBoard *ui;
    vector<vector<QChar>> gameBoard;
    vector<vector<QChar>> gameAnswer;
    int row;
    int column;
};

#endif // ORIGINBOARD_H
