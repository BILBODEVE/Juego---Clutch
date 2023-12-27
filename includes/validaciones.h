#pragma once
#include "estructuras.h"

bool validarOrdenMano(Jugador jugador);

int contarCartasOrdenadas(Jugador Jugador);

bool validarSeleccionCarta(int cartaElegida);

bool validarCartasBlock(Jugador jugador);

bool estaBloqueada(Jugador jugadorActual, int cartaElegida);

bool validarCantidadChar(std::string nombre);

bool validarOpcion(char opcion);

void finalizarJuego();
