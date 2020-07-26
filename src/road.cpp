#include "road.h"


Road::Road(point(), pol()) : start(point), w_points(pol){}

QPoint Road::getStart()
{
    return  start;
}

QPolygon Road::getPoints()
{
    return w_points;
}

