/********************************************************************************
** Form generated from reading UI file 'originboard.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORIGINBOARD_H
#define UI_ORIGINBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OriginBoard
{
public:
    QLineEdit *boardPath;
    QPushButton *loadButton;
    QLabel *label_4;

    void setupUi(QWidget *OriginBoard)
    {
        if (OriginBoard->objectName().isEmpty())
            OriginBoard->setObjectName("OriginBoard");
        OriginBoard->resize(360, 44);
        boardPath = new QLineEdit(OriginBoard);
        boardPath->setObjectName("boardPath");
        boardPath->setGeometry(QRect(90, 10, 121, 21));
        loadButton = new QPushButton(OriginBoard);
        loadButton->setObjectName("loadButton");
        loadButton->setGeometry(QRect(230, 10, 60, 32));
        label_4 = new QLabel(OriginBoard);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 10, 81, 16));

        retranslateUi(OriginBoard);

        QMetaObject::connectSlotsByName(OriginBoard);
    } // setupUi

    void retranslateUi(QWidget *OriginBoard)
    {
        OriginBoard->setWindowTitle(QCoreApplication::translate("OriginBoard", "Form", nullptr));
        boardPath->setText(QCoreApplication::translate("OriginBoard", "./boards/board1.txt", nullptr));
        loadButton->setText(QCoreApplication::translate("OriginBoard", "Load", nullptr));
        label_4->setText(QCoreApplication::translate("OriginBoard", "\347\233\244\351\235\242\346\252\224\344\275\215\347\275\256\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OriginBoard: public Ui_OriginBoard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORIGINBOARD_H
