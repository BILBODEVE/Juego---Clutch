#include <iostream>
#include <cstdlib>
#include "funciones.h"
#include "estructuras.h"

using namespace std;

int main()
{
    // Revisar porque la carta elegida no se intercambia.

    srand(time(0));

    Jugador jugador1;
    Jugador jugador2;

    JugarClutch(jugador1, jugador2);

    return 0;
}