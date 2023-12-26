#include <iostream>
#include <conio.h>   
#include <algorithm> 
#include <string>
#include "../includes/funciones.h"

using namespace std;

const int SIZE_MAZO = 20;
const int SIZE_MANO = 5;
const int PUNTOS_VICTORIA = 15;
const int PUNTOS_VICTORIA_CON_ROBO = 10;
const int PUNTOS_CARTA_DESORDENADA = 5;
const int PUNTOS_SUFRIR_ROBO = 5;
const int PUNTOS_PASAR_TURNO = 10;


void jugarClutch(Jugador &jugador1, Jugador &jugador2, Carta mazo[])
{
    string nombreGanadorHistorico;
    int puntosGanadorHistorico = 0;

    menuPrincipal(jugador1, jugador2, mazo, nombreGanadorHistorico, puntosGanadorHistorico);
}

void mostrarMenu()
{
    cout << "\n****** BIENVENIDO A CLUTCH ******\n";
    separador(30);
    cout << "1 - JUGAR \n";
    cout << "2 - ESTADISTICAS\n";
    cout << "3 - CREDITOS\n";
    cout << "4 - INSTRUCCIONES\n";
    separador(30);
    cout << "0 - SALIR\n";
}

int solicitarNumero()
{
    cout << "Ingrese una opcion: ";
    int opcion;
    cin >> opcion;

    return opcion;
}

void menuPrincipal(Jugador &jugador1, Jugador &jugador2, Carta mazo[], string &nombreGanadorHistorico, int &puntosGanadorHistorico)
{
    mostrarMenu();
    int opcion = solicitarNumero();

    while (opcion < 0 || opcion > 4)
    {
        cout << "\nERROR! Opcion incorrecta. Intentelo nuevamente\n\n";
        opcion = solicitarNumero();
    }

    switch (opcion)
    {
    case 1:
        jugar(jugador1, jugador2, mazo, nombreGanadorHistorico, puntosGanadorHistorico);
        break;
    case 2:
        mostrarEstadisticas(nombreGanadorHistorico, puntosGanadorHistorico);
        break;
    case 3:
        mostrarCreditos();
        break;
    case 4:
        mostrarInstrucciones();
        break;
    case 0:
        cout << "Gracias por visitar CLUTCH!";
        return;
        break;
    }
    volverAlMenu(jugador1, jugador2, mazo, nombreGanadorHistorico, puntosGanadorHistorico);
}

void mostrarEstadisticas(string nombreGanadorHistorico, int puntosGanadorHistorico)
{
    cout << "******** GANADOR HISTORICO: " << nombreGanadorHistorico << " ********\n";
    cout << "TOTAL PUNTOS: " << puntosGanadorHistorico;
}

void mostrarCreditos()
{
    cout << "Desarrollo del proyecto a cargo de: \n";
    cout << "   # Nombre: Facundo Tomas\n";
    cout << "   # Apellido: Araujo Avalos\n";
    cout << "   # Legajo: 29681\n";
    cout << "   # Nombre del equipo: no hay equipo je";
}

