
#include "solar_system.h"

solar_system::solar_system()
{
    sun_mass = 1000;
}

solar_system::~solar_system()
{

}

void solar_system::add_Planet(short id)
{
    planeta* planetNew = new planeta(id);
    planetNew->planet->setGeometry(0, 0, 65, 35);
    planetNew->planet->setText(planetNew->get_planet_Shape());

    planets.push_back(*planetNew);

    delete planetNew;
}

QString solar_system::Sun_Text()
{
    texto_sun = texto_sun + "         -------\n";  //Parte superior

    texto_sun = texto_sun + "       _| \t |_\n";
    texto_sun = texto_sun + "    _|    \t    |_\n";
    texto_sun = texto_sun + " _|      \t        |_\n";
    texto_sun = texto_sun + "|         SUN          |\n";  //Parte central
    texto_sun = texto_sun + " -|        \t        |-\n";
    texto_sun = texto_sun + "    -|     \t     |-\n";
    texto_sun = texto_sun + "       -|  \t  |-\n";

    texto_sun = texto_sun + "         -------";  //Parte inferior

    return texto_sun;
}

