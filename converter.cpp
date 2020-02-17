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
