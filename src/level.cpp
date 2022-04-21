#include "level.h"
#include <QMovie>
#include <QGraphicsScene>
#include <QDebug>
#include <stdio.h>
#include <time.h>
#include <boom.h>
#include <QTextEdit>
#include <QRadioButton>
#include <QGroupBox>
#include <QVBoxLayout>
int landbar::choose = 0;
bool insert_intail(ZombieList& head,Zombie_0* zombie);//
bool insert_intail(ZombieList& head,Zombie_1* zombie);
bool insert_intail(ZombieList& head,Zombie_2* zombie);
bool insert_intail(ZombieList& head,Zombie_3* zombie);
bool insert_intail(ZombieList& head,Zombie_7* zombie);
bool insert_intail(ZombieList& head,Zombie_8* zombie);
ZombieList init();
bool delete_node(ZombieList& head,Zombie_0*zombie);
bool delete_node(ZombieList& head,Zombie_1*zombie);
bool delete_node(ZombieList& head,Zombie_2*zombie);
bool delete_node(ZombieList& head,Zombie_3*zombie);
bool delete_node(ZombieList& head,Zombie_7*zombie);
bool delete_node(ZombieList& head,Zombie_8*zombie);
bool twonone(Land * ground,int st,int row);
void clear(ZombieList& head);

level::level(QWidget *parent) : QMainWindow(parent)
{
    srand(time(NULL));
    QGraphicsScene *scene;
    //QGraphicsView *view;
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 1500, 900);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
//    view = new QGraphicsView(scene, this);
//    view->resize(1353, 903);

//    view->setRenderHint(QPainter::Antialiasing);
//    QPixmap pix;
//    pix.load(":/Image/background_daytime.jpg");
//    pix = pix.scaled(pix.width()*1.5,pix.height()*1.5);
//    view->setBackgroundBrush(pix);

//    view->setCacheMode(QGraphicsView::CacheBackground);
//    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    setFixedSize(1350,900);

//    resize(2100,900);
//    //固定大小
//    setFixedSize(2100,900);
//    //设置窗口标题
////    setWindowTitle(name);
    QLabel *label1=new QLabel(this);
    QTextEdit *inf = new QTextEdit(this);
    inf->move(1150,25);
    inf->resize(250,130);
    card* card1 = new card(":/Image/card_SunFlower.png");
//    card1->setFixedSize(card1->width()*2,card1->height()*2);
    card1->setParent(this);
    card1->move(310,0);

    card* card2 = new card(":/Image/card_Peashooter.png");
//    card1->setFixedSize(card1->width()*2,card1->height()*2);
    card2->setParent(this);
    card2->move(310+card1->width()+15,0);

    card* card3 = new card(":/Image/card_WallNut.png");
//    card1->setFixedSize(card1->width()*2,card1->height()*2);
    card3->setParent(this);
    card3->move(310+card1->width()+15+card2->width()+15,0);

    card* card4 = new card(":/Image/shovel.png");
//    card1->setFixedSize(card1->width()*2,card1->height()*2);
    card4->setParent(this);
    card4->move(1000,0);

    card* card5 = new card(":/Image/card_skyshooter.png");
//    card1->setFixedSize(card1->width()*2,card1->height()*2);
    card5->setParent(this);
    card5->move(310+300,0);

    card* card6 = new card(":/Image/card_quanji.png");
//    card1->setFixedSize(card1->width()*2,card1->height()*2);
    card6->setParent(this);
    card6->move(310+400,0);

    card* card7 = new card(":/Image/card_spikeweed.png");
//    card1->setFixedSize(card1->width()*2,card1->height()*2);
    card7->setParent(this);
    card7->move(310+500,0);

    card* card8 = new card(":/Image/card_yuanwall.png");
