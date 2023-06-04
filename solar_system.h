
#ifndef SOLAR_SYSTEM_H
#define SOLAR_SYSTEM_H

#include "planeta.h"
#include <vector>
#include "global_macros.h"


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

private:
    //Private Attributes


    //Private Methods


};

#endif // SOLAR_SYSTEM_H
