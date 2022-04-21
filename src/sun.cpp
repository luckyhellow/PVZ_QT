#include "sun.h"
#include<QDebug>
#include<level.h>
#include<QString>
Sun::Sun(QObject *parent) : QObject(parent)
{
}

void Sun::sunadd()
{
    qDebug()<<"阳光总数为"<<num_of_sun;
}
