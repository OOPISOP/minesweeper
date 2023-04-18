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

    void mouseReleaseEvent(QMouseEvent *e);
signals:
    void leftButtonClicked();
    void rightButtonClicked();
};

#endif // MYBUTTON_H
