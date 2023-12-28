#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include "../includes/jugar.h"
#include "../includes/variables.h"
#include "../includes/funciones-dado.h"
#include "../includes/inputs.h"
#include "../includes/global.h"
#include "../includes/validaciones.h"

using namespace std;

void jugar(Jugador &jugador1, Jugador &jugador2, Carta mazo[20], string &nombreGanadorHistorico, int &puntosGanadorHistorico)
{
    bool existeGanador = false;
    int ronda = 1;
    string turno;

    cargarMazo(mazo);
    mezclarMazo(mazo);
    registrarNombres(jugador1, jugador2);
    repartirCartas(jugador1, mazo);
    repartirCartas(jugador2, mazo);
    buscarPrimerTurno(jugador1, jugador2, turno);
    separador(62);
    cout << "NOTA: Para finalizar la partida, ingrese un numero negativo\n";
    separador(62);
    mostrarDatosRonda(jugador1, jugador2, ronda, turno);
    ejecutarRondas(jugador1, jugador2, mazo, turno, existeGanador, nombreGanadorHistorico, puntosGanadorHistorico);

    while (existeGanador == false)
    {
        mostrarDatosRonda(jugador1, jugador2, ronda, turno);
        ejecutarRondas(jugador1, jugador2, mazo, turno, existeGanador, nombreGanadorHistorico, puntosGanadorHistorico);
        mezclarMazo(mazo);
    }
    resetearEstados(jugador1);
    resetearEstados(jugador2);
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
 * Genera un indice para el mazo entre 0 y 19.
 */
int generarIndiceMazo()
{
    return rand() % 19;
}

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
        int iCarta = generarIndiceMazo();
        swap(mazo[i].carta, mazo[iCarta].carta);
        swap(mazo[i].palo, mazo[iCarta].palo);
    }
}

void mostrarMazo(Carta mazo[])
{
    for (int i = 0; i < SIZE_MAZO; i++)
    {
        cout << mazo[i].carta << mazo[i].palo << endl;
    }

    cout << endl;
}

void repartirCartas(Jugador &jugador, Carta mazo[])
{
    for (int i = 0; i < SIZE_MANO; i++)
    {
        int iCarta = generarIndiceMazo();

        while (mazo[iCarta].carta == "0")
        {
            iCarta = generarIndiceMazo();
        }
        swap(jugador.mano[i].carta, mazo[iCarta].carta);
        swap(jugador.mano[i].palo, mazo[iCarta].palo);

        mazo[iCarta].carta = "0";
        mazo[iCarta].palo = "0";

        if (validarOrdenMano(jugador))
        {
            repartirCartas(jugador, mazo);
        }
    }
}

void mostrarMano(Jugador jugador1, Jugador jugador2)
{

    cout << "-------------------------- \n";
    cout << "| " << jugador1.nombre << endl;
    for (int i = 0; i < 5; i++)
    {
        if (jugador1.cartaBlock[i] == true)
            cout << "| [" << jugador1.mano[i].carta << ' ' <<  jugador1.mano[i].palo << ']' << " ";
        else
            cout << "| " << jugador1.mano[i].carta << ' ' <<  jugador1.mano[i].palo << " ";
    }

    cout << "\n| \n";

    cout << "| " << jugador2.nombre << endl;
    for (int i = 0; i < 5; i++)
    {
        if (jugador2.cartaBlock[i] == true)
            cout << "| [" << jugador2.mano[i].carta << ' ' <<  jugador2.mano[i].palo << ']' << " ";
        else
            cout << "| " << jugador2.mano[i].carta << ' ' <<  jugador2.mano[i].palo << " ";
    }
    cout << "\n--------------------------\n";
}

int contarCartaDeUnTipo(Jugador jugador, string carta)
{
    int cont = 0;

    for (int i = 0; i < SIZE_MANO; i++)
    {
        if (jugador.mano[i].carta == carta)
            cont++;
    }

    return cont;
}

/**
 * Busca el jugador que comienza la partida
 * Si no encuentra uno, genera un valor de 1 a 2
 * 1 = jugador1.nombre
 * 2 = jugador2.nombre
 */
string buscarPrimerTurno(Jugador &jugador1, Jugador &jugador2, string &turno)
{

    string CARTAS[SIZE_MANO] = {"A", "K", "Q", "J", "10"};

    for(int i=0;i<SIZE_MANO;i++)
    {
        int cantJugador1 = contarCartaDeUnTipo(jugador1,CARTAS[i]);
        int cantJugador2 = contarCartaDeUnTipo(jugador2,CARTAS[i]);

        if (cantJugador1 > cantJugador2)
        {
            turno = jugador1.nombre;
            return turno;
        }
        else if (cantJugador2 > cantJugador1)
        {
            turno = jugador2.nombre;
            return turno;
        }
    }

    int turnoAleatorio = rand() % 2;

    if (turnoAleatorio % 2 == 0)
        turno = jugador2.nombre;
    else
        turno = jugador1.nombre;
    
    return turno;
}

