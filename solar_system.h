
#ifndef SOLAR_SYSTEM_H
#define SOLAR_SYSTEM_H

#include "planeta.h"
#include <map>
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

    //Public Attributes
    std::map<short, planeta> planets;   //All the planets

private:
    //Private Attributes


    //Private Methods


};

#endif // SOLAR_SYSTEM_H
