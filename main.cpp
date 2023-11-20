#include <iostream>
#include <cstdlib> //Incluye srand() y rand()
#include <ctime>   //Incluye time()
#include "funciones.h"
#include "estructuras.h"

using namespace std;

srand(time(0)); // El semillero para rand() solo es necesario declararlo una sola vez en cualquier parte del codigo.
int main()
{

    char tipo_carta[5] = {'\n', 'J', 'Q', 'K', 'A'};              // En ASCII '\n' equivale a 10. Para mostrar este valor es necesario castearlo a int.
    string v_palos[4] = {"\u2665", "\u2663", "\u2660", "\u2666"}; // corazon,trebol,pica,diamante

    // Mazo[][] Almacena en sus elementos el indice correspondiente a cada carta en tipo_carta[].
    int mazo[4][5]{
        0, 1, 2, 3, 4,
        0, 1, 2, 3, 4,
        0, 1, 2, 3, 4,
        0, 1, 2, 3, 4};

    mostrarMenu();
    evaluarOpcion(mostrarMenu());
    // cout << "Mazo inicial\n";
    // mostrarMazo(mazo, tipo_carta, v_palos);
    // cout << endl;
    // cout << "Mazo mezclado\n";
    // mezclarMazo(mazo);
    // mostrarMazo(mazo, tipo_carta, v_palos);
    // cout << endl;
    // cout << "Mano j1:\n";
    // repartirCartas(jugador1, mazo);
    // mostrarMano(jugador1, tipo_carta, v_palos);
    // cout << endl;
    // cout << "Mano j2:\n";
    // repartirCartas(jugador2, mazo);
    // mostrarMano(jugador2, tipo_carta, v_palos);

    return 0;
}