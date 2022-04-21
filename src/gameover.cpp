#include "gameover.h"

Gameover::Gameover(QWidget *parent) : QMainWindow(parent)
{

}
void Gameover::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/Image/ZombieWin.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
