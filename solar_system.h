
#ifndef SOLAR_SYSTEM_H
#define SOLAR_SYSTEM_H

#include "planeta.h"
#include <vector>
#include "global_macros.h"
#include <QTimer>


class solar_system
{
public:
    //Public Methods
        //Constructor y Destructor
    solar_system();
    ~solar_system();
        //General Methods
    void add_Planet(short id);
    QString Sun_Text();

    //Public Attributes
    std::vector<planeta> planets;    //All the planets
    QTimer *timer;
    float T, Sim_Speed;

    QString texto_sun;
    int sun_center_x, sun_center_y;

protected:
    float sun_mass;

};

#endif // SOLAR_SYSTEM_H
