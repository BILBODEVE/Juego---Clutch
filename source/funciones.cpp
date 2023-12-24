#include <iostream>
#include <conio.h>   // getch()
#include <algorithm> // swap()
#include "../includes/funciones.h"

using namespace std;

const int SIZE_MAZO = 20;
const int SIZE_MANO = 5;

// Funcion main
void jugarClutch(Jugador &jugador1, Jugador &jugador2, Mazo mazo[20])
{
    string nombreGanadorHistorico;
    int puntosGanadorHistorico = 0;

    menuPrincipal(jugador1, jugador2, mazo, nombreGanadorHistorico, puntosGanadorHistorico);
}

// Menu
void mostrarMenu()
{
    cout << "\n****** BIENVENIDO A CLUTCH ******\n";
    cout << "--------------------\n";
    cout << "1 - JUGAR \n";
    cout << "2 - ESTADISTICAS\n";
    cout << "3 - CREDITOS\n";
    cout << "4 - INSTRUCCIONES\n";
    cout << "--------------------\n";
    cout << "0 - SALIR\n";
}

int pedirOpcion()
{
    cout << "Ingrese una opcion: ";
    int opcion;
    cin >> opcion;

    return opcion;
}

void menuPrincipal(Jugador &jugador1, Jugador &jugador2, Mazo mazo[20], string &nombreGanadorHistorico, int &puntosGanadorHistorico)
{
    mostrarMenu();
    int opcion = pedirOpcion();

    while (opcion < 0 || opcion > 4)
    {
        cout << "\nERROR! Opcion incorrecta. Intentelo nuevamente\n\n";
        opcion = pedirOpcion();
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
    cout << "-------------------------------------------------------------\n";
    cout << " Cantidad de jugadores: 2\n";
    cout << " Cantidad de cartas: 5 por jugador\n";
    cout << " Cantidad de dados: 1\n";
    cout << " Valores posibles del dado: 1 a 6\n";
    cout << " Objetivo: ordenar las cartas de tal manera que completen la fase de crecimineto de una gallina\n\n";

    cout << "Las fases de crecimiento se representan por el tipo de carta: \n";
    cout << "\t 10: Huevo listo para ser empollado\n";
    cout << "\t J: Huevo empollado con una pequeña grieta\n";
    cout << "\t Q: Se asoma un pico por la grieta\n";
    cout << "\t K: Sale un pequeño pollito\n";
    cout << "\t A: El pollito crecio y ahora es una gallina.\n\n";

    cout << "Segun el valor del dado, se pueden realizar los siguientes movimientos:\n";
    cout << "\t #1 Robar del mazo e intercambiar con una carta del corral.\n";
    cout << "\t #2 Robar del mazo e intercambiarla con una carta del contrario.\n";
    cout << "\t #3 Elegir una carta propia e intercambiarla con una del contrario.\n";
    cout << "\t #4 Intercambiar dos cartas del propio corral.\n";
    cout << "\t #5 Bloquear una carta del propio corral. El contrario no podra accionar sobre esta carta.\n";
    cout << "\t     Si la carta esta bloqueada se muestra entre [].\n";
    cout << "\t #6 Elegir una opcion o pasar el turno.\n\n";

    cout << "El comienzo de la partida esta determinado por el jugador con mayor cantidad de ases(A). En el caso de que ningun jugador posea un as o la cantidad en ambos sea la misma, se evalua la cantidad del segundo tipo de carta, en este caso, la \'K\'. Esta regla se aplica para todos los tipos de cartas subsiguientes.\n";

    cout << "NOTA: la mano de cartas es denominada \"Corral\".\n\n";

    cout << "BUENA SUERTE!\n";
    cout << "-------------------------------------------------------------";
}

char confirmarUnaAccion()
{
    char confirmar;
    cin >> confirmar;

    return toupper(confirmar);
}

void volverAlMenu(Jugador jugador1, Jugador jugador2, Mazo mazo[20], string nombreGanadorHistorico, int puntosGanadorHistorico)
{

    cout << "\n\nDesea volver al menu principal? S(Si)/N(No): ";
    char opcion = confirmarUnaAccion();

    while (opcion != 'S' && opcion != 'N')
    {
        cout << "ERROR! La letra ingresada es incorrecta. Intentelo nuevamente: ";
        opcion = confirmarUnaAccion();
    }

    if (opcion == 'S')
        menuPrincipal(jugador1, jugador2, mazo, nombreGanadorHistorico, puntosGanadorHistorico);
    else
        cout << "Gracias por visitar CLUTCH!";
}

// Datos de la ronda
void mostrarDatosRonda(Jugador jugador1, Jugador jugador2, int &ronda, string turno)
{
    cout << "Ronda: " << ronda++ << endl;
    cout << jugador1.nombre << " vs " << jugador2.nombre << endl
         << endl;
    cout << "| Es turno de: #" << turno << " |" << endl;
    cout << endl;

    mostrarMano(jugador1, jugador2);
}

void pedirNombres(Jugador &jugador1, Jugador &jugador2)
{
    char confirmar = 'N';

    while (confirmar != 'S')
    {
        separador(50);
        cout << "#Registre los nombres de los jugadores: \n";
        cout << " Jugador 1: ";
        cin >> jugador1.nombre;
        cout << " Jugador 2: ";
        cin >> jugador2.nombre;

        cout << "#Confirma los nombres de usuario? S/N: ";
        confirmar = confirmarUnaAccion();
        separador(50);
    }
}

/**
 * Carga 4 grupos de 5 cartas (10,J,Q,K,A)
 * Carga 4 palos unicos para cada carta
 */
void cargarMazo(Mazo mazo[])
{

    for (int j = 0; j < SIZE_MAZO; j++)
    {
        mazo[j].carta = CARTA[j % SIZE_MANO];
    }

    for (int j = 0; j < SIZE_MAZO; j++)
    {
        mazo[j].palo = PALOS[j % 4];
    }
}

void mostrarMazo(Mazo mazo[])
{
    for (int i = 0; i < SIZE_MAZO; i++)
    {
        cout << mazo[i].carta << mazo[i].palo << endl;
    }

    cout << endl;
}

void mezclarMazo(Mazo mazo[])
{
    for (int i = 0; i < SIZE_MAZO; i++)
    {
        int iCarta = generarIndice();
        swap(mazo[i].carta, mazo[iCarta].carta);
        swap(mazo[i].palo, mazo[iCarta].palo);
    }
}

void repartirCartas(Jugador &jugador, Mazo mazo[])
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
        if (jugador1.accion.cartaBlock[i] == true) // Si la carta esta bloqueada se muestra la carta entre [].
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
        if (jugador2.accion.cartaBlock[i] == true)
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

// funciones para le desarrollo de la partida
void jugar(Jugador &jugador1, Jugador &jugador2, Mazo mazo[20], string &nombreGanadorHistorico, int &puntosGanadorHistorico)
{
    bool existeGanador = false;
    int ronda = 1;
    string turno;

    cargarMazo(mazo);
    mezclarMazo(mazo);
    pedirNombres(jugador1, jugador2);
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

    // Si los jugadores anteriores pasaron de turno, recibieron un robo del contrario o tiene cartas bloqueadas reseteo los estados a false para la siguiente partida(solo aplica cuando se juegan mas de una partida en la misma ejecucion).
    resetearEstados(jugador1);
    resetearEstados(jugador2);
}

void ejecutarRondas(Jugador &jugador1, Jugador &jugador2, Mazo mazo[20], string &turno, bool &existeGanador, string &nombreGanadorHistorico, int &puntosGanadorHistorico)
{
    if (turno == jugador1.nombre)
    {
        accionarSegunDado(jugador1, jugador2, mazo);
        encontrarGanador(jugador1, jugador2, existeGanador, nombreGanadorHistorico, puntosGanadorHistorico);
        turno = jugador2.nombre;
    }
    else
    {
        accionarSegunDado(jugador2, jugador1, mazo);
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

    string CARTA[SIZE_MANO] = {"A", "K", "Q", "J", "10"};

    for(int i=0;i<SIZE_MANO;i++)
    {
        int cantJugador1 = contarCartaDeUnTipo(jugador1,CARTA[i]);
        int cantJugador2 = contarCartaDeUnTipo(jugador1,CARTA[i]);

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

void accionarSegunDado(Jugador &jugadorActual, Jugador &jugadorAnterior, Mazo mazo[20])
{
    cout << "Presione enter para tirar el dado: ";
    getch();
    cout << "\n\n";

    int valor_dado = tirarDado();
    cout << "Valor del dado: " << valor_dado << endl;

    if (valor_dado == 6)
    {
        cout << "#6 Elegir una opcion de 1 a 5 o presione 0 para pasar el turno.\n\n";
        separador(50);
        cout << "Segun el valor del dado, se pueden realizar los siguientes movimientos:\n";
        cout << "\t #1 Robar del mazo e intercambiar con una carta del corral.\n";
        cout << "\t #2 Robar del mazo e intercambiarla con una carta del contrario.\n";
        cout << "\t #3 Elegir una carta propia e intercambiarla con una del contrario.\n";
        cout << "\t #4 Intercambiar dos cartas del propio corral.\n";
        cout << "\t #5 Bloquear una carta del propio corral. El contrario no podra accionar sobre esta carta.\n";
        cout << "\t     Si la carta esta bloqueada se muestra entre [].\n";
        cout << "\t #6 Elegir una opcion o pasar el turno.\n\n";
        separador(50);

        valor_dado = pedirOpcion();
        while (valor_dado < 1 || valor_dado > 5)
        {
            cout << "Valor incorrecto!Intentelo nuevamente\n";
            valor_dado = pedirOpcion();
        }
        cout << endl;
    }

    switch (valor_dado)
    {
    case 1:
        accionarDado1(jugadorActual, mazo);
        break;
    case 2:
        accionarDado2(jugadorAnterior, mazo);
        break;
    case 3:
        accionarDado3(jugadorActual, jugadorAnterior);
        break;
    case 4:
        accionarDado4(jugadorActual);
        break;
    case 5:
        if (validarCartasBlock(jugadorActual))
        {
            cout << "ACCION DENEGADA! Todas sus cartas estan bloqueadas. Tire el dado nuevamente.\n\n";
            accionarSegunDado(jugadorActual, jugadorAnterior, mazo);
        }
        else 
            bloquearUnaCarta(jugadorActual);
        break;
    case 0:
        jugadorActual.accion.pasoTurno = true;
        "#Turno cedido\n\n";
        break;
    }
    cout << endl;
}

bool encontrarGanador(Jugador &jugadorActual, Jugador &jugadorAnterior, bool &existeGanador, string &nombreGanadorHistorico, int &puntosGanadorHistorico)
{
    if (validarOrdenMano(jugadorActual))
    {
        jugadorActual.puntos[0] = 15;

        cout << "PARTIDA FINALIZADA!! EL GANADOR ES: " << jugadorActual.nombre << endl;
        mostrarMano(jugadorActual, jugadorAnterior);
        sumarPuntosPorCartaDesordenada(jugadorActual, jugadorAnterior);

        if (!jugadorActual.accion.pasoTurno)
            jugadorActual.puntos[3] = 10;
        if (!jugadorActual.accion.sufrioRobo)
            jugadorActual.puntos[4] = 5;

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
    cout << "Ganar la partida: " << jugador.puntos[0] << endl;
    cout << "Robo ultima carta al jugador rival: " << jugador.puntos[1] << endl;
    cout << "Cartas mal ubicadas del rival " << jugador.puntos[2] / 5 << ": " << jugador.puntos[2] << endl;
    cout << "Sin pasar de turno: " << jugador.puntos[3] << endl;
    cout << "Sin haber sufrido robos: " << jugador.puntos[4] << endl;
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

int robarDelMazo(Mazo mazo[])
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
void intercambiarConElMazo(Jugador &jugador, int cartaElegida, Mazo mazo[])
{
    int cartaDelMazo = robarDelMazo(mazo);

    swap(jugador.mano[cartaElegida].carta,mazo[cartaDelMazo].carta);
    swap(jugador.mano[cartaElegida].palo,mazo[cartaDelMazo].palo);
}

void accionarDado1(Jugador &jugadorActual, Mazo mazo[])
{
    cout << "Robar del mazo e intercambiar con una carta del corral(1 a 5).\n\n";
    cout << "Seleccione una carta (1 a 5): ";
    int cartaElegida = seleccionarCarta();
    cout << "#Presione enter para robar del mazo: ";
    getch();
    cout << endl;

    if (jugadorActual.accion.cartaBlock[cartaElegida])
        jugadorActual.accion.cartaBlock[cartaElegida] = false;

    intercambiarConElMazo(jugadorActual, cartaElegida, mazo);
}

void accionarDado2(Jugador &jugadorAnterior, Mazo mazo[])
{
    cout << "Robar del mazo e intercambiarla con una carta del contrario.\n\n";
    cout << "Seleccione la carta del rival (1 a 5): ";
    int cartaElegida = seleccionarCarta();

    while (estaBloqueada(jugadorAnterior, cartaElegida))
    {
        cout << "ACCION DENEGADA! La carta se encuentra bloqueada. Intentelo nuevamente.\n\n";
        cout << "Seleccione la carta del rival (1 a 5): ";
        cartaElegida = seleccionarCarta();
    }
    intercambiarConElMazo(jugadorAnterior, cartaElegida, mazo);
}

void accionarDado3(Jugador &jugadorActual, Jugador &jugadorAnterior)
{
    cout << "Elegir una carta propia e intercambiarla con una del contrario.\n\n";
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


    if (jugadorActual.accion.cartaBlock[cartaElegida]) 
        jugadorActual.accion.cartaBlock[cartaElegida] = false;

    if (validarOrdenMano(jugadorActual))
        jugadorActual.puntos[1] = 10;

    jugadorAnterior.accion.sufrioRobo = true;
}

void accionarDado4(Jugador &jugadorActual)
{
    cout << "Intercambiar dos cartas del propio corral.\n\n";
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

    if (jugadorActual.accion.cartaBlock[cartaElegida1] || jugadorActual.accion.cartaBlock[cartaElegida2]) 
        swap(jugadorActual.accion.cartaBlock[cartaElegida1], jugadorActual.accion.cartaBlock[cartaElegida2]); 

    swap(jugadorActual.mano[cartaElegida1].carta, jugadorActual.mano[cartaElegida2].carta);
    swap(jugadorActual.mano[cartaElegida1].palo, jugadorActual.mano[cartaElegida2].palo);
}

void bloquearUnaCarta(Jugador &jugadorActual)
{
    cout << "Bloquear una carta del propio corral. El contrario no podra accionar sobre esta carta.\n\n";
    cout << "Seleccione la carta que desea bloquear (1 a 5): ";
    int cartaElegida = seleccionarCarta();
    while(jugadorActual.accion.cartaBlock[cartaElegida])
    {
        cout << "ACCION DENEGADA! La carta seleccionada ya ha sido bloqueada. Intentelo nuevamente: \n";
        cartaElegida = seleccionarCarta();
    }

    jugadorActual.accion.cartaBlock[cartaElegida] = true;
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
        if (jugadorAnterior.mano[i].carta != CARTA[i])
            cont++;
    }

    return cont;
}

void sumarPuntosPorCartaDesordenada(Jugador &jugadorActual, Jugador jugadorAnterior)
{
    jugadorActual.puntos[2] = contarCartaMalUbicada(jugadorAnterior) * 5;
}

/**
 * Genera un indice para el mazo.
 */
int generarIndice()
{
    return rand() % 19;
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
        if (jugador.mano[i].carta == CARTA[i])
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
    if (jugadorActual.accion.cartaBlock[cartaElegida] == true)
    {
        return true;
    }

    return false;
}

/**
 * Validar si existe una carta disponible para bloquear.
*/
bool validarCartasBlock(Jugador jugador)
{
    int cont = 0;

    for (int i = 0; i < SIZE_MANO; i++)
    {
        if (!jugador.accion.cartaBlock[i])
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

void resetearEstados(Jugador &jugador)
{
    for(int i = 0;i<SIZE_MANO)
    {
        jugador.accion.cartaBlock[i] = false;
    }
    jugador.accion.pasoTurno = false;
    jugador.accion.sufrioRobo = false;
}

void separador(int tamaño, const char symbol)
{
    for (int i = 0; i < tamaño; i++)
    {
        cout << symbol;
    }

    cout << endl;
}