void ejecutarRondas(Jugador &jugador1, Jugador &jugador2, Carta mazo[20], string &turno, bool &existeGanador, string &nombreGanadorHistorico, int &puntosGanadorHistorico)
{
    if (turno == jugador1.nombre)
    {
        accionarSegunDado(jugador1, jugador2, mazo, existeGanador, nombreGanadorHistorico, puntosGanadorHistorico);
        encontrarGanador(jugador1, jugador2, existeGanador, nombreGanadorHistorico, puntosGanadorHistorico);
        turno = jugador2.nombre;
    }
    else
    {
        accionarSegunDado(jugador2, jugador1, mazo, existeGanador, nombreGanadorHistorico, puntosGanadorHistorico);
        encontrarGanador(jugador2, jugador1, existeGanador, nombreGanadorHistorico, puntosGanadorHistorico);
        turno = jugador1.nombre;
    }
}

void mostrarDatosRonda(Jugador jugador1, Jugador jugador2, int &ronda, string turno)
{
    cout << "Ronda: " << ronda++ << endl;
    cout << jugador1.nombre << " vs " << jugador2.nombre << endl
         << endl;
    cout << "| Es turno de: #" << turno << " |" << endl;
    cout << endl;

    mostrarMano(jugador1,jugador2);
}

bool encontrarGanador(Jugador &jugadorActual, Jugador &jugadorAnterior, bool &existeGanador, string &nombreGanadorHistorico, int &puntosGanadorHistorico)
{
    if (validarOrdenMano(jugadorActual))
    {
        jugadorActual.puntos[(int)Puntajes::GANAR] = PUNTOS_VICTORIA;

        cout << "\nPARTIDA FINALIZADA!! EL GANADOR ES: " << jugadorActual.nombre << endl;
        mostrarMano(jugadorActual, jugadorAnterior);
        sumarPuntosPorCartaDesordenada(jugadorActual, jugadorAnterior);

        if (!jugadorActual.pasoTurno)
            jugadorActual.puntos[(int)Puntajes::POR_PASAR_TURNO] = PUNTOS_PASAR_TURNO;
        if (!jugadorActual.sufrioRobo)
            jugadorActual.puntos[(int)Puntajes::POR_SUFRIR_ROBO] = PUNTOS_SUFRIR_ROBO;

        mostrarGanador(jugadorActual);
        calcularGanadorHistorico(jugadorActual, nombreGanadorHistorico, puntosGanadorHistorico);

        existeGanador = true;
    }

    return existeGanador;
}

int contarCartaMalUbicada(Jugador jugadorAnterior)
{
    int cont = 0;

    for (int i = 0; i < SIZE_MANO; i++)
    {
        if (jugadorAnterior.mano[i].carta != CARTAS[i])
            cont++;
    }

    return cont;
}

void sumarPuntosPorCartaDesordenada(Jugador &jugadorActual, Jugador jugadorAnterior)
{
    jugadorActual.puntos[(int)Puntajes::CARTA_MAL_UBICADA] = contarCartaMalUbicada(jugadorAnterior) * PUNTOS_CARTA_DESORDENADA;
}

int sumarTotalPuntos(Jugador jugador)
{
    int totalPuntos = 0;
    for (int i = 0; i < 5; i++)
    {
        totalPuntos += jugador.puntos[i];
    }
    return totalPuntos;
}

void mostrarGanador(Jugador jugador)
{
    cout << "PUNTAJE: \n";
    cout << "-------------------------------------------\n";
    cout << "Ganar la partida: " << jugador.puntos[(int)Puntajes::GANAR] << " puntos." << endl;
    cout << "Robo ultima carta al jugador rival: " << jugador.puntos[(int)Puntajes::GANAR_ROBANDO] << " puntos." << endl;
    cout << "Cartas mal ubicadas del rival " << jugador.puntos[(int)Puntajes::CARTA_MAL_UBICADA] / PUNTOS_CARTA_DESORDENADA 
         << ": " << jugador.puntos[(int)Puntajes::CARTA_MAL_UBICADA] << " puntos." << endl;
    cout << "Sin pasar de turno: " << jugador.puntos[(int)Puntajes::POR_PASAR_TURNO] << " puntos." << endl;
    cout << "Sin haber sufrido robos: " << jugador.puntos[(int)Puntajes::POR_SUFRIR_ROBO] << " puntos." << endl;
    cout << "-------------------------------------------\n";
    cout << "TOTAL: " << sumarTotalPuntos(jugador) << " puntos.";
    
}

/**
 * Busca el jugador con mayor cantidad de puntos.
*/
void calcularGanadorHistorico(Jugador jugador, string &nombreGanadorHistorico, int &puntosGanadorHistorico)
{
    int totalPuntos = sumarTotalPuntos(jugador);

    if (totalPuntos > puntosGanadorHistorico)
    {
        puntosGanadorHistorico = totalPuntos;
        nombreGanadorHistorico = jugador.nombre;
    }
}

/**
 * Resetea el estado de las cartas bloqueadas y acciones.
*/
void resetearEstados(Jugador &jugador)
{
    for(int i = 0;i<SIZE_MANO;i++)
        jugador.cartaBlock[i] = false;

    jugador.pasoTurno = false;
    jugador.sufrioRobo = false;
}

void finalizarJuego()
{
    cout << "\nGracias por visitar CLUTCH!!";
    exit(0);
}

