#include "mybutton.h"
#include <QMouseEvent>

MyButton::MyButton(QWidget *parent):QPushButton(parent)
{

}


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