void mostrarInstrucciones()
{
    separador(60);
    cout << " Cantidad de jugadores: 2\n";
    cout << " Cantidad de cartas: 5 por jugador\n";
    cout << " Cantidad de dados: 1\n";
    cout << " Valores posibles del dado: 1 a 6\n";
    cout << " Objetivo: ordenar las cartas de tal manera que completen la fase de crecimineto de una gallina\n\n";

    separador(40);
    cout << "Las fases de crecimiento se representan por el tipo de carta: \n";
    cout << "\t 10: Huevo listo para ser empollado\n";
    cout << "\t J: Huevo empollado con una pequeña grieta\n";
    cout << "\t Q: Se asoma un pico por la grieta\n";
    cout << "\t K: Sale un pequeño pollito\n";
    cout << "\t A: El pollito crecio y ahora es una gallina.\n\n";
    separador(40);
    cout << "Segun el valor del dado, se pueden realizar los siguientes movimientos:\n";
    cout << "\t #1 Robar del mazo e intercambiar con una carta del corral.\n";
    cout << "\t #2 Robar del mazo e intercambiarla con una carta del contrario.\n";
    cout << "\t #3 Elegir una carta propia e intercambiarla con una del contrario.\n";
    cout << "\t #4 Intercambiar dos cartas del propio corral.\n";
    cout << "\t #5 Bloquear una carta del propio corral. El contrario no podra accionar sobre esta carta.\n";
    cout << "\t     Si la carta esta bloqueada se muestra entre [].\n";
    cout << "\t #6 Elegir una opcion o pasar el turno.\n\n";
    separador(40);
    cout << "El comienzo de la partida esta determinado por el jugador con mayor cantidad de ases(A).\nEn el caso de que ningun jugador posea un AS o la cantidad en ambos sea la misma, se evalua la cantidad del segundo tipo de carta, en este caso, la \'K\'.\nEsta regla se aplica para todos los tipos de cartas subsiguientes.\n\n";

    cout << "NOTA: la mano de cartas es denominada \"Corral\".\n\n";

    cout << "BUENA SUERTE!\n";
    
}

char pedirOpcion()
{
    char opcion;

    do
    {
        cout << "\nDesea volver al menu principal? S(Si)/N(No): ";
        cin >> opcion;
        opcion = toupper(opcion);
    } while (validarOpcion(opcion));
    

    return opcion;
}

void volverAlMenu(Jugador jugador1, Jugador jugador2, Carta mazo[], string nombreGanadorHistorico, int puntosGanadorHistorico)
{

    char opcion = pedirOpcion();

    if (opcion == 'S')
        menuPrincipal(jugador1, jugador2, mazo, nombreGanadorHistorico, puntosGanadorHistorico);
    else
        cout << "Gracias por visitar CLUTCH!";
}

void mostrarDatosRonda(Jugador jugador1, Jugador jugador2, int &ronda, string turno)
{
    cout << "Ronda: " << ronda++ << endl;
    cout << jugador1.nombre << " vs " << jugador2.nombre << endl
         << endl;
    cout << "| Es turno de: #" << turno << " |" << endl;
    cout << endl;

    mostrarMano(jugador1, jugador2);
}

void registrarNombres(Jugador &jugador1, Jugador &jugador2)
{
    char confirmar = 'N';

    cin.ignore();

    while (confirmar != 'S')
    {
        separador(50);
        cout << "#Registre los nombres de los jugadores: \n";

        solicitarUnNombre(jugador1, 1);
        while(validarCantidadChar(jugador1.nombre))
        {
            cout << "ERROR! El nombre no debe superar los 20 caracteres. Intentelo nuevamente.\n";
            solicitarUnNombre(jugador1,1);
        }

        solicitarUnNombre(jugador2, 2);
        while(validarCantidadChar(jugador2.nombre))
        {
            cout << "ERROR! El nombre no debe superar los 20 caracteres. Intentelo nuevamente.\n";
            solicitarUnNombre(jugador2,2);
        }

        cout << "#Confirma los nombres de usuario? S/N: ";
        confirmar = pedirOpcion();
        separador(50);
    }
}

/**
 * Carga 4 grupos de 5 cartas (10,J,Q,K,A)
 * Carga 4 palos unicos para cada carta
 */
void cargarMazo(Carta mazo[])
{

    for (int j = 0; j < SIZE_MAZO; j++)
    {
        mazo[j].carta = CARTAS[j % SIZE_MANO];
    }

    for (int j = 0; j < SIZE_MAZO; j++)
    {
        mazo[j].palo = PALOS[j % 4];
    }
}

void mostrarCarta(Carta mazo[])
{
    for (int i = 0; i < SIZE_MAZO; i++)
    {
        cout << mazo[i].carta << mazo[i].palo << endl;
    }

    cout << endl;
}

void mezclarMazo(Carta mazo[])
{
    for (int i = 0; i < SIZE_MAZO; i++)
    {
        int iCarta = generarIndice();
        swap(mazo[i].carta, mazo[iCarta].carta);
        swap(mazo[i].palo, mazo[iCarta].palo);
    }
}

