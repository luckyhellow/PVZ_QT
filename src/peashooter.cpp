#include "peashooter.h"

Peashooter::Peashooter()
{   
    attack = 1;
    life = 50;
    //cd = 7;
    pin->start(1000);
//    connect(pin, &QTimer::timeout,[=](){
//        n = (n+1)%4;
//        pea[n] = new Pea(260+122*col,145+145*row);
//    });
}
Peashooter::~Peashooter()
{
    pin->stop();
}
