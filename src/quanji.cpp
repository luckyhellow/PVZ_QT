#include "quanji.h"

Quanji::Quanji()
{
    attack = 1;
    life = 200;
    //cd = 7;
    pin->start(300);
}
Quanji::~Quanji()
{
    pin->stop();
}
