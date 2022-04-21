#include "gamewin.h"

Gamewin::Gamewin(QWidget *parent) : QMainWindow(parent)
{

}
void Gamewin::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/Image/Youwin.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
