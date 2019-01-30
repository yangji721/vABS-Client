#include "mainwindow.h"
#include <QApplication>
#include "logindialog.h"
#include <QDesktopWidget>
#include <QProcess>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>


QString gstrFilePath = "";
void relogin(void);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    gstrFilePath = QCoreApplication::applicationFilePath();

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("login.db");
    if(database.open())
    {
        qDebug() << "Database Opened";
        QSqlQuery sql_query;
        QString create_sql = "create table user (loginid varchar(30), password varchar(30))";

        sql_query.prepare(create_sql);
    }

    //MainWindow w;
    LoginDialog dlg;
    if(dlg.exec()==QDialog::Accepted)
    {
        QString loginname = dlg.name;
        MainWindow w(loginname);
        w.show();
        w.move ((QApplication::desktop()->width() - w.width())/2,(QApplication::desktop()->height() - w.height())/2);
        int nret = a.exec();
        if (nret == 2)
        {
            atexit(relogin);
        }
        return nret;
    }
    else return 0;
}

void relogin(){
    QProcess process;
    process.startDetached(gstrFilePath);
}
