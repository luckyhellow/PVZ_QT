#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <QObject>
#include <stdlib.h>
#include <QTimer>
#include <time.h>
#include <qlabel.h>
class Zombie : public QObject
{
    Q_OBJECT
public:
    explicit Zombie(QObject *parent = nullptr);
    int life;
    int x;
    int y;
    int row;
    int st;
    QLabel *labelzom;
    QTimer *pin = new QTimer();
    int attack;
    int type;//1 陆地 2 飞行
    QLabel * showlife;
signals:

};

#endif // ZOMBIE_H
