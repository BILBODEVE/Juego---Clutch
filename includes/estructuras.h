#pragma once

struct Carta
{
    std::string carta;
    std::string palo;
};

enum class Puntajes : int{
    GANAR,
    GANAR_ROBANDO,
    CARTA_MAL_UBICADA,
    POR_PASAR_TURNO,
    POR_SUFRIR_ROBO
};

struct Jugador
{
    std::string nombre;

    Carta mano[5];
    int puntos[5] = {};
    bool cartaBlock[5] = {};
    bool pasoTurno = false;
    bool sufrioRobo = false;
};

const std::string CARTAS[5] = {"10", "J", "Q", "K", "A"};
const std::string PALOS[4] = {"\u2665", "\u2663", "\u2660", "\u2666"};
