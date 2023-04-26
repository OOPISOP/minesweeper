/********************************************************************************
** Form generated from reading UI file 'startui.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTUI_H
#define UI_STARTUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartUI
{
public:
    QLabel *label_2;
    QLabel *gameState;
    QLabel *label;
    QComboBox *comboBox;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;
    QPushButton *gameBoardButon;
    QPushButton *gameAnswerButton;
    QPushButton *gameStateButton;
    QPushButton *startGameButton;

    void setupUi(QWidget *StartUI)
    {
        if (StartUI->objectName().isEmpty())
            StartUI->setObjectName("StartUI");
        StartUI->resize(481, 243);
        label_2 = new QLabel(StartUI);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(12, 12, 80, 16));
        gameState = new QLabel(StartUI);
        gameState->setObjectName("gameState");
        gameState->setGeometry(QRect(100, 12, 50, 16));
        label = new QLabel(StartUI);
        label->setObjectName("label");
        label->setGeometry(QRect(12, 41, 67, 16));
        comboBox = new QComboBox(StartUI);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(84, 39, 172, 32));
        stackedWidget = new QStackedWidget(StartUI);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(11, 81, 459, 56));
        page = new QWidget();
        page->setObjectName("page");
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);
        gameBoardButon = new QPushButton(StartUI);
        gameBoardButon->setObjectName("gameBoardButon");
        gameBoardButon->setGeometry(QRect(12, 147, 132, 32));
        gameAnswerButton = new QPushButton(StartUI);
        gameAnswerButton->setObjectName("gameAnswerButton");
        gameAnswerButton->setGeometry(QRect(158, 147, 141, 32));
        gameStateButton = new QPushButton(StartUI);
        gameStateButton->setObjectName("gameStateButton");
        gameStateButton->setGeometry(QRect(313, 147, 128, 32));
        startGameButton = new QPushButton(StartUI);
        startGameButton->setObjectName("startGameButton");
        startGameButton->setGeometry(QRect(180, 190, 95, 32));

        retranslateUi(StartUI);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(StartUI);
    } // setupUi

    void retranslateUi(QWidget *StartUI)
    {
        StartUI->setWindowTitle(QCoreApplication::translate("StartUI", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("StartUI", "GameState\357\274\232", nullptr));
        gameState->setText(QCoreApplication::translate("StartUI", "Standby", nullptr));
        label->setText(QCoreApplication::translate("StartUI", "\350\274\211\345\205\245\351\241\236\345\236\213\357\274\232", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("StartUI", "\347\233\244\351\235\242\346\252\224", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("StartUI", "\346\214\207\345\256\232\347\202\270\345\275\210\346\225\270\351\207\217\347\233\244\351\235\242", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("StartUI", "\346\214\207\345\256\232\347\202\270\345\275\210\347\224\237\346\210\220\347\216\207\347\233\244\351\235\242", nullptr));

        gameBoardButon->setText(QCoreApplication::translate("StartUI", "Print GameBoard", nullptr));
        gameAnswerButton->setText(QCoreApplication::translate("StartUI", "Print GameAnswer", nullptr));
        gameStateButton->setText(QCoreApplication::translate("StartUI", "Print GameState", nullptr));
        startGameButton->setText(QCoreApplication::translate("StartUI", "StartGame", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartUI: public Ui_StartUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTUI_H
