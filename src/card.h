#ifndef CARD_H
#define CARD_H
#include "mypushbutton.h"
#include "land.h"
class card: public MyPushButton
{
    Q_OBJECT
public:
    card(QString normalImg);
    static int cardType;
};

#endif // CARD_H
