#pragma once
#include "estructuras.h"

void jugarClutch(Jugador &jugador1, Jugador &jugador2, Mazo mazo[20]);
// Menu.
int mostrarMenu();
void menuPrincipal(Jugador &jugador1, Jugador &jugador2, Mazo mazo[20], std::string &nombreGanadorHistorico, int &puntosGanadorHistorico);
void volverAlMenu(Jugador jugador1, Jugador jugador2, Mazo mazo[20], std::string nombreGanadorHistorico, int puntosGanadorHistorico);
// Estadistica.
void mostrarEstadisticas(std::string nombreGanadorHistorico, int puntosGanadorHistorico);
// Creditos.
void mostrarCreditos();
// Instrucciones del juego.
void mostrarInstrucciones();

// Funciones para el mazo y mano
void cargarMazo(Mazo mazo[20]);
void mezclarMazo(Mazo mazo[20]);
void mostrarMazo(Mazo mazo[20]);
void repartirCartas(Jugador &jugador, Mazo mazo[20]);
void mostrarMano(Jugador jugador1, Jugador jugador2);

// Funciones para desarrollar la partida.
void jugar(Jugador &jugador1, Jugador &jugador2, Mazo mazo[20], std::string &nombreGanadorHistorico, int &puntosGanadorHistorico);
void mostrarDatosRonda(Jugador jugador1, Jugador jugador2, int &ronda, std::string turno);
void pedirNombres(Jugador &jugador1, Jugador &jugador2);
void buscarPrimerTurno(Jugador &jugador1, Jugador &jugador2, std::string &turno);
void ejecutarRondas(Jugador &jugador1, Jugador &jugador2, Mazo mazo[20], std::string &turno, bool &existeGanador, std::string &nombreGanadorHistorico, int &puntosGanadorHistorico);
bool encontrarGanador(Jugador &jugadorActual, Jugador &jugadorAnterior, bool &existeGanador, std::string &nombreGanadorHistorico, int &puntosGanadorHistorico);
void mostrarGanador(Jugador jugador);
void calcularGanadorHistorico(Jugador jugador, std::string &nombreGanadorHistorico, int &puntosGanadorHistorico);

//  Desarrollo de las acciones del juego.
void accionarSegunDado(Jugador &jugador1, Jugador &jugador2, Mazo mazo[20]);

int seleccionarCarta();
int robarDelMazo(Mazo mazo[20]);
void intercambiarCarta(Jugador &jugadorActual, int cartaElegida, Mazo mazo[20]); // Realiza la accion de intercambiar una carta con el mazo
// accion1
void intercambiarCartaPropia(Jugador &jugador, Mazo mazo[20]);
// accion2
void intercambiarCartaRival(Jugador &jugadorAnterior, Mazo mazo[20]);
// accion3
void intercambiarEntreCorral(Jugador &jugadorActual, Jugador &jugadorAnterior, int cartaElegida, int cartaRival);
void intercambioEntreJugadores(Jugador &jugadorActual, Jugador &jugadorAnterior);
//  accion4
void intercambiarCorralPropio(Jugador &jugadorActual);
// accion5
void bloquearCarta(Jugador &jugadorActual);

// Sistema de puntuacion.
void puntajeTotal(Jugador ganador);
void contarCartaMalUbicada(Jugador &jugadorActual, Jugador &jugadorAnterior);
int sumarTotalPuntos(Jugador jugador);

// Generar numeros aleatorios (dado, indices).
int tirarDado();
int generarIndice();

// Validaciones
int validarMano(Jugador jugador);
bool validarSeleccionCarta(int cartaElegida);
bool validarCantCartasBlock(Jugador jugador);
bool validarCartaBloqueada(Jugador jugadorActual, int cartaElegida);