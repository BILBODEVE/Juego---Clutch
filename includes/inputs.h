#pragma once
#include "estructuras.h"

int seleccionarCarta();

int pedirOpcionMenu();

char pedirConfirmacion();

void solicitarUnNombre(Jugador &jugador, int nro_jugador);

void registrarNombres(Jugador &jugador1, Jugador &jugador2);

bool confirmarFinJuego();
