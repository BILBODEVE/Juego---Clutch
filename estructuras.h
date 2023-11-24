#pragma once
struct Jugador
{
    std::string nombre;
    int mano[2][5]; // Para determinar la mano, establezco una matriz de 2 filas. La primer fila corresponde al tipo de carta y la segunda al palo correspondiente.
    int puntos;
};

int mazo[4][5]{
    0, 1, 2, 3, 4,
    0, 1, 2, 3, 4,
    0, 1, 2, 3, 4,
    0, 1, 2, 3, 4};

int iCarta = 0;
int iPalo = 0;