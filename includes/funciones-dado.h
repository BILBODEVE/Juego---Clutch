#pragma once
#include "estructuras.h"

void accionarSegunDado(Jugador &jugador1, Jugador &jugador2, Carta mazo[20], bool &existeGanador, std::string &nombreGanadorHistorico, int &puntosGanadorHistorico);

int robarDelMazo(Carta mazo[20]);

void intercambiarCartaConMazo(Jugador &jugador, int cartaElegida, Carta mazo[20]);

void accionarDado1(Jugador &jugadorActual, Carta mazo[20]);

void accionarDado2(Jugador &jugadorAnterior, Jugador &jugadorActual, Carta mazo[20], bool &existeGanador, std::string &nombreGanadorHistorico, int &puntosGanadorHistorico);

void accionarDado3(Jugador &jugadorActual, Jugador &jugadorAnterior);

void intercambiarEntreJugadores(Jugador &jugadorActual, Jugador &jugadorAnterior, int cartaElegida, int cartaRival);

void accionarDado4(Jugador &jugadorActual);

void accionarDado5(Jugador &jugadorActual);

int tirarDado();
