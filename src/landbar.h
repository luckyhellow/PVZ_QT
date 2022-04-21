#ifndef LANDBAR_H
#define LANDBAR_H
#include "mypushbutton.h"
#include <QLabel>
#include "sunflower.h"
#include "peashooter.h"
#include "wallnut.h"
#include "zombie_0.h"
#include "skyshooter.h"
#include "quanji.h"
#include "spikeweed.h"
#include "yuanwall.h"
#define NOPLANT 0
#define SUNFLOWER 1
#define PEA 2
#define WALLNUT 3
class landbar:public MyPushButton
{
    Q_OBJECT
public:
    landbar(QString normalImg);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    static int choose;//操作（种什么 或者铲子
    QLabel*label;
    QMovie*movie;
    Sunflower *sunflower;
    Peashooter * peashooter;
    Skyshooter * skyshooter;
    Wallnut *wallnut;
    Quanji *quanji;
    Spikeweed *spikeweed;
    Yuanwall * yuanwall;

    int type;//决定能不能种植或者种植近战还是远战目标
//    ZombieList  head = NULL;
//    bool insert_intail(Zombie_0*zombie);
//    bool delete_node(Zombie_0*zombie);
//    void clear();
};

#endif // LANDBAR_H
