#pragma once
#include "estructuras.h"
// Funcion main.
void JugarClutch(Jugador jugador1, Jugador jugador2, int mazo[][5], std::string tipo_carta[], std::string v_palos[]);

// Funciones globales.
<<<<<<< HEAD
int generarNumero(int);
=======
int generarNumAleatorio(int, int);                                                // El primero entero define el num max a generar y el segundo a partir de que numero lo quiero hacer.
>>>>>>> 1c755b6651aeebc8ac1fde62e1febbb6e30134b5
void mostrarMazo(int mazo[][5], std::string tipo_carta[], std::string v_palos[]); // std::string lo utilizo para no incluir espacios de nombre.

// Bienvenida.
void mensajeBienvenida();

// Menu.
void menuPrincipal(Jugador jugador1, Jugador jugador2, int mazo[][5], std::string tipo_carta[], std::string v_palos[]);
int mostrarMenu();
void validarEleccion(int eleccion);

// Funciones para desarrollar la partida.
void jugar(Jugador jugador1, Jugador jugador2, int mazo[][5], std::string tipo_carta[], std::string v_palos[]);
<<<<<<< HEAD
void datosJuego(Jugador jugador1, Jugador jugador2, int &ronda);
=======
void datosJuego(Jugador jugador1, Jugador jugador2, int ronda);
>>>>>>> 1c755b6651aeebc8ac1fde62e1febbb6e30134b5
void pedirNombres(Jugador &jugador1, Jugador &jugador2);
void primerTurno(Jugador jugador1, Jugador jugador2, std::string tipo_carta[]);
void mezclarMazo(int mazo[][5]);
void repartirCartas(Jugador &jugador, int mazo[][5]);
void validarMano(Jugador jugador, int mazo[][5]);
<<<<<<< HEAD
void mostrarMano(Jugador jugador, std::string tipo_carta[], std::string v_palos[]); // std::string lo utilizo para no incluir espacios de nombre.

=======
void mostrarMano(Jugador jugador, std::string tipo_carta[], std::string v_palos[], int ronda); // std::string lo utilizo para no incluir espacios de nombre.
void evaluarDado(int valorDado);

// Acciones segun dado
void robarMazo(int mazo[][5], int &iCarta, int &iPalo);

void accion1(Jugador &jugador, int mazo[][5], std::string tipo_carta[], std::string v_palos[], int iCarta, int iPalo);
>>>>>>> 1c755b6651aeebc8ac1fde62e1febbb6e30134b5
// Estadistica
void mostrarEstadisticas();

// Creditos
void mostrarCreditos();

void setColor();
