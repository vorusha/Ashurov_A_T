#include "converter.h"
#include "ui_converter.h"

converter::converter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::converter)
{
    ui->setupUi(this);
}

converter::~converter()
{
    delete ui;
}

void converter::showEvent(QShowEvent *event)
{
    QSqlQuery query;

    query.prepare("SELECT MIN(Data) FROM Kursi");
    if (query.exec())
    {
        query.first();

        QString data = query.value(0).toString();
        QStringList list = data.split('-');
        data = list[1]+'.'+list[2]+'.'+list[0];

        ui->dateEdit->setMinimumDate(QDate::fromString(data, "dd.MM.yyyy"));
    }


    query.prepare("SELECT * FROM Valuti");
    if (query.exec())
    {
        query.first();
        while (!query.isNull(0))
        {
            ui->comboBox->addItem(query.value(1).toString());
            ui->comboBox_2->addItem(query.value(1).toString());
            IDto.push_back(query.value(0).toString());
            IDto.push_back(query.value(1).toString());
            IDfrom.push_back(query.value(0).toString());
            IDfrom.push_back(query.value(1).toString());
            query.next();
        }
    }
}

/*void converter::on_tableView_3_clicked(const QModelIndex &index)
{
    int temp_id;
    temp_id=ui->tableView_3->model()->data(ui->tableView_3->model()->index(index.row(),0)).toInt();
    IDfrom=temp_id;

    QSqlQuery *query = new QSqlQuery();
    query->prepare("SELECT Name FROM Valuti WHERE id = :id");
    query->bindValue(":id",temp_id);

    if (query->exec())
    {
        query->next();
        ui->lineEdit_4->setText(query->value(0).toString());
    }
}

void converter::on_tableView_2_clicked(const QModelIndex &index)
{
    int temp_id;
    temp_id=ui->tableView_2->model()->data(ui->tableView_2->model()->index(index.row(),0)).toInt();
    IDto=temp_id;

    QSqlQuery *query = new QSqlQuery();
    query->prepare("SELECT Name FROM Valuti WHERE id = :id");
    query->bindValue(":id",temp_id);

    if (query->exec())
    {
        query->next();
        ui->lineEdit_2->setText(query->value(0).toString());
    }
}*/

void converter::on_pushButton_clicked()
{
    int sum = ui->lineEdit_3->text().toInt();
    int i=0, idt, idfr;

    while(QString::compare(IDfrom[i],ui->comboBox->currentText(),Qt::CaseSensitive))
    {
        i++;
    }
    idfr=IDfrom[i-1].toInt();
    i=0;

    while(QString::compare(IDto[i],ui->comboBox_2->currentText(),Qt::CaseSensitive))
    {
        i++;
    }
    idt=IDto[i-1].toInt();

    QSqlQuery query;
    QString data = '"'+ui->dateEdit->date().toString("dd.MM.yyyy")+'"';
    query.prepare("EXEC dbo.Test_convertera :sum,:to,:from," + data);
    query.bindValue(":sum",sum);
    query.bindValue(":to",idt);
    query.bindValue(":from",idfr);

    if (query.exec())
    {
        query.prepare("SELECT * FROM dbo.Converter_rez");
        query.exec();
        query.last();
        double rez = query.value(0).toDouble();
        ui->lineEdit->setText(QString::number(rez));
    }
}
