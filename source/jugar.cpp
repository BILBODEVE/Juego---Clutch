#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include "../includes/jugar.h"
#include "../includes/variables.h"
#include "../includes/funciones-dado.h"
#include "../includes/inputs.h"
#include "../includes/mazo.h"
#include "../includes/recursos.h"
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
    mostrarDatosRonda(jugador1, jugador2, ronda, turno);
    separador(62);
    cout << "NOTA: Para finalizar la partida, ingrese un numero negativo\n";
    separador(62);
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

void repartirCartas(Jugador &jugador, Carta mazo[])
{
    for (int i = 0; i < SIZE_MANO; i++)
    {
        int iCarta = generarIndice();

        while (mazo[iCarta].carta == "0")
        {
            iCarta = generarIndice();
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

void calcularGanadorHistorico(Jugador jugador, string &nombreGanadorHistorico, int &puntosGanadorHistorico)
{
    int totalPuntos = sumarTotalPuntos(jugador);

    if (totalPuntos > puntosGanadorHistorico)
    {
        puntosGanadorHistorico = totalPuntos;
        nombreGanadorHistorico = jugador.nombre;
    }
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




