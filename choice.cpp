#include "choice.h"
#include "ui_choice.h"

choice::choice(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::choice)
{
    ui->setupUi(this);

    stonk = new stonks();
    ship = new ships();

    connect(stonk,&stonks::choiceWindow,this,&choice::show);
    connect(ship,&ships::choiceWindow,this,&choice::show);
}

choice::~choice()
{
    delete ui;
}

void choice::on_pushButton_clicked()
{
    this->close();
    stonk->show();
}

void choice::on_pushButton_2_clicked()
{
    this->close();
    ship->show();
}
