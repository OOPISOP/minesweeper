#ifndef MINEAMOUNT_H
#define MINEAMOUNT_H

#include <QWidget>

namespace Ui {
class MineAmount;
}

class MineAmount : public QWidget
{
    Q_OBJECT

public:
    explicit MineAmount(QWidget *parent = nullptr);
    ~MineAmount();

private:
    Ui::MineAmount *ui;
};

#endif // MINEAMOUNT_H
