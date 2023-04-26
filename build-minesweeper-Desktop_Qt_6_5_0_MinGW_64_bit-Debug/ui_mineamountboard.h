/********************************************************************************
** Form generated from reading UI file 'mineamountboard.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MINEAMOUNTBOARD_H
#define UI_MINEAMOUNTBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MineAmountBoard
{
public:
    QLabel *label;
    QSpinBox *bomb;
    QPushButton *pushButton;

    void setupUi(QWidget *MineAmountBoard)
    {
        if (MineAmountBoard->objectName().isEmpty())
            MineAmountBoard->setObjectName("MineAmountBoard");
        MineAmountBoard->resize(181, 36);
        label = new QLabel(MineAmountBoard);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 51, 21));
        bomb = new QSpinBox(MineAmountBoard);
        bomb->setObjectName("bomb");
        bomb->setGeometry(QRect(70, 10, 41, 22));
        pushButton = new QPushButton(MineAmountBoard);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(110, 10, 61, 21));

        retranslateUi(MineAmountBoard);

        QMetaObject::connectSlotsByName(MineAmountBoard);
    } // setupUi

    void retranslateUi(QWidget *MineAmountBoard)
    {
        MineAmountBoard->setWindowTitle(QCoreApplication::translate("MineAmountBoard", "Form", nullptr));
        label->setText(QCoreApplication::translate("MineAmountBoard", "\347\202\270\345\275\210\346\225\270\351\207\217", nullptr));
        pushButton->setText(QCoreApplication::translate("MineAmountBoard", "Load", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MineAmountBoard: public Ui_MineAmountBoard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MINEAMOUNTBOARD_H
