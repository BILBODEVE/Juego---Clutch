#include <iostream>
#include <cstdlib>
#include "funciones.h"
#include "estructuras.h"

using namespace std;

int main()
{
    srand(time(0));
    string tipo_carta[5] = {"10", "J", "Q", "K", "A"};            // En ASCII '\n' equivale a 10.
    string v_palos[4] = {"\u2665", "\u2663", "\u2660", "\u2666"}; // corazon,trebol,pica,diamante.

    int mazo[4][5]{
        0, 1, 2, 3, 4,
        0, 1, 2, 3, 4,
        0, 1, 2, 3, 4,
        0, 1, 2, 3, 4};

    Jugador jugador1;
    Jugador jugador2;

    JugarClutch(jugador1, jugador2, mazo, tipo_carta, v_palos);

    return 0;
}