//    card1->setFixedSize(card1->width()*2,card1->height()*2);
    card8->setParent(this);
    card8->move(310+600,0);

    connect(card1,&MyPushButton::clicked,[=](){
        card1->tik();
        card1->tok();
        label1->setPixmap(QPixmap(":/Image/card_SunFlower.png"));
        label1->resize(85,120);
        label1->move(1200-150,5);
        label1->show();
        landbar::choose = 1;
        inf->setPlainText(" life: 50 \n attack: 0 \n 射程: 0");
//        inf->move(1200,5);
    });
    connect(card2,&MyPushButton::clicked,[=](){
        card2->tik();
        card2->tok();
        label1->setPixmap(QPixmap(":/Image/card_Peashooter.png"));
        label1->resize(85,120);
        label1->move(1200-150,5);
        label1->show();
        landbar::choose = 2;
        inf->setPlainText(" life: 50 \n attack: 1 \n 射程: 整行\n(打击地面单位)");
    });
    connect(card3,&MyPushButton::clicked,[=](){
        card3->tik();
        card3->tok();
        label1->setPixmap(QPixmap(":/Image/card_WallNut.png"));
        label1->resize(85,120);
        label1->move(1200-150,5);
        label1->show();
        landbar::choose = 3;
        inf->setPlainText(" life: 500 \n attack: 0 \n 射程: 0");
    });
    connect(card4,&MyPushButton::clicked,[=](){
        card4->tik();
        card4->tok();
        label1->setPixmap(QPixmap(":/Image/shovel.png"));
        label1->resize(85,120);
        label1->setAlignment(Qt::AlignCenter);
        label1->move(1200-150,5);
        label1->show();
        landbar::choose = 4;
        inf->setPlainText(" 铲子 \n铲除你不想要的植物");
    });
    connect(card5,&MyPushButton::clicked,[=](){
        card5->tik();
        card5->tok();
        label1->setPixmap(QPixmap(":/Image/card_skyshooter.png"));
        label1->resize(85,120);
        label1->setAlignment(Qt::AlignCenter);
        label1->move(1200-150,5);
        label1->show();
        landbar::choose = 5;
        qDebug()<<landbar::choose;
        inf->setPlainText(" life: 50 \n attack: 1 \n 射程: 整行\n(地空都可打击)");
    });
    connect(card6,&MyPushButton::clicked,[=](){
        card6->tik();
        card6->tok();
        label1->setPixmap(QPixmap(":/Image/card_quanji.png"));
        label1->resize(85,120);
        label1->setAlignment(Qt::AlignCenter);
        label1->move(1200-150,5);
        label1->show();
        landbar::choose = 6;
        inf->setPlainText(" life: 200 \n attack: 1 \n 射程: 1\n(地空都可打击)");
    });
    connect(card7,&MyPushButton::clicked,[=](){
        card7->tik();
        card7->tok();
        label1->setPixmap(QPixmap(":/Image/card_spikeweed.png"));
        label1->resize(85,120);
        label1->setAlignment(Qt::AlignCenter);
        label1->move(1200-150,5);
        label1->show();
        landbar::choose = 7;
        inf->setPlainText(" life: 100 \n attack: 1 \n 射程: 1\n(打击地面单位)");
    });
    connect(card8,&MyPushButton::clicked,[=](){
        card8->tik();
        card8->tok();
        label1->setPixmap(QPixmap(":/Image/card_yuanwall.png"));
        label1->resize(85,120);
        label1->setAlignment(Qt::AlignCenter);
        label1->move(1200-150,5);
        label1->show();
        landbar::choose = 8;
        inf->setPlainText(" life: 50 \n attack: 0 \n 射程: 整行\n(生成坚果墙)");
    });
    ground = new Land;
    for(int i=0;i<ground->col;i++)
    {
        for(int j=0;j<ground->row;j++)
        {
            Head[i][j] = NULL;
            skyHead[i][j] = NULL;
            ground->landbutton[i][j]->setParent(this);
            ground->landbutton[i][j]->move(230+122*i,145+145*j);
            connect(ground->landbutton[i][j],&MyPushButton::clicked,[=](){
                if(ground->land[i][j]==NOPLANT)
                {
                    ground->landbutton[i][j]->label=new QLabel(this);
                    if(landbar::choose==1 and ground->landtype[i][j] ==1)
                    {
                        qDebug()<< ground->landtype[i][j];
                        if(Sun::num_of_sun >= 50)
                        {
                            Sun::num_of_sun-=50;
                            this->sunline.setText(QString::number(Sun::num_of_sun));
                            ground->landbutton[i][j]->sunflower = new Sunflower();
                            ground->landbutton[i][j]->sunflower->col = i;
                            ground->landbutton[i][j]->sunflower->row = j;
                            //sunflower->setMovie(":/Image/sunflower.gif");
                            connect(ground->landbutton[i][j]->sunflower->timerSun,&QTimer::timeout,[=](){
                                Sun::num_of_sun += 25;
                                this->sunline.setText(QString::number(Sun::num_of_sun));
                            });
                            ground->landbutton[i][j]->movie = new QMovie(":/Image/sunflower.gif");
                            ground->landbutton[i][j]->label->setMovie(ground->landbutton[i][j]->movie);
                            ground->landbutton[i][j]->label->resize(110,140);
                            ground->landbutton[i][j]->label->move(260+122*i,130+145*j);
                            ground->landbutton[i][j]->movie->start();
                            ground->landbutton[i][j]->label->show();
                            ground->landbutton[i][j]->sunflower->showlife = new QLabel(this);
                            ground->landbutton[i][j]->sunflower->showlife->setText(QString::number(ground->landbutton[i][j]->sunflower->life));
                            ground->landbutton[i][j]->sunflower->showlife->move(260+122*i,130+145*j);
                            ground->landbutton[i][j]->sunflower->showlife->show();
                            ground->land[i][j]=1;
                            landbar::choose = 0;
                            //ground->landbutton[i][j]->label->clear();

                        }
                    }
                    else if(landbar::choose==2 and ground->landtype[i][j] ==2)
                    {
                        if(Sun::num_of_sun>=100)
                        {
                            Sun::num_of_sun-=100;
                            this->sunline.setText(QString::number(Sun::num_of_sun));
                            ground->landbutton[i][j]->peashooter = new Peashooter();
                            ground->landbutton[i][j]->peashooter->col = i;//qDebug()<<i;
                            ground->landbutton[i][j]->peashooter->row = j;//qDebug()<<j;
                            connect(ground->landbutton[i][j]->peashooter->pin,&QTimer::timeout,[=](){
                                Pea*pea = new Pea(260+122*ground->landbutton[i][j]->peashooter->col,170+145*ground->landbutton[i][j]->peashooter->row);
                                QLabel *labelpea=new QLabel(this);
                                QLabel *shanghai=new QLabel(this);
                                QPixmap *pix = new  QPixmap(":/Image/Pea.png");
                                QPixmap *pix2 = new  QPixmap(":/Image/boom.png");
                                labelpea->setPixmap(*pix);
                                shanghai->setPixmap(*pix2);
                                boom* peaboom = new boom();
                                connect(pea->pin,&QTimer::timeout,[=](){

                                    if((pea->x-160)/122>8)
                                    {
                                         labelpea->clear();
                                         pea->pin->stop();
                                         delete pea;
                                    }
                                    else if(Head[(pea->x-160)/122][j]==NULL)
                                    {
                                        labelpea->move(pea->x,pea->y);
                                        labelpea->show();
                                    }
                                    else
                                    {
                                        if(Head[(pea->x-160)/122][j]->type == 0){

                                        Head[(pea->x-160)/122][j]->zombie->life -=1;
                                        shanghai->move(Head[(pea->x-160)/122][j]->zombie->x+10,Head[(pea->x-160)/122][j]->zombie->y+20);
                                        shanghai->show();
                                        connect(peaboom->pin,&QTimer::timeout,[=](){
                                            shanghai->clear();
                                        });


                                        if(Head[(pea->x-160)/122][j]->zombie->life<=0)
                                        {
                                            Zombie_0 *zom = Head[(pea->x-160)/122][j]->zombie;
                                            delete_node(Head[(pea->x-160)/122][j],Head[(pea->x-160)/122][j]->zombie);
                                            zom->showlife->clear();
                                            zom->labelzom->clear();
                                            zom->pin->stop();
                                            delete zom;
                                        }
                                        labelpea->clear();

                                        pea->pin->stop();
                                        delete pea;
                                        }
                                        else if(Head[(pea->x-160)/122][j]->type == 1){
                                        Head[(pea->x-160)/122][j]->zombie_1->life -=1;
                                        shanghai->move(Head[(pea->x-160)/122][j]->zombie_1->x+10,Head[(pea->x-160)/122][j]->zombie_1->y+20);
                                        shanghai->show();
                                        connect(peaboom->pin,&QTimer::timeout,[=](){
                                            shanghai->clear();
                                        });
                                        if(Head[(pea->x-160)/122][j]->zombie_1->life<=0)
                                        {
                                            Zombie_1 *zom = Head[(pea->x-160)/122][j]->zombie_1;
                                            delete_node(Head[(pea->x-160)/122][j],Head[(pea->x-160)/122][j]->zombie_1);
                                            zom->showlife->clear();
                                            zom->labelzom->clear();
                                            zom->pin->stop();
                                            delete zom;
                                        }
                                        labelpea->clear();
                                        pea->pin->stop();
                                        delete pea;
                                        }
                                        else if(Head[(pea->x-160)/122][j]->type == 2){
                                        Head[(pea->x-160)/122][j]->zombie_2->life -=1;
                                        shanghai->move(Head[(pea->x-160)/122][j]->zombie_2->x+10,Head[(pea->x-160)/122][j]->zombie_2->y+20);
                                        shanghai->show();
                                        connect(peaboom->pin,&QTimer::timeout,[=](){
                                            shanghai->clear();
                                        });
                                        if(Head[(pea->x-160)/122][j]->zombie_2->life<=0)
                                        {
                                            Zombie_2 *zom = Head[(pea->x-160)/122][j]->zombie_2;
                                            delete_node(Head[(pea->x-160)/122][j],Head[(pea->x-160)/122][j]->zombie_2);
                                            zom->showlife->clear();
                                            zom->labelzom->clear();
                                            zom->pin->stop();
                                            delete zom;
                                        }
                                        labelpea->clear();
                                        pea->pin->stop();
                                        delete pea;
                                        }
                                        else if(Head[(pea->x-160)/122][j]->type == 3){
                                        Head[(pea->x-160)/122][j]->zombie_3->life -=1;
                                        shanghai->move(Head[(pea->x-160)/122][j]->zombie_3->x+10,Head[(pea->x-160)/122][j]->zombie_3->y+20);
                                        shanghai->show();
                                        connect(peaboom->pin,&QTimer::timeout,[=](){
                                            shanghai->clear();
                                        });
                                        if(Head[(pea->x-160)/122][j]->zombie_3->life<=0)
                                        {
                                            Zombie_3 *zom = Head[(pea->x-160)/122][j]->zombie_3;
                                            delete_node(Head[(pea->x-160)/122][j],Head[(pea->x-160)/122][j]->zombie_3);
                                            zom->showlife->clear();
                                            zom->labelzom->clear();
                                            zom->pin->stop();
                                            delete zom;
                                        }
                                        labelpea->clear();
                                        pea->pin->stop();
                                        delete pea;
                                        }
                                    }
                                });

                            });
                            ground->landbutton[i][j]->movie = new QMovie(":/Image/peashooter.gif");
                            ground->landbutton[i][j]->label->setMovie(ground->landbutton[i][j]->movie);
                            ground->landbutton[i][j]->label->resize(110,140);
                            ground->landbutton[i][j]->label->move(260+122*i,130+145*j);
                            ground->landbutton[i][j]->movie->start();
                            ground->landbutton[i][j]->label->show();
                            ground->landbutton[i][j]->peashooter->showlife = new QLabel(this);
                            ground->landbutton[i][j]->peashooter->showlife->setText(QString::number(ground->landbutton[i][j]->peashooter->life));
                            ground->landbutton[i][j]->peashooter->showlife->move(260+122*i,130+145*j);
                            ground->landbutton[i][j]->peashooter->showlife->show();
                            ground->land[i][j]=2;
                            landbar::choose = 0;

                        }
                    }
                    else if(landbar::choose==3 and ground->landtype[i][j] ==1)
                    {
                        if(Sun::num_of_sun>=50)
                        {
                            Sun::num_of_sun-=50;

                            this->sunline.setText(QString::number(Sun::num_of_sun));
                            ground->landbutton[i][j]->wallnut = new Wallnut();
                            ground->landbutton[i][j]->wallnut->showlife = new QLabel(this);
                            ground->landbutton[i][j]->movie = new QMovie(":/Image/wallnut.gif");
                            ground->landbutton[i][j]->label->setMovie(ground->landbutton[i][j]->movie);
                            ground->landbutton[i][j]->label->resize(110,140);
                            ground->landbutton[i][j]->label->move(260+122*i,130+145*j);
                            ground->landbutton[i][j]->movie->start();
                            ground->landbutton[i][j]->label->show();
                            ground->landbutton[i][j]->wallnut->showlife->setText(QString::number(ground->landbutton[i][j]->wallnut->life));
                            ground->landbutton[i][j]->wallnut->showlife->move(260+122*i,130+145*j);
                            ground->landbutton[i][j]->wallnut->showlife->show();
                            ground->land[i][j]=3;
                            qDebug()<<ground->land[i][j]<<"i j"<<i<<j;
                            landbar::choose = 0;

                         }
                    }
                    else if(landbar::choose==5 and ground->landtype[i][j] ==2)
                    {
                        qDebug()<<landbar::choose;
                        if(Sun::num_of_sun>=125)
                        {
                            Sun::num_of_sun-=125;
                            this->sunline.setText(QString::number(Sun::num_of_sun));
                            ground->landbutton[i][j]->skyshooter = new Skyshooter();
                            ground->landbutton[i][j]->skyshooter->col = i;//qDebug()<<i;
                            ground->landbutton[i][j]->skyshooter->row = j;//qDebug()<<j;
                            connect(ground->landbutton[i][j]->skyshooter->pin,&QTimer::timeout,[=](){
                                Pea*pea = new Pea(260+122*ground->landbutton[i][j]->skyshooter->col,170+145*ground->landbutton[i][j]->skyshooter->row);
                                QLabel *labelpea=new QLabel(this);
                                QLabel *shanghai=new QLabel(this);
                                QPixmap *pix = new  QPixmap(":/Image/skypea.png");
                                QPixmap *pix2 = new  QPixmap(":/Image/boom.png");
                                labelpea->setPixmap(*pix);
                                shanghai->setPixmap(*pix2);
                                boom* peaboom = new boom();
                                connect(pea->pin,&QTimer::timeout,[=](){
                                    if((pea->x-160)/122>8)
                                    {
                                         labelpea->clear();
                                         pea->pin->stop();
                                         delete pea;
                                    }
                                    else if(Head[(pea->x-160)/122][j]==NULL and skyHead[(pea->x-160)/122][j]==NULL)
                                    {
                                        labelpea->move(pea->x,pea->y);
                                        labelpea->show();
                                    }
                                    else if(skyHead[(pea->x-160)/122][j]!=NULL)
                                    {
                                        if(skyHead[(pea->x-160)/122][j]->type == 7){
                                        skyHead[(pea->x-160)/122][j]->zombie_7->life -=1;
                                        shanghai->move(skyHead[(pea->x-160)/122][j]->zombie_7->x+10,skyHead[(pea->x-160)/122][j]->zombie_7->y+20);
                                        shanghai->show();
                                        connect(peaboom->pin,&QTimer::timeout,[=](){
                                            shanghai->clear();
                                            delete peaboom;
                                        });
                                        if(skyHead[(pea->x-160)/122][j]->zombie_7->life<=0)
                                        {
                                            Zombie_7 *zom = skyHead[(pea->x-160)/122][j]->zombie_7;
                                            delete_node(skyHead[(pea->x-160)/122][j],skyHead[(pea->x-160)/122][j]->zombie_7);
                                            zom->showlife->clear();
                                            zom->labelzom->clear();
                                            zom->pin->stop();
                                            delete zom;
                                        }
                                        labelpea->clear();
                                        pea->pin->stop();
                                        delete pea;
                                        }
                                        else if(skyHead[(pea->x-160)/122][j]->type == 8){
                                        skyHead[(pea->x-160)/122][j]->zombie_8->life -=1;
                                        shanghai->move(skyHead[(pea->x-160)/122][j]->zombie_8->x+10,skyHead[(pea->x-160)/122][j]->zombie_8->y+20);
                                        shanghai->show();
                                        connect(peaboom->pin,&QTimer::timeout,[=](){
                                            shanghai->clear();
                                            delete peaboom;
                                        });
                                        if(skyHead[(pea->x-160)/122][j]->zombie_8->life<=0)
                                        {
                                            Zombie_8 *zom = skyHead[(pea->x-160)/122][j]->zombie_8;
                                            delete_node(skyHead[(pea->x-160)/122][j],skyHead[(pea->x-160)/122][j]->zombie_8);
                                            zom->showlife->clear();
                                            zom->labelzom->clear();
                                            zom->pin->stop();
                                            delete zom;
                                        }
                                        labelpea->clear();
                                        pea->pin->stop();
                                        delete pea;
                                        }
                                    }
                                    else
                                    {
                                        if(Head[(pea->x-160)/122][j]->type == 0){
                                        Head[(pea->x-160)/122][j]->zombie->life -=1;
                                        shanghai->move(Head[(pea->x-160)/122][j]->zombie->x+10,Head[(pea->x-160)/122][j]->zombie->y+20);
                                        shanghai->show();
                                        connect(peaboom->pin,&QTimer::timeout,[=](){
                                            shanghai->clear();
                                            delete peaboom;
                                        });
                                        if(Head[(pea->x-160)/122][j]->zombie->life<=0)
                                        {
                                            Zombie_0 *zom = Head[(pea->x-160)/122][j]->zombie;
                                            delete_node(Head[(pea->x-160)/122][j],Head[(pea->x-160)/122][j]->zombie);
                                            zom->showlife->clear();
                                            zom->labelzom->clear();
                                            zom->pin->stop();
                                            delete zom;
                                        }
                                        labelpea->clear();
                                        pea->pin->stop();
                                        delete pea;
                                        }
                                        else if(Head[(pea->x-160)/122][j]->type == 1){
                                        Head[(pea->x-160)/122][j]->zombie_1->life -=1;
                                        shanghai->move(Head[(pea->x-160)/122][j]->zombie_1->x+10,Head[(pea->x-160)/122][j]->zombie_1->y+20);
                                        shanghai->show();
                                        connect(peaboom->pin,&QTimer::timeout,[=](){
                                            shanghai->clear();
                                            delete peaboom;
                                        });
                                        if(Head[(pea->x-160)/122][j]->zombie_1->life<=0)
                                        {
                                            Zombie_1 *zom = Head[(pea->x-160)/122][j]->zombie_1;
                                            delete_node(Head[(pea->x-160)/122][j],Head[(pea->x-160)/122][j]->zombie_1);
                                            zom->showlife->clear();
                                            zom->labelzom->clear();
                                            zom->pin->stop();
                                            delete zom;
                                        }
                                        labelpea->clear();
                                        pea->pin->stop();
                                        delete pea;
                                        }
                                        else if(Head[(pea->x-160)/122][j]->type == 2){
                                        Head[(pea->x-160)/122][j]->zombie_2->life -=1;
                                        shanghai->move(Head[(pea->x-160)/122][j]->zombie_2->x+10,Head[(pea->x-160)/122][j]->zombie_2->y+20);
                                        shanghai->show();
                                        connect(peaboom->pin,&QTimer::timeout,[=](){
                                            shanghai->clear();
                                            delete peaboom;
                                        });
                                        if(Head[(pea->x-160)/122][j]->zombie_2->life<=0)
                                        {
                                            Zombie_2 *zom = Head[(pea->x-160)/122][j]->zombie_2;
                                            delete_node(Head[(pea->x-160)/122][j],Head[(pea->x-160)/122][j]->zombie_2);
                                            zom->showlife->clear();
                                            zom->labelzom->clear();
                                            zom->pin->stop();
                                            delete zom;
                                        }
                                        labelpea->clear();
                                        pea->pin->stop();
                                        delete pea;
                                        }
                                        else if(Head[(pea->x-160)/122][j]->type == 3){
                                        Head[(pea->x-160)/122][j]->zombie_3->life -=1;
                                        shanghai->move(Head[(pea->x-160)/122][j]->zombie_3->x+10,Head[(pea->x-160)/122][j]->zombie_3->y+20);
                                        shanghai->show();
                                        connect(peaboom->pin,&QTimer::timeout,[=](){
                                            shanghai->clear();
                                            delete peaboom;
                                        });
                                        if(Head[(pea->x-160)/122][j]->zombie_3->life<=0)
                                        {
                                            Zombie_3 *zom = Head[(pea->x-160)/122][j]->zombie_3;
                                            delete_node(Head[(pea->x-160)/122][j],Head[(pea->x-160)/122][j]->zombie_3);
                                            zom->showlife->clear();
                                            zom->labelzom->clear();
                                            zom->pin->stop();
                                            delete zom;
                                        }
                                        labelpea->clear();
                                        pea->pin->stop();
                                        delete pea;
                                        }
                                    }
                                });

                            });
                            ground->landbutton[i][j]->movie = new QMovie(":/Image/skyshooter.gif");
                            ground->landbutton[i][j]->label->setMovie(ground->landbutton[i][j]->movie);
                            ground->landbutton[i][j]->label->resize(110,140);
                            ground->landbutton[i][j]->label->move(260+122*i,130+145*j);
                            ground->landbutton[i][j]->movie->start();
                            ground->landbutton[i][j]->label->show();
                            ground->landbutton[i][j]->skyshooter->showlife = new QLabel(this);
                            ground->landbutton[i][j]->skyshooter->showlife->setText(QString::number(ground->landbutton[i][j]->skyshooter->life));
                            ground->landbutton[i][j]->skyshooter->showlife->move(260+122*i,130+145*j);
                            ground->landbutton[i][j]->skyshooter->showlife->show();
                            ground->land[i][j]=5;
                            landbar::choose = 0;

                        }
                    }
                    else if(landbar::choose==6 and ground->landtype[i][j] ==1)
                    {
                        qDebug()<<landbar::choose;
                        if(Sun::num_of_sun>=150)
                        {
                            Sun::num_of_sun-=150;
                            this->sunline.setText(QString::number(Sun::num_of_sun));
                            ground->landbutton[i][j]->quanji = new Quanji();
                            ground->landbutton[i][j]->quanji->col = i;//qDebug()<<i;
                            ground->landbutton[i][j]->quanji->row = j;//qDebug()<<j;
                            qDebug()<<"ye wen vs zom"<<i<<j;
                            connect(ground->landbutton[i][j]->quanji->pin,&QTimer::timeout,[=](){
                                qDebug()<<"pin!";
                                QLabel *shanghai=new QLabel(this);
                                QPixmap *pix2 = new  QPixmap(":/Image/boom.png");
                                shanghai->setPixmap(*pix2);
                                boom* peaboom = new boom();
                                if(Head[i][j]==NULL and skyHead[i][j]==NULL) qDebug()<<"no zom"<<i<<j;
                                else if(skyHead[i][j]!=NULL)
                                {
                                    if(skyHead[i][j]->type == 7){
                                    skyHead[i][j]->zombie_7->life -=1;
                                    shanghai->move(skyHead[i][j]->zombie_7->x+10,skyHead[i][j]->zombie_7->y+20);
                                    shanghai->show();
                                    connect(peaboom->pin,&QTimer::timeout,[=](){
                                        shanghai->clear();
                                        delete peaboom;
                                    });
                                    if(skyHead[i][j]->zombie_7->life<=0)
                                    {
                                        Zombie_7 *zom = skyHead[i][j]->zombie_7;
                                        delete_node(skyHead[i][j],skyHead[i][j]->zombie_7);
                                        zom->showlife->clear();
                                        zom->labelzom->clear();
                                        zom->pin->stop();
                                        delete zom;
                                    }
                                    }
                                    else if(skyHead[i][j]->type == 8){
                                    skyHead[i][j]->zombie_8->life -=1;
                                    shanghai->move(skyHead[i][j]->zombie_8->x+10,skyHead[i][j]->zombie_8->y+20);
                                    shanghai->show();
                                    connect(peaboom->pin,&QTimer::timeout,[=](){
                                        shanghai->clear();
                                        delete peaboom;
                                    });
                                    if(skyHead[i][j]->zombie_8->life<=0)
                                    {
                                        Zombie_8 *zom = skyHead[i][j]->zombie_8;
                                        delete_node(skyHead[i][j],skyHead[i][j]->zombie_8);
                                        zom->showlife->clear();
                                        zom->labelzom->clear();
                                        zom->pin->stop();
                                        delete zom;
                                    }
                                    }
                                }
                                else
                                {
                                    qDebug()<<"ye wen vs zom"<<i<<j;
                                    if(Head[i][j]->type == 0){
                                    Head[i][j]->zombie->life -=1;
                                    shanghai->move(Head[i][j]->zombie->x+10,Head[i][j]->zombie->y+20);
                                    shanghai->show();
                                    connect(peaboom->pin,&QTimer::timeout,[=](){
                                        shanghai->clear();
                                        delete peaboom;
                                    });
                                    if(Head[i][j]->zombie->life<=0)
                                    {
                                        Zombie_0 *zom = Head[i][j]->zombie;
                                        delete_node(Head[i][j],Head[i][j]->zombie);
                                        zom->showlife->clear();
                                        zom->labelzom->clear();
                                        zom->pin->stop();
                                        delete zom;
                                    }
                                    }
                                    else if(Head[i][j]->type == 1){
                                    Head[i][j]->zombie_1->life -=1;
                                    shanghai->move(Head[i][j]->zombie_1->x+10,Head[i][j]->zombie_1->y+20);
                                    shanghai->show();
                                    connect(peaboom->pin,&QTimer::timeout,[=](){
                                        shanghai->clear();
                                        delete peaboom;
                                    });
                                    if(Head[i][j]->zombie_1->life<=0)
                                    {
                                        Zombie_1 *zom = Head[i][j]->zombie_1;
                                        delete_node(Head[i][j],Head[i][j]->zombie_1);
                                        zom->showlife->clear();
                                        zom->labelzom->clear();
                                        zom->pin->stop();
                                        delete zom;
                                    }
                                    }
                                    else if(Head[i][j]->type == 2){
                                    Head[i][j]->zombie_2->life -=1;
                                    shanghai->move(Head[i][j]->zombie_2->x+10,Head[i][j]->zombie_2->y+20);
                                    shanghai->show();
                                    connect(peaboom->pin,&QTimer::timeout,[=](){
                                        shanghai->clear();
                                        delete peaboom;
                                    });
                                    if(Head[i][j]->zombie_2->life<=0)
                                    {
                                        Zombie_2 *zom = Head[i][j]->zombie_2;
                                        delete_node(Head[i][j],Head[i][j]->zombie_2);
                                        zom->showlife->clear();
                                        zom->labelzom->clear();
                                        zom->pin->stop();
                                        delete zom;
                                    }
                                    }
                                    else if(Head[i][j]->type == 3){
                                    Head[i][j]->zombie_3->life -=1;
                                    shanghai->move(Head[i][j]->zombie_3->x+10,Head[i][j]->zombie_3->y+20);
                                    shanghai->show();
                                    connect(peaboom->pin,&QTimer::timeout,[=](){
                                        shanghai->clear();
                                        delete peaboom;
                                    });
                                    if(Head[i][j]->zombie_3->life<=0)
                                    {
                                        Zombie_3 *zom = Head[i][j]->zombie_3;
                                        delete_node(Head[i][j],Head[i][j]->zombie_3);
                                        zom->showlife->clear();
                                        zom->labelzom->clear();
                                        zom->pin->stop();
                                        delete zom;
                                    }
                                    }
                            }


                            });
                            ground->landbutton[i][j]->movie = new QMovie(":/Image/quanji.gif");
                            ground->landbutton[i][j]->label->setMovie(ground->landbutton[i][j]->movie);
                            ground->landbutton[i][j]->label->setAlignment(Qt::AlignCenter);
                            ground->landbutton[i][j]->label->resize(110,140);
                            ground->landbutton[i][j]->label->move(260+122*i,130+145*j);
                            ground->landbutton[i][j]->movie->start();
                            ground->landbutton[i][j]->label->show();
                            ground->landbutton[i][j]->quanji->showlife = new QLabel(this);
                            ground->landbutton[i][j]->quanji->showlife->setText(QString::number(ground->landbutton[i][j]->quanji->life));
                            ground->landbutton[i][j]->quanji->showlife->move(260+122*i,130+145*j);
                            ground->landbutton[i][j]->quanji->showlife->show();
                            ground->land[i][j]=6;
                            landbar::choose = 0;

                        }
                    }
                    else if(landbar::choose==7 and ground->landtype[i][j] ==1)
                    {
                        qDebug()<<landbar::choose;
                        if(Sun::num_of_sun>=100)
                        {
                            Sun::num_of_sun-=100;
                            this->sunline.setText(QString::number(Sun::num_of_sun));
                            ground->landbutton[i][j]->spikeweed = new Spikeweed();
                            ground->landbutton[i][j]->spikeweed->col = i;//qDebug()<<i;
                            ground->landbutton[i][j]->spikeweed->row = j;//qDebug()<<j;
                            qDebug()<<"spikeweed vs zom"<<i<<j;
                            connect(ground->landbutton[i][j]->spikeweed->pin,&QTimer::timeout,[=](){
                                qDebug()<<"pin!";
                                QLabel *shanghai=new QLabel(this);
                                QPixmap *pix2 = new  QPixmap(":/Image/boom.png");
                                shanghai->setPixmap(*pix2);
                                boom* peaboom = new boom();
                                if(Head[i][j]==NULL) qDebug()<<"no zom"<<i<<j;
                                else
                                {
                                    Node*p = Head[i][j];
                                    while(p!=NULL){
                                    qDebug()<<"spikeweed vs zom"<<i<<j;
                                    if(p->type == 0){
                                    p->zombie->life -=1;
                                    shanghai->move(Head[i][j]->zombie->x+10,Head[i][j]->zombie->y+20);
                                    shanghai->show();
                                    connect(peaboom->pin,&QTimer::timeout,[=](){
                                        shanghai->clear();
                                        delete peaboom;
                                    });
                                    if(p->zombie->life<=0)
                                    {
                                        Zombie_0 *zom = p->zombie;
                                        Node *q=p->next;
                                        delete_node(Head[i][j],p->zombie);
                                        zom->showlife->clear();
                                        zom->labelzom->clear();
                                        zom->pin->stop();
                                        delete zom;
                                        p=q;
                                    }
                                    else p = p->next;
                                    }
                                    else if(p->type == 1){
                                    p->zombie_1->life -=1;
                                    shanghai->move(Head[i][j]->zombie_1->x+10,Head[i][j]->zombie_1->y+20);
                                    shanghai->show();
                                    connect(peaboom->pin,&QTimer::timeout,[=](){
                                        shanghai->clear();
                                        delete peaboom;
                                    });
                                    if(p->zombie_1->life<=0)
                                    {
                                        Zombie_1 *zom = p->zombie_1;
                                        Node *q=p->next;
                                        delete_node(Head[i][j],p->zombie_1);
                                        zom->showlife->clear();
                                        zom->labelzom->clear();
                                        zom->pin->stop();
                                        delete zom;
                                        p=q;
                                    }
                                    else p = p->next;
                                    }
                                    else if(p->type == 2){
                                    p->zombie_2->life -=1;
                                    shanghai->move(Head[i][j]->zombie_2->x+10,Head[i][j]->zombie_2->y+20);
                                    shanghai->show();
                                    connect(peaboom->pin,&QTimer::timeout,[=](){
                                        shanghai->clear();
                                        delete peaboom;
                                    });
                                    if(p->zombie_2->life<=0)
                                    {
                                        Zombie_2 *zom = p->zombie_2;
                                        Node *q=p->next;
                                        delete_node(Head[i][j],p->zombie_2);
                                        zom->showlife->clear();
                                        zom->labelzom->clear();
                                        zom->pin->stop();
                                        delete zom;
                                        p=q;
                                    }
                                    else p = p->next;
                                    }
                                    else if(p->type == 3){
                                    p->zombie_3->life -=1;
                                    shanghai->move(Head[i][j]->zombie_3->x+10,Head[i][j]->zombie_3->y+20);
                                    shanghai->show();
                                    connect(peaboom->pin,&QTimer::timeout,[=](){
                                        shanghai->clear();
                                        delete peaboom;
                                    });
                                    if(p->zombie_3->life<=0)
                                    {
                                        Zombie_3 *zom = p->zombie_3;
                                        Node *q=p->next;
                                        delete_node(Head[i][j],p->zombie_3);
                                        zom->showlife->clear();
                                        zom->labelzom->clear();
                                        zom->pin->stop();
                                        delete zom;
                                        p=q;
                                    }
                                    }
                                }
                            }


                            });
                            ground->landbutton[i][j]->movie = new QMovie(":/Image/Spikeweed.gif");
                            ground->landbutton[i][j]->label->setMovie(ground->landbutton[i][j]->movie);
                            ground->landbutton[i][j]->label->setAlignment(Qt::AlignCenter);
                            ground->landbutton[i][j]->label->resize(110,140);
                            ground->landbutton[i][j]->label->move(260+122*i,130+145*j);
                            ground->landbutton[i][j]->movie->start();
                            ground->landbutton[i][j]->label->show();
                            ground->landbutton[i][j]->spikeweed->showlife = new QLabel(this);
                            ground->landbutton[i][j]->spikeweed->showlife->setText(QString::number(ground->landbutton[i][j]->spikeweed->life));
                            ground->landbutton[i][j]->spikeweed->showlife->move(260+122*i,130+145*j);
                            ground->landbutton[i][j]->spikeweed->showlife->show();
                            ground->land[i][j]=7;
                            landbar::choose = 0;

                        }
                    }
                    else if(landbar::choose==8 and ground->landtype[i][j] ==2)
                    {
                        qDebug()<<landbar::choose;
                        if(Sun::num_of_sun>=125)
                        {
                            Sun::num_of_sun-=125;
                            this->sunline.setText(QString::number(Sun::num_of_sun));
                            ground->landbutton[i][j]->yuanwall = new Yuanwall();
                            ground->landbutton[i][j]->yuanwall->col = i;//qDebug()<<i;
                            ground->landbutton[i][j]->yuanwall->row = j;//qDebug()<<j;
                            //qDebug()<<"ye wen vs zom"<<i<<j;
                            connect(ground->landbutton[i][j]->yuanwall->pin,&QTimer::timeout,[=](){
                                qDebug()<<"pin!";
                                if(ground->landbutton[i][j]->yuanwall->lf == true){
                                for(int find = i+1;find<ground->col;find++)
                                {
                                    qDebug()<<"join for";
                                    if(ground->landtype[find][j]==1 and ground->land[find][j] == 0)
                                    {
                                        qDebug()<<"join if"<<find;
                                        ground->landbutton[find][j]->label=new QLabel(this);
                                        ground->landbutton[find][j]->wallnut = new Wallnut();
                                        ground->landbutton[find][j]->wallnut->showlife = new QLabel(this);
                                        ground->landbutton[find][j]->wallnut->showlife->setText(QString::number(ground->landbutton[find][j]->wallnut->life));
                                        ground->landbutton[find][j]->wallnut->showlife->move(260+122*find,130+145*j);
                                        ground->landbutton[find][j]->wallnut->showlife->show();
                                        ground->landbutton[find][j]->movie = new QMovie(":/Image/wallnut.gif");
                                        ground->landbutton[find][j]->label->setMovie(ground->landbutton[find][j]->movie);
                                        ground->landbutton[find][j]->label->resize(110,140);
                                        ground->landbutton[find][j]->label->move(260+122*find,130+145*j);
                                        ground->landbutton[find][j]->movie->start();
                                        ground->landbutton[find][j]->label->show();
                                        ground->land[find][j]=3;
                                        break;
                                    }
                                }
                                }
                                else{
                                    int rfind = -1;
                                    for(int find = i+1;find<ground->col;find++)
                                    {
                                        qDebug()<<"join for";
                                        if(ground->landtype[find][j]==1 and ground->land[find][j] == 0)
                                        {
//                                            qDebug()<<"join if"<<find;
//                                            ground->landbutton[find][j]->label=new QLabel(this);
//                                            ground->landbutton[find][j]->wallnut = new Wallnut();
//                                            ground->landbutton[find][j]->wallnut->showlife = new QLabel(this);
//                                            ground->landbutton[find][j]->wallnut->showlife->setText(QString::number(ground->landbutton[find][j]->wallnut->life));
//                                            ground->landbutton[find][j]->wallnut->showlife->move(260+122*find,130+145*j);
//                                            ground->landbutton[find][j]->wallnut->showlife->show();
//                                            ground->landbutton[find][j]->movie = new QMovie(":/Image/wallnut.gif");
//                                            ground->landbutton[find][j]->label->setMovie(ground->landbutton[find][j]->movie);
//                                            ground->landbutton[find][j]->label->resize(110,140);
//                                            ground->landbutton[find][j]->label->move(260+122*find,130+145*j);
//                                            ground->landbutton[find][j]->movie->start();
//                                            ground->landbutton[find][j]->label->show();
//                                            ground->land[find][j]=3;
//                                            break;
                                            rfind = find;
                                        }
                                    }
                                    if(rfind != -1){
                                        int find = rfind;
                                        qDebug()<<"join if"<<find;
                                        ground->landbutton[find][j]->label=new QLabel(this);
                                        ground->landbutton[find][j]->wallnut = new Wallnut();
                                        ground->landbutton[find][j]->wallnut->showlife = new QLabel(this);
                                        ground->landbutton[find][j]->wallnut->showlife->setText(QString::number(ground->landbutton[find][j]->wallnut->life));
                                        ground->landbutton[find][j]->wallnut->showlife->move(260+122*find,130+145*j);
                                        ground->landbutton[find][j]->wallnut->showlife->show();
                                        ground->landbutton[find][j]->movie = new QMovie(":/Image/wallnut.gif");
                                        ground->landbutton[find][j]->label->setMovie(ground->landbutton[find][j]->movie);
                                        ground->landbutton[find][j]->label->resize(110,140);
                                        ground->landbutton[find][j]->label->move(260+122*find,130+145*j);
                                        ground->landbutton[find][j]->movie->start();
                                        ground->landbutton[find][j]->label->show();
                                        ground->land[find][j]=3;
                                    }
                                }

                            });
                            ground->landbutton[i][j]->movie = new QMovie(":/Image/yuan_wall.gif");
                            ground->landbutton[i][j]->label->setMovie(ground->landbutton[i][j]->movie);
                            ground->landbutton[i][j]->label->setAlignment(Qt::AlignCenter);
                            ground->landbutton[i][j]->label->resize(110,140);
                            ground->landbutton[i][j]->label->move(260+122*i,130+145*j);
                            ground->landbutton[i][j]->movie->start();
                            ground->landbutton[i][j]->label->show();
                            ground->landbutton[i][j]->yuanwall->showlife = new QLabel(this);
                            ground->landbutton[i][j]->yuanwall->showlife->setText(QString::number(ground->landbutton[i][j]->yuanwall->life));
                            ground->landbutton[i][j]->yuanwall->showlife->move(260+122*i,130+145*j);
                            ground->landbutton[i][j]->yuanwall->showlife->show();
                            ground->land[i][j]=8;
                            landbar::choose = 0;
                            ground->landbutton[i][j]->yuanwall->buttongroup = new QGroupBox(this);
                            QRadioButton *cl = new QRadioButton("l");
                            cl->setText("l");
                            QRadioButton *cr = new QRadioButton("r");
                            cr->setText("r");
                            QVBoxLayout *layout = new QVBoxLayout;
                            layout->addWidget(cl);
                            layout->addWidget(cr);
                            ground->landbutton[i][j]->yuanwall->buttongroup->setLayout(layout);
                            ground->landbutton[i][j]->yuanwall->buttongroup->setGeometry(260+122*i-20,130+145*j,110,120);
                            connect(cl, &QRadioButton::clicked, [=](){
                                    ground->landbutton[i][j]->yuanwall->lf = true;
                            });
                            connect(cr, &QRadioButton::clicked, [=](){
                                    ground->landbutton[i][j]->yuanwall->lf = false;
                            });
                            ground->landbutton[i][j]->yuanwall->buttongroup->show();
                        }


                    }
                }
                else if(landbar::choose==4)
                {
                    qDebug()<<4;
                    ground->landbutton[i][j]->label->clear();
                    if(ground->land[i][j]==1)
                    {
                        ground->landbutton[i][j]->sunflower->showlife->clear();
                        ground->landbutton[i][j]->sunflower->~Sunflower();

                    }
                    else if(ground->land[i][j]==2)
                    {
                        ground->landbutton[i][j]->peashooter->showlife->clear();
                        ground->landbutton[i][j]->peashooter->~Peashooter();

                    }
                    else if(ground->land[i][j]==3)
                    {
                        ground->landbutton[i][j]->wallnut->showlife->clear();
                        ground->landbutton[i][j]->wallnut->~Wallnut();
                    }
                    else if(ground->land[i][j]==5)
                    {
                        ground->landbutton[i][j]->skyshooter->showlife->clear();
                        ground->landbutton[i][j]->skyshooter->~Skyshooter();
                    }
                    else if(ground->land[i][j]==6)
                    {
                        ground->landbutton[i][j]->quanji->showlife->clear();
                        ground->landbutton[i][j]->quanji->~Quanji();
                    }
                    else if(ground->land[i][j]==7)
                    {
                        ground->landbutton[i][j]->spikeweed->showlife->clear();
                        ground->landbutton[i][j]->spikeweed->~Spikeweed();
                    }
                    else if(ground->land[i][j]==8)
                    {
                        ground->landbutton[i][j]->yuanwall->showlife->clear();
                        ground->landbutton[i][j]->yuanwall->buttongroup->close();
                        ground->landbutton[i][j]->yuanwall->~Yuanwall();
                    }
                    ground->land[i][j]=0;
                    landbar::choose = 0;
                }
            });
        }
    }
    timeId1 = startTimer(10000);
    timeId2 = startTimer(200000);
    timeId3 = startTimer(22222);
    timeId4 = startTimer(33000);
}

