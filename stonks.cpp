#include "stonks.h"
#include "ui_stonks.h"

stonks::stonks(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::stonks)
{
    ui->setupUi(this);

    conv = new converter();
    addn = new addnew();
}

stonks::~stonks()
{
    delete ui;
}

void stonks::on_pushButton_3_clicked()
{
    model = new QSqlQueryModel();
    model->setQuery("SELECT u.Data, d.name AS Currency, u.Kurs FROM Kursi u INNER JOIN Valuti d ON u.IDV = d.id");
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setSortingEnabled(true);
    QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(model); // create proxy
    proxyModel->setSourceModel(model);
    ui->tableView->setSortingEnabled(true); // enable sortingEnabled
    ui->tableView->setModel(proxyModel);
    ui->tableView->show();
}

void stonks::on_pushButton_4_clicked()
{
    conv->show();
}



void stonks::on_pushButton_clicked()
{
    QString val = ui->comboBox->currentText();
    QString data = ui->dateEdit->date().toString("dd.MM.yyyy");
    model = new QSqlQueryModel();
    model->setQuery("SELECT u.Data, d.name AS Currency, u.Kurs FROM Kursi u INNER JOIN Valuti d ON u.IDV = d.id WHERE d.name = '"+val+"' AND u.Data = '"+data+"'");
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
}


void stonks::on_pushButton_2_clicked()
{
    addn->show();
}

void stonks::on_pushButton_5_clicked()
{
    this->close();
    emit choiceWindow();
}
