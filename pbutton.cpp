#include "pbutton.h"
#include "qmessagebox.h"
#include "dialog2.h"


PButton::PButton(QWidget *parent):QPushButton(parent)
{

}

void PButton::paintEvent(QPaintEvent *p)
{
    QPushButton::paintEvent(p);
}

void PButton::setclick()
{
    QObject::connect(this,SIGNAL(clicked()),this,SLOT(display()));
}

void PButton::display()
{
    //QMessageBox::information(NULL,"test", "hi");
    QString index = PButton::text();
    dialog2->transmit(index);
    dialog2->show();
}
