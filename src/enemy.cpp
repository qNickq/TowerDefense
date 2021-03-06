#include "enemy.h"


Enemy::Enemy(Road _way, int wave) : way(_way)
{
    distance = 0;
    sprite = new QPixmap(":/res/images/Enemy.png");
    max_hp = 100 + 20*wave;
    current_hp = max_hp;
    speed = 1000;
    point = 1;
    prize = 10;
    this->setPos(way.getStart().x(), way.getStart().y());
    life = new QTimer();
    connect(life, SIGNAL(timeout()), this, SLOT(move()));
    life->start(speed / 50);
}

void Enemy::move()
{

    if(this->scenePos() != way.getPoints().last())
    {
        distance += (this->scenePos() - way.getPoints()[point]).manhattanLength();

        if(this->scenePos() == way.getPoints()[point]) ++point;
        else
        {
            if(this->scenePos().x() < ((way.getPoints()[point]).x()))
            {
                dx = 1;
            }
            else if (this->scenePos().x() > (way.getPoints()[point].x()))
            {
                dx = -1;
            }
            else
            {
                dx = 0;
            }
            if(this->scenePos().y() < (way.getPoints()[point].y()))
            {
                dy = 1;
            }
            else if (this->scenePos().y() > (way.getPoints()[point].y()))
            {
                dy = -1;
            }
            else
            {
                dy = 0;
            }

            moveBy(dx,dy);
        }
    }
    else
    {
        life->stop();
        life->disconnect();
        emit win();
        delete this;
    }
}

void Enemy::stop()
{
    life->stop();
    life->disconnect();
}

int Enemy::getPoint()
{
    return point;
}

int Enemy::getDistance()
{
    return  distance;
}

void Enemy::damaged(int damage)
{
    current_hp -=damage;

    if(current_hp <= 0 )
    {
        emit dead(prize);
    }
}

QRectF Enemy::boundingRect() const
{
    return QRectF(0, 0, sprite->width(), sprite->height());
}

QPainterPath Enemy::shape() const
{
    QPainterPath path;
    path.addEllipse(boundingRect());
    return path;
}

void Enemy::Enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(QBrush(*sprite));
    painter->setPen(Qt::NoPen);
    painter->drawRect(0, 0, sprite->width(), sprite->height());
    painter->setBrush(Qt::green);
    painter->drawRect(0, 0, current_hp*sprite->width()/max_hp, 3);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

Enemy::~Enemy()
{
    if (life != nullptr)
    {
        life->stop();
        life->disconnect();
        delete life;
    }
    delete sprite;
}