void level::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/Image/background_daytime.png");
    painter.drawPixmap(0,0,pix.width()*1.5,pix.height()*1.5,pix);

    pix.load(":/Image/SunBack.png");
    painter.drawPixmap(0,0,pix.width()*2,pix.height()*2,pix);

    pix.load(":/Image/SeedChooser_Background.png");
    painter.drawPixmap(1200-150,0,pix.width(),pix.height(),pix);
}

void level::timerEvent(QTimerEvent *event)
{
    if(event->timerId()==timeId1 /*and first ==1*/)
    {
//        first = 0;
        r = floor[rand()%num_of_floor];
//        r =0 ;
        zom_type = rand()%num_of_floorzom;//暂时只有四种地面僵尸 TODO
        if(zom_type == 0){//移动并攻击我方近战单位，攻击范围为自己所在的格子
        Zombie_0*zombie = new Zombie_0;
        zombie->y = 130+145*r;
        zombie->row = r;
        zombie->labelzom=new QLabel(this);
        QMovie*movie = new QMovie(":/Image/Zombie_0_walk.gif");
        QMovie*movie2 = new QMovie(":/Image/Zombie_0_eat.gif");
        zombie->labelzom->setMovie(movie);
        zombie->labelzom->setAlignment(Qt::AlignCenter);
        zombie->labelzom->resize(120,130);
        zombie->showlife = new QLabel(this);
        connect(zombie->pin,&QTimer::timeout,[=](){
            int st = (zombie->x-160)/122;
            zombie->showlife->setText(QString::number(zombie->life));
            zombie->showlife->move(zombie->x,zombie->y);
            zombie->showlife->show();
            if(st<0 and first == 1)
            {
                first = 0;
                Gameover*gameover = new Gameover;
                killTimer(timeId1);
                killTimer(timeId2);
                killTimer(timeId3);
                killTimer(timeId4);
                this->close();
                gameover->setWindowTitle("you lost");
                gameover->resize(900,600);
                gameover->show();

            }
            if(st>=9 or ground->land[st][zombie->row]==0 or ground->land[st][zombie->row]==2 or ground->land[st][zombie->row]==5 or ground->land[st][zombie->row]==7 or ground->land[st][zombie->row]==8)//该格子上为远程植物或者没植物 TODO:补充更多远程的
            {
                zombie->labelzom->setMovie(movie);
                zombie->x-=1;
                zombie->labelzom->move(zombie->x,zombie->y);
                zombie->labelzom->show();
                //更新位置到地面僵尸链表中
    //           qDebug()<<st;
    //           insert_intail(Head[8][0],zombie);
               if(st<9 and st>=0)
               {
                    if(zombie->st >8)
                    {
                        insert_intail(Head[st][zombie->row],zombie);
                        //qDebug()<<1;
                        zombie->st = 8;
                    }
                    else if(st<zombie->st)
                    {
                        delete_node(Head[zombie->st][zombie->row],zombie);
                        insert_intail(Head[st][zombie->row],zombie);
                        zombie->st = st;
                    }
               }
                movie->start();
            }
            else if(st<=8 and st>=0 and ground->land[st][zombie->row]!=0)//遇到近战植物
            {
                if(st<zombie->st)
                {
                    delete_node(Head[zombie->st][zombie->row],zombie);
                    insert_intail(Head[st][zombie->row],zombie);
                    zombie->st = st;
                }
                qDebug()<<"僵尸识别出了植物";
                zombie->labelzom->setMovie(movie2);
                if(ground->land[st][zombie->row] == 1)
                {
                    ground->landbutton[st][zombie->row]->sunflower->life -= 1;
                    ground->landbutton[st][zombie->row]->sunflower->showlife->setText(QString::number(ground->landbutton[st][zombie->row]->sunflower->life));
                    if(ground->landbutton[st][zombie->row]->sunflower->life<=0)
                    {
                        ground->landbutton[st][zombie->row]->sunflower->showlife->clear();
                        ground->landbutton[st][zombie->row]->label->clear();
                        ground->landbutton[st][zombie->row]->sunflower->~Sunflower();
                        ground->land[st][zombie->row]=0;
                     }
                }
//                else if(ground->land[st][zombie->row] == 2)
//                {
//                    ground->landbutton[st][zombie->row]->peashooter->life -= 1;
//                    if(ground->landbutton[st][zombie->row]->peashooter->life<=0)
//                    {
//                        ground->landbutton[st][zombie->row]->label->clear();
//                        ground->landbutton[st][zombie->row]->peashooter->~Peashooter();
//                        ground->land[st][zombie->row]=0;
//                    }
//                }
                else if(ground->land[st][zombie->row] == 3)
                {
                    ground->landbutton[st][zombie->row]->wallnut->life -= 1;
                    ground->landbutton[st][zombie->row]->wallnut->showlife->setText(QString::number(ground->landbutton[st][zombie->row]->wallnut->life));
                    if(ground->landbutton[st][zombie->row]->wallnut->life<=0)
                    {
                        ground->landbutton[st][zombie->row]->wallnut->showlife->clear();
                        ground->landbutton[st][zombie->row]->label->clear();
                        ground->landbutton[st][zombie->row]->wallnut->~Wallnut();
                        ground->land[st][zombie->row]=0;

                    }
                }
                else if(ground->land[st][zombie->row] == 6)
                {
                    ground->landbutton[st][zombie->row]->quanji->life -= 1;
                    ground->landbutton[st][zombie->row]->quanji->showlife->setText(QString::number(ground->landbutton[st][zombie->row]->quanji->life));
                    if(ground->landbutton[st][zombie->row]->quanji->life<=0)
                    {
                        ground->landbutton[st][zombie->row]->quanji->showlife->clear();
                        ground->landbutton[st][zombie->row]->label->clear();
                        ground->landbutton[st][zombie->row]->quanji->~Quanji();
                        ground->land[st][zombie->row]=0;
                    }
                }
                movie2->start();
            }

        });
        }
        else if(zom_type == 1){//移动并攻击我方近战单位，攻击范围严格大于一格
        Zombie_1*zombie = new Zombie_1;
        zombie->y = 130+145*r;
        zombie->row = r;
        zombie->labelzom=new QLabel(this);
        QMovie*movie = new QMovie(":/Image/Zombie_1_walk.gif");
        QMovie*movie2 = new QMovie(":/Image/Zombie_1_eat.gif");
        zombie->labelzom->setMovie(movie);
        zombie->labelzom->setAlignment(Qt::AlignCenter);
        zombie->labelzom->resize(120,130);
        zombie->showlife = new QLabel(this);
        connect(zombie->pin,&QTimer::timeout,[=](){
            int st = (zombie->x-160)/122;
            zombie->showlife->setText(QString::number(zombie->life));
            zombie->showlife->move(zombie->x,zombie->y);
            zombie->showlife->show();
            if(st<0 and first == 1)
            {
                first = 0;
                Gameover*gameover = new Gameover;
                killTimer(timeId1);
                killTimer(timeId2);
                killTimer(timeId3);
                killTimer(timeId4);
                this->close();
                gameover->setWindowTitle("you lost");
                gameover->resize(900,600);
                gameover->show();

            }
            if(twonone(ground,st,zombie->row))//远程或者没植物 TODO:补充更多远程的
            {
                zombie->labelzom->setMovie(movie);
                zombie->x-=1;
                zombie->labelzom->move(zombie->x,zombie->y);
                zombie->labelzom->show();
                //更新位置到地面僵尸链表中
    //           qDebug()<<st;
    //           insert_intail(Head[8][0],zombie);
               if(st<9 and st>=0)
               {
                    if(zombie->st >8)
                    {
                        insert_intail(Head[st][zombie->row],zombie);
                        //qDebug()<<1;
                        zombie->st = 8;
                    }
                    else if(st<zombie->st)
                    {
                        delete_node(Head[zombie->st][zombie->row],zombie);
                        insert_intail(Head[st][zombie->row],zombie);
                        zombie->st = st;
                    }
               }
                movie->start();
            }
            else if(st<=8 and st>=0 and !twonone(ground,st,zombie->row))//遇到近战植物
            {
                if(st<zombie->st)
                {
                    delete_node(Head[zombie->st][zombie->row],zombie);
                    insert_intail(Head[st][zombie->row],zombie);
                    zombie->st = st;
                }
                qDebug()<<"僵尸识别出了植物"<<st;
                zombie->labelzom->setMovie(movie2);
                if(ground->land[st][zombie->row] == 1)
                {
                    ground->landbutton[st][zombie->row]->sunflower->life -= 1;
                    ground->landbutton[st][zombie->row]->sunflower->showlife->setText(QString::number(ground->landbutton[st][zombie->row]->sunflower->life));
                    if(ground->landbutton[st][zombie->row]->sunflower->life<=0)
                    {
                        ground->landbutton[st][zombie->row]->sunflower->showlife->clear();
                        ground->landbutton[st][zombie->row]->label->clear();
                        ground->landbutton[st][zombie->row]->sunflower->~Sunflower();
                        ground->land[st][zombie->row]=0;
                     }
                }
//                else if(ground->land[st][zombie->row] == 2)
//                {
//                    ground->landbutton[st][zombie->row]->peashooter->life -= 1;
//                    if(ground->landbutton[st][zombie->row]->peashooter->life<=0)
//                    {
//                        ground->landbutton[st][zombie->row]->label->clear();
//                        ground->landbutton[st][zombie->row]->peashooter->~Peashooter();
//                        ground->land[st][zombie->row]=0;
//                    }
//                }
                else if(ground->land[st][zombie->row] == 3)
                {
                    ground->landbutton[st][zombie->row]->wallnut->life -= 1;
                    ground->landbutton[st][zombie->row]->wallnut->showlife->setText(QString::number(ground->landbutton[st][zombie->row]->wallnut->life));
                    if(ground->landbutton[st][zombie->row]->wallnut->life<=0)
                    {
                        ground->landbutton[st][zombie->row]->wallnut->showlife->clear();
                        ground->landbutton[st][zombie->row]->label->clear();
                        ground->landbutton[st][zombie->row]->wallnut->~Wallnut();
                        ground->land[st][zombie->row]=0;
                    }
                }
                else if(ground->land[st][zombie->row] == 6)
                {
                    ground->landbutton[st][zombie->row]->quanji->life -= 1;
                    ground->landbutton[st][zombie->row]->quanji->showlife->setText(QString::number(ground->landbutton[st][zombie->row]->quanji->life));
                    if(ground->landbutton[st][zombie->row]->quanji->life<=0)
                    {
                        ground->landbutton[st][zombie->row]->quanji->showlife->clear();
                        ground->landbutton[st][zombie->row]->label->clear();
                        ground->landbutton[st][zombie->row]->quanji->~Quanji();
                        ground->land[st][zombie->row]=0;
                    }
                }
                else if(st-1>=0 and (ground->land[st-1][zombie->row] == 1 or ground->land[st-1][zombie->row] == 3 or ground->land[st-1][zombie->row] == 6))
                {
                        if(ground->land[st-1][zombie->row] == 1)
                        {
                            ground->landbutton[st-1][zombie->row]->sunflower->life -= 1;
                            ground->landbutton[st-1][zombie->row]->sunflower->showlife->setText(QString::number(ground->landbutton[st-1][zombie->row]->sunflower->life));
                            if(ground->landbutton[st-1][zombie->row]->sunflower->life<=0)
                            {
                                ground->landbutton[st-1][zombie->row]->sunflower->showlife->clear();
                                ground->landbutton[st-1][zombie->row]->label->clear();
                                ground->landbutton[st-1][zombie->row]->sunflower->~Sunflower();
                                ground->land[st-1][zombie->row]=0;
                             }
                        }
                        else if(ground->land[st-1][zombie->row] == 3)
                        {
                            ground->landbutton[st-1][zombie->row]->wallnut->life -= 1;
                            ground->landbutton[st-1][zombie->row]->wallnut->showlife->setText(QString::number(ground->landbutton[st-1][zombie->row]->wallnut->life));
                            if(ground->landbutton[st-1][zombie->row]->wallnut->life<=0)
                            {
                                ground->landbutton[st-1][zombie->row]->wallnut->showlife->clear();
                                ground->landbutton[st-1][zombie->row]->label->clear();
                                ground->landbutton[st-1][zombie->row]->wallnut->~Wallnut();
                                ground->land[st-1][zombie->row]=0;
                            }
                        }
                        else if(ground->land[st-1][zombie->row] == 6)
                        {
                            ground->landbutton[st-1][zombie->row]->quanji->life -= 1;
                            ground->landbutton[st-1][zombie->row]->quanji->showlife->setText(QString::number(ground->landbutton[st-1][zombie->row]->quanji->life));
                            if(ground->landbutton[st-1][zombie->row]->quanji->life<=0)
                            {
                                ground->landbutton[st-1][zombie->row]->quanji->showlife->clear();
                                ground->landbutton[st-1][zombie->row]->label->clear();
                                ground->landbutton[st-1][zombie->row]->quanji->~Quanji();
                                ground->land[st-1][zombie->row]=0;
                            }
                        }
                  }
                    else if(st-2>=0)
                    {
                        if(ground->land[st-2][zombie->row] == 1)
                        {
                            ground->landbutton[st-2][zombie->row]->sunflower->life -= 1;
                            ground->landbutton[st-2][zombie->row]->sunflower->showlife->setText(QString::number(ground->landbutton[st-2][zombie->row]->sunflower->life));
                            if(ground->landbutton[st-2][zombie->row]->sunflower->life<=0)
                            {
                                ground->landbutton[st-2][zombie->row]->sunflower->showlife->clear();
                                ground->landbutton[st-2][zombie->row]->label->clear();
                                ground->landbutton[st-2][zombie->row]->sunflower->~Sunflower();
                                ground->land[st-2][zombie->row]=0;
                             }
                        }
                        else if(ground->land[st-2][zombie->row] == 3)
                        {
                            ground->landbutton[st-2][zombie->row]->wallnut->life -= 1;
                            ground->landbutton[st-2][zombie->row]->wallnut->showlife->setText(QString::number(ground->landbutton[st-2][zombie->row]->wallnut->life));
                            if(ground->landbutton[st-2][zombie->row]->wallnut->life<=0)
                            {
                                ground->landbutton[st-2][zombie->row]->wallnut->showlife->clear();
                                ground->landbutton[st-2][zombie->row]->label->clear();
                                ground->landbutton[st-2][zombie->row]->wallnut->~Wallnut();
                                ground->land[st-2][zombie->row]=0;
                            }
                        }
                        else if(ground->land[st-2][zombie->row] == 6)
                        {
                            ground->landbutton[st-2][zombie->row]->quanji->life -= 1;
                            ground->landbutton[st-2][zombie->row]->quanji->showlife->setText(QString::number(ground->landbutton[st-2][zombie->row]->quanji->life));
                            if(ground->landbutton[st-2][zombie->row]->quanji->life<=0)
                            {
                                ground->landbutton[st-2][zombie->row]->quanji->showlife->clear();
                                ground->landbutton[st-2][zombie->row]->label->clear();
                                ground->landbutton[st-2][zombie->row]->quanji->~Quanji();
                                ground->land[st-2][zombie->row]=0;
                            }
                        }
                    }
                movie2->start();
            }

        });
        }
        if(zom_type == 2){
        Zombie_2*zombie = new Zombie_2;
        zombie->y = 130+145*r;
        zombie->row = r;
        zombie->labelzom=new QLabel(this);
        QMovie*movie = new QMovie(":/Image/Zombie_2_walk.gif");
        QMovie*movie2 = new QMovie(":/Image/Zombie_2_eat.gif");
        zombie->labelzom->setMovie(movie);
        zombie->labelzom->setAlignment(Qt::AlignCenter);
        zombie->labelzom->resize(120,130);
        zombie->showlife = new QLabel(this);
        connect(zombie->pin,&QTimer::timeout,[=](){
            zombie->showlife->setText(QString::number(zombie->life));
            zombie->showlife->move(zombie->x,zombie->y);
            zombie->showlife->show();
            int st = (zombie->x-160)/122;
            if(st<0 and first == 1)
            {
                first = 0;
                Gameover*gameover = new Gameover;
                killTimer(timeId1);
                killTimer(timeId2);
                killTimer(timeId3);
                killTimer(timeId4);
                this->close();
                gameover->setWindowTitle("you lost");
                gameover->resize(900,600);
                gameover->show();

            }
            if(st>=9 or ground->land[st][zombie->row]==0 or ground->land[st][zombie->row]==7)//如果加入了空中单位可能就要修改了 TODO
            {
                zombie->labelzom->setMovie(movie);
                zombie->x-=1;
                zombie->labelzom->move(zombie->x,zombie->y);
                zombie->labelzom->show();
                //更新位置到链表中
     //          qDebug()<<st;
    //           insert_intail(Head[8][0],zombie);
               if(st<9 and st>=0)
               {
                    if(zombie->st >8)
                    {
                        insert_intail(Head[st][zombie->row],zombie);
                        //qDebug()<<1;
                        zombie->st = 8;
                    }
                    else if(st<zombie->st)
                    {
                        delete_node(Head[zombie->st][zombie->row],zombie);
                        insert_intail(Head[st][zombie->row],zombie);
                        zombie->st = st;
                    }
               }
                movie->start();
            }
            else if(st<=8 and st>=0 and ground->land[st][zombie->row]!=0 and ground->land[st][zombie->row]!=7)
            {
                if(st<zombie->st)
                {
                    delete_node(Head[zombie->st][zombie->row],zombie);
                    insert_intail(Head[st][zombie->row],zombie);
                    zombie->st = st;
                }
                qDebug()<<"僵尸识别出了植物"<<st<<(Head[st][zombie->row]==NULL);
                zombie->labelzom->setMovie(movie2);
                if(ground->land[st][zombie->row] == 1)
                {
                    ground->landbutton[st][zombie->row]->sunflower->life -= 1;
                    ground->landbutton[st][zombie->row]->sunflower->showlife->setText(QString::number(ground->landbutton[st][zombie->row]->sunflower->life));
                    if(ground->landbutton[st][zombie->row]->sunflower->life<=0)
                    {
                        ground->landbutton[st][zombie->row]->sunflower->showlife->clear();;
                        ground->landbutton[st][zombie->row]->label->clear();
                        ground->landbutton[st][zombie->row]->sunflower->~Sunflower();
                        ground->land[st][zombie->row]=0;
                     }
                }
                else if(ground->land[st][zombie->row] == 2)
                {
                    ground->landbutton[st][zombie->row]->peashooter->life -= 1;
                    ground->landbutton[st][zombie->row]->peashooter->showlife->setText(QString::number(ground->landbutton[st][zombie->row]->peashooter->life));
                    if(ground->landbutton[st][zombie->row]->peashooter->life<=0)
                    {
                        ground->landbutton[st][zombie->row]->peashooter->showlife->clear();
                        ground->landbutton[st][zombie->row]->label->clear();
                        ground->landbutton[st][zombie->row]->peashooter->~Peashooter();
                        ground->land[st][zombie->row]=0;
                    }
                }
                else if(ground->land[st][zombie->row] == 3)
                {
                    ground->landbutton[st][zombie->row]->wallnut->life -= 1;
                    ground->landbutton[st][zombie->row]->wallnut->showlife->setText(QString::number(ground->landbutton[st][zombie->row]->wallnut->life));
                    if(ground->landbutton[st][zombie->row]->wallnut->life<=0)
                    {
                        ground->landbutton[st][zombie->row]->wallnut->showlife->clear();
                        ground->landbutton[st][zombie->row]->label->clear();
                        ground->landbutton[st][zombie->row]->wallnut->~Wallnut();
                        ground->land[st][zombie->row]=0;
                    }
                }
                else if(ground->land[st][zombie->row] == 5)
                {
                    ground->landbutton[st][zombie->row]->skyshooter->life -= 1;
                    ground->landbutton[st][zombie->row]->skyshooter->showlife->setText(QString::number(ground->landbutton[st][zombie->row]->skyshooter->life));
                    if(ground->landbutton[st][zombie->row]->skyshooter->life<=0)
                    {
                        ground->landbutton[st][zombie->row]->skyshooter->showlife->clear();
                        ground->landbutton[st][zombie->row]->label->clear();
                        ground->landbutton[st][zombie->row]->skyshooter->~Skyshooter();
                        ground->land[st][zombie->row]=0;
                    }
                }
                else if(ground->land[st][zombie->row] == 6)
                {
                    ground->landbutton[st][zombie->row]->quanji->life -= 1;
                    ground->landbutton[st][zombie->row]->quanji->showlife->setText(QString::number(ground->landbutton[st][zombie->row]->quanji->life));
                    if(ground->landbutton[st][zombie->row]->quanji->life<=0)
                    {
                        ground->landbutton[st][zombie->row]->quanji->showlife->clear();
                        ground->landbutton[st][zombie->row]->label->clear();
                        ground->landbutton[st][zombie->row]->quanji->~Quanji();
                        ground->land[st][zombie->row]=0;
                    }
                }
                else if(ground->land[st][zombie->row] == 8)
                {
                    ground->landbutton[st][zombie->row]->yuanwall->life -= 1;
                    ground->landbutton[st][zombie->row]->yuanwall->showlife->setText(QString::number(ground->landbutton[st][zombie->row]->yuanwall->life));
                    if(ground->landbutton[st][zombie->row]->yuanwall->life<=0)
                    {
                        ground->landbutton[st][zombie->row]->yuanwall->buttongroup->close();
                        ground->landbutton[st][zombie->row]->yuanwall->showlife->clear();
                        ground->landbutton[st][zombie->row]->label->clear();
                        ground->landbutton[st][zombie->row]->yuanwall->~Yuanwall();
                        ground->land[st][zombie->row]=0;
                    }
                }
                movie2->start();
            }

        });
        }
        if(zom_type == 3){
        Zombie_3*zombie = new Zombie_3;
        zombie->y = 130+145*r;
        zombie->row = r;
        zombie->labelzom=new QLabel(this);
        QMovie*movie = new QMovie(":/Image/Zombie_3_walk.gif");
        QMovie*movie2 = new QMovie(":/Image/Zombie_3_eat.gif");
        QMovie*movie3 = new QMovie(":/Image/heart.gif");
        zombie->labelzom->setMovie(movie);
        zombie->labelzom->setAlignment(Qt::AlignCenter);
        zombie->labelzom->resize(120,130);
        zombie->showlife = new QLabel(this);
        connect(zombie->pin,&QTimer::timeout,[=](){
            zombie->showlife->setText(QString::number(zombie->life));
            zombie->showlife->move(zombie->x,zombie->y);
            zombie->showlife->show();
            if(zombie->times==400)
            {
                if(zombie->time2==0)
                {
                    zombie->labelzom->setMovie(movie3);
                    zombie->labelzom->resize(120,130);
                    movie3->start();
                    zombie->time2++;
                }
                else if(zombie->time2==20)
                {
                    zombie->times=0;
                    zombie->time2 =0;
                    int st = (zombie->x-160)/122;
                    if(st>=0 and st<9)
                    {
                        ZombieList p =  Head[st][zombie->row];
                        while(p!=NULL)
                        {
                            switch (p->type) {
                            case 0:
                                p->zombie->life = p->zombie->life + 10;
                                break;
                            case 1:
                                p->zombie_1->life = p->zombie_1->life + 10;
                                break;
                            case 2:
                                p->zombie_2->life = p->zombie_2->life + 10;
                                break;
                            case 3:
                                p->zombie_3->life = p->zombie_3->life + 10;
                                break;
                            }
                            p = p->next;
                        }
                    }
                }
                else
                    zombie->time2++;
            }
            else{
            zombie->times++;
            int st = (zombie->x-160)/122;
            if(st<0 and first == 1)
            {
                first = 0;
                Gameover*gameover = new Gameover;
                killTimer(timeId1);
                killTimer(timeId2);
                killTimer(timeId3);
                killTimer(timeId4);
                this->close();
                gameover->setWindowTitle("you lost");
                gameover->resize(900,600);
                gameover->show();

            }
            if(st>=9 or ground->land[st][zombie->row]==0 or ground->land[st][zombie->row]==7)//如果加入了空中单位可能就要修改了 TODO
            {
                zombie->labelzom->setMovie(movie);
                zombie->x-=1;
                zombie->labelzom->move(zombie->x,zombie->y);
                zombie->labelzom->show();
                //更新位置到链表中
     //          qDebug()<<st;
    //           insert_intail(Head[8][0],zombie);
               if(st<9 and st>=0)
               {
                    if(zombie->st >8)
                    {
                        insert_intail(Head[st][zombie->row],zombie);
                        //qDebug()<<1;
                        zombie->st = 8;
                    }
                    else if(st<zombie->st)
                    {
                        delete_node(Head[zombie->st][zombie->row],zombie);
                        insert_intail(Head[st][zombie->row],zombie);
                        zombie->st = st;
                    }
               }
                movie->start();
            }
            else if(st<=8 and st>=0 and ground->land[st][zombie->row]!=0 and ground->land[st][zombie->row]!=7)
            {
                if(st<zombie->st)
                {
                    delete_node(Head[zombie->st][zombie->row],zombie);
                    insert_intail(Head[st][zombie->row],zombie);
                    zombie->st = st;
                }
                qDebug()<<"僵尸识别出了植物"<<st;
                zombie->labelzom->setMovie(movie2);
                if(ground->land[st][zombie->row] == 1)
                {
                    ground->landbutton[st][zombie->row]->sunflower->life -= 1;
                    ground->landbutton[st][zombie->row]->sunflower->showlife->setText(QString::number(ground->landbutton[st][zombie->row]->sunflower->life));
                    if(ground->landbutton[st][zombie->row]->sunflower->life<=0)
                    {
                        ground->landbutton[st][zombie->row]->sunflower->showlife->clear();
                        ground->landbutton[st][zombie->row]->label->clear();
                        ground->landbutton[st][zombie->row]->sunflower->~Sunflower();
                        ground->land[st][zombie->row]=0;
                     }
                }
                else if(ground->land[st][zombie->row] == 2)
                {
                    ground->landbutton[st][zombie->row]->peashooter->life -= 1;
                    ground->landbutton[st][zombie->row]->peashooter->showlife->setText(QString::number(ground->landbutton[st][zombie->row]->peashooter->life));
                    if(ground->landbutton[st][zombie->row]->peashooter->life<=0)
                    {
                        ground->landbutton[st][zombie->row]->peashooter->showlife->clear();
                        ground->landbutton[st][zombie->row]->label->clear();
                        ground->landbutton[st][zombie->row]->peashooter->~Peashooter();
                        ground->land[st][zombie->row]=0;
                    }
                }
                else if(ground->land[st][zombie->row] == 3)
                {
                    ground->landbutton[st][zombie->row]->wallnut->life -= 1;
                    ground->landbutton[st][zombie->row]->wallnut->showlife->setText(QString::number(ground->landbutton[st][zombie->row]->wallnut->life));
                    if(ground->landbutton[st][zombie->row]->wallnut->life<=0)
                    {
                        ground->landbutton[st][zombie->row]->wallnut->showlife->clear();
                        ground->landbutton[st][zombie->row]->label->clear();
                        ground->landbutton[st][zombie->row]->wallnut->~Wallnut();
                        ground->land[st][zombie->row]=0;
                    }
                }
                else if(ground->land[st][zombie->row] == 5)
                {
                    ground->landbutton[st][zombie->row]->skyshooter->life -= 1;
                    ground->landbutton[st][zombie->row]->skyshooter->showlife->setText(QString::number(ground->landbutton[st][zombie->row]->skyshooter->life));
                    if(ground->landbutton[st][zombie->row]->skyshooter->life<=0)
                    {
                        ground->landbutton[st][zombie->row]->skyshooter->showlife->clear();
                        ground->landbutton[st][zombie->row]->label->clear();
                        ground->landbutton[st][zombie->row]->skyshooter->~Skyshooter();
                        ground->land[st][zombie->row]=0;
                    }
                }
                else if(ground->land[st][zombie->row] == 6)
                {
                    ground->landbutton[st][zombie->row]->quanji->life -= 1;
                    ground->landbutton[st][zombie->row]->quanji->showlife->setText(QString::number(ground->landbutton[st][zombie->row]->quanji->life));
                    if(ground->landbutton[st][zombie->row]->quanji->life<=0)
                    {
                        ground->landbutton[st][zombie->row]->quanji->showlife->clear();
                        ground->landbutton[st][zombie->row]->label->clear();
                        ground->landbutton[st][zombie->row]->quanji->~Quanji();
                        ground->land[st][zombie->row]=0;
                    }
                }
                else if(ground->land[st][zombie->row] == 8)
                {
                    ground->landbutton[st][zombie->row]->yuanwall->life -= 1;
                    ground->landbutton[st][zombie->row]->yuanwall->showlife->setText(QString::number(ground->landbutton[st][zombie->row]->yuanwall->life));
                    if(ground->landbutton[st][zombie->row]->yuanwall->life<=0)
                    {
                        ground->landbutton[st][zombie->row]->yuanwall->buttongroup->close();
                        ground->landbutton[st][zombie->row]->yuanwall->showlife->clear();
                        ground->landbutton[st][zombie->row]->label->clear();
                        ground->landbutton[st][zombie->row]->yuanwall->~Yuanwall();
                        ground->land[st][zombie->row]=0;
                    }
                }
                movie2->start();
            }
}
        });
        }
    }
    if(event->timerId()==timeId2 and first ==1)
    {
        first = 0;
        Gamewin*gamewin = new Gamewin;
        killTimer(timeId1);
        killTimer(timeId2);
        killTimer(timeId3);
        killTimer(timeId4);
        this->close();
        gamewin->setWindowTitle("you win");
        gamewin->resize(900,600);
        gamewin->show();
    }
    if(event->timerId()==timeId3)
    {

    }
    if(event->timerId()==timeId4)
    {
        r = sky[rand()%num_of_sky];
        zom_type = rand()%num_of_skyzom;
        if(zom_type == 0)
        {
            Zombie_7*zombie = new Zombie_7;
            zombie->y = 130+145*r;
            zombie->row = r;
            zombie->labelzom=new QLabel(this);
            QMovie*movie = new QMovie(":/Image/Zombie_7.gif");
            QMovie*movie2 = new QMovie(":/Image/Zombie_7.gif");
            zombie->labelzom->setMovie(movie);
            zombie->labelzom->setAlignment(Qt::AlignCenter);
            zombie->labelzom->resize(120,130);
            zombie->showlife = new QLabel(this);
            connect(zombie->pin,&QTimer::timeout,[=](){
                int st = (zombie->x-160)/122;
                zombie->showlife->setText(QString::number(zombie->life));
                zombie->showlife->move(zombie->x,zombie->y);
                zombie->showlife->show();
                if(st<0 and first == 1)
                {
                    first = 0;
                    Gameover*gameover = new Gameover;
                    killTimer(timeId1);
                    killTimer(timeId2);
                    killTimer(timeId3);
                    killTimer(timeId4);
                    this->close();
                    gameover->setWindowTitle("you lost");
                    gameover->resize(900,600);
                    gameover->show();

                }
                if(st>=9 or ground->land[st][zombie->row]==0 or ground->land[st][zombie->row]==7)//如果加入了空中单位可能就要修改了 TODO
                {
                    zombie->labelzom->setMovie(movie);
                    zombie->x-=1;
                    zombie->labelzom->move(zombie->x,zombie->y);
                    zombie->labelzom->show();
                    //更新位置到链表中
         //          qDebug()<<st;
        //           insert_intail(Head[8][0],zombie);
                   if(st<9 and st>=0)
                   {
                        if(zombie->st >8)
                        {
                            insert_intail(skyHead[st][zombie->row],zombie);
                            //qDebug()<<1;
                            zombie->st = 8;
                        }
                        else if(st<zombie->st)
                        {
                            delete_node(skyHead[zombie->st][zombie->row],zombie);
                            insert_intail(skyHead[st][zombie->row],zombie);
                            zombie->st = st;
                        }
                   }
                    movie->start();
                }
                else if(st<=8 and st>=0 and ground->land[st][zombie->row]!=0 and ground->land[st][zombie->row]!=7)
                {
                    if(st<zombie->st)
                    {
                        delete_node(skyHead[zombie->st][zombie->row],zombie);
                        insert_intail(skyHead[st][zombie->row],zombie);
                        zombie->st = st;
                    }
                    qDebug()<<"僵尸识别出了植物"<<st<<(skyHead[st][zombie->row]==NULL);
                    zombie->labelzom->setMovie(movie2);
                    if(ground->land[st][zombie->row] == 1)
                    {
                        ground->landbutton[st][zombie->row]->sunflower->life -= 1;
                        ground->landbutton[st][zombie->row]->sunflower->showlife->setText(QString::number(ground->landbutton[st][zombie->row]->sunflower->life));
                        if(ground->landbutton[st][zombie->row]->sunflower->life<=0)
                        {
                            ground->landbutton[st][zombie->row]->sunflower->showlife->clear();
                            ground->landbutton[st][zombie->row]->label->clear();
                            ground->landbutton[st][zombie->row]->sunflower->~Sunflower();
                            ground->land[st][zombie->row]=0;
                         }
                    }
                    else if(ground->land[st][zombie->row] == 2)
                    {
                        ground->landbutton[st][zombie->row]->peashooter->life -= 1;
                        ground->landbutton[st][zombie->row]->peashooter->showlife->setText(QString::number(ground->landbutton[st][zombie->row]->peashooter->life));
                        if(ground->landbutton[st][zombie->row]->peashooter->life<=0)
                        {
                            ground->landbutton[st][zombie->row]->peashooter->showlife->clear();
                            ground->landbutton[st][zombie->row]->label->clear();
                            ground->landbutton[st][zombie->row]->peashooter->~Peashooter();
                            ground->land[st][zombie->row]=0;
                        }
                    }
                    else if(ground->land[st][zombie->row] == 3)
                    {
                        ground->landbutton[st][zombie->row]->wallnut->life -= 1;
                        ground->landbutton[st][zombie->row]->wallnut->showlife->setText(QString::number(ground->landbutton[st][zombie->row]->wallnut->life));
                        if(ground->landbutton[st][zombie->row]->wallnut->life<=0)
                        {
                            ground->landbutton[st][zombie->row]->wallnut->showlife->clear();
                            ground->landbutton[st][zombie->row]->label->clear();
                            ground->landbutton[st][zombie->row]->wallnut->~Wallnut();
                            ground->land[st][zombie->row]=0;
                        }
                    }
                    else if(ground->land[st][zombie->row] == 5)
                    {
                        ground->landbutton[st][zombie->row]->skyshooter->life -= 1;
                        ground->landbutton[st][zombie->row]->skyshooter->showlife->setText(QString::number(ground->landbutton[st][zombie->row]->skyshooter->life));
                        if(ground->landbutton[st][zombie->row]->skyshooter->life<=0)
                        {
                            ground->landbutton[st][zombie->row]->skyshooter->showlife->clear();
                            ground->landbutton[st][zombie->row]->label->clear();
                            ground->landbutton[st][zombie->row]->skyshooter->~Skyshooter();
                            ground->land[st][zombie->row]=0;
                        }
                    }
                    else if(ground->land[st][zombie->row] == 6)
                    {
                        ground->landbutton[st][zombie->row]->quanji->life -= 1;
                        ground->landbutton[st][zombie->row]->quanji->showlife->setText(QString::number(ground->landbutton[st][zombie->row]->quanji->life));
                        if(ground->landbutton[st][zombie->row]->quanji->life<=0)
                        {
                            ground->landbutton[st][zombie->row]->quanji->showlife->clear();
                            ground->landbutton[st][zombie->row]->label->clear();
                            ground->landbutton[st][zombie->row]->quanji->~Quanji();
                            ground->land[st][zombie->row]=0;
                        }
                    }
                    else if(ground->land[st][zombie->row] == 8)
                    {
                        ground->landbutton[st][zombie->row]->yuanwall->life -= 1;
                        ground->landbutton[st][zombie->row]->yuanwall->showlife->setText(QString::number(ground->landbutton[st][zombie->row]->yuanwall->life));
                        if(ground->landbutton[st][zombie->row]->yuanwall->life<=0)
                        {
                            ground->landbutton[st][zombie->row]->yuanwall->buttongroup->close();
                            ground->landbutton[st][zombie->row]->yuanwall->showlife->clear();
                            ground->landbutton[st][zombie->row]->label->clear();
                            ground->landbutton[st][zombie->row]->yuanwall->~Yuanwall();
                            ground->land[st][zombie->row]=0;
                        }
                    }
                    movie2->start();
                }

            });
        }
        else if(zom_type == 1)
        {
            Zombie_8*zombie = new Zombie_8;
            zombie->y = 130+145*r;
            zombie->row = r;
            zombie->labelzom=new QLabel(this);
            QMovie*movie = new QMovie(":/Image/Zombie_8.gif");
//            QMovie*movie2 = new QMovie(":/Image/Zombie_8.gif");
            zombie->labelzom->setMovie(movie);
            zombie->labelzom->setAlignment(Qt::AlignCenter);
            zombie->labelzom->resize(120,130);
            zombie->showlife = new QLabel(this);
            connect(zombie->pin,&QTimer::timeout,[=](){
                zombie->showlife->setText(QString::number(zombie->life));
                zombie->showlife->move(zombie->x,zombie->y);
                zombie->showlife->show();
                zombie->labelzom->setMovie(movie);
                zombie->x-=1;
                zombie->labelzom->move(zombie->x,zombie->y);
                zombie->labelzom->show();
                movie->start();
                int st = (zombie->x-160)/122;
                if(st<0 and first == 1)
                {
                    first = 0;
                    Gameover*gameover = new Gameover;
                    killTimer(timeId1);
                    killTimer(timeId2);
                    killTimer(timeId3);
                    killTimer(timeId4);
                    this->close();
                    gameover->setWindowTitle("you lost");
                    gameover->resize(900,600);
                    gameover->show();

                }
                else if(st <9 and st>=0){
                        if(zombie->st >8)
                        {
                            insert_intail(skyHead[st][zombie->row],zombie);
                            qDebug()<<"join 8";
                            zombie->st = 8;
                        }
                        else if(st<zombie->st)
                        {
                            delete_node(skyHead[zombie->st][zombie->row],zombie);
                            qDebug()<<"out 8";
                            insert_intail(skyHead[st][zombie->row],zombie);
                            qDebug()<<"join 7";
                            zombie->st = st;
                        }
                        //qDebug()<<"plant begin";
                        if(ground->land[st][zombie->row] == 1)
                        {
                            ground->landbutton[st][zombie->row]->sunflower->life -= 1;
                            ground->landbutton[st][zombie->row]->sunflower->showlife->setText(QString::number(ground->landbutton[st][zombie->row]->sunflower->life));
                            if(ground->landbutton[st][zombie->row]->sunflower->life<=0)
                            {
                                ground->landbutton[st][zombie->row]->sunflower->showlife->clear();
                                ground->landbutton[st][zombie->row]->label->clear();
                                ground->landbutton[st][zombie->row]->sunflower->~Sunflower();
                                ground->land[st][zombie->row]=0;
                             }
                        }
                        else if(ground->land[st][zombie->row] == 2)
                        {
                            ground->landbutton[st][zombie->row]->peashooter->life -= 1;
                            ground->landbutton[st][zombie->row]->peashooter->showlife->setText(QString::number(ground->landbutton[st][zombie->row]->peashooter->life));
                            if(ground->landbutton[st][zombie->row]->peashooter->life<=0)
                            {
                                ground->landbutton[st][zombie->row]->peashooter->showlife->clear();
                                ground->landbutton[st][zombie->row]->label->clear();
                                ground->landbutton[st][zombie->row]->peashooter->~Peashooter();
                                ground->land[st][zombie->row]=0;
                            }
                        }
                        else if(ground->land[st][zombie->row] == 3)
                        {
                            ground->landbutton[st][zombie->row]->wallnut->life -= 1;
                            ground->landbutton[st][zombie->row]->wallnut->showlife->setText(QString::number(ground->landbutton[st][zombie->row]->wallnut->life));
                            if(ground->landbutton[st][zombie->row]->wallnut->life<=0)
                            {
                                ground->landbutton[st][zombie->row]->wallnut->showlife->clear();
                                ground->landbutton[st][zombie->row]->label->clear();
                                ground->landbutton[st][zombie->row]->wallnut->~Wallnut();
                                ground->land[st][zombie->row]=0;
                            }
                        }
                        else if(ground->land[st][zombie->row] == 5)
                        {
                            ground->landbutton[st][zombie->row]->skyshooter->life -= 1;
                            ground->landbutton[st][zombie->row]->skyshooter->showlife->setText(QString::number(ground->landbutton[st][zombie->row]->skyshooter->life));
                            if(ground->landbutton[st][zombie->row]->skyshooter->life<=0)
                            {
                                ground->landbutton[st][zombie->row]->skyshooter->showlife->clear();
                                ground->landbutton[st][zombie->row]->label->clear();
                                ground->landbutton[st][zombie->row]->skyshooter->~Skyshooter();
                                ground->land[st][zombie->row]=0;
                            }
                        }
                        else if(ground->land[st][zombie->row] == 6)
                        {
                            ground->landbutton[st][zombie->row]->quanji->life -= 1;
                            ground->landbutton[st][zombie->row]->quanji->showlife->setText(QString::number(ground->landbutton[st][zombie->row]->quanji->life));
                            if(ground->landbutton[st][zombie->row]->quanji->life<=0)
                            {
                                ground->landbutton[st][zombie->row]->quanji->showlife->clear();
                                ground->landbutton[st][zombie->row]->label->clear();
                                ground->landbutton[st][zombie->row]->quanji->~Quanji();
                                ground->land[st][zombie->row]=0;
                            }
                        }
                        else if(ground->land[st][zombie->row] == 8)
                        {
                            ground->landbutton[st][zombie->row]->yuanwall->life -= 1;
                            ground->landbutton[st][zombie->row]->yuanwall->showlife->setText(QString::number(ground->landbutton[st][zombie->row]->yuanwall->life));
                            if(ground->landbutton[st][zombie->row]->yuanwall->life<=0)
                            {
                                ground->landbutton[st][zombie->row]->yuanwall->buttongroup->close();
                                ground->landbutton[st][zombie->row]->yuanwall->showlife->clear();
                                ground->landbutton[st][zombie->row]->label->clear();
                                ground->landbutton[st][zombie->row]->yuanwall->~Yuanwall();
                                ground->land[st][zombie->row]=0;
                            }
                        }
                    }
            });
        }
    }
}

