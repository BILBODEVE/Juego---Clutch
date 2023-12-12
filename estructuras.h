#pragma once

struct Mazo
{
    std::string carta;
    std::string palo;
};

struct Acciones
{
    bool cartaBlock[5] = {false, false, false, false, false};
    bool pasoTurno = false;
    bool sufrioRobo = false;
};

struct Jugador
{
    std::string nombre;
    Mazo mano[5];
    Acciones accion;
    int puntos[5] = {};
};

struct GanadorHistorico
{
    std::string nombre;
    int puntos[5] = {};
    int puntajeTotal = 0;
};

const std::string TIPO_CARTA[5] = {"10", "J", "Q", "K", "A"};
const std::string V_PALOS[4] = {"\u2665", "\u2663", "\u2660", "\u2666"}; // corazon,trebol,pica,diamante.