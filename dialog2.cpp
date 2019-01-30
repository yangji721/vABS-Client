#include "dialog2.h"
#include "ui_dialog2.h"

Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setStretchLastSection(QHeaderView::Stretch);
    ui->tableWidget_2->horizontalHeader()->setStretchLastSection(QHeaderView::Stretch);
}

Dialog2::~Dialog2()
{
    delete ui;
}

void Dialog2::transmit(QString teemo)
{
    ui->tableWidget->setItem(0,0,new QTableWidgetItem(teemo));
}