bool insert_intail(ZombieList& head,Zombie_0* zombie)//
{
    if(head == NULL)
    {
        head = new Node;
        head->zombie = zombie;
        head->type = 0;
        head->next = NULL;
        return 1;
        return 0;
    }
    else
    {   Node *q;
        Node *p;
        for(p=head;p!=NULL;p=p->next)
        {
            q=p;
        }
        q->next = new Node;
        q->next->next = NULL;
        q->next->zombie = zombie;
        q->next->type = 0;
        return 1;
    }
    return 0;
}

bool delete_node(ZombieList& head,Zombie_0*zombie)
{
    Node* p = head;
    Node *q = head;
    if(head ==NULL)
        return 0;
    else if(head->zombie == zombie)
    {
        head = head->next;
        delete p;
        qDebug()<<"释放了内存";
    }
    else
    {
        for(;p!=NULL;p=p->next)
        {
            if(p->zombie==zombie)
            {
                q->next = p->next;
                delete p;
                qDebug()<<"释放了内存";
                break;
            }
            else
            {
                q=p;
            }
        }
    }
    return 0;
}


void clear(ZombieList& head)
{
    if(head==NULL) return;
    Node* p = head;
    Node* q = NULL;
    while(p!=NULL)
    {
        q = p;
        p = p->next;
        delete q;
    }
    head = NULL;
}
bool insert_intail(ZombieList& head,Zombie_1* zombie)//
{
    if(head == NULL)
    {
        head = new Node;
        head->zombie_1 = zombie;
        head->type = 1;
        head->next = NULL;
        return 1;
        return 0;
    }
    else
    {   Node *q;
        Node *p;
        for(p=head;p!=NULL;p=p->next)
        {
            q=p;
        }
        q->next = new Node;
        q->next->next = NULL;
        q->next->zombie_1 = zombie;
        q->next->type = 1;
        return 1;
    }
    return 0;
}

