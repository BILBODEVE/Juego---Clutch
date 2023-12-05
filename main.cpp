#include <iostream>
#include <cstdlib>
#include "funciones.h"
#include "estructuras.h"

using namespace std;

int main()
{
    /*

        *La carta elegida no se intercambia porque la funcion que controla el primer turno + primerTurno + intercambiarCarta necesita recibir por referencia la struct jugador -> solucionado parcialmente.

        * Darle fluides a las rondas, revisar el ciclo while que controla el estado de la partida.

        * A medida que avanza el juego, el turno se modifica, mostrar el valor correspondiente en cada vuelta.

        * El desarrollo del primer turno quizas puede modificarse y obtener una version mas simple, revisalo.

    */

    srand(time(0));

    JugarClutch();

    return 0;
}