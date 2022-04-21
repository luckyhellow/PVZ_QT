#ifndef WALLNUT_H
#define WALLNUT_H

#include <QObject>
#include <plant.h>
#include <QLabel>
class Wallnut : public Plant
{
    Q_OBJECT
public:
    Wallnut();
    ~Wallnut();
    QLabel *showlife;

signals:

};

#endif // WALLNUT_H
