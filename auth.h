#ifndef AUTH_H
#define AUTH_H

#include <QWidget>

#include <QtSql>
#include <QMessageBox>

#include <stonks.h>
#include <ui_stonks.h>

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

    stonks *kursi;

private slots:
    void on_pushButton_clicked();

private:
    Ui::auth *ui;
    QSqlDatabase bd;
};

#endif // AUTH_H
