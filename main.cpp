#include <iostream>
#include <cstdlib>
#include "funciones.h"
#include "estructuras.h"

using namespace std;

int main()
{
    /*
     *La carta elegida no se intercambia porque la funcion que controla el primer turno + primerTurno + intercambiarCarta necesita recibir por referencia la struct jugador -> solucionado parcialmente.
     *Evaluar en cada ronda que no exista un ganador.
     */

    srand(time(0));

    JugarClutch();

    return 0;
}