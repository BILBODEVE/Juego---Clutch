#pragma once
#include "estructuras.h"

bool validarOpcion(char opcion);

int contarCartasOrdenadas(Jugador Jugador);

bool validarOrdenMano(Jugador jugador);

bool estaBloqueada(Jugador jugadorActual, int cartaElegida);

bool validarCartasBlock(Jugador jugador);

bool validarSeleccionCarta(int cartaElegida);

bool validarCantidadChar(std::string nombre);



