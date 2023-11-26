#include <iostream>
#include <cstdlib>
#include "funciones.h"
#include "estructuras.h"

using namespace std;

int main()
{
    srand(time(0));

    // En ASCII '\n' equivale a 10.
    string tipo_carta[5] = {"10", "J", "Q", "K", "A"};
    // corazon,trebol,pica,diamante.
    string v_palos[4] = {"\u2665", "\u2663", "\u2660", "\u2666"};

    Jugador jugador1;
    Jugador jugador2;

    JugarClutch(jugador1, jugador2, mazo, tipo_carta, v_palos);

    return 0;
}