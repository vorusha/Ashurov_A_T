#include "edit.h"
#include "ui_edit.h"



edit::edit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::edit)
{
    ui->setupUi(this);
}

edit::~edit()
{
    delete ui;
}

void edit::obrID(int id)
{
    QSqlQuery* query = new QSqlQuery();
    query->prepare("SELECT Name,Sebestoimost FROM Sudno WHERE ID=:id");
    query->bindValue(":id",id);

    if(query->exec())
    {
        query->first();
        ui->lineEdit_3->setText(QString::number(id));
        ui->lineEdit->setText(query->value(0).toString());
        ui->lineEdit_2->setText(query->value(1).toString());
    }
}

void edit::on_pushButton_clicked()
{
    QSqlQuery* query = new QSqlQuery();
    query->prepare("UPDATE Sudno SET Name=:name, Sebestoimost=:price WHERE id=:id");
    query->bindValue(":name",ui->lineEdit->text());
    query->bindValue(":price",ui->lineEdit_2->text());
    query->bindValue(":id",ui->lineEdit_3->text().toInt());

    if(query->exec())
    {

    }
}
