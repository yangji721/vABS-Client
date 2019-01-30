#ifndef PBUTTON
#define PBUTTON

#include <QPushButton>
#include "dialog2.h"

class PButton : public QPushButton
{
    Q_OBJECT

public:
    PButton(QWidget *parent);
    void paintEvent(QPaintEvent *);
    void setclick();

public slots:
    void display();
private:
    Dialog2 *dialog2 = new Dialog2;
};

#endif // PBUTTON

