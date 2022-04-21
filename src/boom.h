#ifndef BOOM_H
#define BOOM_H


#include <common.h>
#include <plant.h>
#include <QTimer>
#include <pea.h>

class boom: public Plant
{
    Q_OBJECT
public:
    boom();
    ~boom();
    QTimer *pin = new QTimer();
};

#endif // BOOM_H
