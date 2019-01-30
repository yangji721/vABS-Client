#include "dialog.h"
#include "ui_dialog.h"
#include <QStandardItemModel>
#include <QStandardItem>
#include <QTreeWidgetItem>
#include <QTreeWidget>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //ui->tableWidget_2->horizontalHeader()->setStretchLastSection(QHeaderView::Stretch);
    //ui->tableWidget_2->verticalHeader()->setStretchLastSection(QHeaderView::Stretch);
/*
    QStandardItemModel *model = new QStandardItemModel(ui->treeView);
    model->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("VO Information"));

    QList<QStandardItem*> items1;
    QStandardItem* item1 = new QStandardItem(QStringLiteral("root signature"));
    items1.append(item1);
    model->appendRow(items1);
*/
    ui->treeWidget->setColumnCount(1);
    ui->treeWidget->setHeaderLabel(tr("VO Structure"));
    ui->treeWidget->header()->setDefaultAlignment(Qt::AlignCenter);

    //QTreeWidgetItem *imageItem1 = new QTreeWidgetItem(ui->treeWidget,QStringList(QString("Root Signature: dc400F5271d7ba08F929F7F3881a18508d4a0bd0")));
    //imageItem1->setIcon(0,QIcon("/home/yang/Pictures/demo/text.svg"));

    //QTreeWidgetItem *imageItem1_1 = new QTreeWidgetItem(imageItem1,QStringList(QString("Band1")));
    //imageItem1->addChild(imageItem1_1);

    QTreeWidgetItem *imageItem2 = new QTreeWidgetItem(ui->treeWidget,QStringList(QString("Root Node")));
    QTreeWidgetItem *imageItem2_3 = new QTreeWidgetItem(imageItem2,QStringList(QString("Grid Signature: cE92728a6713450F295F7b927664dEaa675ab5da")));
    QTreeWidgetItem *imageItem2_1 = new QTreeWidgetItem(imageItem2,QStringList(QString("Child Nodes")));

    imageItem2_3->setIcon(0,QIcon("/Users/scaryang/Desktop/Interface/build-demo-Desktop-Debug/text.svg"));

    imageItem2->setIcon(0,QIcon("/Users/scaryang/Desktop/Interface/build-demo-Desktop-Debug/folder.svg"));
    imageItem2_1->setIcon(0,QIcon("/Users/scaryang/Desktop/Interface/build-demo-Desktop-Debug/folder.svg"));
    QTreeWidgetItem *imageItem2_2 = new QTreeWidgetItem(imageItem2_1,QStringList(QString("Grid Signature: c0a4bbc2c55816dF18cE5619abcdF5d8")));
    imageItem2_2->setIcon(0,QIcon("/Users/scaryang/Desktop/Interface/build-demo-Desktop-Debug/text.svg"));
    imageItem2->addChild(imageItem2_1);
    imageItem2->addChild(imageItem2_3);
    imageItem2_1->addChild(imageItem2_2);
    imageItem2_1->setIcon(0,QIcon("/Users/scaryang/Desktop/Interface/build-demo-Desktop-Debug/folder.svg"));

    QTreeWidgetItem *imageItem2_4 = new QTreeWidgetItem(imageItem2,QStringList(QString("Child Nodes")));
    imageItem2_4->setIcon(0,QIcon("/Users/scaryang/Desktop/Interface/build-demo-Desktop-Debug/folder.svg"));
    imageItem2->addChild(imageItem2_4);

    //QTreeWidgetItem *imageItem3_1 = new QTreeWidgetItem(imageItem2_4,QStringList(QString("Grid Signature: 27316ba3dc0a4bbc2c55816d99bb5E849cb0a456")));
    //imageItem3_1->setIcon(0,QIcon("/home/yang/Pictures/demo/text.svg"));
    //imageItem2_4->addChild(imageItem3_1);

    QTreeWidgetItem *imageItem3_2 = new QTreeWidgetItem(imageItem2_4,QStringList(QString("Child Nodes")));
    imageItem3_2->setIcon(0,QIcon("/Users/scaryang/Desktop/Interface/build-demo-Desktop-Debug/folder.svg"));
    imageItem2_4->addChild(imageItem3_2);

    QTreeWidgetItem *imageItem4_2 = new QTreeWidgetItem(imageItem3_2,QStringList(QString("Record Signature: E451d2032085bF18cE5619ab946bcdF5d8b3dE20")));
    imageItem4_2->setIcon(0,QIcon("/Users/scaryang/Desktop/Interface/build-demo-Desktop-Debug/text.svg"));
    imageItem4_2->addChild(imageItem3_2);

    QTreeWidgetItem *imageItem3_3 = new QTreeWidgetItem(imageItem2_4,QStringList(QString("Child Nodes")));
    imageItem3_3->setIcon(0,QIcon("/Users/scaryang/Desktop/Interface/build-demo-Desktop-Debug/folder.svg"));
    imageItem2_4->addChild(imageItem3_3);

    QTreeWidgetItem *imageItem4_1 = new QTreeWidgetItem(imageItem3_3,QStringList(QString("Record Signature: F6d2a86544626EF4aE2284b43EE4615F974E97F7")));
    imageItem4_1->setIcon(0,QIcon("/Users/scaryang/Desktop/Interface/build-demo-Desktop-Debug/text.svg"));
    imageItem3_3->addChild(imageItem4_1);
    ui->treeWidget->expandAll();

    ui->textBrowser->setText(tr("87 ms"));
    ui->textBrowser->setAlignment(Qt::AlignCenter|Qt::AlignBottom|Qt::AlignHCenter);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::AddRoot(QString name, QString Description)
{
    QTreeWidgetItem *itm = new QTreeWidgetItem(ui->treeWidget);
    itm->setText(0,name);
    itm->setText(1,Description);
    ui->treeWidget->addTopLevelItem(itm);
}

void Dialog::AddChild(QTreeWidgetItem *parent, QString name, QString Description)
{
    QTreeWidgetItem *itm = new QTreeWidgetItem();
    itm->setText(0,name);
    itm->setText(1,Description);
    parent->addChild(itm);
}
