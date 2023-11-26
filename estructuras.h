#pragma once

struct Mazo
{
    std::string carta;
    std::string palo;
};

struct Jugador
{
    std::string nombre;
    Mazo mano[5]; // Para determinar la mano, establezco una matriz de 2 filas. La primer fila corresponde al tipo de carta y la segunda al palo correspondiente.
    int puntos;
};

extern std::string tipo_carta[5]; // En ASCII '\n' equivale a 10.
extern std::string v_palos[4];    // corazon,trebol,pica,diamante.

const int CANT_CARTAS = 20;