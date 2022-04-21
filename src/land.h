#ifndef LAND_H
#define LAND_H
#include "sunflower.h"
#include "peashooter.h"
#include "landbar.h"


class Land
{
public:
    int col = 9;//
    int row = 5;//
    Land();
//    Land(int x,int y);
    int land[9+1][5+1];//记录状态 该块上的植物种植情况
    int landtype[9+1][5+1];//记录近战远战或者不能种植
    landbar* landbutton[9+1][5+1];
    void plant(int TPYE);

    //Q line1[10]; 记录1-9格上的僵尸 用链表//按帧数更新zombie状态 思考后决定放到每个块上
    //Q line2[10];
    //Q line3[10];
    //Q line4[10];
    //Q line5[10];
};

#endif // LAND_H
