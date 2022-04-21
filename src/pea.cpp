#include "pea.h"

Pea::Pea(int a, int b)
{
    x = a;
    y = b;
    pin->start(50);
    connect(pin, &QTimer::timeout,[=](){
        x+=25;
        //需加一个操作 按帧数检测是否同僵尸碰撞  在level中实现 因为pea没land的接口
        //僵尸不能用块直接表示，一块上可以有很多僵尸 所以我们在块上附带一个链表
    });
}
