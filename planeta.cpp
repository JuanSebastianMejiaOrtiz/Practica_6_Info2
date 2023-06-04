
#include "planeta.h"

planeta::planeta()
{
    planet = new QLabel;

    //Set Default Values
    setID(0);  //ID

    setX(0);
    setY(0);
    setVX(0);
    setVY(0);
    setAX(0);
    setAY(0);
}

planeta::planeta(short ID)
{
    planet = new QLabel;

    //Set Default Values
    setID(ID);
    setX(0);
    setY(0);
    setVX(0);
    setVY(0);
    setAX(0);
    setAY(0);
    setMass(0);

    std::string id_string = std::to_string(id);
    QString qtexto = QString::fromStdString(id_string);
    QString default_planet;
    default_planet = "--------------";  //Parte Superior
    default_planet = "|  Planeta " + qtexto + "  |";
    default_planet = "--------------";  //Parte Inferior

    set_planet_Shape(default_planet);
}

planeta::~planeta()
{

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

void planeta::setMass(float masa)
{
    mass = masa;
}

float planeta::getMass()
{
    return mass;
}

void planeta::set_planet_Shape(QString shape)
{
    planet_Shape = shape;
}

QString planeta::get_planet_Shape()
{
    return planet_Shape;
}


