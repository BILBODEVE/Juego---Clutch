#include <iostream>
#include "funciones.h"
#include "estructuras.h"

using namespace std;

void JugarClutch(Jugador jugador1, Jugador jugador2, int mazo[][5], std::string tipo_carta[], string v_palos[])
{
    mensajeBienvenida();
    menuPrincipal(jugador1, jugador2, mazo, tipo_carta, v_palos);
}

void mensajeBienvenida()
{
    cout << "Bienvenido a CLUTCH.\n\n";
}

void menuPrincipal(Jugador jugador1, Jugador jugador2, int mazo[][5], std::string tipo_carta[], string v_palos[])
{
    int eleccion;
    eleccion = mostrarMenu();

    switch (eleccion)
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
        break;
    default:
        validarEleccion(eleccion); //   Corto la ejecucion del programa.
        cout << endl;
    }
}

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
    cout << endl;

    return opcion;
}

void validarEleccion(int eleccion)
{
    while (eleccion < 0 || eleccion > 3)
    {
        cout << "ERROR: La opcion ingresada es incorrecta. \n Intentelo nuevamente a continuacion: \n\n";
        eleccion = mostrarMenu();
    }
}

void jugar(Jugador jugador1, Jugador jugador2, int mazo[][5], string tipo_carta[], string v_palos[])
{
    int ronda = 0;
    pedirNombres(jugador1, jugador2);
    mezclarMazo(mazo);
    repartirCartas(jugador1, mazo);
    repartirCartas(jugador2, mazo);
    cout << "---------------------------------------\n";
    primerTurno(jugador1, jugador2, tipo_carta);
    cout << "---------------------------------------\n";
    while (ronda < 100)
    {
        ronda++;
        datosJuego(jugador1, jugador2, ronda);
        mostrarMano(jugador1, tipo_carta, v_palos);
        cout << "\n\n";
        mostrarMano(jugador2, tipo_carta, v_palos);
        int valorDado = generarNumAleatorio(6, 1); // Valor del dado
        cout << "#Valor del dado: " << valorDado << endl;
    }
}

void datosJuego(Jugador jugador1, Jugador jugador2, int ronda)
{
    cout << "Ronda: " << ronda << endl;
    cout << jugador1.nombre << " vs " << jugador2.nombre << endl;
}

void pedirNombres(Jugador &jugador1, Jugador &jugador2)
{
    char confirma = 'N';

    while (confirma != 'S')
    {
        cout << "---------------------------------------\n";
        cout << "#Registre los nombres de los jugadores: \n";
        cout << " Jugador 1: ";
        cin >> jugador1.nombre;
        cout << " Jugador 2: ";
        cin >> jugador2.nombre;

        cout << "#Confirma los nombrse de usuario? S/N: ";
        cin >> confirma;
        confirma = toupper(confirma);
        cout << "---------------------------------------\n\n";
    }
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
            carta = generarNumAleatorio(4, 0); // Genera un indice aleatorio correspondiente a la columna de mazo[][].
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
        int carta = generarNumAleatorio(4, 0);
        int palo = generarNumAleatorio(3, 0);

        while (mazo[palo][carta] == -1) // Si elemento = -1 quiere decir que esa carta junto con su palo ya fue entregada. Entonces se genera un nuevo indice.
        {
            carta = generarNumAleatorio(4, 0);
            palo = generarNumAleatorio(3, 0);
        }

        jugador.mano[0][i] = mazo[palo][carta];
        jugador.mano[1][i] = palo;
        mazo[palo][carta] = -1; // Una vez asignado el elemento lo quito del mazo dando valor -1.
    }

    // validarMano(jugador, mazo);
}

void validarMano(Jugador jugador, int mazo[][5], int ronda)
{
    int cont = 0;

    for (int i = 0; i < 4; i++) // El contador va hasta el indice 3 ya que a partir del indice 4 no existen mas elementos dentro del array.
    {
        if (jugador.mano[0][i] + 1 == jugador.mano[0][i + 1])
        {
            cont++;
        }
    }

    if (cont == 4)
    {
        if (ronda == 1)
        {
            repartirCartas(jugador, mazo);
        }
        else
        {
            // mostrar ganador
        }
    }
}

void mostrarMano(Jugador jugador, string tipo_carta[], string v_palos[])
{
    cout << "Mano jugador: " << jugador.nombre << endl;
    for (int i = 0; i < 5; i++)
    {
        if (jugador.mano[i][i] == 0)
        {
            cout << tipo_carta[jugador.mano[0][i]] << v_palos[jugador.mano[1][i]] << "  ";
        }
        else
        {
            cout << tipo_carta[jugador.mano[0][i]] << v_palos[jugador.mano[1][i]] << "  ";
        }
    }
}

void primerTurno(Jugador jugador1, Jugador jugador2, string tipo_carta[])
{
    int indice_carta = 4;
    bool maximo = false;

    while (maximo == false)
    {

        int cont1 = 0;
        int cont2 = 0;

        for (int i = 0; i < 5; i++)
        {
            if (jugador1.mano[0][i] == indice_carta)
            {
                cont1++;
            }

            if (jugador2.mano[0][i] == indice_carta)
            {
                cont2++;
            }
        }

        if (cont1 > cont2)
        {
            cout << "Comienza el jugador: " << jugador1.nombre << endl;
            maximo = true;
        }
        else if (cont2 > cont1)
        {
            cout << "Comienza el jugador: " << jugador2.nombre << endl;
            maximo = true;
        }

        indice_carta--;
    }
}

void valorDado(int valorDado)
{
    switch (valorDado)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    default:
        break;
    }
}

int generarNumAleatorio(int n, int m)
{
    int valor = rand() % n + m;
    return valor;
}

void robarMazo(int mazo[][5], int &iCarta, int &iPalo)
{
    iCarta = generarNumAleatorio(4, 0);
    iPalo = generarNumAleatorio(3, 0);

    while (mazo[iPalo][iCarta] == -1)
    {
        int iCarta = generarNumAleatorio(4, 0);
    }

    mazo[iPalo][iCarta] = -1;
}

void accion1(Jugador &jugador, int mazo[][5], string tipo_carta[], string v_palos[], int iCarta, int iPalo)
{
    int cartaElegida;
    cout << "Ingrese la carta que desea intercambiar: ";
    cin >> cartaElegida;
    cout << "Presione enter para robar una carta del mazo: ";
    cout << "Su nueva carta es: " << tipo_carta[iCarta] << v_palos[iPalo];
    mazo[jugador.mano[1][cartaElegida - 1]][jugador.mano[0][cartaElegida - 1]] = jugador.mano[0][cartaElegida - 1];
    jugador.mano[0][cartaElegida - 1] = iCarta;
    jugador.mano[1][cartaElegida - 1] = iPalo;
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
void mostrarMazo(int mazo[][5], string tipo_carta[], string v_palos[])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << tipo_carta[mazo[i][j]] << v_palos[i] << endl;
        }
    }
}