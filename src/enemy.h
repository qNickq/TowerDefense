#pragma once
#include <QGraphicsObject>
#include <QPainter>
#include <QTimer>
#include "road.h"

class Enemy: public QGraphicsObject
{
    Q_OBJECT

public:
    Enemy(Road, int wave);
    ~Enemy();
    int getPoint();
    int getDistance();
    void damaged(int);

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QPainterPath shape() const;

public slots:
    void move();
    void stop();
signals:
    void dead(int);
    void win();

private:
    QPixmap * sprite;
    QTimer * life;
    static Road* way;

    int distance;
    int prize;
    int point;
    int max_hp;
    int current_hp;
    int speed;
    double dy;
    double dx;
};

