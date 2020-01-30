#include "addnew.h"
#include "ui_addnew.h"
#include<QDebug>

addnew::addnew(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addnew)
{
    ui->setupUi(this);
}

addnew::~addnew()
{
    delete ui;
}

void addnew::showEvent(QShowEvent *event)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM Valuti");
    int i = 1;
    if (query.exec())
    {
        query.first();
        while (!query.isNull(0))
        {
            ui->comboBox->addItem(QString::number(i) + ". " + query.value(1).toString());
            i++;
            query.next();
        }
    }
}



void addnew::on_pushButton_clicked()
{
    QSqlQuery query;
    QString data ="'" + ui->dateEdit->date().toString("dd.MM.yyyy") + "'";
    int idv = ui->comboBox->currentText().split(".")[0].toInt();
    double kurs = ui->doubleSpinBox->value();
    query.prepare("INSERT INTO Kursi (Data,IDV,Kurs) VALUES ("+data+","+QString::number(idv)+","+QString::number(kurs)+")");
    qDebug() << "INSERT INTO Kursi (Data,IDV,Kurs) VALUES ("+data+","+QString::number(idv)+","+QString::number(kurs)+")";
    query.exec();
    this->close();
}
