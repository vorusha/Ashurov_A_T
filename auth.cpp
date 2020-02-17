#include "auth.h"
#include "ui_auth.h"

auth::auth(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::auth)
{
    ui->setupUi(this);

    kursi = new choice();

    ui->lineEdit_4->setEchoMode(QLineEdit::Password);
    qmb = new QMessageBox();
}

auth::~auth()
{
    delete ui;
}

void auth::on_pushButton_clicked()
{
    bd = QSqlDatabase::addDatabase("QODBC");
    bd.setDatabaseName("DRIVER={SQL Server};SERVER="+ui->lineEdit->text()+";DATABASE="+ui->lineEdit_2->text()+";");
    bd.setUserName(ui->lineEdit_3->text());
    bd.setPassword(ui->lineEdit_4->text());
    qmb->setWindowTitle("Information");
    if(bd.open())
    {
        this->close();
        kursi->show();
    }
    else
    {
        qmb->setText("Error:Database did not opened");
        qmb->show();
    }
}

