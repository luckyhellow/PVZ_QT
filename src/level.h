#ifndef LEVEL_H
#define LEVEL_H

#include <QMainWindow>
#include <QPainter>
#include <QPushButton>
#include <QLineEdit>
#include <land.h>
#include <card.h>
#include <QImage>
#include <QLabel>
#include <sun.h>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimerEvent>
#include <zombie_0.h>
#include <zombie_1.h>
#include <zombie_2.h>
#include <zombie_3.h>
#include <zombie_7.h>
#include <zombie_8.h>
#include <gameover.h>
#include <gamewin.h>

typedef struct Node {
    int type;
    //Zombie_0 * zombie = NULL;
    Zombie_0* zombie = NULL;
    Zombie_1* zombie_1 = NULL;
    Zombie_2* zombie_2 = NULL;
    Zombie_3* zombie_3 = NULL;
    //加其他地面僵尸的指针
    Zombie_7* zombie_7 = NULL;
    Zombie_8* zombie_8 = NULL;
    Node* next = NULL;
} Node;

typedef struct Node* ZombieList;
class level : public QMainWindow
{
    Q_OBJECT
protected:
    void timerEvent(QTimerEvent *event);
public:
    explicit level(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    QString name;
    QLineEdit sunline;
    QLineEdit there;
    int timeId1;
    int first = 1;
    int timeId2;
    int timeId3;
    int timeId4;
    int r;
    Land *ground;
    int listtype[5+1];//记录路径用的
    ZombieList Head[10][6];
    ZombieList skyHead[10][6];//
    int floor[6];
    int num_of_floor = 0;
    int sky[6];
    int num_of_sky = 0;
    int zom_type;
    int num_of_floorzom = 4;//暂时四种地面僵尸
    int num_of_skyzom = 2;//暂时两种飞行僵尸
signals:

};

#endif // LEVEL1_H
