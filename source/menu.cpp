#include <iostream>
#include "../includes/variables.h"
#include "../includes/menu.h"
#include "../includes/jugar.h"
#include "../includes/inputs.h"
#include "../includes/recursos.h"
#include "../includes/validaciones.h"

using namespace std;

void menuPrincipal(Jugador &jugador1, Jugador &jugador2, Carta mazo[],string& nombreGanadorHistorico,int& puntosGanadorHistorico)
{
    

    mostrarMenu();
    int opcion = pedirOpcionMenu();

    while (opcion < 0 || opcion > 4)
    {
        cout << "\nERROR! Opcion incorrecta. Intentelo nuevamente\n\n";
        opcion = pedirOpcionMenu();
    }

    switch (opcion)
    {
    case 1:
        jugar(jugador1, jugador2, mazo, nombreGanadorHistorico, puntosGanadorHistorico);
        break;
    case 2:
        mostrarEstadisticas(nombreGanadorHistorico, puntosGanadorHistorico);
        break;
    case 3:
        mostrarCreditos();
        break;
    case 4:
        mostrarInstrucciones();
        break;
    case 0:
        cout << "\nGracias por visitar CLUTCH!\n";
        return;
        break;
    }
    volverAlMenu(jugador1, jugador2, mazo, nombreGanadorHistorico, puntosGanadorHistorico);
}

void mostrarEstadisticas(string nombreGanadorHistorico, int puntosGanadorHistorico)
{
    cout << "******** GANADOR HISTORICO: " << nombreGanadorHistorico << " ********\n";
    cout << "TOTAL PUNTOS: " << puntosGanadorHistorico;
}

void mostrarCreditos()
{
    cout << "\nDesarrollo del proyecto a cargo de: \n";
    cout << "   # Nombre: Facundo Tomas\n";
    cout << "   # Apellido: Araujo Avalos\n";
    cout << "   # Legajo: 29681\n";
    cout << "   # Nombre del equipo: yo, yo y mi otro yo\n";
}

void mostrarInstrucciones()
{
    separador(60);
    cout << " Cantidad de jugadores: 2\n";
    cout << " Cantidad de cartas: 5 por jugador\n";
    cout << " Cantidad de dados: 1\n";
    cout << " Valores posibles del dado: 1 a 6\n";
    cout << " Objetivo: ordenar las cartas de tal manera que completen la fase de crecimineto de una gallina\n\n";

    separador(40);
    cout << "Las fases de crecimiento se representan por el tipo de carta: \n";
    cout << "\t 10: Huevo listo para ser empollado\n";
    cout << "\t J: Huevo empollado con una pequeña grieta\n";
    cout << "\t Q: Se asoma un pico por la grieta\n";
    cout << "\t K: Sale un pequeño pollito\n";
    cout << "\t A: El pollito crecio y ahora es una gallina.\n\n";
    separador(40);
    cout << "Segun el valor del dado, se pueden realizar los siguientes movimientos:\n";
    cout << "\t #1 Robar del mazo e intercambiar con una carta del corral.\n";
    cout << "\t #2 Robar del mazo e intercambiarla con una carta del contrario.\n";
    cout << "\t #3 Elegir una carta propia e intercambiarla con una del contrario.\n";
    cout << "\t #4 Intercambiar dos cartas del propio corral.\n";
    cout << "\t #5 Bloquear una carta del propio corral. El contrario no podra accionar sobre esta carta.\n";
    cout << "\t     Si la carta esta bloqueada se muestra entre [].\n";
    cout << "\t #6 Elegir una opcion o pasar el turno.\n";
    separador(40);
    cout << "\nEl comienzo de la partida esta determinado por el jugador con mayor cantidad de ases(A).\nEn el caso de que ningun jugador posea un AS o la cantidad en ambos sea la misma, se evalua la cantidad del segundo tipo de carta, en este caso, la \'K\'.\nEsta regla se aplica para todos los tipos de cartas subsiguientes de forma descendente.\n\n";

    cout << "NOTA: la mano de cartas es denominada \"Corral\".\n\n";

    cout << "BUENA SUERTE!\n";
    
}

void volverAlMenu(Jugador jugador1, Jugador jugador2, Carta mazo[],string& nombreGanadorHistorico, int& puntosGanadorHistorico)
{

    cout << "\nDesea volver al menu principal? S(Si)/N(No): ";
    char opcion = pedirConfirmacion();
    while(validarOpcion(opcion))
    {
        cout << "\nDesea volver al menu principal? S(Si)/N(No): ";
        opcion = pedirConfirmacion();
    }

    if (opcion == 'S')
        menuPrincipal(jugador1, jugador2, mazo, nombreGanadorHistorico,puntosGanadorHistorico);
    else
        cout << "Gracias por visitar CLUTCH!";
}

