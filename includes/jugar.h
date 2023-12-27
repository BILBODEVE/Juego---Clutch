#pragma once
#include "estructuras.h"

void jugar(Jugador &jugador1, Jugador &jugador2, Carta mazo[20], std::string &nombreGanadorHistorico, int &puntosGanadorHistorico);

void repartirCartas(Jugador &jugador, Carta mazo[20]);

std::string buscarPrimerTurno(Jugador &jugador1, Jugador &jugador2, std::string &turno);

int contarCartaDeUnTipo(Jugador jugador, std::string carta);

void ejecutarRondas(Jugador &jugador1, Jugador &jugador2, Carta mazo[20], std::string &turno, bool &existeGanador, std::string &nombreGanadorHistorico, int &puntosGanadorHistorico);

bool encontrarGanador(Jugador &jugadorActual, Jugador &jugadorAnterior, bool &existeGanador, std::string &nombreGanadorHistorico, int &puntosGanadorHistorico);

void calcularGanadorHistorico(Jugador jugador, std::string &nombreGanadorHistorico, int &puntosGanadorHistorico);

int contarCartaMalUbicada(Jugador jugadorAnterior);

void sumarPuntosPorCartaDesordenada(Jugador &jugadorActual, Jugador jugadorAnterior);

int sumarTotalPuntos(Jugador jugador);
