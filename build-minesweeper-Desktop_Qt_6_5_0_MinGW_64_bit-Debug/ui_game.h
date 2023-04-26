/********************************************************************************
** Form generated from reading UI file 'game.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Game
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *gameState;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLabel *bombCount;
    QLabel *label_8;
    QLabel *flagCount;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QLabel *openBlankCount;
    QLabel *label_10;
    QLabel *remainBlankCount;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *gameBoardButton;
    QPushButton *gameAnswerButton;
    QPushButton *gameStateButton;
    QGridLayout *gridLayout;

    void setupUi(QWidget *Game)
    {
        if (Game->objectName().isEmpty())
            Game->setObjectName("Game");
        Game->resize(499, 364);
        gridLayout_2 = new QGridLayout(Game);
        gridLayout_2->setObjectName("gridLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(Game);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        gameState = new QLabel(Game);
        gameState->setObjectName("gameState");

        horizontalLayout->addWidget(gameState);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_4 = new QLabel(Game);
        label_4->setObjectName("label_4");

        horizontalLayout_2->addWidget(label_4);

        bombCount = new QLabel(Game);
        bombCount->setObjectName("bombCount");

        horizontalLayout_2->addWidget(bombCount);

        label_8 = new QLabel(Game);
        label_8->setObjectName("label_8");

        horizontalLayout_2->addWidget(label_8);

        flagCount = new QLabel(Game);
        flagCount->setObjectName("flagCount");

        horizontalLayout_2->addWidget(flagCount);


        gridLayout_2->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_6 = new QLabel(Game);
        label_6->setObjectName("label_6");

        horizontalLayout_3->addWidget(label_6);

        openBlankCount = new QLabel(Game);
        openBlankCount->setObjectName("openBlankCount");

        horizontalLayout_3->addWidget(openBlankCount);

        label_10 = new QLabel(Game);
        label_10->setObjectName("label_10");

        horizontalLayout_3->addWidget(label_10);

        remainBlankCount = new QLabel(Game);
        remainBlankCount->setObjectName("remainBlankCount");

        horizontalLayout_3->addWidget(remainBlankCount);


        gridLayout_2->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        gameBoardButton = new QPushButton(Game);
        gameBoardButton->setObjectName("gameBoardButton");

        horizontalLayout_4->addWidget(gameBoardButton);

        gameAnswerButton = new QPushButton(Game);
        gameAnswerButton->setObjectName("gameAnswerButton");

        horizontalLayout_4->addWidget(gameAnswerButton);

        gameStateButton = new QPushButton(Game);
        gameStateButton->setObjectName("gameStateButton");

        horizontalLayout_4->addWidget(gameStateButton);


        gridLayout_2->addLayout(horizontalLayout_4, 3, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        gridLayout->setSizeConstraint(QLayout::SetFixedSize);

        gridLayout_2->addLayout(gridLayout, 4, 0, 1, 1);


        retranslateUi(Game);

        QMetaObject::connectSlotsByName(Game);
    } // setupUi

    void retranslateUi(QWidget *Game)
    {
        Game->setWindowTitle(QCoreApplication::translate("Game", "Form", nullptr));
        label->setText(QCoreApplication::translate("Game", "GameState :", nullptr));
        gameState->setText(QCoreApplication::translate("Game", "Playing", nullptr));
        label_4->setText(QCoreApplication::translate("Game", "Bomb Count :", nullptr));
        bombCount->setText(QCoreApplication::translate("Game", "0", nullptr));
        label_8->setText(QCoreApplication::translate("Game", "Flag Count :", nullptr));
        flagCount->setText(QCoreApplication::translate("Game", "0", nullptr));
        label_6->setText(QCoreApplication::translate("Game", "Open Blank Count :", nullptr));
        openBlankCount->setText(QCoreApplication::translate("Game", "0", nullptr));
        label_10->setText(QCoreApplication::translate("Game", "Remain Blank Count :", nullptr));
        remainBlankCount->setText(QCoreApplication::translate("Game", "0", nullptr));
        gameBoardButton->setText(QCoreApplication::translate("Game", "Print GameBoard", nullptr));
        gameAnswerButton->setText(QCoreApplication::translate("Game", "Print GameAnswer", nullptr));
        gameStateButton->setText(QCoreApplication::translate("Game", "Print GameState", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Game: public Ui_Game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
