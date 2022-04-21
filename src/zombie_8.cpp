#include "zombie_8.h"

Zombie_8::Zombie_8()
{
    type = 2;//飞行的
    attack = 1;
    life = 10;
    pin->start(50);
}
