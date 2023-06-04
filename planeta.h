
#ifndef PLANETA_H
#define PLANETA_H

#include <QLabel>

class planeta
{
public:
    //Public Methods
    planeta();
    planeta(short ID);
    ~planeta();

        //Set and Get Methods
    short getID() const;
    void setID(short nid);

    void setX(float xnew);
    float getX();

    void setY(float ynew);
    float getY();

    void setVX(float vxnew);
    float getVX();

    void setVY(float vynew);
    float getVY();

    void setAX(float axnew);
    float getAX();

    void setAY(float aynew);
    float getAY();

    void set_planet_Shape(QString shape);
    QString get_planet_Shape();

private:
    //Private Attributes
    float x, y; //Position in x and y
    float vx, vy; //Speed in x and y
    float ax, ay; //Aceleration in x and y

    short id;

    QString planet_Shape;
};

#endif // PLANETA_H
