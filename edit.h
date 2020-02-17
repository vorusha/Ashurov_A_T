#ifndef EDIT_H
#define EDIT_H

#include <QWidget>
#include <QSqlQuery>

namespace Ui {
class edit;
}

class edit : public QWidget
{
    Q_OBJECT

public:
    explicit edit(QWidget *parent = nullptr);
    ~edit();

private slots:
    void obrID(int);


    void on_pushButton_clicked();

private:
    Ui::edit *ui;
};

#endif // EDIT_H
