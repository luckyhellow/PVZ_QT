#ifndef PEA_H
#define PEA_H
#include <QObject>
#include <QTimer>
class Pea : public QObject
{
    Q_OBJECT
public:
    Pea(int a,int b);
    QTimer *pin = new QTimer();
    int x,y;
};

#endif // PEA_H
