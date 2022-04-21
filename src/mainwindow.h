#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QMainWindow>//窗口类头文件
#include <sun.h>
#include <timecontrol.h>
#include <QPushButton>
#include <windows.h>
#include <QPainter>
#include <level.h>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <fstream>
//#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT //宏允许类中使用信号和槽

public:
    MainWindow(QWidget *parent = nullptr);//构造函数
    ~MainWindow();//析构函数

    void paintEvent(QPaintEvent *);

private:
    Ui::MainWindow *ui;
    TimeControl * TC;
    int l;
    int h;
    int landtype[9+1][5+1];//记录近战远战或者不能种植
    int listtype[5+1];//记录路径
    bool choosedlevel = false;//是否完成选关
};
#endif // MAINWINDOW_H
