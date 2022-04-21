#include "timecontrol.h"

TimeControl::TimeControl(QObject *parent) : QObject(parent)
{

}
void TimeControl:: beginsuntime()
{
    timerSun->start(10000);
}
