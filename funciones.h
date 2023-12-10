#pragma once
#include "estructuras.h"

// Funciones globales.
int generarIndice();

// Menu.
void menuPrincipal();
int mostrarMenu();
// Estadistica
void mostrarEstadisticas();
// Creditos
void mostrarCreditos();
// Instrucciones del juego;
void mostrarInstrucciones();

// Funciones para el mazo y mano
void cargarMazo(Mazo mazo[20]);
void mezclarMazo(Mazo mazo[20]);
void mostrarMazo(Mazo mazo[20]);
void repartirCartas(Jugador &jugador);
int validarMano(Jugador jugador);
void mostrarMano();

// Funciones para desarrollar la partida.
void jugar(Mazo mazo[20]);
void datosJuego(int &ronda);
void pedirNombres();
void buscarPrimerTurno();
void determinarJugadorActual();
bool encontrarGanador(Jugador jugador);
void mostrarGanador(Jugador jugador);
void calcularGanadorHistorico(Jugador jugador);

//  Acciones del juego
int tirarDado();
void accionarSegunDado(Jugador &jugador);
int seleccionarCarta();
int robarDelMazo();

void intercambiarCarta(Jugador &Jugador, int cartaElegida); // Realiza la accion de intercambiar una carta con el mazo
// accion1
void intercambiarCartaPropia(Jugador &jugador);
// accion2
void intercambiarCartaRival();
// accion3
void intercambiarEntreCorral(Jugador &jugadorActual, Jugador &jugador2, int cartaElegida, int cartaRival);
void intercambioEntreJugadores();
//  accion4
void intercambiarCorralPropio(Jugador &jugador);
// accion5
void bloquearCarta(Jugador &jugador);
bool validarCartaBloqueada(Jugador jugador, int cartaElegida);

// Puntajes
void puntajeTotal(Jugador ganador);
void cartaMalUbicada(Jugador jugador);
int contarCartaMalUbicada(Jugador jugador);
int sumarTotalPuntos(Jugador jugador);

// Validaciones
bool validarSeleccionCarta(int cartaElegida);
bool validarCantCartasBlock(Jugador jugador); // Si un jugador tiene el total de cartas bloqueadas y el juego vuelve a pedir que bloquee otra carta, vuelve a tirar el dado
void volverAlMenu();