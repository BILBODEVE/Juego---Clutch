#include <iostream>
#include <conio.h>
#include "funciones.h"

using namespace std;

string tipo_carta[5] = {"10", "J", "Q", "K", "A"};            // En ASCII '\n' equivale a 10.
string v_palos[4] = {"\u2665", "\u2663", "\u2660", "\u2666"}; // corazon,trebol,pica,diamante.

int mazo[4][5] = {
    0, 1, 2, 3, 4,
    0, 1, 2, 3, 4,
    0, 1, 2, 3, 4,
    0, 1, 2, 3, 4};
int iCarta;
int iPalo;

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
        break; //   Corto la ejecucion del programa.
    default:
        validarEleccion(eleccion);
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
    datosJuego(jugador1, jugador2, ronda);
    mostrarMano(jugador1, tipo_carta, v_palos);
    mostrarMano(jugador2, tipo_carta, v_palos);
    tirarDado(jugador1, jugador2);
}

void datosJuego(Jugador jugador1, Jugador jugador2, int &ronda)
{
    cout << "Ronda: " << ronda++ << endl;
    cout << jugador1.nombre << " vs " << jugador2.nombre << endl;
    cout << endl;
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
            carta = generarIndices(4); // Genera un indice aleatorio correspondiente a la columna de mazo[][].
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
        iCarta = generarIndices(4);
        iPalo = generarIndices(3);

        while (mazo[iPalo][iCarta] == -1) // Si elemento = -1 quiere decir que esa carta junto con su palo ya fue entregada. Entonces se genera un nuevo indice.
        {
            iCarta = generarIndices(4);
            iPalo = generarIndices(3);
        }

        jugador.mano[0][i] = mazo[iPalo][iCarta];
        jugador.mano[1][i] = iPalo;
        mazo[iPalo][iCarta] = -1; // Una vez asignado el elemento lo quito del mazo dando valor -1.
    }

    validarMano(jugador, mazo);
}

void validarMano(Jugador jugador, int mazo[][5])
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
        repartirCartas(jugador, mazo);
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

    cout << endl;
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

int generarIndices(int n)
{
    int valor = rand() % n;
    return valor;
}

int generarValorDado()
{
    int dado = rand() % 5 + 1;
    return dado;
}

void tirarDado(Jugador jugador1, Jugador jugador2)
{

    cout << "\nPresione enter para tirar el dado: " << getche() << endl;
    int valor_dado = 1;

    cout << "Valor del dado: #" << valor_dado << endl;

    switch (valor_dado)
    {
    case 1:
        cout << "#1 Elegir una carta de su propio corral(1-5) y robar una carta del mazo.Se intercambian las dos.La carta robada pasa a formar parte del corral y la carta seleccionada se incorpora al mazo\n\n";

        intercambiarCarta(jugador1);
        break;
    case 2:
        cout << "Elegir una carta del corral del contrario(1-5) y robar una carta del mazo.Se intercambian las dos.La carta robada pasa a formar parte del corral del contrario y la carta seleccionada se incorpora al mazo.";
        break;
    case 3:
        cout << "Elegir una carta del corral propio (1-5) e intercambiarla por una carta del corral del contrario(1 - 5).Las cartas seleccionadas se intercambian.";
        break;
    case 4:
        cout << "Intercambiar dos cartas del propio corral. Se eligen dos cartas del propio corral(1 - 5) y se intercambian entre sí.";
        break;
    case 5:
        cout << "Bloquear una carta del corral. La carta bloqueada no puede ser elegida por el contrario para intercambio(acciones 2 y 3) pero sí puede ser elegida por uno mismo.";
        break;
    case 6:
        cout << "Elegir cualquiera de las acciones anteriores o bien pasar el turno.";
        break;
    }

    cout << endl;

    mostrarMano(jugador1, tipo_carta, v_palos);
    mostrarMano(jugador2, tipo_carta, v_palos);
}

void robarDelMazo(int &iCarta, int &iPalo)
{
    iCarta = generarIndices(4);
    iPalo = generarIndices(3);

    while (mazo[iPalo][iCarta] == -1)
    {
        iCarta = generarIndices(4);
        iPalo = generarIndices(3);
    }

    mazo[iPalo][iCarta] = -1;
}

void intercambiarCarta(Jugador &jugador)
{
    int indice_carta_mano;
    cout << "#Ingrese la carta que desea intercambiar: ";
    cin >> indice_carta_mano;
    indice_carta_mano -= -1;
    cout << "#Presione enter para robar del mazo: " << getche() << endl;

    robarDelMazo(iCarta, iPalo);

    mazo[jugador.mano[1][indice_carta_mano]][jugador.mano[0][indice_carta_mano]] = jugador.mano[0][indice_carta_mano];
    jugador.mano[0][indice_carta_mano] = iCarta;
    jugador.mano[1][indice_carta_mano] = iPalo;
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