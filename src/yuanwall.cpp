#include "yuanwall.h"

Yuanwall::Yuanwall()
{
    attack = 0;
    life = 50;
    //cd = 7;
    pin->start(30000);
}
Yuanwall::~Yuanwall()
{
    pin->stop();
}
