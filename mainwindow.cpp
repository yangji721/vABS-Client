#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "logindialog.h"
#include <string>
#include <QTextCodec>
#include "dialog.h"
#include "dialog2.h"
#include <QtCore/QCoreApplication>
#include <qdatetime.h>
#include <QTimer>
#include "pbutton.h"
#include <QHBoxLayout>
#include <iostream>
#include <fstream>

using namespace std;

MainWindow::MainWindow(QString temp,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Display login information
    string login;
    {
        ifstream fin("login.txt");
        fin >> login;
    }
    QString Qlogin = QString::fromStdString(login);
    ui->label_4->setText("Welcome "+Qlogin);

    QPixmap mypixmap;
    mypixmap.load(tr("/Users/scaryang/Desktop/Interface/build-demo-Desktop-Debug/outline-info-24px.svg"));
/*
    ui->mainexit_2->clearMask();
    ui->mainexit_2->setBackgroundRole(QPalette::Base);
    ui->mainexit_2->setFixedSize(mypixmap.width(),mypixmap.height());
    ui->mainexit_2->setIcon(mypixmap);
    ui->mainexit_2->setIconSize(QSize(mypixmap.width(),mypixmap.height()));
    ui->mainexit_2->setFlat(true);
*/

    //add search action icon
    QAction *searchAction = new QAction(ui->pidlineEdit);
    searchAction->setIcon(QIcon("/Users/scaryang/Desktop/Interface/build-demo-Desktop-Debug/query.svg"));
    ui->pidlineEdit->addAction(searchAction,QLineEdit::LeadingPosition);
    ui->pidlineEdit_2->addAction(searchAction,QLineEdit::LeadingPosition);
    ui->aidlineEdit->addAction(searchAction,QLineEdit::LeadingPosition);
    ui->aidlineEdit_2->addAction(searchAction,QLineEdit::LeadingPosition);
    ui->aidlineEdit_3->addAction(searchAction,QLineEdit::LeadingPosition);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerUpdate()));
    timer->start(1000);

    ui->widget->setStyleSheet("background-color:rgb(220,220,220)");

    //set tablewidget table aligned
    ui->tableWidget->horizontalHeader()->setStretchLastSection(QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->pidlineEdit->clear();
    ui->aidlineEdit->clear();
    ui->pidlineEdit->setFocus();
    ui->vbutton->setIcon(QIcon());
}

