#pragma once
#include "estructuras.h"

void jugar(Jugador &jugador1, Jugador &jugador2, Carta mazo[20], std::string &nombreGanadorHistorico, int &puntosGanadorHistorico);

void registrarNombres(Jugador &jugador1, Jugador &jugador2);

int generarIndiceMazo();

void cargarMazo(Carta mazo[20]);

void mezclarMazo(Carta mazo[20]);

void mostrarMazo(Carta mazo[]);

void repartirCartas(Jugador &jugador, Carta mazo[20]);

void mostrarMano(Jugador jugador1, Jugador jugador2);

int contarCartaDeUnTipo(Jugador jugador, std::string carta);

std::string buscarPrimerTurno(Jugador &jugador1, Jugador &jugador2, std::string &turno);

void ejecutarRondas(Jugador &jugador1, Jugador &jugador2, Carta mazo[20], std::string &turno, bool &existeGanador, std::string &nombreGanadorHistorico, int &puntosGanadorHistorico);

void mostrarDatosRonda(Jugador jugador1, Jugador jugador2, int &ronda, std::string turno);

bool encontrarGanador(Jugador &jugadorActual, Jugador &jugadorAnterior, bool &existeGanador, std::string &nombreGanadorHistorico, int &puntosGanadorHistorico);

int contarCartaMalUbicada(Jugador jugadorAnterior);

void sumarPuntosPorCartaDesordenada(Jugador &jugadorActual, Jugador jugadorAnterior);

int sumarTotalPuntos(Jugador jugador);

void mostrarGanador(Jugador jugador);

void calcularGanadorHistorico(Jugador jugador, std::string &nombreGanadorHistorico, int &puntosGanadorHistorico);

void resetearEstados(Jugador &jugador);

void finalizarJuego();