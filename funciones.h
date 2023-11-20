#pragma once
#include "estructuras.h"

// Funciones globales
int generarNumero(int);
void mostrarMazo(int mazo[][5], char tipo_carta[], std::string v_palos[]); // std::string lo utilizo para no incluir espacios de nombre.

// Funcion p/menu
int mostrarMenu();
void evaluarOpcion(int);

// Jugar
void jugar();
void mezclarMazo(int mazo[][5]);
void repartirCartas(Jugador &jugador, int mazo[][5]);
void mostrarMano(Jugador jugador, char tipo_carta[], std::string v_palos[]); // std::string lo utilizo para no incluir espacios de nombre.
int buscarMayoriaCartas(Jugador jugador, int indice_carta);
// Estadistica
void mostrarEstadisticas();

// Creditos
void mostrarCreditos();

// Funciones para probar codigo codigo
