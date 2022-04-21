#ifndef SUN_H
#define SUN_H
#include <QObject>
#include <QLineEdit>
class Sun : public QObject
{
    Q_OBJECT
public:
    static int num_of_sun;
    explicit Sun(QObject *parent = nullptr);
    void sunadd();
};

#endif // SUN_H
