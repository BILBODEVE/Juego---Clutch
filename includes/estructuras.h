#pragma once

struct Mazo
{
    std::string carta;
    std::string palo;
};

struct Acciones
{
    bool cartaBlock[5] = {};
    bool pasoTurno = false;
    bool sufrioRobo = false;
};

struct Jugador
{
    std::string nombre;
    Mazo mano[5];
    Acciones accion;
    int puntos[5] = {}; // Los indices se correlacionan con el orden en el que se describe el valor de los puntajes en la consigna.
};

const std::string CARTA[5] = {"10", "J", "Q", "K", "A"};
const std::string PALOS[4] = {"\u2665", "\u2663", "\u2660", "\u2666"}; // corazon,trebol,pica,diamante.
