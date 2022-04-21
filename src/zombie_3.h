#ifndef ZOMBIE_3_H
#define ZOMBIE_3_H

#include <QObject>
#include <zombie.h>

class Zombie_3 : public Zombie
{
    Q_OBJECT
public:
    Zombie_3();
    int times = 0;
    int time2 = 0;

signals:

};

#endif // ZOMBIE_3_H
