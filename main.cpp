#include <iostream>
#include <cstdlib> 
#include <time.h>  
#include "includes/funciones.h"
#include "includes/estructuras.h"

using namespace std;

int main()
{
    srand(time(0));

    Carta mazo[20];
    Jugador jugador1;
    Jugador jugador2;

    jugarClutch(jugador1, jugador2, mazo);

    return 0;
}