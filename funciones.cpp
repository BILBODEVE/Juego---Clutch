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
    cout << "\n*****Bienvenido a CLUTCH*****\n\n";
    menuPrincipal(mazo);
}

int mostrarMenu()
{
    int opcion;
    cout << "Eliga una opcion: \n";
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
    buscarPrimerTurno();
    cout << "# Es turno de: " << turno << endl;
    mostrarMano();
    determinarJugadorActual();
    while (estado == false)
    {
        datosJuego(ronda);
        cout << "# Es turno de: " << turno << endl;
        mostrarMano();
        determinarJugadorActual();
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

        cout << "#Confirma los nombres de usuario? S/N: ";
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

    cout << "-------------------------- \n";
    cout << "| " << jugador1.nombre << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "| " << jugador1.mano[i].carta << jugador1.mano[i].palo << " ";
    }

    cout << "\n| \n";

    cout << "| " << jugador2.nombre << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "| " << jugador2.mano[i].carta << jugador2.mano[i].palo << " ";
    }
    cout << "\n--------------------------\n";
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
        accionarSegunDado(jugador1);
        buscarGanador(jugador1);
        turno = jugador2.nombre; // El valor de turno se modifica una vez que se ejecute la accion del jugador actual.
    }
    else
    {
        accionarSegunDado(jugador2);
        buscarGanador(jugador2);
        turno = jugador1.nombre;
    }
}

int tirarDado()
{
    int dado = rand() % 5 + 1;
    return dado;
}

void accionarSegunDado(Jugador &jugador)
{
    cout << "\nPresione enter para tirar el dado: " << getche() << "\n\n";
    int valor_dado = 5;

    cout << "Valor del dado: " << valor_dado << endl;

    if (valor_dado == 6)
    {
        cout << "#6 Elegir una opcion de 1 a 5 o presione 0 para pasar el turno: ";
        cin >> valor_dado;
    }

    switch (valor_dado)
    {
    case 1:
        cout << "#1 Robar del mazo e intercambiar con una carta del corral(1 a 5).\n\n";
        intercambiarCartaPropia(jugador);
        break;
    case 2:
        cout << "#2 Robar del mazo e intercambiarla con una carta del cotrario(1 a 5).\n\n";
        intercambiarCartaRival();
        break;
    case 3:
        cout << "#3 Elegir una carta propia e intercambiarla con una del contrario (1 a 5).\n\n";
        intercambioEntreJugadores();
        break;
    case 4:
        cout << "#4 Intercambiar dos cartas del propio corral(1 a 5).\n\n";
        intercambiarCorralPropio(jugador);
        break;
    case 5:
        cout << "#5 Bloquear una carta del propio corral. El contrario no podra accionar sobre esta carta.\n\n";
        bloquearCarta(jugador);
        break;
    case 0:
        "#Turno cedido\n\n";
        break;
    default:
        accionarSegunDado(jugador);
        break;
    }

    cout << endl;
}

int seleccionarCarta()
{
    int carta;
    cin >> carta;
    carta -= 1;

    return carta;
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

void intercambiarCartaPropia(Jugador &jugador)
{

    cout << "#Ingrese la carta que desea intercambiar: ";
    int cartaElegida = seleccionarCarta();
    cout << "#Presione enter para robar del mazo: " << getche() << endl;

    if (jugador.cartasBloq[cartaElegida])
    {
        jugador.cartasBloq[cartaElegida] = false;
    }

    intercambiarCarta(jugador, cartaElegida);
}

void intercambiarCartaRival()
{
    cout << "Ingrese la carta del rival que desea intercambiar:";
    int cartaElegida = seleccionarCarta();

    if (turno == jugador1.nombre)
    {
        if (validarCartaBloqueada(jugador2, cartaElegida))
        {
            cout << "!!La carta se encuentra bloqueada, seleccione otra carta: \n";
            intercambiarCartaRival();
        }
        else
        {
            intercambiarCarta(jugador2, cartaElegida);
        }
    }
    else
    {
        if (validarCartaBloqueada(jugador1, cartaElegida))
        {
            cout << "!!La carta se encuentra bloqueada, seleccione otra carta: \n";
            intercambiarCartaRival();
        }
        else
        {
            intercambiarCarta(jugador1, cartaElegida);
        }
    }
}

void intercambioEntreJugadores()
{
    cout << "Ingrese la carta de su corral: ";
    int cartaElegida = seleccionarCarta();
    cout << "Ingrese la carta del corral contrario: ";
    int cartaRival = seleccionarCarta();

    if (turno == jugador1.nombre)
    {
        if (validarCartaBloqueada(jugador2, cartaRival))
        {
            cout << "!!La carta se encuentra bloqueada, seleccione otra carta: \n";
            intercambioEntreJugadores();
        }
        else
        {
            intercambiarEntreCorral(jugador1, jugador2, cartaElegida, cartaRival);
        }
    }
    else
    {
        if (validarCartaBloqueada(jugador1, cartaRival))
        {
            cout << "!!La carta se encuentra bloqueada, seleccione otra carta: \n";
            intercambioEntreJugadores();
        }
        else
        {
            intercambiarEntreCorral(jugador2, jugador1, cartaElegida, cartaRival);
        }
    }
}

void intercambiarEntreCorral(Jugador &jugadorActual, Jugador &jugador, int cartaElegida, int cartaRival)
{
    string auxCarta = jugadorActual.mano[cartaElegida].carta;
    string auxPalo = jugadorActual.mano[cartaElegida].palo;

    jugadorActual.mano[cartaElegida].carta = jugador.mano[cartaRival].carta;
    jugadorActual.mano[cartaElegida].palo = jugador.mano[cartaRival].palo;

    jugador.mano[cartaRival].carta = auxCarta;
    jugador.mano[cartaRival].palo = auxPalo;
}

void intercambiarCorralPropio(Jugador &jugador)
{
    cout << "Seleccione una carta: ";
    int cartaElegida = seleccionarCarta();
    cout << "Seleccione con cual sera intercambiada: ";
    int cartaIntercambiar = seleccionarCarta();

    // Validacion en caso de que esta carta se bloquee en la accion4.
    if (jugador.cartasBloq[cartaElegida])
    {
        jugador.cartasBloq[cartaElegida] = false;
        jugador.cartasBloq[cartaIntercambiar] = true;
    }

    string auxCarta = jugador.mano[cartaElegida].carta;
    string auxPalo = jugador.mano[cartaElegida].palo;

    jugador.mano[cartaElegida].carta = jugador.mano[cartaIntercambiar].carta;
    jugador.mano[cartaElegida].palo = jugador.mano[cartaIntercambiar].palo;

    jugador.mano[cartaIntercambiar].carta = auxCarta;
    jugador.mano[cartaIntercambiar].palo = auxPalo;
}

void bloquearCarta(Jugador &jugador)
{
    cout << "Seleccione la carta que desea bloquear: ";
    int cartaElegida = seleccionarCarta();
    if (jugador.cartasBloq[cartaElegida])
    {
        cout << "!!La carta seleccionada ya ha sido bloqueada. Intentelo nuevamente: \n";
        bloquearCarta(jugador);
    }
    else
    {
        jugador.cartasBloq[cartaElegida] = true;
    }
}

bool validarCartaBloqueada(Jugador jugador, int cartaElegida)
{
    if (jugador.cartasBloq[cartaElegida] == true)
    {
        return true;
    }

    return false;
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
