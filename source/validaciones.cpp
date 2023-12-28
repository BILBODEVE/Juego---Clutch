#include <iostream>
#include "../includes/validaciones.h"
#include "../includes/variables.h"
#include "../includes/inputs.h"

using namespace std;

bool validarOpcion(char opcion)
{
    if(opcion != 'S' && opcion != 'N')
        return true;

    return false;
}

/**
 * Cuenta la cantidad de cartas ordenadas.
 */
int contarCartasOrdenadas(Jugador jugador)
{
    int cont = 0;
    for (int i = 0; i < SIZE_MANO; i++)
    {
        if (jugador.mano[i].carta == CARTAS[i])
            cont++;
        else
            cont = 0;
    }
    return cont;
}

/**
 * Evalua si la mano esta ordenada.
 */
bool validarOrdenMano(Jugador jugador)
{
    if (contarCartasOrdenadas(jugador) == 5)
        return true;

    return false;
}

bool estaBloqueada(Jugador jugadorActual, int cartaElegida)
{
    if (jugadorActual.cartaBlock[cartaElegida])
        return true;

    return false;
}

/**
 * Validar si existe al menos una carta desbloqueada.
*/
bool validarCartasBlock(Jugador jugador)
{
    int cont = 0;

    for (int i = 0; i < SIZE_MANO; i++)
    {
        if (!jugador.cartaBlock[i])
            return false;
    }
    return true;
}

/**
 * Valida un valor entre 1 y 5.
 * Si carta<0 evalua la posibilidad de finalizar la partida.
*/
bool validarSeleccionCarta(int cartaElegida)
{
    if(cartaElegida < 0)
       return confirmarFinJuego();

    if (cartaElegida < 1 || cartaElegida > 5)
            return true;

    return false;
}

/**
 * El nombre no debe superar los 20 char.
*/
bool validarCantidadChar(string nombre)
{
    return nombre.size() > 20;
}



