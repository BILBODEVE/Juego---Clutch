#pragma once
#include "estructuras.h"

void mostrarMenu();

void mostrarMazo(Carta mazo[]);

void mostrarMano(Jugador jugador1, Jugador jugador2);

void mostrarDatosRonda(Jugador jugador1, Jugador jugador2, int &ronda, std::string turno);

void mostrarGanador(Jugador jugador);

int generarIndice();

void resetearEstados(Jugador &jugador);

void separador(int tamaño, const char symbol = '-');