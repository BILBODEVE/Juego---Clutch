#pragma once
#include "estructuras.h"
// Funcion main.
void JugarClutch(Jugador jugador1, Jugador jugador2);

// Funciones globales.
int generarIndice();
int generarValorDado();

void mostrarMazo(Mazo mazo[20]); // std::string lo utilizo para no incluir espacios de nombre.
void cargarMazo(Mazo mazo[20]);
// Bienvenida.
void mensajeBienvenida();

// Menu.
void menuPrincipal(Jugador jugador1, Jugador jugador2, Mazo mazo[20]);
int mostrarMenu();
void validarEleccion(int eleccion);

// Funciones para desarrollar la partida.
void jugar(Jugador jugador1, Jugador jugador2, Mazo mazo[20]);
void datosJuego(Jugador jugador1, Jugador jugador2, int &ronda);
void pedirNombres(Jugador &jugador1, Jugador &jugador2);
void primerTurno(Jugador jugador1, Jugador jugador2);
void mezclarMazo(Mazo mazo[20]);
void repartirCartas(Jugador &jugador);
void validarMano(Jugador jugador, Mazo mazo[20]);
void mostrarMano(Jugador jugador); // std::string lo utilizo para no incluir espacios de nombre.
void tirarDado(Jugador &jugador);
int robarDelMazo();
void intercambiarCarta(Jugador &jugador);

// Estadistica
void mostrarEstadisticas();

// Creditos
void mostrarCreditos();

void setColor();
