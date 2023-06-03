
#include "planeta.h"

planeta::planeta()
{

}

planeta::planeta(short ID)
{
    //Set Pixmap
    QPixmap img;
    img.load("://Sprites/planeta.png");

    //Set Default Values
    setID(ID);
    setX(0);
    setY(0);
    setVX(0);
    setVY(0);
    setAX(0);
    setAY(0);
}

short planeta::getID() const
{
    return id;
}

void planeta::setID(short nid)
{
    id = nid;
}

void planeta::setX(float xnew)
{
    x = xnew;
}

float planeta::getX()
{
    return x;
}

void planeta::setY(float ynew)
{
    y = ynew;
}

float planeta::getY()
{
    return y;
}

void planeta::setVX(float vxnew)
{
    vx = vxnew;
}

float planeta::getVX()
{
    return vx;
}

void planeta::setVY(float vynew)
{
    vy = vynew;
}

float planeta::getVY()
{
    return vy;
}

void planeta::setAX(float axnew)
{
    ax = axnew;
}

float planeta::getAX()
{
    return ax;
}

void planeta::setAY(float aynew)
{
    ay = aynew;
}

float planeta::getAY()
{
    return ay;
}


