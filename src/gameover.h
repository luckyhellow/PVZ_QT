#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QMainWindow>
#include <QPainter>

class Gameover : public QMainWindow
{
    Q_OBJECT
public:
    explicit Gameover(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
signals:

};

#endif // GAMEOVER_H
