#pragma once
#include "estructuras.h"

void jugarClutch(Jugador &jugador1, Jugador &jugador2, Mazo mazo[20]);
void mostrarMenu();
int pedirOpcionMenu();
char confirmarUnaAccion();
void menuPrincipal(Jugador &jugador1, Jugador &jugador2, Mazo mazo[20], std::string &nombreGanadorHistorico, int &puntosGanadorHistorico);
void volverAlMenu(Jugador jugador1, Jugador jugador2, Mazo mazo[20], std::string nombreGanadorHistorico, int puntosGanadorHistorico);
void mostrarEstadisticas(std::string nombreGanadorHistorico, int puntosGanadorHistorico);
void mostrarCreditos();
void mostrarInstrucciones();

void cargarMazo(Mazo mazo[20]);
void mezclarMazo(Mazo mazo[20]);
void mostrarMazo(Mazo mazo[20]);
void repartirCartas(Jugador &jugador, Mazo mazo[20]);
void mostrarMano(Jugador jugador1, Jugador jugador2);

void jugar(Jugador &jugador1, Jugador &jugador2, Mazo mazo[20], std::string &nombreGanadorHistorico, int &puntosGanadorHistorico);
void mostrarDatosRonda(Jugador jugador1, Jugador jugador2, int &ronda, std::string turno);
void pedirNombres(Jugador &jugador1, Jugador &jugador2);
std::string buscarPrimerTurno(Jugador &jugador1, Jugador &jugador2, std::string &turno);
int contarCartaDeUnTipo(Jugador jugador, std::string carta);
void ejecutarRondas(Jugador &jugador1, Jugador &jugador2, Mazo mazo[20], std::string &turno, bool &existeGanador, std::string &nombreGanadorHistorico, int &puntosGanadorHistorico);
bool encontrarGanador(Jugador &jugadorActual, Jugador &jugadorAnterior, bool &existeGanador, std::string &nombreGanadorHistorico, int &puntosGanadorHistorico);
void mostrarGanador(Jugador jugador);
void calcularGanadorHistorico(Jugador jugador, std::string &nombreGanadorHistorico, int &puntosGanadorHistorico);

void accionarSegunDado(Jugador &jugador1, Jugador &jugador2, Mazo mazo[20]);

int seleccionarCarta();
int robarDelMazo(Mazo mazo[20]);
void intercambiarConElMazo(Jugador &jugador, int cartaElegida, Mazo mazo[20]);
void accionarDado1(Jugador &jugadorActual, Mazo mazo[20]);
void accionarDado2(Jugador &jugadorAnterior, Mazo mazo[20]);
void accionarDado3(Jugador &jugadorActual, Jugador &jugadorAnterior);
void intercambiarEntreJugadores(Jugador &jugadorActual, Jugador &jugadorAnterior, int cartaElegida, int cartaRival);
void accionarDado4(Jugador &jugadorActual);
void bloquearUnaCarta(Jugador &jugadorActual);

void puntajeTotal(Jugador ganador);
int contarCartaMalUbicada(Jugador jugadorAnterior);
void sumarPuntosPorCartaDesordenada(Jugador &jugadorActual, Jugador jugadorAnterior);
int sumarTotalPuntos(Jugador jugador);

int tirarDado();
int generarIndice();

bool validarOrdenMano(Jugador jugador);
int contarCartasOrdenadas(Jugador Jugador);
bool validarSeleccionCarta(int cartaElegida);
bool validarCartasBlock(Jugador jugador);
bool estaBloqueada(Jugador jugadorActual, int cartaElegida);

void resetearEstados(Jugador &jugador);

void separador(int tamaño, const char symbol = '-');