void repartirCartas(Jugador &jugador, Carta mazo[])
{
    for (int i = 0; i < SIZE_MANO; i++)
    {
        int iCarta = generarIndice();

        while (mazo[iCarta].carta == "0")
        {
            iCarta = generarIndice();
        }
        swap(jugador.mano[i].carta, mazo[iCarta].carta);
        swap(jugador.mano[i].palo, mazo[iCarta].palo);

        mazo[iCarta].carta = "0";
        mazo[iCarta].palo = "0";

        if (validarOrdenMano(jugador))
        {
            repartirCartas(jugador, mazo);
        }
    }
}

void mostrarMano(Jugador jugador1, Jugador jugador2)
{

    cout << "-------------------------- \n";
    cout << "| " << jugador1.nombre << endl;
    for (int i = 0; i < 5; i++)
    {
        if (jugador1.cartaBlock[i] == true) // Si la carta esta bloqueada se muestra la carta entre [].
        {
            cout << "| [" << jugador1.mano[i].carta << jugador1.mano[i].palo << ']'
                 << " ";
        }
        else
        {
            cout << "| " << jugador1.mano[i].carta << jugador1.mano[i].palo << " ";
        }
    }

    cout << "\n| \n";

    cout << "| " << jugador2.nombre << endl;
    for (int i = 0; i < 5; i++)
    {
        if (jugador2.cartaBlock[i] == true)
        {
            cout << "| [" << jugador2.mano[i].carta << jugador2.mano[i].palo << ']'
                 << " ";
        }
        else
        {
            cout << "| " << jugador2.mano[i].carta << jugador2.mano[i].palo << " ";
        }
    }
    cout << "\n--------------------------\n";
}

void jugar(Jugador &jugador1, Jugador &jugador2, Carta mazo[20], string &nombreGanadorHistorico, int &puntosGanadorHistorico)
{
    bool existeGanador = false;
    int ronda = 1;
    string turno;

    cargarMazo(mazo);
    mezclarMazo(mazo);
    registrarNombres(jugador1, jugador2);
    repartirCartas(jugador1, mazo);
    repartirCartas(jugador2, mazo);
    buscarPrimerTurno(jugador1, jugador2, turno);
    mostrarDatosRonda(jugador1, jugador2, ronda, turno);
    ejecutarRondas(jugador1, jugador2, mazo, turno, existeGanador, nombreGanadorHistorico, puntosGanadorHistorico);

    while (existeGanador == false)
    {
        mostrarDatosRonda(jugador1, jugador2, ronda, turno);
        ejecutarRondas(jugador1, jugador2, mazo, turno, existeGanador, nombreGanadorHistorico, puntosGanadorHistorico);
        mezclarMazo(mazo);
    }
    resetearEstados(jugador1);
    resetearEstados(jugador2);
}

void ejecutarRondas(Jugador &jugador1, Jugador &jugador2, Carta mazo[20], string &turno, bool &existeGanador, string &nombreGanadorHistorico, int &puntosGanadorHistorico)
{
    if (turno == jugador1.nombre)
    {
        accionarSegunDado(jugador1, jugador2, mazo, existeGanador, nombreGanadorHistorico, puntosGanadorHistorico);
        encontrarGanador(jugador1, jugador2, existeGanador, nombreGanadorHistorico, puntosGanadorHistorico);
        turno = jugador2.nombre;
    }
    else
    {
        accionarSegunDado(jugador2, jugador1, mazo, existeGanador, nombreGanadorHistorico, puntosGanadorHistorico);
        encontrarGanador(jugador2, jugador1, existeGanador, nombreGanadorHistorico, puntosGanadorHistorico);
        turno = jugador1.nombre;
    }
}

int contarCartaDeUnTipo(Jugador jugador, string carta)
{
    int cont = 0;

    for (int i = 0; i < SIZE_MANO; i++)
    {
            if (jugador.mano[i].carta == carta)
                cont++;
    }

    return cont;
}

