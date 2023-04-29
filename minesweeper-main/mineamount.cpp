#include "mineamount.h"
#include "ui_mineamount.h"

MineAmount::MineAmount(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MineAmount)
{
    ui->setupUi(this);
}

MineAmount::~MineAmount()
{
    delete ui;
}
