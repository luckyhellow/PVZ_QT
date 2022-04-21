#ifndef SKYSHOOTER_H
#define SKYSHOOTER_H
#include <common.h>
#include <plant.h>
#include <QTimer>
#include <pea.h>

class Skyshooter :public Plant
{
    Q_OBJECT
public:
    Skyshooter();
    ~Skyshooter();
    QTimer *pin = new QTimer();
    QLabel *showlife;
};

#endif // SKYSHOOTER_H
