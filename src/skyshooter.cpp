#include "skyshooter.h"

Skyshooter::Skyshooter()
{
    attack = 1;
    life = 50;
    //cd = 7;
    pin->start(1000);
}
Skyshooter::~Skyshooter()
{
    pin->stop();
}
