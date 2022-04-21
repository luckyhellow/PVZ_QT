#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenuBar>
#include <QPainter>
#include <mypushbutton.h>
#include <QDebug>
using namespace std;

//Zombie 僵尸类
//Plant  植物类
//Sun    阳光类
//TimeControl 时钟管理类
//开始后，定时触发信号，Sun响应生产阳光
int Sun::num_of_sun = 50;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)//触发
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/Image/Icon.png"));
//    QPushButton *CGMS = new QPushButton("闯关模式",this);
//    //CGMS->show();顶层方式
//    //若想在窗口中则需下述依赖
//    //CGMS->setParent(this);
//    //显示文本
//    //CGMS->setText("闯关模式");
//    CGMS->move(750,150);
//    CGMS->resize(200,100);
//    QPushButton *WJMS = new QPushButton("无尽模式",this);
//    WJMS->move(750,270);
//    WJMS->resize(200,100);
    //重置窗口大小
    resize(1080,800);
    //固定大小
    setFixedSize(1080,800);
    //设置窗口标题
    setWindowTitle("(lucky)Plant_vs_Zombie");


      // //////////
     //   菜单   //
    // //////////


    //创建菜单栏
    QMenuBar* bar = menuBar();
    //菜单栏放入窗口
    setMenuBar(bar);
    //创建菜单
    QMenu *fileMenu = bar->addMenu("文件");
    QMenu *editMenu = bar->addMenu("编辑");

    fileMenu->addAction("尚未完善");
    fileMenu->addSeparator();
    fileMenu->addAction("尚未完善");
    editMenu->addAction("尚未完善");




//    QPushButton *EXITBUTTON = new QPushButton("退出游戏",this);
//    EXITBUTTON->move(750,390);
//    EXITBUTTON->resize(200,100);
//    //点击按钮执行某个动作
//    //connect(信号发送者，发送的具体信号，信号接收者，信号处理)
//    connect(EXITBUTTON,&QPushButton::clicked,this,&QMainWindow::close);

    //阳光
    Sun::num_of_sun = 50;
    this->TC = new TimeControl(this);
    Sun * S = new Sun;
//    //产生则增加
//    //connect(TC,&TimeControl::suntime,S,&Sun::sunadd);
//    //connect(TC,&TimeControl::suntime,this,&MainWindow::TenSecond);
//    //按键连接
//    //connect(CGMS,&QPushButton::clicked,this,&MainWindow::TenSecond);
//    //connect(CGMS,&QPushButton::clicked,TC,&TimeControl::suntime);
//    //connect(CGMS,&QPushButton::clicked,this,&MainWindow::TenSecond);
    connect(TC->timerSun, &QTimer::timeout,[=](){
        Sun::num_of_sun += 25;
    });
//    connect(CGMS,&QPushButton::clicked,TC,&TimeControl::beginsuntime);
//    //connect(CGMS,SLOT(&QPushButton::clicked()),timer,SLOT(&QTimer::start()));
    MyPushButton *startButton = new MyPushButton(":/Image/StartButton.png");
    startButton->setParent(this);
//    startButton->resize(startButton->width()*2,startButton->height()*2);
//    startButton->setFixedSize(startButton->width()*2,startButton->height()*2);
//    startButton->setIconSize(QSize(startButton->width()*2,startButton->height()*2));
    startButton->move(this->width()*0.5-150,500);
    MyPushButton *chooselevel1Button = new MyPushButton(":/Image/level1_button.png");
    chooselevel1Button->setParent(this);
    chooselevel1Button->move(50,100);
    MyPushButton *otherButton = new MyPushButton(":/Image/other_button.png");
    otherButton->setParent(this);
    otherButton->move(50,250);
    connect(chooselevel1Button,&MyPushButton::clicked,[=](){
        chooselevel1Button->tik();
        chooselevel1Button->tok();
        ifstream in_file("C:/level1.txt",ios::in);//ifstream in_file(":/level1.txt",ios::in);
        if(!in_file)
        {
            cout<<"调整上一行的路径"<<endl;
            exit(-1);
        }
        int x[200];
        int i=0;
        in_file >> x[i];
        while(!in_file.fail())
        {
             i++;
             in_file >> x[i];
        }
        in_file.close();
        l = x[0];
        h = x[1];
        for(int i=0;i<l;i++)//x坐标的感觉
        {
            for(int j=0;j<h;j++)//y坐标的感觉
            {
                landtype[i][j] = x[j*l+i+2];
            }
        }
        qDebug()<<x[0]<<x[1]<<x[2]<<x[3]<<x[4]<<landtype[0][0]<<landtype[0][1]<<landtype[0][2]<<landtype[0][3]<<endl;
        for(int i=0;i<h;i++)
        {
            listtype[i] = x[l*h+2+i];
        }
        if(choosedlevel == false){
        connect(startButton,&MyPushButton::clicked,[=](){
        //        qDebug() << "呵呵";
                level * levelnow = new level;
                levelnow->ground->col = l;
                levelnow->ground->row = h;
                for(int i=0;i<l;i++)
                {
                    for(int j=0;j<h;j++)
                    {
                        levelnow->ground->landtype[i][j] = landtype[i][j];
                        qDebug()<<i<<j<<levelnow->ground->landtype[i][j]<<endl;
                    }
                }
                for(int i=0;i<h;i++)
                {
                    levelnow->listtype[i] = listtype[i];
                    if(listtype[i] == 1)
                    {
                        levelnow->floor[levelnow->num_of_floor] = i;
                        levelnow->num_of_floor++;
                    }
                    if(listtype[i] == 2)
                    {
                        levelnow->sky[levelnow->num_of_sky] = i;
                        levelnow->num_of_sky++;
                    }
                    if(listtype[i] == 3)
                    {
                        levelnow->floor[levelnow->num_of_floor] = i;
                        levelnow->num_of_floor++;
                        levelnow->sky[levelnow->num_of_sky] = i;
                        levelnow->num_of_sky++;
                    }
                }
                qDebug()<<levelnow->num_of_sky<<levelnow->num_of_floor;
                startButton->tik();
                startButton->tok();
                TC->beginsuntime();
                levelnow->name = ui->lineEdit_yourname->text();
                QTimer::singleShot(500,this,[=](){

                    this->hide();
                    levelnow->setWindowTitle(levelnow->name);
                    levelnow->sunline.setParent(levelnow);
                    levelnow->sunline.setReadOnly(true);
                    levelnow->sunline.setText(QString::number(50));
                    levelnow->sunline.move(80,5);
                    levelnow->sunline.resize(150,60);
                    levelnow->there.setParent(levelnow);
                    levelnow->there.setReadOnly(true);
                    levelnow->there.setText("you choose:");
                    levelnow->there.move(1150,0);
                    levelnow->there.resize(180,30);
                    levelnow->connect(TC->timerSun, &QTimer::timeout,[=](){
                        levelnow->sunline.setParent(levelnow);
                        levelnow->sunline.setText(QString::number(S->num_of_sun));
                        levelnow->sunline.move(80,5);
                        levelnow->sunline.resize(150,60);
                        levelnow->sunline.show();
                    });
                    levelnow->sunline.show();
                    levelnow->show();
                });
            });
        choosedlevel = true;
        };
    });
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/Image/SelectorBackground.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    pix.load(":/Image/yourname.png");
    pix = pix.scaled(pix.width()*2,pix.height()*2);
    painter.drawPixmap(this->width()*0.5-300,this->height()*0.5-210,pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}
