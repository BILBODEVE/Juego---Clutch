#include <iostream>
#include <cstdlib>
#include "funciones.h"

using namespace std;

int mostrarMenu()
{
    int opcion;
    cout << "Eliga una opcion: \n";

    cout << "CLUTCH \n";
    cout << "--------------------\n";
    cout << "1 - JUGAR \n";
    cout << "2 - ESTADISTICAS\n";
    cout << "3 - CREDITOS\n";
    cout << "--------------------\n";
    cout << "0 - SALIR\n";
    cin >> opcion;

    return opcion;
}

void evaluarOpcion(int opcion)
{
    switch (opcion)
    {
    case 1:
        jugar();
        break;
    case 2:
        mostrarEstadisticas();
        break;
    case 3:
        mostrarCreditos();
    case 0:
        break; //   Corto la ejecucion del programa.
    default:
        cout << "La opcion elegida es incorrecta. Vuelva a intentarlo";
        mostrarMenu(); //   Vuelvo a llamar a mostrarMenu para obtener un valor correcto.
    }
}

void jugar()
{
    // void mostrarMazo(int mazo[][5], char tipo_carta[], string v_palos[]);
    // void mezclarMazo(int mazo[][5]);
    // void repartirCartas(Jugador jugador1, int mazo[][5]);
    // void repartirCartas(Jugador jugador2, int mazo[][5]);
    // void mostrarMano(Jugador jugador1, char tipo_carta[], string v_palos[]);
    // void mostrarMano(Jugador jugador2, char tipo_carta[], string v_palos[]);
}

void mezclarMazo(int mazo[][5])
{
    // Las cartas se mezclan por fila.
    int auxiliar;
    int carta;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            carta = generarNumero(4); // Genera un indice aleatorio correspondiente a la columna de mazo[][].
            auxiliar = mazo[i][j];
            mazo[i][j] = mazo[i][carta];
            mazo[i][carta] = auxiliar;
        }
    }
}

void repartirCartas(Jugador &jugador, int mazo[][5]) //&jugador es pasado como referencia para modificar el valor original de la matriz
{

    for (int i = 0; i < 5; i++)
    {
        // Genero un numero aleatorio correspondiente a la fila y columna de mazo[][].
        int carta = generarNumero(4);
        int palo = generarNumero(3);

        while (mazo[palo][carta] == -1) // Si elemento = -1 quiere decir que esa carta junto con su palo ya fue entregada. Entonces se genera un nuevo indice.
        {
            carta = generarNumero(4);
            palo = generarNumero(3);
        }

        jugador.mano[0][i] = mazo[palo][carta];
        jugador.mano[1][i] = palo;
        mazo[palo][carta] = -1; // Una vez asignado el elemento lo quito del mazo dando valor -1.
    }
}

void mostrarMano(Jugador jugador, char tipo_carta[], string v_palos[])
{
    for (int i = 0; i < 5; i++)
    {
        if (jugador.mano[0][i] == 0)
        {
            cout << (int)tipo_carta[jugador.mano[0][i]] << v_palos[jugador.mano[1][i]] << endl; // Si un tipo de carta es 0 corresponde a '\n' que es =10 por ende necesito castear este elemento?
        }
        else
        {
            cout << tipo_carta[jugador.mano[0][i]] << v_palos[jugador.mano[1][i]] << endl;
        }
    }
}

int buscarMayoriaCartas(Jugador jugador, int indice_carta)
{
    int cont = 0;

    if (jugador.mano[0][0] == indice_carta)
    {
        cont++;
    }

    return cont;
}

int generarNumero(int n)
{
    int valor = rand() % n;
    return valor;
}
void mostrarEstadisticas()
{
    cout << "hola" << endl;
}
void mostrarCreditos()
{
    cout << "Hola" << endl;
}

// Funciones para probar codigo.
void mostrarMazo(int mazo[][5], char tipo_carta[], string v_palos[])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (tipo_carta[mazo[i][j]] == '\n')
            {
                cout << (int)tipo_carta[mazo[i][j]] << v_palos[i] << endl;
            }
            else
            {
                cout << tipo_carta[mazo[i][j]] << v_palos[i] << endl;
            }
        }
    }
}