#include <iostream>
#include <cstdlib>
#include "funciones.h"
#include "estructuras.h"

using namespace std;

int main()
{
    srand(time(0));

    Jugador jugador1;
    Jugador jugador2;

    JugarClutch(jugador1, jugador2);

    return 0;
}