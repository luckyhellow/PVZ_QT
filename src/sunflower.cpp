#include "sunflower.h"

Sunflower::Sunflower()
{
    attack = 0;
    life = 50;
    cd = 7;
    timerSun->start(10000);
}

Sunflower::~Sunflower()
{
    timerSun->stop();
}