bool delete_node(ZombieList& head,Zombie_1*zombie)
{
    Node* p = head;
    Node *q = head;
    if(head ==NULL)
        return 0;
    else if(head->zombie_1 == zombie)
    {
        head = head->next;
        delete p;
        qDebug()<<"释放了内存";
    }
    else
    {
        for(;p!=NULL;p=p->next)
        {
            if(p->zombie_1==zombie)
            {
                q->next = p->next;
                delete p;
                qDebug()<<"释放了内存";
                break;
            }
            else
            {
                q=p;
            }
        }
    }
    return 0;
}

bool insert_intail(ZombieList& head,Zombie_2* zombie)//
{
    if(head == NULL)
    {
        head = new Node;
        head->zombie_2 = zombie;
        head->type = 2;
        head->next = NULL;
        return 1;
        return 0;
    }
    else
    {   Node *q;
        Node *p;
        for(p=head;p!=NULL;p=p->next)
        {
            q=p;
        }
        q->next = new Node;
        q->next->next = NULL;
        q->next->zombie_2 = zombie;
        q->next->type = 2;
        return 1;
    }
    return 0;
}

bool delete_node(ZombieList& head,Zombie_2*zombie)
{
    Node* p = head;
    Node *q = head;
    if(head ==NULL)
        return 0;
    else if(head->zombie_2 == zombie)
    {
        head = head->next;
        delete p;
        qDebug()<<"释放了内存";
    }
    else
    {
        for(;p!=NULL;p=p->next)
        {
            if(p->zombie_2==zombie)
            {
                q->next = p->next;
                delete p;
                qDebug()<<"释放了内存";
                break;
            }
            else
            {
                q=p;
            }
        }
    }
    return 0;
}

