/***********************************************************************
 * File: mybutton.cpp
 * Author: B11115033
 * Create Date: 2023/04/18
 * Editor: B11115033
 * Update Date: 2023/04/20
 * Description: Imp the my button extend QPushButton so that can use mouseReleaseEvent to check Left and Right
***********************************************************************/
#include "mybutton.h"
#include <QMouseEvent>

MyButton::MyButton(QWidget *parent):QPushButton(parent)
{

}
//Intent:the check the left and right button event
//Pre:need to push the button
//Pos:if push the left button it will call leftbutton fuction that know now is left click,or right click
void MyButton::mouseReleaseEvent(QMouseEvent *e)
{
    if (Qt::LeftButton == e->button())
    {
        leftButtonClicked();
    }
    else if (Qt::RightButton == e->button())
    {
        rightButtonClicked();
    }
}
