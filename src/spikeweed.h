#ifndef SPIKEWEED_H
#define SPIKEWEED_H
#include <common.h>
#include <plant.h>
#include <QTimer>
#include <pea.h>

class Spikeweed :public Plant
{
    Q_OBJECT
public:
    Spikeweed();
    ~Spikeweed();
    QTimer *pin = new QTimer();
    QLabel *showlife;
};

#endif // SPIKEWEED_H
