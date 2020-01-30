#ifndef ADDNEW_H
#define ADDNEW_H

#include <QWidget>

#include <QSqlQuery>

namespace Ui {
class addnew;
}

class addnew : public QWidget
{
    Q_OBJECT

public:
    explicit addnew(QWidget *parent = nullptr);
    ~addnew();

private slots:
    void on_pushButton_clicked();

private:
    Ui::addnew *ui;
    void showEvent(QShowEvent *event);
};

#endif // ADDNEW_H
