#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H
#include "QPushButton"
#include "QMouseEvent"
#include <iostream>
#include <vector>
#include <QMouseEvent>
#include <QAbstractButton>
#include "MyPushButton.h"
#include <queue>
#include <QCoreApplication>
#include <QApplication>
#include <QAbstractEventDispatcher>
using namespace std;
bool expandDig(vector<vector<QChar>>& map, vector<vector<QChar>> answer, int inY, int inX)
{
    if (answer[inY][inX] == 'X')
    {
        qDebug() <<  "Lose game";
        return false;
    }
    else if (answer[inY][inX] == '0')
    {
        // The input surround poistion
        int dir[8][2] = { -1, -1, 0, -1, 1, -1, 1, 0, 1, 1, 0, 1, -1, 1, -1, 0 };

        queue<pair<int, int>> que;
        que.push(pair<int, int>(inY, inX));
        while (!que.empty()) {
            int y = que.front().first;
            int x = que.front().second;
            que.pop();
            for (int i = 0; i < 8; i++) {
                int nextY = y + dir[i][0];
                int nextX = x + dir[i][1];
                if (nextX < 0 || nextY < 0 || nextY >= answer.size() || nextX >= answer[0].size())
                    continue;
                if (map[nextY][nextX] == '0')
                {
                    continue;
                }
                QChar tot = answer[nextY][nextX];
                if (tot != '0')
                {
                    map[nextY][nextX] = tot;
                }
                else
                {
                    map[nextY][nextX] = '0';
                    que.push(pair<int, int>(nextY, nextX));

                }
            }
        }
    }
    else
    {
        map[inY][inX] = answer[inY][inX];
    }
    return true;
}

using namespace std;
class MyPushButton : public QPushButton
{
public:
    MyPushButton(QWidget *parent = nullptr, vector<vector<QChar>>& gameBoard, vector<vector<QChar>>& gameAnswer, int inY, int inX) :
        QPushButton(parent),
        gameBoard(gameBoard),
        gameAnswer(gameAnswer)
    {
        this->inY = inY;
        this->inX = inX;
    }
//     void enterLeft(vector<vector<QChar>>& gameBoard,vector<vector<QChar>>& gameAnswer,int inY,int inX);

private:
    vector<vector<QChar>>& gameBoard;
    vector<vector<QChar>>& gameAnswer;
    int inY;
    int inX;
protected:
    void mousePressEvent(QMouseEvent *event) override
    {
        if (event->button() == Qt::LeftButton) {
            // 左鍵按下的處理
            if (gameBoard[inY][inX] != '#' || gameBoard[inY][inX] == 'f')
            {
                qDebug() <<  "<LeftClick " << inY << " " << inX << ">" << " : Failed";
            }
            else
            {
                qDebug() << "<LeftClick " << inY << " " << inX << ">" << " : Success";
                expandDig(gameBoard, gameAnswer, inY, inX);
            }
        }
        else if (event->button() == Qt::RightButton) {
            // 右鍵按下的處理
        }
        QPushButton::mousePressEvent(event);
    }
};

#endif // MYPUSHBUTTON_H