bool insert_intail(ZombieList& head,Zombie_3* zombie)//
{
    if(head == NULL)
    {
        head = new Node;
        head->zombie_3 = zombie;
        head->type = 3;
        head->next = NULL;
        return 1;
        return 0;
    }
    else
    {   Node *q;
        Node *p;
        for(p=head;p!=NULL;p=p->next)
        {
            q=p;
        }
        q->next = new Node;
        q->next->next = NULL;
        q->next->zombie_3 = zombie;
        q->next->type = 3;
        return 1;
    }
    return 0;
}

bool delete_node(ZombieList& head,Zombie_3*zombie)
{
    Node* p = head;
    Node *q = head;
    if(head ==NULL)
        return 0;
    else if(head->zombie_3 == zombie)
    {
        head = head->next;
        delete p;
        qDebug()<<"释放了内存";
    }
    else
    {
        for(;p!=NULL;p=p->next)
        {
            if(p->zombie_3==zombie)
            {
                q->next = p->next;
                delete p;
                qDebug()<<"释放了内存";
                break;
            }
            else
            {
                q=p;
            }
        }
    }
    return 0;
}

bool insert_intail(ZombieList& head,Zombie_7* zombie)//
{
    if(head == NULL)
    {
        head = new Node;
        head->zombie_7 = zombie;
        head->type = 7;
        head->next = NULL;
        return 1;
        return 0;
    }
    else
    {   Node *q;
        Node *p;
        for(p=head;p!=NULL;p=p->next)
        {
            q=p;
        }
        q->next = new Node;
        q->next->next = NULL;
        q->next->zombie_7 = zombie;
        q->next->type = 7;
        return 1;
    }
    return 0;
}