//equality query button
void MainWindow::on_querybtn_clicked()
{
    if (ui->pidlineEdit->text().isEmpty()||ui->aidlineEdit->text().isEmpty())
    {
        QMessageBox::warning(this,tr("warning"),tr("Query information can not be empty!"));
        return;
    }
    querypid = ui->pidlineEdit->text();
    queryaid = ui->aidlineEdit->text();

    //display right result
    QPixmap pixmap("/Users/scaryang/Desktop/Interface/build-demo-Desktop-Debug/Verified.png");
    QIcon ButtonIcon(pixmap);
    ui->vbutton->setIcon(ButtonIcon);
    ui->vbutton->setIconSize(QSize(40,40));

    //generate multi-button
    QString str;
    int i = 0;
    PButton *button[3];

    //set font in button
    QFont FontObj;
    FontObj.setFamily(QStringLiteral("Helvetica"));
    FontObj.setPointSize(14);
    FontObj.setUnderline(true);

    for (;i < 3;i++)
    {
        button[i] = new PButton(this);
        button[i]->setVisible(true);
        str.setNum(i,10);
        button[i]->setText("No." + str);
        //button[i]->setGeometry(10,i*height+3, width,height);
        button[i]->setclick();
        button[i]->setBackgroundRole(QPalette::Base);
        button[i]->setFlat(true);
        button[i]->setFont(FontObj);
        button[i]->setStyleSheet("QPushButton {color: blue}");


        QWidget* pWidget = new QWidget();
        QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
        pLayout->addWidget(button[i]);
        pWidget->setLayout(pLayout);
        pLayout->setAlignment(Qt::AlignCenter);
        pLayout->setContentsMargins(0, 0, 0, 0);
        ui->tableWidget->setCellWidget(i,0 ,pWidget);
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->pidlineEdit_2->clear();
    ui->aidlineEdit_2->clear();
    ui->aidlineEdit_3->clear();

    ui->pidlineEdit_2->setFocus();

    ui->vbutton->setIcon(QIcon());

    //delete all rows in tablewidget
    //ui->tableWidget->setRowCount(0);
}

//range query button
void MainWindow::on_querybtn_2_clicked()
{
    if (ui->pidlineEdit_2->text().isEmpty()||ui->aidlineEdit_2->text().isEmpty()||ui->aidlineEdit_3->text().isEmpty())
    {
        QMessageBox::warning(this,tr("warning"),tr("Query information can not be empty!"));
        return;
    }
    querypid = ui->pidlineEdit_2->text();
    queryaid = ui->aidlineEdit_2->text();
    queryaid2= ui->aidlineEdit_3->text();

    //display right result
    QPixmap pixmap("/Users/scaryang/Desktop/Interface/build-demo-Desktop-Debug/Verified.png");
    QIcon ButtonIcon(pixmap);
    ui->vbutton->setIcon(ButtonIcon);
    ui->vbutton->setIconSize(QSize(40,40));

    //generate multi-button
    QString str;
    int i = 0;
    PButton *button[3];

    //set font in button
    QFont FontObj;
    FontObj.setFamily(QStringLiteral("Helvetica"));
    FontObj.setPointSize(14);
    FontObj.setUnderline(true);

    for (;i < 3;i++)
    {
        button[i] = new PButton(this);
        button[i]->setVisible(true);
        str.setNum(i,10);
        button[i]->setText("No." + str);
        //button[i]->setGeometry(10,i*height+3, width,height);
        button[i]->setclick();
        button[i]->setBackgroundRole(QPalette::Base);
        button[i]->setFlat(true);
        button[i]->setFont(FontObj);
        button[i]->setStyleSheet("QPushButton {color: blue}");


        QWidget* pWidget = new QWidget();
        QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
        pLayout->addWidget(button[i]);
        pWidget->setLayout(pLayout);
        pLayout->setAlignment(Qt::AlignCenter);
        pLayout->setContentsMargins(0, 0, 0, 0);
        ui->tableWidget->setCellWidget(i,0 ,pWidget);
    }
}

//display time
void MainWindow::timerUpdate(void)
{
   QDateTime time = QDateTime::currentDateTime();
   QString str = time.toString("yyyy-MM-dd hh:mm:ss");
   //ui->label_22->setText(str);
}

//logout
void MainWindow::on_out_btn_clicked()
{
   qApp->exit(2);
}

//display account information
void MainWindow::on_account_btn_clicked()
{
    QMessageBox *msgBox;
    string account;
    {
        ifstream fin("login.txt");
        fin >> account;
    }
    if (account == "Admin"){
        msgBox = new QMessageBox("User Information",
                                 "Admin \n\nan administrator of the system",
                                 QMessageBox::Information,
                                 QMessageBox::Ok | QMessageBox::Default,
                                 QMessageBox::Cancel | QMessageBox::Escape,
                                 0);
        msgBox->show();
    }else{
        msgBox = new QMessageBox("User Information",
                                 "Doctor \n\n Cannot access any inforamtion",
                                 QMessageBox::Information,
                                 QMessageBox::Ok | QMessageBox::Default,
                                 QMessageBox::Cancel | QMessageBox::Escape,
                                 0);
        msgBox->show();
    }
}

//display verification time
void MainWindow::on_vbutton_clicked()
{
    dialog->show();
}

/*  //set label as an icon
    QString filename("/Users/scaryang/Desktop/Interface/build-demo-Desktop-Debug/Verified.png");
    QImage* img = new QImage;
    if (!(img->load(filename)))
    {
        QMessageBox::information(this,tr("Fail to open image"),tr("Fail to open image!"));
        delete img;
        return;
    }

    img->scaled(ui->label_5->size(),Qt::KeepAspectRatio);
    ui->label_5->setScaledContents(true);
    ui->label_5->setPixmap(QPixmap::fromImage(*img));
    dialog->show();
*/

/*
void MainWindow::on_mainexit_2_clicked()
{
    dialog->show();
}


void MainWindow::on_actionLogout_triggered()
{
    qApp->exit(2);
}

void MainWindow::on_mainexit_3_clicked()
{
    dialog2->show();
}

void MainWindow::on_actionUser_triggered()
{
    QMessageBox *msgBox;
    msgBox = new QMessageBox("User Information",
                             "Admin \nan administrator of the system",
                             QMessageBox::Information,
                             QMessageBox::Ok | QMessageBox::Default,
                             QMessageBox::Cancel | QMessageBox::Escape,
                             0);
    msgBox->show();
}


void MainWindow::on_actionContact_Us_triggered()
{
    QMessageBox *msgBox;
    msgBox = new QMessageBox("About System",
                             "Verifiable Attribute-Based Search System over Shared Data",
                             QMessageBox::Information,
                             QMessageBox::Ok | QMessageBox::Default,
                             QMessageBox::Cancel | QMessageBox::Escape,
                             0);
    msgBox->show();
}

void MainWindow::on_actionContact_Us_2_triggered()
{
    QMessageBox *msgBox;
    msgBox = new QMessageBox("About Us",
                             "Website: https://www.comp.hkbu.edu.hk/~db/",
                             QMessageBox::Information,
                             QMessageBox::Ok | QMessageBox::Default,
                             QMessageBox::Cancel | QMessageBox::Escape,
                             0);
    msgBox->show();
}
*/

/*
    /generate multi-button
    QString str;
    int i = 0;
    PButton *button[6];
    for (;i<6;i++)
    {
        button[i] = new PButton(this);
        button[i]->setVisible(true);
        str.setNum(i,10);
        button[i]->setText("button"+str);
        ui->verticalLayout->addWidget(button[i]);
        ui->verticalLayout->setStretchFactor(button[i],1);
        //button[i]->setGeometry(10,i*height+3, width,height);
        button[i]->setclick();
        button[i]->setBackgroundRole(QPalette::Base);
        button[i]->setFlat(true);
    }

    ui->tableWidget->horizontalHeader()->setStretchLastSection(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setStretchLastSection(QHeaderView::Stretch);
    int rowindex = 5;
    ui->tableWidget->setRowCount(rowindex);
    ui->tableWidget->setItem(0,0, new QTableWidgetItem("No.2"));
    ui->tableWidget->setItem(0,1, new QTableWidgetItem("Direct infection of joint in infectious and parasitic diseases classified elsewhere"));
    ui->tableWidget->setItem(0,2, new QTableWidgetItem("1994-07-22"));
    ui->tableWidget->setItem(0,3, new QTableWidgetItem("1994-07-28"));

    ui->tableWidget->setItem(1,0, new QTableWidgetItem("No.3"));
    ui->tableWidget->setItem(1,1, new QTableWidgetItem("Disseminated intravascular coagulation"));
    ui->tableWidget->setItem(1,2, new QTableWidgetItem("2003-03-02"));
    ui->tableWidget->setItem(1,3, new QTableWidgetItem("2003-03-22"));

    ui->tableWidget->setItem(2,0, new QTableWidgetItem("No.4"));
    ui->tableWidget->setItem(2,1, new QTableWidgetItem("Chronic myeloid leukemia"));
    ui->tableWidget->setItem(2,2, new QTableWidgetItem("2007-07-03"));
    ui->tableWidget->setItem(2,3, new QTableWidgetItem("2007-07-08"));

    ui->tableWidget->setItem(3,0, new QTableWidgetItem("No.5"));
    ui->tableWidget->setItem(3,1, new QTableWidgetItem("Not Known"));
    ui->tableWidget->setItem(3,2, new QTableWidgetItem("Not Known"));
    ui->tableWidget->setItem(3,3, new QTableWidgetItem("Not Known"));

    ui->tableWidget->setItem(4,0, new QTableWidgetItem("No.6"));
    ui->tableWidget->setItem(4,1, new QTableWidgetItem("Rheumatoid polyneuropathy with rheumatoid arthritis of shoulder"));
    ui->tableWidget->setItem(4,2, new QTableWidgetItem("2012-04-13"));
    ui->tableWidget->setItem(4,3, new QTableWidgetItem("2012-04-24"));
*/
/*    //add button
    QWidget* pWidget = new QWidget();
    QPushButton* btn_edit = new QPushButton();
    btn_edit->setText("No.2");
    btn_edit->setFlat(true);
    QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
    pLayout->addWidget(btn_edit);
    pLayout->setAlignment(Qt::AlignCenter);
    pLayout->setContentsMargins(0, 0, 0, 0);
    pWidget->setLayout(pLayout);
    ui->tableWidget->setCellWidget(0, 0, pWidget);
*/




