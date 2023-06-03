
#include "solar_system.h"

solar_system::solar_system()
{
    planets = new std::vector<planeta>;
}

solar_system::~solar_system()
{
    delete planets;
}

void solar_system::add_Planet(short id)
{
    planeta planetNew(id);
    planets->push_back(planetNew);
}

