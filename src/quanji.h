#ifndef QUANJI_H
#define QUANJI_H
#include <common.h>
#include <plant.h>
#include <QTimer>
#include <pea.h>

class Quanji :public Plant
{
    Q_OBJECT
public:
    Quanji();
    ~Quanji();
    QTimer *pin = new QTimer();
    QLabel *showlife;
};

#endif // QUANJI_H
