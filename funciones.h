#pragma once
#include "estructuras.h"

// Funciones globales
int generarNumero(int);
void mostrarMazo(int mazo[][5], char tipo_carta[], std::string v_palos[]); // std::string lo utilizo para no incluir espacios de nombre.

// Menu
int mostrarMenu();
void evaluarOpcion(int opcion, Jugador jugador1, Jugador jugador2, int mazo[][5], char tipo_carta[], std::string v_palos[]);

// Jugar
void jugar(Jugador jugador1, Jugador jugador2, int mazo[][5], char tipo_carta[], std::string v_palos[]);
void mezclarMazo(int mazo[][5]);
void repartirCartas(Jugador &jugador, int mazo[][5]);
void mostrarMano(Jugador jugador, char tipo_carta[], std::string v_palos[]); // std::string lo utilizo para no incluir espacios de nombre.
int contarCartas(Jugador jugador, int indice_carta);
int buscarMaximo(int cont1, int cont2);
void primerTurno(bool max, Jugador jugador, Jugador, int cont1, int cont2);

// Estadistica
void mostrarEstadisticas();

// Creditos
void mostrarCreditos();
