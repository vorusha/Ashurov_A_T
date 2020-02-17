#ifndef SHIPS_H
#define SHIPS_H

#include <QWidget>

#include <QSqlQueryModel>
#include <QSortFilterProxyModel>

#include "edit.h"
#include "ui_edit.h"

namespace Ui {
class ships;
}

class ships : public QWidget
{
    Q_OBJECT

public:
    explicit ships(QWidget *parent = nullptr);
    ~ships();

    int globid,fl;
    edit* edi;

signals:
    void choiceWindow();

    void sendID(int);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void EditMenu(QPoint);

    void editing();

private:
    Ui::ships *ui;
    QSqlQueryModel *model;
    void showEvent(QShowEvent *event);
};

#endif // SHIPS_H
