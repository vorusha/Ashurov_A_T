#ifndef AUTH_H
#define AUTH_H

#include <QWidget>

#include <QtSql>
#include <QMessageBox>

#include <choice.h>
#include <ui_choice.h>

namespace Ui {
class auth;
}

class auth : public QWidget
{
    Q_OBJECT

public:
    explicit auth(QWidget *parent = nullptr);
    ~auth();

    QMessageBox *qmb;

    choice *kursi;

private slots:
    void on_pushButton_clicked();

private:
    Ui::auth *ui;
    QSqlDatabase bd;
};

#endif // AUTH_H
