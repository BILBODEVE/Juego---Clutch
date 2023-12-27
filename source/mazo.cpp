#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "../includes/mazo.h"
#include "../includes/recursos.h"
#include "../includes/variables.h"

using namespace std;

/**
 * Carga 4 grupos de 5 cartas (10,J,Q,K,A)
 * Carga 4 palos unicos para cada carta
 */
void cargarMazo(Carta mazo[])
{

    for (int j = 0; j < SIZE_MAZO; j++)
    {
        mazo[j].carta = CARTAS[j % SIZE_MANO];
    }

    for (int j = 0; j < SIZE_MAZO; j++)
    {
        mazo[j].palo = PALOS[j % 4];
    }
}

void mezclarMazo(Carta mazo[])
{
    for (int i = 0; i < SIZE_MAZO; i++)
    {
        int iCarta = generarIndice();
        swap(mazo[i].carta, mazo[iCarta].carta);
        swap(mazo[i].palo, mazo[iCarta].palo);
    }
}



