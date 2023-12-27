#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "../includes/funciones-dado.h"
#include "../includes/recursos.h"
#include "../includes/inputs.h"
#include "../includes/validaciones.h"
#include "../includes/jugar.h"
#include "../includes/variables.h"

using namespace std;

void accionarSegunDado(Jugador &jugadorActual, Jugador &jugadorAnterior, Carta mazo[20],bool &existeGanador, string &nombreGanadorHistorico, int &puntosGanadorHistorico)
{
    cout << "Presione enter para tirar el dado...";
    getch();
    
    int valor_dado = tirarDado();
    cout << "\nValor del dado: " << valor_dado << endl;

    if (valor_dado == 6)
    {
        cout << "#6 Elegir una opcion de 1 a 5 o ingrese 0 para pasar el turno.\n\n";
        separador(50);
        cout << "Segun el valor del dado, se pueden realizar los siguientes movimientos:\n";
        cout << "\t #1 Robar del mazo e intercambiar con una carta del corral.\n";
        cout << "\t #2 Robar del mazo e intercambiarla con una carta del contrario.\n";
        cout << "\t #3 Elegir una carta propia e intercambiarla con una del contrario.\n";
        cout << "\t #4 Intercambiar dos cartas del propio corral.\n";
        cout << "\t #5 Bloquear una carta del propio corral. El contrario no podra accionar sobre esta carta.\n";
        cout << "\t     Si la carta esta bloqueada se muestra entre [].\n";
        cout << "\t #6 Elegir una opcion o pasar el turno.\n";
        separador(50);

        valor_dado = pedirOpcionMenu();

        if(valor_dado < 0)
            confirmarFinJuego();

        while (valor_dado < 1 || valor_dado > 5)
        {
            cout << "Intentelo nuevamente a continuacion\n";
            valor_dado = pedirOpcionMenu();
        }
        
    }

    switch (valor_dado)
    {
    case 1:
        accionarDado1(jugadorActual, mazo);
        break;
    case 2:
        accionarDado2(jugadorAnterior, jugadorActual, mazo, existeGanador, nombreGanadorHistorico, puntosGanadorHistorico);
        if(validarCartasBlock(jugadorAnterior))
        {
            cout << "El jugador " << jugadorAnterior.nombre << " tiene todas las cartas bloqueadas.Vuelva a tirar el dado.\n";
            accionarSegunDado(jugadorActual, jugadorAnterior, mazo, existeGanador, nombreGanadorHistorico, puntosGanadorHistorico);
        }
        break;
    case 3:
        accionarDado3(jugadorActual, jugadorAnterior);
        if(validarCartasBlock(jugadorAnterior))
        {
            cout << "El jugador " << jugadorAnterior.nombre << " tiene todas las cartas bloqueadas.Vuelva a tirar el dado.\n";
            accionarSegunDado(jugadorActual, jugadorAnterior, mazo, existeGanador, nombreGanadorHistorico, puntosGanadorHistorico);
        }
        break;
    case 4:
        accionarDado4(jugadorActual);
        break;
    case 5:
        if (validarCartasBlock(jugadorActual))
        {
            cout << "ACCION DENEGADA! Todas sus cartas estan bloqueadas. Tire el dado nuevamente.\n\n";
            accionarSegunDado(jugadorActual, jugadorAnterior, mazo, existeGanador, nombreGanadorHistorico, puntosGanadorHistorico);
        }
        else 
            accionarDado5(jugadorActual);
        break;
    case 0:
        jugadorActual.pasoTurno = true;
        "#Turno cedido\n\n";
        break;
    }
    cout << endl;
}

int robarDelMazo(Carta mazo[])
{
    int iCarta = generarIndice();

    while (mazo[iCarta].carta == "0")
    {
        iCarta = generarIndice();
    }

    return iCarta;
}

void intercambiarCartaConMazo(Jugador &jugador, int cartaElegida, Carta mazo[])
{
    int cartaDelCarta = robarDelMazo(mazo);

    swap(jugador.mano[cartaElegida].carta,mazo[cartaDelCarta].carta);
    swap(jugador.mano[cartaElegida].palo,mazo[cartaDelCarta].palo);
}

/**
 * Robar una carta del mazo.
 * Intercambiar con una carta propia.
*/
void accionarDado1(Jugador &jugadorActual, Carta mazo[])
{
    cout << "\nRobar del mazo e intercambiar con una carta del corral(1 a 5).\n";
    cout << "Seleccione una carta (1 a 5): ";
    int cartaElegida = seleccionarCarta();
   
    cout << "#Presione enter para robar del mazo...";
    getch();
    cout << endl;

    if (jugadorActual.cartaBlock[cartaElegida])
        jugadorActual.cartaBlock[cartaElegida] = false;

    intercambiarCartaConMazo(jugadorActual, cartaElegida, mazo);
}

