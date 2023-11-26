#pragma once
#include "estructuras.h"

// Funciones globales.
int generarIndice();

// Funcion main.
void JugarClutch(Jugador jugador1, Jugador jugador2);

// Bienvenida.
void mensajeBienvenida();

// Menu.
void menuPrincipal(Jugador jugador1, Jugador jugador2, Mazo mazo[20]);
int mostrarMenu();
void validarEleccion(int eleccion);
// Estadistica
void mostrarEstadisticas();
// Creditos
void mostrarCreditos();

// Funciones para el mazo y mano
void cargarMazo(Mazo mazo[20]);
void mezclarMazo(Mazo mazo[20]);
void mostrarMazo(Mazo mazo[20]);
void repartirCartas(Jugador &jugador);
bool validarMano(Jugador jugador);
void mostrarMano(Jugador jugador);

// Funciones para desarrollar la partida.
void jugar(Jugador jugador1, Jugador jugador2, Mazo mazo[20]);
void buscarGanador(Jugador jugador1, Jugador jugador2, bool &estado);
void datosJuego(Jugador jugador1, Jugador jugador2, int &ronda);
void pedirNombres(Jugador &jugador1, Jugador &jugador2);
void primerTurno(Jugador jugador1, Jugador jugador2);

//  Acciones del juego
int generarValorDado();
void tirarDado(Jugador &jugador);
int robarDelMazo();
void intercambiarCarta(Jugador &jugador);
