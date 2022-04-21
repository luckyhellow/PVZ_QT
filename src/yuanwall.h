#ifndef YUANWALL_H
#define YUANWALL_H
#include <common.h>
#include <plant.h>
#include <QTimer>
#include <QButtonGroup>
#include <QGroupBox>

class Yuanwall :public Plant
{
    Q_OBJECT
public:
    Yuanwall();
    ~Yuanwall();
    QTimer *pin = new QTimer();
    QLabel *showlife;
//    QButtonGroup *buttongroup;
    QGroupBox *buttongroup;
    bool lf = true;

};

#endif // YUANWALL_H
