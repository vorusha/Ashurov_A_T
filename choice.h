#ifndef CHOICE_H
#define CHOICE_H

#include <QWidget>

#include <stonks.h>
#include <ships.h>


namespace Ui {
class choice;
}

class choice : public QWidget
{
    Q_OBJECT

public:
    explicit choice(QWidget *parent = nullptr);
    ~choice();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::choice *ui;

    stonks *stonk;
    ships *ship;
};

#endif // CHOICE_H
