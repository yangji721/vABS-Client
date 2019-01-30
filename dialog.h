#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QTreeWidgetItem>
#include <QTreeWidget>


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    void AddRoot(QString name, QString Description);
    void AddChild(QTreeWidgetItem *parent, QString name, QString Description);
    ~Dialog();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
