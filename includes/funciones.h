#pragma once
#include "estructuras.h"

// Funcion main.
void jugarClutch(Jugador &jugador1, Jugador &jugador2, Mazo mazo[20]);
// Menu.
void mostrarMenu();
int pedirOpcionMenu();
char confirmarUnaAccion();
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
void intercambiarCarta(Jugador &jugadorActual, int cartaElegida, Mazo mazo[20]);
// accion1
void accionarDado1(Jugador &jugador, Mazo mazo[20]);
// accion2
void accionarDado2(Jugador &jugadorAnterior, Mazo mazo[20]);
// accion3
void accionarDado3(Jugador &jugadorActual, Jugador &jugadorAnterior);
void intercambiarEntreCorral(Jugador &jugadorActual, Jugador &jugadorAnterior, int cartaElegida, int cartaRival);
//  accion4
void accionarDado4(Jugador &jugadorActual);
// accion5
void accionarDado5(Jugador &jugadorActual);

// Sistema de puntuacion.
void puntajeTotal(Jugador ganador);
void contarCartaMalUbicada(Jugador &jugadorActual, Jugador &jugadorAnterior);
int sumarTotalPuntos(Jugador jugador);

// Generar numeros aleatorios (dado, indices).
int tirarDado();
int generarIndice();

// Validaciones
bool validarOrdenMano(Jugador jugador);
int contarCartasOrdenadas(Jugador Jugador);
bool validarSeleccionCarta(int cartaElegida);
bool contarCantCartasBlock(Jugador jugador);
bool validarCartaBloqueada(Jugador jugadorActual, int cartaElegida);

// Resetear estados
void resetearEstados(Jugador &jugador);

// Separadores
void separador(int tamaño, const char symbol = '-');