/**
 * Busca el jugador que comienza la partida
 * Si no encuentra uno, genera un valor de 1 a 2
 * 1 = jugador1.nombre
 * 2 = jugador2.nombre
 */
string buscarPrimerTurno(Jugador &jugador1, Jugador &jugador2, string &turno)
{

    string CARTAS[SIZE_MANO] = {"A", "K", "Q", "J", "10"};

    for(int i=0;i<SIZE_MANO;i++)
    {
        int cantJugador1 = contarCartaDeUnTipo(jugador1,CARTAS[i]);
        int cantJugador2 = contarCartaDeUnTipo(jugador2,CARTAS[i]);

        if (cantJugador1 > cantJugador2)
        {
            turno = jugador1.nombre;
            return turno;
        }
        else if (cantJugador2 > cantJugador1)
        {
            turno = jugador2.nombre;
            return turno;
        }
    }

    int turnoAleatorio = rand() % 2;

    if (turnoAleatorio % 2 == 0)
        turno = jugador2.nombre;
    else
        turno = jugador1.nombre;
    
    return turno;
}

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

        valor_dado = solicitarNumero();
        while (valor_dado < 1 || valor_dado > 5)
        {
            cout << "Valor incorrecto!Intentelo nuevamente\n";
            valor_dado = solicitarNumero();
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

bool encontrarGanador(Jugador &jugadorActual, Jugador &jugadorAnterior, bool &existeGanador, string &nombreGanadorHistorico, int &puntosGanadorHistorico)
{
    if (validarOrdenMano(jugadorActual))
    {
        jugadorActual.puntos[(int)Puntajes::GANAR] = PUNTOS_VICTORIA;

        cout << "\nPARTIDA FINALIZADA!! EL GANADOR ES: " << jugadorActual.nombre << endl;
        mostrarMano(jugadorActual, jugadorAnterior);
        sumarPuntosPorCartaDesordenada(jugadorActual, jugadorAnterior);

        if (!jugadorActual.pasoTurno)
            jugadorActual.puntos[(int)Puntajes::POR_PASAR_TURNO] = PUNTOS_PASAR_TURNO;
        if (!jugadorActual.sufrioRobo)
            jugadorActual.puntos[(int)Puntajes::POR_SUFRIR_ROBO] = PUNTOS_SUFRIR_ROBO;

        mostrarGanador(jugadorActual);
        calcularGanadorHistorico(jugadorActual, nombreGanadorHistorico, puntosGanadorHistorico);

        existeGanador = true;
    }

    return existeGanador;
}

void mostrarGanador(Jugador jugador)
{
    cout << "PUNTAJE: \n";
    cout << "-------------------------------------------\n";
    cout << "Ganar la partida: " << jugador.puntos[(int)Puntajes::GANAR] << endl;
    cout << "Robo ultima carta al jugador rival: " << jugador.puntos[(int)Puntajes::GANAR_ROBANDO] << endl;
    cout << "Cartas mal ubicadas del rival " << jugador.puntos[(int)Puntajes::CARTA_MAL_UBICADA] / 5 << ": " << jugador.puntos[(int)Puntajes::CARTA_MAL_UBICADA] << endl;
    cout << "Sin pasar de turno: " << jugador.puntos[(int)Puntajes::POR_PASAR_TURNO] << endl;
    cout << "Sin haber sufrido robos: " << jugador.puntos[(int)Puntajes::POR_SUFRIR_ROBO] << endl;
    cout << "-------------------------------------------\n";
    cout << "TOTAL: " << sumarTotalPuntos(jugador);
    
}

void calcularGanadorHistorico(Jugador jugador, string &nombreGanadorHistorico, int &puntosGanadorHistorico)
{
    int totalPuntos = sumarTotalPuntos(jugador);

    if (totalPuntos > puntosGanadorHistorico)
    {
        puntosGanadorHistorico = totalPuntos;
        nombreGanadorHistorico = jugador.nombre;
    }
}

int seleccionarCarta()
{
    int carta;
    cin >> carta;
    while (validarSeleccionCarta(carta))
    {
        cout << "ERROR! La carta seleccionada es incorrrecta. Intentelo nuevamente.\n";
        cout << "Seleccione una carta (1 a 5): ";
        cin >> carta;
    }
    carta -= 1;

    return carta;
}

int robarDelCarta(Carta mazo[])
{
    int iCarta = generarIndice();

    while (mazo[iCarta].carta == "0")
    {
        iCarta = generarIndice();
    }

    return iCarta;
}

/**
 * 
*/
void intercambiarCartaConMazo(Jugador &jugador, int cartaElegida, Carta mazo[])
{
    int cartaDelCarta = robarDelCarta(mazo);

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

int sumarTotalPuntos(Jugador jugador)
{
    int totalPuntos = 0;
    for (int i = 0; i < 5; i++)
    {
        totalPuntos += jugador.puntos[i];
    }
    return totalPuntos;
}

int contarCartaMalUbicada(Jugador jugadorAnterior)
{
    int cont = 0;

    for (int i = 0; i < SIZE_MANO; i++)
    {
        if (jugadorAnterior.mano[i].carta != CARTAS[i])
            cont++;
    }

    return cont;
}

void sumarPuntosPorCartaDesordenada(Jugador &jugadorActual, Jugador jugadorAnterior)
{
    jugadorActual.puntos[(int)Puntajes::CARTA_MAL_UBICADA] = contarCartaMalUbicada(jugadorAnterior) * PUNTOS_CARTA_DESORDENADA;
}

/**
 * Genera un indice para el mazo.
 * Iterar me asegura obtener un indice random.
 */
int generarIndice()
{
    int indice;

    for(int i=0;i<SIZE_MAZO;i++)
    {
        indice = rand() % 19;
    }
    
    return indice;
}

int tirarDado()
{
    int dado = rand() % 6 + 1;
    return dado;
}

/**
 * Cuenta la cantidad de cartas ordenadas.
 */
int contarCartasOrdenadas(Jugador jugador)
{
    int cont = 0;
    for (int i = 0; i < SIZE_MANO; i++)
    {
        if (jugador.mano[i].carta == CARTAS[i])
            cont++;
        else
            cont = 0;
    }
    return cont;
}

/**
 * Valida la cantidad de cartas ordenadas.
 */
bool validarOrdenMano(Jugador jugador)
{
    if (contarCartasOrdenadas(jugador) == 5)
        return true;

    return false;
}

bool estaBloqueada(Jugador jugadorActual, int cartaElegida)
{
    if (jugadorActual.cartaBlock[cartaElegida] == true)
    {
        return true;
    }

    return false;
}

/**
 * Validar si existe al menos una carta desbloqueada.
*/
bool validarCartasBlock(Jugador jugador)
{
    int cont = 0;

    for (int i = 0; i < SIZE_MANO; i++)
    {
        if (!jugador.cartaBlock[i])
            return false;
    }
    return true;
}

/**
 * Valor entre 1 y 5.
*/
bool validarSeleccionCarta(int cartaElegida)
{
    if (cartaElegida < 1 || cartaElegida > 5)
    {
        return true;
    }

    return false;
}

/**
 * El nombre no debe superar los 20 char.
*/
bool validarCantidadChar(string nombre)
{
    return nombre.size() > 20;
}

bool validarOpcion(char opcion)
{
    if(opcion != 'S' && opcion != 'N')
        return true;

    return false;
}

void solicitarUnNombre(Jugador &jugador, int nro_jugador)
{
    cout << "Nombre jugador" << nro_jugador << ": ";
    getline(cin,jugador.nombre);
}

void resetearEstados(Jugador &jugador)
{
    for(int i = 0;i<SIZE_MANO;i++)
    {
        jugador.cartaBlock[i] = false;
    }
    jugador.pasoTurno = false;
    jugador.sufrioRobo = false;
}

void separador(int tamaño, const char symbol)
{
    for (int i = 0; i < tamaño; i++)
    {
        cout << symbol;
    }

    cout << endl;
}