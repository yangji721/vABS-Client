#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include "dialog.h"
#include "logindialog.h"
#include "dialog2.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QString temp,QWidget *parent = 0);
    QString xyz;
    ~MainWindow();

public slots:
    void timerUpdate(void);

private slots:
    void on_pushButton_2_clicked();

    void on_querybtn_clicked();

    void on_pushButton_3_clicked();

    void on_querybtn_2_clicked();

    void on_out_btn_clicked();

    void on_account_btn_clicked();

    void on_vbutton_clicked();

private:
    Ui::MainWindow *ui;
    QString querypid;
    QString queryaid;
    QString queryaid2;
    QString res_verification;
    Dialog *dialog = new Dialog;
    Dialog2 *dialog2 = new Dialog2;
};

#endif // MAINWINDOW_H
