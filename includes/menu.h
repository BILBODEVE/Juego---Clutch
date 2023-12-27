#pragma once
#include "estructuras.h"

void menuPrincipal(Jugador &jugador1, Jugador &jugador2, Carta mazo[20]);

void volverAlMenu(Jugador jugador1, Jugador jugador2, Carta mazo[20]);

void mostrarEstadisticas(std::string nombreGanadorHistorico, int puntosGanadorHistorico);

void mostrarCreditos();

void mostrarInstrucciones();
