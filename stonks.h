#ifndef STONKS_H
#define STONKS_H

#include <QMainWindow>

#include <QSqlQueryModel>
#include <QSortFilterProxyModel>

#include <converter.h>
#include <ui_converter.h>
#include <addnew.h>
#include <ui_addnew.h>

namespace Ui {
class stonks;
}

class stonks : public QMainWindow
{
    Q_OBJECT

public:
    explicit stonks(QWidget *parent = nullptr);
    ~stonks();

    converter *conv;
    addnew *addn;

signals:
    void choiceWindow();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::stonks *ui;
    QSqlQueryModel *model;
};

#endif // STONKS_H
