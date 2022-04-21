#include "spikeweed.h"

Spikeweed::Spikeweed()
{
    attack = 1;
    life = 100;
    //cd = 7;
    pin->start(1000);
}
Spikeweed::~Spikeweed()
{
    pin->stop();
}
