#ifndef SUNFLOWER_H
#define SUNFLOWER_H

#include <QTimer>
#include <QTimerEvent>
#include <plant.h>

class Sunflower : public Plant
{
    Q_OBJECT
public:
    QTimer *timerSun = new QTimer();
    //QTimer *timerZombie = new QTimer(this);
    Sunflower();
    ~Sunflower();
    QLabel *showlife;
};

#endif // TIMECONTROL_H
