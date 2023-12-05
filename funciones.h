#pragma once
#include "estructuras.h"

// Funciones globales.
int generarIndice();

// Funcion main.
void JugarClutch();

// Bienvenida.
void mensajeBienvenida();

// Menu.
void menuPrincipal(Mazo mazo[20]);
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
void mostrarMano();

// Funciones para desarrollar la partida.
void jugar(Mazo mazo[20]);
void buscarGanador(bool &estado);
void datosJuego(int &ronda);
void pedirNombres();
void primerTurno();
void turnos();

//  Acciones del juego
int tirarDado();
void accionarSegunDado(Jugador &jugador);
int robarDelMazo();
void intercambiarCarta(Jugador &jugador);
