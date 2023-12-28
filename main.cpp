#include <iostream>
#include <cstdlib> 
#include <time.h>  
#include "includes/menu.h"

using namespace std;

int main()
{
    srand(time(0));

    Carta mazo[20];
    Jugador jugador1;
    Jugador jugador2;
    string nombreGanadorHistorico;
    int puntosGanadorHistorico;

    menuPrincipal(jugador1, jugador2, mazo, nombreGanadorHistorico, puntosGanadorHistorico);

    return 0;
}