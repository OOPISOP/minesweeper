#pragma once
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtCore/QObject>
#include <QtCore/QDebug>

class MineSweeperGUI : public QWidget
{
	Q_OBJECT

public:
	MineSweeperGUI(int rows, int cols, int minus, QWidget* parent = nullptr);
    void changeText() {
		QPushButton* button = qobject_cast<QPushButton*>(sender());
		if (button) { button->setText("q"); }
	}
private:
	int mines;
	int rows;
	int cols;
};
