#include "ships.h"
#include "ui_ships.h"
#include <QDebug>
#include <qmenu.h>

ships::ships(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ships)
{
    ui->setupUi(this);

    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tableView,SIGNAL(customContextMenuRequested(QPoint)),SLOT(EditMenu(QPoint)));
    fl=0;
}

ships::~ships()
{
    delete ui;
}

void ships::showEvent(QShowEvent *event)
{
    model = new QSqlQueryModel();
    model->setQuery("SELECT ID, Name, Sebestoimost AS Price, dok AS Dock FROM Sudno");
    //SELECT u.ID, u.Name, d.Name AS Tip, u.Sebestoimost, u.dok AS Dock FROM Sudno u INNER JOIN TipSudna d ON u.TipS = d.ID
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setSortingEnabled(true);
    QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(model); // create proxy
    proxyModel->setSourceModel(model);
    ui->tableView->setSortingEnabled(true); // enable sortingEnabled
    ui->tableView->setModel(proxyModel);
    ui->tableView->show();
}

void ships::on_pushButton_2_clicked()
{
    this->close();
    emit choiceWindow();
}

void ships::on_pushButton_3_clicked()
{
    model = new QSqlQueryModel();
    model->setQuery("SELECT ID, Name, Sebestoimost AS Price, dok AS Dock FROM Sudno");
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setSortingEnabled(true);
    QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(model); // create proxy
    proxyModel->setSourceModel(model);
    ui->tableView->setSortingEnabled(true); // enable sortingEnabled
    ui->tableView->setModel(proxyModel);
    ui->tableView->show();
}

void ships::EditMenu(QPoint pos)
{

        QModelIndex index=ui->tableView->indexAt(pos);
        globid = ui->tableView->model()->data(ui->tableView->model()->index(index.row(),0)).toInt();
        QMenu* menu = new QMenu(this);
        QFont font("MS Reference Sans Serif",10);
        menu->setFont(font);
        QPalette palette = menu->palette();
        palette.setColor(QPalette::Text, QColor(0, 85, 0));
        palette.setColor(QPalette::HighlightedText, QColor(154, 255, 154));
        menu->setPalette(palette);
        menu->setStyleSheet("QMenu::item:selected{"
                            "background-color: rgb(154, 255, 154);"
                            "color: rgb(0, 85, 0);"
                            "}");

        QAction* izm = new QAction("Edit",this);
        connect(izm,SIGNAL(triggered()),this,SLOT(editing()));

        menu->addAction(izm);
        menu->popup(ui->tableView->viewport()->mapToGlobal(pos));

}

void ships::editing()
{
    edi=new edit();
    connect(this,SIGNAL(sendID(int)),edi,SLOT(obrID(int)));
    emit sendID(globid);
    edi->show();

    disconnect(this,SIGNAL(sendID(int)),edi,SLOT(obrID(int)));
}
