#ifndef PLANT_H
#define PLANT_H

#include <QObject>
#include <QPainter>
#include <QMovie>
#include <QTimer>
#include <QLabel>

class Plant : public QObject
{
    Q_OBJECT
public:
    Plant();
    //~Plant() override;
    int life;
    int cd;
    int price;
    int row;
    int col;
    int attack;
    int attack_type;//1 近距离 2 远距离
    int p_type;//1 地面 2 空中
//    QRectF boundingRect() const Q_DECL_OVERRIDE;
//    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;
//    QMovie *movie;
//    void setMovie(QString path);
signals:

};

#endif // PLANT_H
