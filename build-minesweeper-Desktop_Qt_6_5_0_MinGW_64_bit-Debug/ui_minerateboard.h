/********************************************************************************
** Form generated from reading UI file 'minerateboard.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MINERATEBOARD_H
#define UI_MINERATEBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MineRateBoard
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QDoubleSpinBox *rate;

    void setupUi(QWidget *MineRateBoard)
    {
        if (MineRateBoard->objectName().isEmpty())
            MineRateBoard->setObjectName("MineRateBoard");
        MineRateBoard->resize(209, 39);
        pushButton = new QPushButton(MineRateBoard);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(130, 10, 61, 21));
        label = new QLabel(MineRateBoard);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 71, 21));
        rate = new QDoubleSpinBox(MineRateBoard);
        rate->setObjectName("rate");
        rate->setGeometry(QRect(80, 10, 42, 22));

        retranslateUi(MineRateBoard);

        QMetaObject::connectSlotsByName(MineRateBoard);
    } // setupUi

    void retranslateUi(QWidget *MineRateBoard)
    {
        MineRateBoard->setWindowTitle(QCoreApplication::translate("MineRateBoard", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("MineRateBoard", "Load", nullptr));
        label->setText(QCoreApplication::translate("MineRateBoard", "\347\202\270\345\275\210\347\224\237\346\210\220\347\216\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MineRateBoard: public Ui_MineRateBoard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MINERATEBOARD_H
