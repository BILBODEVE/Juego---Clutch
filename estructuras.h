#pragma once

struct Mazo
{
    std::string carta;
    std::string palo;
};

struct Jugador
{
    std::string nombre;
    Mazo mano[5];
    bool cartasBloq[5] = {false, false, false, false, false};
    int puntos;
};

extern std::string tipo_carta[5];
extern std::string v_palos[4];

const int CANT_CARTAS = 19; // Mazo mazo indexa a partir de 0.