bool delete_node(ZombieList& head,Zombie_7*zombie)
{
    Node* p = head;
    Node *q = head;
    if(head ==NULL)
        return 0;
    else if(head->zombie_7 == zombie)
    {
        head = head->next;
        delete p;
        qDebug()<<"释放了内存";
    }
    else
    {
        for(;p!=NULL;p=p->next)
        {
            if(p->zombie_7==zombie)
            {
                q->next = p->next;
                delete p;
                qDebug()<<"释放了内存";
                break;
            }
            else
            {
                q=p;
            }
        }
    }
    return 0;
}

bool insert_intail(ZombieList& head,Zombie_8* zombie)//
{
    if(head == NULL)
    {
        head = new Node;
        head->zombie_8 = zombie;
        head->type = 8;
        head->next = NULL;
        return 1;
        return 0;
    }
    else
    {   Node *q;
        Node *p;
        for(p=head;p!=NULL;p=p->next)
        {
            q=p;
        }
        q->next = new Node;
        q->next->next = NULL;
        q->next->zombie_8 = zombie;
        q->next->type = 8;
        return 1;
    }
    return 0;
}

bool delete_node(ZombieList& head,Zombie_8*zombie)
{
    Node* p = head;
    Node *q = head;
    if(head ==NULL)
        return 0;
    else if(head->zombie_8 == zombie)
    {
        head = head->next;
        delete p;
        qDebug()<<"释放了内存";
    }
    else
    {
        for(;p!=NULL;p=p->next)
        {
            if(p->zombie_8==zombie)
            {
                q->next = p->next;
                delete p;
                qDebug()<<"释放了内存";
                break;
            }
            else
            {
                q=p;
            }
        }
    }
    return 0;
}

