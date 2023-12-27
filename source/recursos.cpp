#include <iostream>
#include "../includes/recursos.h"
#include "../includes/jugar.h"
#include "../includes/variables.h"

using namespace std;

void mostrarMenu()
{
    cout << "\n****** BIENVENIDO A CLUTCH ******\n";
    separador(30);
    cout << "1 - JUGAR \n";
    cout << "2 - ESTADISTICAS\n";
    cout << "3 - CREDITOS\n";
    cout << "4 - INSTRUCCIONES\n";
    separador(30);
    cout << "0 - SALIR\n";
}

void mostrarDatosRonda(Jugador jugador1, Jugador jugador2, int &ronda, string turno)
{
    cout << "Ronda: " << ronda++ << endl;
    cout << jugador1.nombre << " vs " << jugador2.nombre << endl
         << endl;
    cout << "| Es turno de: #" << turno << " |" << endl;
    cout << endl;

    mostrarMano(jugador1, jugador2);
}

void mostrarMazo(Carta mazo[])
{
    for (int i = 0; i < SIZE_MAZO; i++)
    {
        cout << mazo[i].carta << mazo[i].palo << endl;
    }

    cout << endl;
}

void mostrarMano(Jugador jugador1, Jugador jugador2)
{

    cout << "-------------------------- \n";
    cout << "| " << jugador1.nombre << endl;
    for (int i = 0; i < 5; i++)
    {
        if (jugador1.cartaBlock[i] == true) // Si la carta esta bloqueada se muestra la carta entre [].
        {
            cout << "| [" << jugador1.mano[i].carta << jugador1.mano[i].palo << ']'
                 << " ";
        }
        else
        {
            cout << "| " << jugador1.mano[i].carta << jugador1.mano[i].palo << " ";
        }
    }

    cout << "\n| \n";

    cout << "| " << jugador2.nombre << endl;
    for (int i = 0; i < 5; i++)
    {
        if (jugador2.cartaBlock[i] == true)
        {
            cout << "| [" << jugador2.mano[i].carta << jugador2.mano[i].palo << ']'
                 << " ";
        }
        else
        {
            cout << "| " << jugador2.mano[i].carta << jugador2.mano[i].palo << " ";
        }
    }
    cout << "\n--------------------------\n";
}

void mostrarGanador(Jugador jugador)
{
    cout << "PUNTAJE: \n";
    cout << "-------------------------------------------\n";
    cout << "Ganar la partida: " << jugador.puntos[(int)Puntajes::GANAR] << endl;
    cout << "Robo ultima carta al jugador rival: " << jugador.puntos[(int)Puntajes::GANAR_ROBANDO] << endl;
    cout << "Cartas mal ubicadas del rival " << jugador.puntos[(int)Puntajes::CARTA_MAL_UBICADA] / PUNTOS_CARTA_DESORDENADA << ": " << jugador.puntos[(int)Puntajes::CARTA_MAL_UBICADA] << endl;
    cout << "Sin pasar de turno: " << jugador.puntos[(int)Puntajes::POR_PASAR_TURNO] << endl;
    cout << "Sin haber sufrido robos: " << jugador.puntos[(int)Puntajes::POR_SUFRIR_ROBO] << endl;
    cout << "-------------------------------------------\n";
    cout << "TOTAL: " << sumarTotalPuntos(jugador);
    
}

/**
 * Genera un indice para el mazo.
 * Iterar me asegura obtener un indice random.
 */
int generarIndice()
{
    return rand() % 19;
}

void resetearEstados(Jugador &jugador)
{
    for(int i = 0;i<SIZE_MANO;i++)
        jugador.cartaBlock[i] = false;

    jugador.pasoTurno = false;
    jugador.sufrioRobo = false;
}

void separador(int tamaño, const char symbol)
{
    for (int i = 0; i < tamaño; i++)
        cout << symbol;

    cout << endl;
}