#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>
#include <fstream>
#include <iostream>

using namespace std;

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    ui->usrLineEdit->setText("Doctor");
    ui->pwdLineEdit->setText("123");
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_loginBtn_clicked()
{
    name = ui->usrLineEdit->text().trimmed();
    if(ui->usrLineEdit->text().trimmed() == tr("Admin") &&
            ui->pwdLineEdit->text() == tr("123"))
    {
        accept();
        ofstream outfile("login.txt", ofstream::out);
        outfile << "Admin";
        outfile.close();
    } else if(ui->usrLineEdit->text().trimmed() == tr("Doctor") &&
              ui->pwdLineEdit->text() == tr("123"))
    {
        accept();
        ofstream outfile("login.txt", ofstream::out);
        outfile << "Doctor";
        outfile.close();
    }else {
        QMessageBox::warning(this, tr("Waring"),
                                 tr("Username or Password is error!"),
                                 QMessageBox::Yes);
    }
    ui->usrLineEdit->clear();
    ui->pwdLineEdit->clear();
    ui->usrLineEdit->setFocus();
}

