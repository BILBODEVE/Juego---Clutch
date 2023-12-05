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
    cout << "---------------------------------------\n";
    primerTurno();
    cout << "---------------------------------------\n";

    while (estado == false)
    {
        datosJuego(ronda);
        mostrarMano();
        // buscarGanador( estado);
        mezclarMazo(mazo);
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
    validarMano(jugador);
}

bool validarMano(Jugador jugador)
{
    int cont = 0;

    for (int i = 0; i < 5; i++)
    {
        if (jugador.mano[i].carta == tipo_carta[i]) // si el orden de las cartas en la mano es igual a tipo_carta quiere decir que el corral esta ordenado.
        {
            cont++;
        }
    }
    if (cont == 5) // cont = 5 indica que se ordeno el corral.
    {
        if (ronda == 1) // si la mano esta ordenada y es la 1er rondase vuelve a repartir.
        {
            repartirCartas(jugador);
        }
        else
        {
            return true;
        }
    }

    return false;
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

void primerTurno()
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
            cout << "Comienza el jugador: " << jugador1.nombre << endl;
            maximo = true;
            tirarDado(jugador1);
        }
        else if (cont2 > cont1)
        {
            cout << "Comienza el jugador: " << jugador2.nombre << endl;
            maximo = true;
            tirarDado(jugador2);
        }

        indice_carta--;
    }
}

void tirarDado(Jugador &jugador)
{
    cout << "\nPresione enter para tirar el dado: " << getche() << endl;
    int valor_dado = 1;

    cout << "Valor del dado: #" << valor_dado << endl;

    switch (valor_dado)
    {
    case 1:
        cout << "#1 Robar del mazo e intercambiar con una carta del corral.\n\n";
        intercambiarCarta(jugador);
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
}

void intercambiarCarta(Jugador &jugador)
{
    string auxCarta, auxPalo;
    int cartaElegida;

    cout << "#Ingrese la carta que desea intercambiar: ";
    cin >> cartaElegida;
    cartaElegida = cartaElegida - 1;
    cout << "#Presione enter para robar del mazo: " << getche() << endl;

    int cartaRobada = robarDelMazo(); // Genero un indice que se corresponde a el valor de una carta dentro del mazo.

    // Guarda la carta seleccionada por el usuario para no perder su valor en la reasignacion posterior.
    auxCarta = jugador.mano[cartaElegida].carta;
    auxPalo = jugador.mano[cartaElegida].palo;

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

/*void buscarGanador(  bool &estado)
{
    if (validarMano())
    {
        estado = true;
        cout << "El ganador es: " << .nombre;
    }
    else if (validarMano(jugador2))
    {
        estado = true;
        cout << "El ganador es: " << jugador2.nombre;
    }

    cout << endl;
}*/

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

int generarValorDado()
{
    int dado = rand() % 5 + 1;
    return dado;
}