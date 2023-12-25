#pragma once

struct Carta
{
    std::string carta;
    std::string palo;
};

struct Jugador
{
    std::string nombre;

    Carta mano[5];
    // enum Puntos
    // {
    //     GANAR = 0,
    //     GANAR_ROBANDO = 0,
    //     CARTAS_MAL_UBICADAS = 0,
    //     POR_PASAR_TURNO = 0,
    //     POR_SUFRIR_ROBO = 0
    // };
    int puntos[5] = {};
    bool cartaBlock[5] = {};
    bool pasoTurno = false;
    bool sufrioRobo = false;
};

const std::string CARTAS[5] = {"10", "J", "Q", "K", "A"};
const std::string PALOS[4] = {"\u2665", "\u2663", "\u2660", "\u2666"}; // corazon,trebol,pica,diamante.
