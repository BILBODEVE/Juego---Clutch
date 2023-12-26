#pragma once
#include "estructuras.h"

void jugarClutch(Jugador &jugador1, Jugador &jugador2, Carta mazo[20]);
void mostrarMenu();
int pedirOpcionMenu();
char pedirOpcion();
void menuPrincipal(Jugador &jugador1, Jugador &jugador2, Carta mazo[20], std::string &nombreGanadorHistorico, int &puntosGanadorHistorico);
void volverAlMenu(Jugador jugador1, Jugador jugador2, Carta mazo[20], std::string nombreGanadorHistorico, int puntosGanadorHistorico);
void mostrarEstadisticas(std::string nombreGanadorHistorico, int puntosGanadorHistorico);
void mostrarCreditos();
void mostrarInstrucciones();

void cargarMazo(Carta mazo[20]);
void mezclarMazo(Carta mazo[20]);
void mostrarCarta(Carta mazo[20]);
void repartirCartas(Jugador &jugador, Carta mazo[20]);
void mostrarMano(Jugador jugador1, Jugador jugador2);

void jugar(Jugador &jugador1, Jugador &jugador2, Carta mazo[20], std::string &nombreGanadorHistorico, int &puntosGanadorHistorico);
void mostrarDatosRonda(Jugador jugador1, Jugador jugador2, int &ronda, std::string turno);
void solicitarUnNombre(Jugador &jugador, int nro_jugador);
void registrarNombres(Jugador &jugador1, Jugador &jugador2);
std::string buscarPrimerTurno(Jugador &jugador1, Jugador &jugador2, std::string &turno);
int contarCartaDeUnTipo(Jugador jugador, std::string carta);
void ejecutarRondas(Jugador &jugador1, Jugador &jugador2, Carta mazo[20], std::string &turno, bool &existeGanador, std::string &nombreGanadorHistorico, int &puntosGanadorHistorico);
bool encontrarGanador(Jugador &jugadorActual, Jugador &jugadorAnterior, bool &existeGanador, std::string &nombreGanadorHistorico, int &puntosGanadorHistorico);
void mostrarGanador(Jugador jugador);
void calcularGanadorHistorico(Jugador jugador, std::string &nombreGanadorHistorico, int &puntosGanadorHistorico);

void accionarSegunDado(Jugador &jugador1, Jugador &jugador2, Carta mazo[20], bool &existeGanador, std::string &nombreGanadorHistorico, int &puntosGanadorHistorico);

int seleccionarCarta();
int robarDelCarta(Carta mazo[20]);
void intercambiarCartaConMazo(Jugador &jugador, int cartaElegida, Carta mazo[20]);
void accionarDado1(Jugador &jugadorActual, Carta mazo[20]);
void accionarDado2(Jugador &jugadorAnterior, Jugador &jugadorActual, Carta mazo[20], bool &existeGanador, std::string &nombreGanadorHistorico, int &puntosGanadorHistorico);
void accionarDado3(Jugador &jugadorActual, Jugador &jugadorAnterior);
void intercambiarEntreJugadores(Jugador &jugadorActual, Jugador &jugadorAnterior, int cartaElegida, int cartaRival);
void accionarDado4(Jugador &jugadorActual);
void accionarDado5(Jugador &jugadorActual);

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
bool validarCantidadChar(std::string nombre);
bool validarOpcion(char opcion);

void resetearEstados(Jugador &jugador);

void separador(int tamaño, const char symbol = '-');