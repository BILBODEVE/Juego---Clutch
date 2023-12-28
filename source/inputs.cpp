#include <iostream>
#include "../includes/inputs.h"
#include "../includes/validaciones.h"
#include "../includes/recursos.h"

using namespace std;

int pedirOpcionMenu()
{
    cout << "Ingrese una opcion: ";
    int opcion;
    cin >> opcion;

    return opcion;
}

char pedirConfirmacion()
{
    char opcion;
    cin >> opcion;

    return toupper(opcion);
}

int seleccionarCarta()
{
    int carta;
    cin >> carta;

    while (validarSeleccionCarta(carta))
    {
        cout << "\nIntentelo nuevamente a continuacion (el valor del dado se conserva).\n";
        cout << "Seleccione la carta (1 a 5): ";
        cin >> carta;
        cout << endl;
    }

    return carta - 1;
}

void solicitarUnNombre(Jugador &jugador, int nro_jugador)
{
    cout << "Nombre jugador" << nro_jugador << ": ";
    getline(cin,jugador.nombre);
}

void registrarNombres(Jugador &jugador1, Jugador &jugador2)
{
    char confirmar = 'N';

    cin.ignore();

    while (confirmar != 'S')
    {
        separador(50);
        cout << "#Registre los nombres de los jugadores: \n";

        solicitarUnNombre(jugador1, 1);
        while(validarCantidadChar(jugador1.nombre))
        {
            cout << "ERROR! El nombre no debe superar los 20 caracteres. Intentelo nuevamente.\n";
            solicitarUnNombre(jugador1,1);
        }

        solicitarUnNombre(jugador2, 2);
        while(validarCantidadChar(jugador2.nombre))
        {
            cout << "ERROR! El nombre no debe superar los 20 caracteres. Intentelo nuevamente.\n";
            solicitarUnNombre(jugador2,2);
        }

        cout << "#Confirma los nombres de usuario? S/N: ";
        confirmar = pedirConfirmacion();
        separador(50);
    }
}

/**
 * Retorna true cuando el usuario continua jugando.
*/
bool confirmarFinJuego()
{
    cout << "Desea salir del juego? Presione S(si) para continuar o N(no) para seguir jugando: ";
    int opcion = pedirConfirmacion();
    if(opcion == 'S')
        finalizarJuego();

    return true;
}
