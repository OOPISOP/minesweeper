/********************************************************************************
** Form generated from reading UI file 'assignboard.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASSIGNBOARD_H
#define UI_ASSIGNBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AssignBoard
{
public:
    QLabel *label_2;
    QStackedWidget *fomStackWidget;
    QWidget *page;
    QWidget *page_2;
    QSpinBox *cols;
    QLabel *label;
    QSpinBox *rows;
    QStackedWidget *stackedWidget;
    QWidget *page_3;
    QWidget *page_4;

    void setupUi(QWidget *AssignBoard)
    {
        if (AssignBoard->objectName().isEmpty())
            AssignBoard->setObjectName("AssignBoard");
        AssignBoard->resize(400, 48);
        label_2 = new QLabel(AssignBoard);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(100, 10, 41, 21));
        fomStackWidget = new QStackedWidget(AssignBoard);
        fomStackWidget->setObjectName("fomStackWidget");
        fomStackWidget->setGeometry(QRect(330, 140, 171, 21));
        page = new QWidget();
        page->setObjectName("page");
        fomStackWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        fomStackWidget->addWidget(page_2);
        cols = new QSpinBox(AssignBoard);
        cols->setObjectName("cols");
        cols->setGeometry(QRect(140, 10, 42, 22));
        label = new QLabel(AssignBoard);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 10, 51, 21));
        rows = new QSpinBox(AssignBoard);
        rows->setObjectName("rows");
        rows->setGeometry(QRect(50, 10, 42, 22));
        stackedWidget = new QStackedWidget(AssignBoard);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(200, 0, 171, 41));
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        stackedWidget->addWidget(page_4);

        retranslateUi(AssignBoard);

        QMetaObject::connectSlotsByName(AssignBoard);
    } // setupUi

    void retranslateUi(QWidget *AssignBoard)
    {
        AssignBoard->setWindowTitle(QCoreApplication::translate("AssignBoard", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("AssignBoard", "Cols :", nullptr));
        label->setText(QCoreApplication::translate("AssignBoard", "Rows :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AssignBoard: public Ui_AssignBoard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASSIGNBOARD_H
