#include "boom.h"

boom::boom()
{
    //cd = 7;
    pin->start(500);
//    connect(pin, &QTimer::timeout,[=](){
//        n = (n+1)%4;
//        pea[n] = new Pea(260+122*col,145+145*row);
//    });
}
boom::~boom()
{
    pin->stop();
}
