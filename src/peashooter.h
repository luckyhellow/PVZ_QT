#ifndef PEASHOOTER_H
#define PEASHOOTER_H
#include <common.h>
#include <plant.h>
#include <QTimer>
#include <pea.h>

class Peashooter: public Plant
{
    Q_OBJECT
public:
    Peashooter();
    ~Peashooter();
    QTimer *pin = new QTimer();
    //Pea *pea[5];
    //int n = 0;
    QLabel *showlife;
};

#endif // PEASHOOTER_H