bool twonone(Land * ground,int st,int row)
{
    if(st>=9)
        return true;
    else if(st>=2)
    {
        if((ground->land[st][row]==0 or ground->land[st][row]==2 or ground->land[st][row]==5 or ground->land[st][row]==7 or ground->land[st][row]==8)and(ground->land[st-1][row]==0 or ground->land[st-1][row]==2 or ground->land[st-1][row]==5 or ground->land[st-1][row]==7 or ground->land[st-1][row]==8)and(ground->land[st-2][row]==0 or ground->land[st-2][row]==2 or ground->land[st-2][row]==5 or ground->land[st-2][row]==7 or ground->land[st-2][row]==8))
        {
            return true;
        }
    }
    else if(st==1)
    {
        if((ground->land[st][row]==0 or ground->land[st][row]==2 or ground->land[st][row]==5 or ground->land[st][row]==7 or ground->land[st][row]==8)and(ground->land[st-1][row]==0 or ground->land[st-1][row]==2 or ground->land[st-1][row]==5 or ground->land[st-1][row]==7 or ground->land[st-1][row]==8))
        {
            return true;
        }
    }
    else if(st==0)
    {
        if(ground->land[st][row]==0 or ground->land[st][row]==2 or ground->land[st][row]==5 or ground->land[st][row]==7 or ground->land[st][row]==8)
        {
            return true;
        }
    }
    return false;
}
