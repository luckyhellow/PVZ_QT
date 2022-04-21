#ifndef TIMECONTROL_H
#define TIMECONTROL_H

#include <QTimer>
#include <QObject>

class TimeControl : public QObject
{
    Q_OBJECT
public:
    QTimer *timerSun = new QTimer(this);
    //QTimer *timerZombie = new QTimer(this);
    explicit TimeControl(QObject *parent = nullptr);
    void beginsuntime();
    //void beginzombietime();
signals:
    //void suntime();
};

#endif // TIMECONTROL_H
