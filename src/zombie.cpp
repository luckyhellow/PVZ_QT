#include "zombie.h"

Zombie::Zombie(QObject *parent) : QObject(parent)
{
    //srand(time(NULL));
    x = 1500;
    y = 0;
    row = 0;
    st =10;//初始不在0-8号的几个格子里
}
