#pragma once
#include "estructuras.h"
// Funcion main.
void JugarClutch(Jugador jugador1, Jugador jugador2, int mazo[][5], char tipo_carta[], std::string v_palos[]);

// Funciones globales.
int generarNumero(int);
void mostrarMazo(int mazo[][5], char tipo_carta[], std::string v_palos[]); // std::string lo utilizo para no incluir espacios de nombre.

// Bienvenida.
void mensajeBienvenida();

// Menu.
void menuPrincipal(Jugador jugador1, Jugador jugador2, int mazo[][5], char tipo_carta[], std::string v_palos[]);
int mostrarMenu();
void validarEleccion(int eleccion);

// Funciones para desarrollar la partida.
void jugar(Jugador jugador1, Jugador jugador2, int mazo[][5], char tipo_carta[], std::string v_palos[]);
void pedirNombres(Jugador &jugador1, Jugador &jugador2);
void mezclarMazo(int mazo[][5]);
void repartirCartas(Jugador &jugador, int mazo[][5]);
void mostrarMano(Jugador jugador, char tipo_carta[], std::string v_palos[]); // std::string lo utilizo para no incluir espacios de nombre.
int contarCartas(Jugador jugador, int indice_carta);
void primerTurno(Jugador jugador1, Jugador jugador2);

// Estadistica
void mostrarEstadisticas();

// Creditos
void mostrarCreditos();
