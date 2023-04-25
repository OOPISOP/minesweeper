/***********************************************************************
 * File: mybutton.h
 * Author: B11115033
 * Create Date: 2023/04/18
 * Editor: B11115033
 * Update Date: 2023/04/20
 * Description: define the my button extend QPushButton so that can use mouseReleaseEvent to check Left and Right
***********************************************************************/
#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QMouseEvent>
#include<QPushButton>
#include<QWidget>
class MyButton :public QPushButton
{
    Q_OBJECT
public:
     MyButton(QWidget *parent = nullptr);
    //if mouse click the button it will be called
    void mouseReleaseEvent(QMouseEvent *e);
signals:
    //if left click will be called,and imp the left button event
    void leftButtonClicked();
    //if right click will be called,and imp the right button event
    void rightButtonClicked();
};

#endif // MYBUTTON_H
