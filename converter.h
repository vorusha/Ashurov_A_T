#ifndef CONVERTER_H
#define CONVERTER_H

#include <QWidget>

#include <QSqlQuery>
#include <QSqlQueryModel>

#include <QString>
#include <QDate>

namespace Ui {
class converter;
}

class converter : public QWidget
{
    Q_OBJECT

public:
    explicit converter(QWidget *parent = nullptr);
    ~converter();

    QVector<QString> IDto;
    QVector<QString> IDfrom;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::converter *ui;
    QSqlQueryModel *model;
    void showEvent(QShowEvent *event);
};

#endif // CONVERTER_H
