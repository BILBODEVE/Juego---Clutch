#include <iostream>
#include "../includes/jugar.h"
#include "../includes/inputs.h"
#include "../includes/validaciones.h"

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
    }

    return carta - 1;
}

void solicitarUnNombre(Jugador &jugador, int nro_jugador)
{
    cout << "Nombre jugador" << nro_jugador << ": ";
    getline(cin,jugador.nombre);
}

bool confirmarFinJuego()
{
    cout << "\nDesea salir del juego? Presione S(si) para continuar o N(no) para seguir jugando: ";
    int opcion = pedirConfirmacion();
    if(opcion == 'S')
        finalizarJuego();

    return true;
}
