#pragma once
struct Jugador
{
    std::string nombre;
    int mano[2][5]; // Para determinar la mano, establezco una matriz de 2 filas. La primer fila corresponde al tipo de carta y la segunda al palo correspondiente.
    int puntos;
};

extern int mazo[4][5];

extern std::string tipo_carta[5]; // En ASCII '\n' equivale a 10.
extern std::string v_palos[4];    // corazon,trebol,pica,diamante.