
#include "solar_system.h"

solar_system::solar_system()
{

}

solar_system::~solar_system()
{

}

void solar_system::add_Planet(short id)
{
    planeta planetNew(id);
    planets.push_back(planetNew);
}

QString solar_system::Sun_Text()
{
    QString texto_sun;

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

