#pragma once
#include "estructuras.h"
// Funcion main.
void JugarClutch(Jugador jugador1, Jugador jugador2, int mazo[][5], std::string tipo_carta[], std::string v_palos[]);

// Funciones globales.
int generarIndices(int);
int generarValorDado();

void mostrarMazo(int mazo[][5], std::string tipo_carta[], std::string v_palos[]); // std::string lo utilizo para no incluir espacios de nombre.

// Bienvenida.
void mensajeBienvenida();

// Menu.
void menuPrincipal(Jugador jugador1, Jugador jugador2, int mazo[][5], std::string tipo_carta[], std::string v_palos[]);
int mostrarMenu();
void validarEleccion(int eleccion);

// Funciones para desarrollar la partida.
void jugar(Jugador jugador1, Jugador jugador2, int mazo[][5], std::string tipo_carta[], std::string v_palos[]);
void datosJuego(Jugador jugador1, Jugador jugador2, int &ronda);
void pedirNombres(Jugador &jugador1, Jugador &jugador2);
void primerTurno(Jugador jugador1, Jugador jugador2, std::string tipo_carta[]);
void mezclarMazo(int mazo[][5]);
void repartirCartas(Jugador &jugador, int mazo[][5]);
void validarMano(Jugador jugador, int mazo[][5]);
void mostrarMano(Jugador jugador, std::string tipo_carta[], std::string v_palos[]); // std::string lo utilizo para no incluir espacios de nombre.
void tirarDado(Jugador jugador1, Jugador jugador2);
void robarDelMazo(int &iCarta, int &iPalo);
void intercambiarCarta(Jugador &jugador);

// Estadistica
void mostrarEstadisticas();

// Creditos
void mostrarCreditos();

void setColor();
