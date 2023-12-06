#include <iostream>
#include <conio.h>
#include "funciones.h"

using namespace std;

string tipo_carta[5] = {"10", "J", "Q", "K", "A"};
string v_palos[4] = {"\u2665", "\u2663", "\u2660", "\u2666"}; // corazon,trebol,pica,diamante.
Mazo mazo[20];
Jugador jugador1;
Jugador jugador2;
int iCarta;
int ronda = 1;
bool estado = false;
string turno;

void JugarClutch()
{
    mensajeBienvenida();
    menuPrincipal(mazo);
}

void mensajeBienvenida()
{
    cout << "Bienvenido a CLUTCH.\n\n";
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

void menuPrincipal(Mazo mazo[20])
{
    int eleccion;
    eleccion = mostrarMenu();

    switch (eleccion)
    {
    case 1:
        jugar(mazo);
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

void validarEleccion(int eleccion)
{
    while (eleccion < 0 || eleccion > 3)
    {
        cout << "ERROR: La opcion ingresada es incorrecta. \n Intentelo nuevamente a continuacion: \n\n";
        eleccion = mostrarMenu();
    }
}

void jugar(Mazo mazo[20])
{
    cargarMazo(mazo);
    mezclarMazo(mazo);
    pedirNombres();
    repartirCartas(jugador1);
    repartirCartas(jugador2);

    datosJuego(ronda);
    mostrarMano();
    buscarPrimerTurno();
    cout << "---------------------------------------\n";
    determinarJugadorActual();
    cout << "---------------------------------------\n";
    while (estado == false)
    {
        datosJuego(ronda);
        mostrarMano();
        determinarJugadorActual();
        /*mezclarMazo(mazo); Deberia ejecutarse dentro de turnos()?*/
    }
}

void datosJuego(int &ronda)
{
    cout << "Ronda: " << ronda++ << endl;
    cout << jugador1.nombre << " vs " << jugador2.nombre << endl;
    cout << endl;
}

void pedirNombres()
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

void cargarMazo(Mazo mazo[20])
{

    for (int j = 0; j < 20; j++)
    {
        mazo[j].carta = tipo_carta[j % 5];
    }

    for (int j = 0; j < 20; j++)
    {
        mazo[j].palo = v_palos[j % 4];
    }
}

void mezclarMazo(Mazo mazo[20])
{
    for (int i = 0; i < 20; i++)
    {
        int iCarta = generarIndice();
        string auxCarta;
        string auxPalo;

        auxCarta = mazo[i].carta;
        auxPalo = mazo[i].palo;

        mazo[i].carta = mazo[iCarta].carta;
        mazo[i].palo = mazo[iCarta].palo;

        mazo[iCarta].carta = auxCarta;
        mazo[iCarta].palo = auxPalo;
    }
}

void mostrarMazo(Mazo mazo[20])
{
    for (int i = 0; i < 20; i++)
    {
        cout << mazo[i].carta << mazo[i].palo << endl;
    }

    cout << endl;
}

void repartirCartas(Jugador &jugador) //&jugador es pasado por referencia para modificar el valor original de la matriz
{
    for (int i = 0; i < 5; i++)
    {
        int iCarta = generarIndice();

        while (mazo[iCarta].carta == "0") // Si el elemento es =0 esa carta ya se entrego.
        {
            iCarta = generarIndice();
        }

        jugador.mano[i].carta = mazo[iCarta].carta;
        jugador.mano[i].palo = mazo[iCarta].palo;

        mazo[iCarta].carta = "0"; // Los elementos en las posiciones correspondientes se "eliminan" del mazo.
        mazo[iCarta].palo = "0";  // Los elementos en las posiciones correspondientes se "eliminan" del mazo.
    }
    if (validarMano(jugador) == 5) // Si la condicion es =true , la mano esta ordenada. Se vuelve a repartir.
    {
        repartirCartas(jugador);
    }
}

int validarMano(Jugador jugador)
{
    int cont = 0;
    for (int i = 0; i < 5; i++)
    {
        if (jugador.mano[i].carta == tipo_carta[i]) // si el orden de las cartas en la mano es igual a tipo_carta quiere decir que el corral esta ordenado.
        {
            cont++;
        }
        else
        {
            cont = 0;
        }
    }

    return cont;
}

void mostrarMano()
{
    cout << "Mano jugador: " << jugador1.nombre << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << jugador1.mano[i].carta << jugador1.mano[i].palo << endl;
    }

    cout << "Mano jugador: " << jugador2.nombre << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << jugador2.mano[i].carta << jugador2.mano[i].palo << endl;
    }

    cout << endl;
}

void buscarPrimerTurno()
{
    int indice_carta = 4;
    bool maximo = false;

    while (maximo == false)
    {
        int cont1 = 0;
        int cont2 = 0;

        for (int i = 0; i < 5; i++)
        {
            if (jugador1.mano[i].carta == tipo_carta[indice_carta])
            {
                cont1++;
            }

            if (jugador2.mano[i].carta == tipo_carta[indice_carta])
            {
                cont2++;
            }
        }
        if (cont1 > cont2)
        {
            maximo = true;
            turno = jugador1.nombre;
        }
        else if (cont2 > cont1)
        {
            maximo = true;
            turno = jugador2.nombre;
        }
        indice_carta--;
    }
}

void determinarJugadorActual()
{
    if (turno == jugador1.nombre)
    {
        /*Una vez mostrado el jugador actual que debe jugar, se almacena en turno el jugador contrario.*/
        cout << "Es turno de: " << turno;
        // El problema con esta asignacion, es que turno siempre guarda el jugador que sigue, no el actual. Esto me trae problemas a la hora de usar turno en otras funciones.
        turno = jugador2.nombre;
        accionarSegunDado(jugador1);
        buscarGanador(jugador1);
    }
    else
    {
        cout << "Es turno de: " << turno;
        turno = jugador1.nombre;
        accionarSegunDado(jugador2);
        buscarGanador(jugador2);
    }
}

int tirarDado()
{
    int dado = rand() % 2 + 1;
    return dado;
}

void accionarSegunDado(Jugador &jugador)
{
    cout << "\nPresione enter para tirar el dado: " << getche() << endl;
    int valor_dado = tirarDado();

    cout << "Valor del dado: #" << valor_dado << endl;

    switch (valor_dado)
    {
    case 1:
        cout << "#1 Robar del mazo e intercambiar con una carta del corral.\n\n";
        intercambiarCartaPropia(jugador);
        break;
    case 2:
        cout << "Elegir una carta del corral del contrario(1-5) y robar una carta del mazo.Se intercambian las dos.La carta robada pasa a formar parte del corral del contrario y la carta seleccionada se incorpora al mazo. \n\n";
        intercambiarCartaRival();
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
}

void intercambiarCartaPropia(Jugador &jugador)
{

    cout << "#Ingrese la carta que desea intercambiar: ";
    int cartaElegida = seleccionarCarta();
    cout << "#Presione enter para robar del mazo: " << getche() << endl;

    intercambiarCarta(jugador, cartaElegida);
}

void intercambiarCartaRival()
{
    cout << "Ingrese la carta del contrario que desea intercambiar:";
    int cartaElegida = seleccionarCarta();

    if (turno == jugador1.nombre)
    {
        intercambiarCarta(jugador1, cartaElegida);
    }
    else
    {
        intercambiarCarta(jugador2, cartaElegida);
    }
}

int seleccionarCarta()
{
    int carta;
    cin >> carta;
    carta -= 1;

    return carta;
}

void intercambiarCarta(Jugador &jugador, int cartaElegida)
{
    int cartaRobada = robarDelMazo(); // Deberia estar por fuera de la funcion?

    // Guarda la carta seleccionada por el usuario para no perder su valor en la reasignacion posterior.
    string auxCarta = jugador.mano[cartaElegida].carta;
    string auxPalo = jugador.mano[cartaElegida].palo;

    // La nueva carta del usuario se genera mediante lo que tenga mazo en el indice correspondiente a cartaRobada.
    jugador.mano[cartaElegida].carta = mazo[cartaRobada].carta;
    jugador.mano[cartaElegida].palo = mazo[cartaRobada].palo;

    // La carta seleccionada para intercambiar reemplaza los valores de la carta robada.
    mazo[cartaRobada].carta = auxCarta;
    mazo[cartaRobada].palo = auxPalo;
}

int robarDelMazo()
{
    iCarta = generarIndice();

    while (mazo[iCarta].carta == "0")
    {
        iCarta = generarIndice();
    }

    return iCarta;
}

bool buscarGanador(Jugador jugador)
{
    if (validarMano(jugador) == 5)
    {
        estado = true;
    }
    mostrarGanador(jugador);

    return estado;
}

void mostrarGanador(Jugador jugador)
{
    if (estado)
    {
        cout << "HITO: " << jugador.nombre << endl;
        cout << "Puntos: " << 150 << endl;
        cout << "Puntos: " << 10 << endl;
        cout << jugador.nombre << "gano el juego con un total de " << 150 << "puntos";
    }
}

void mostrarEstadisticas()
{
    cout << "hola" << endl;
}

void mostrarCreditos()
{
    cout << "Hola" << endl;
}

int generarIndice()
{
    int indice = rand() % CANT_CARTAS;

    return indice;
}
