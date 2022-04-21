#include "mainwindow.h"

#include <QApplication>//包含应用程序类

int main(int argc, char *argv[])//argc命令行变量数，argv变量数量数组
{
    QApplication a(argc, argv);//应用程序对象
    MainWindow w;//窗口对象
    w.show();
    return a.exec();
}