/**
 * Robar una carta del mazo.
 * Intercambiarla con una del rival.
*/
void accionarDado2(Jugador &jugadorAnterior, Jugador &jugadorActual, Carta mazo[],bool &existeGanador, string &nombreGanadorHistorico, int &puntosGanadorHistorico)
{
    cout << "\nRobar del mazo e intercambiarla con una carta del contrario.\n";
    cout << "Seleccione la carta del rival (1 a 5): ";
    int cartaElegida = seleccionarCarta();

    while (estaBloqueada(jugadorAnterior, cartaElegida))
    {
        cout << "ACCION DENEGADA! La carta se encuentra bloqueada. Intentelo nuevamente.\n\n";
        cout << "Seleccione la carta del rival (1 a 5): ";
        cartaElegida = seleccionarCarta();
    }

    intercambiarCartaConMazo(jugadorAnterior, cartaElegida, mazo);

    if(validarOrdenMano(jugadorAnterior))
        encontrarGanador(jugadorAnterior, jugadorActual, existeGanador, nombreGanadorHistorico, puntosGanadorHistorico);

}

/**
 * Intercambio entre jugadores.
*/
void accionarDado3(Jugador &jugadorActual, Jugador &jugadorAnterior)
{
    cout << "\nElegir una carta propia e intercambiarla con una del contrario.\n";
    cout << "Seleccione una carta de su corral (1 a 5): ";
    int cartaElegida = seleccionarCarta();
    cout << "Seleccione una carta del corral contrario (1 a 5): ";
    int cartaRival = seleccionarCarta();

    while (estaBloqueada(jugadorAnterior, cartaRival))
    {
        cout << "ACCION DENEGADA! La carta se encuentra bloqueada.Intentelo nuevamente.\n";
        cout << "Seleccione una carta del corral contrario (1 a 5): ";
        cartaRival = seleccionarCarta();
    }
    intercambiarEntreJugadores(jugadorActual, jugadorAnterior, cartaElegida, cartaRival);
}

/**
 * Intercambio de cartas.
*/
void intercambiarEntreJugadores(Jugador &jugadorActual, Jugador &jugadorAnterior, int cartaElegida, int cartaRival)
{

    swap(jugadorActual.mano[cartaElegida].carta,jugadorAnterior.mano[cartaRival].carta);
    swap(jugadorActual.mano[cartaElegida].palo,jugadorAnterior.mano[cartaRival].palo);


    if (jugadorActual.cartaBlock[cartaElegida]) 
        jugadorActual.cartaBlock[cartaElegida] = false;

    if (validarOrdenMano(jugadorActual))
        jugadorActual.puntos[(int)Puntajes::GANAR_ROBANDO] = PUNTOS_VICTORIA_CON_ROBO;

    jugadorAnterior.sufrioRobo = true;
}

/**
 * Intercambio entre cartas propias.
*/
void accionarDado4(Jugador &jugadorActual)
{
    cout << "\nIntercambiar dos cartas del propio corral.\n";
    cout << "Seleccione la primer carta (1 a 5): ";
    int cartaElegida1 = seleccionarCarta();
    cout << "Seleccione la segunda carta (1 a 5): ";
    int cartaElegida2 = seleccionarCarta();

    while (cartaElegida2 == cartaElegida1)
    {
        cout << "ERROR! No puede elegir 2 veces la misma carta.Intentelo nuevamente.\n";
        cout << "Seleccione la segunda carta (1 a 5): ";
        cartaElegida2 = seleccionarCarta();
    }

    if (jugadorActual.cartaBlock[cartaElegida1] || jugadorActual.cartaBlock[cartaElegida2]) 
        swap(jugadorActual.cartaBlock[cartaElegida1], jugadorActual.cartaBlock[cartaElegida2]); 

    swap(jugadorActual.mano[cartaElegida1].carta, jugadorActual.mano[cartaElegida2].carta);
    swap(jugadorActual.mano[cartaElegida1].palo, jugadorActual.mano[cartaElegida2].palo);
}

/**
 * Bloquear una carta propia.
*/
void accionarDado5(Jugador &jugadorActual)
{
    cout << "\nBloquear una carta del propio corral. El contrario no podra accionar sobre esta carta.\n";
    cout << "Seleccione la carta que desea bloquear (1 a 5): ";
    int cartaElegida = seleccionarCarta();
    while(jugadorActual.cartaBlock[cartaElegida])
    {
        cout << "ACCION DENEGADA! La carta seleccionada ya ha sido bloqueada. Intentelo nuevamente: \n";
        cartaElegida = seleccionarCarta();
    }

    jugadorActual.cartaBlock[cartaElegida] = true;
}

int tirarDado()
{
    return rand() % 6 + 1;
}