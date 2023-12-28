#pragma once
#include "estructuras.h"

void mostrarMenu();

void menuPrincipal(Jugador &jugador1, Jugador &jugador2, Carta mazo[20],std::string& nombreGanadorHistorico, int& puntosGanadorHistorico);

void mostrarEstadisticas(std::string nombreGanadorHistorico, int puntosGanadorHistorico);

void mostrarCreditos();

void mostrarInstrucciones();

void volverAlMenu(Jugador jugador1, Jugador jugador2, Carta mazo[20], std::string& nombreGanadorHistorico, int& puntosGanadorHistorico);