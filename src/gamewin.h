#ifndef GAMEWIN_H
#define GAMEWIN_H

#include <QMainWindow>
#include <QPainter>

class Gamewin : public QMainWindow
{
    Q_OBJECT
public:
    explicit Gamewin(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
signals:

};

#endif // GAMEWIN_H
