#include <iostream>
#include "funciones.h"
#include "estructuras.h"

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
    cout << "Ingrese la opcion elegida: ";
    cin >> opcion;

    return opcion;
}

void evaluarOpcion(int opcion, Jugador jugador1, Jugador jugador2, int mazo[][5], char tipo_carta[], string v_palos[])
{
    switch (opcion)
    {
    case 1:
        jugar(jugador1, jugador2, mazo, tipo_carta, v_palos);
        break;
    case 2:
        mostrarEstadisticas();
        break;
    case 3:
        mostrarCreditos();
        break;
    case 0:
        break; //   Corto la ejecucion del programa.
    default:
        cout << "La opcion elegida es incorrecta. Vuelva a intentarlo";
        mostrarMenu(); //   Vuelvo a llamar a mostrarMenu para obtener un valor correcto.
    }
}

void jugar(Jugador jugador1, Jugador jugador2, int mazo[][5], char tipo_carta[], string v_palos[])
{
    mezclarMazo(mazo);
    repartirCartas(jugador1, mazo);
    repartirCartas(jugador2, mazo);
    mostrarMano(jugador1, tipo_carta, v_palos);
    mostrarMano(jugador2, tipo_carta, v_palos);
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

void primerTurno(bool max, Jugador jugador, int cont1, int cont2)
{
    int indice_carta = 0; // Indice carta corresponde a los indices de el vector tipo_carta
    int comienza = 0;     // Comienza almacena el numero del jugador al cual le toca jugar primero.

    while (comienza == 0 && indice_carta < 5)
    {
        cont1 = contarCartas(jugador1, indice_carta);
        cont2 = contarCartas(jugador2, indice_carta);
        comienza = buscarMaximo(jugador, cont1, cont2);

        indice_carta++; // Si comienza sigue siendo =0 , sigo buscando un maximo;
    }

    if (comienza)
    {
        cout << "Comineza el jugador " << jugador1.nombre << endl;
    }
    else
    {
        cout << "Comineza el jugador " << jugador2.nombre << endl;
    }
}

int contarCartas(Jugador jugador, int indice_carta)
{
    int cont;
    for (int i = 0; i < 5; i++)
    {
        if (jugador.mano[indice_carta][indice_carta] == indice_carta)
        {
            cont++;
        }
    }

    return cont;
}

int buscarMaximo(Jugador jugador, int cont1, int cont2)
{
    if (cont1 > cont2)
    {
        return 0;
    }
    else if (cont2 > cont1)
    {
        return 1;
    }
    else
    {
        return 2;
    }
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