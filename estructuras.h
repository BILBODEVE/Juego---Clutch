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

extern std::string tipo_carta[5];
extern std::string v_palos[4]; // corazon,trebol,pica,diamante.
