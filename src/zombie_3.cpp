#include "zombie_3.h"

Zombie_3::Zombie_3(){
    type = 1;//地面的
    attack = 1;
    life = 10;
    pin->start(50);
//    connect(pin, &QTimer::timeout,[=](){
//        //x-=1;
//        //按频率检测是否同植物相遇，有则开始吃  在level中实现 因为此处没有land的接口
//        //按频率更新僵尸的位置
//    });
}
