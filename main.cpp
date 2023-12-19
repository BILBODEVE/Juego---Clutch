#include <iostream>
#include <cstdlib> //rand() ,srand()
#include <time.h>  //time()
#include "Headers/funciones.h"
#include "Headers/estructuras.h"

using namespace std;

int main()
{
    srand(time(0));

    Mazo mazo[20];
    Jugador jugador1;
    Jugador jugador2;

    jugarClutch(jugador1, jugador2, mazo);

    return 0;
}