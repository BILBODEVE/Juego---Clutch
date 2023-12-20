#include <iostream>
#include <conio.h>   // getch()
#include <algorithm> // swap()
#include "headers/funciones.h"

using namespace std;

// Funcion main
void jugarClutch(Jugador &jugador1, Jugador &jugador2, Mazo mazo[20])
{
    string nombreGanadorHistorico;
    int puntosGanadorHistorico = 0;

    menuPrincipal(jugador1, jugador2, mazo, nombreGanadorHistorico, puntosGanadorHistorico);
}

// Menu
int mostrarMenu()
{
    int opcion;

    cout << "\n****** BIENVENIDO A CLUTCH ******\n";
    cout << "--------------------\n";
    cout << "1 - JUGAR \n";
    cout << "2 - ESTADISTICAS\n";
    cout << "3 - CREDITOS\n";
    cout << "4 - INSTRUCCIONES\n";
    cout << "--------------------\n";
    cout << "0 - SALIR\n";
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    cout << endl;

    return opcion;
}

void menuPrincipal(Jugador &jugador1, Jugador &jugador2, Mazo mazo[20], string &nombreGanadorHistorico, int &puntosGanadorHistorico)
{
    int opcion = mostrarMenu();

    while (opcion < 0 || opcion > 4)
    {
        cout << "ERROR! Opcion incorrecta. Intentelo nuevamente: \n";
        opcion = mostrarMenu();
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
        break;
    default:
        menuPrincipal(jugador1, jugador2, mazo, nombreGanadorHistorico, puntosGanadorHistorico);
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
    cout << "\t #5 Bloquear una carta del propio corral. El contrario no podra accionar sobre esta carta. Si la carta esta bloqueada se muestra entre [].\n";
    cout << "\t #6 Elegir una opcion o pasar el turno.\n\n";

    cout << "El comienzo de la partida esta determinado por el jugador con mayor cantidad de ases(A). En el caso de que ningun jugador posea un as o la cantidad en ambos sea la misma, se evalua la cantidad del segundo tipo de carta, en este caso, la \'K\'. Esta regla se aplica para todos los tipos de cartas subsiguientes.\n";

    cout << "NOTA: la mano de cartas es denominada \"Corral\".\n\n";

    cout << "BUENA SUERTE!\n";
    cout << "-------------------------------------------------------------";
}

void volverAlMenu(Jugador jugador1, Jugador jugador2, Mazo mazo[20], string nombreGanadorHistorico, int puntosGanadorHistorico)
{
    char opcion;
    cout << "\n\nDesea volver al menu principal? S(Si)/N(No): ";
    cin >> opcion;
    opcion = toupper(opcion);

    if (opcion != 'S' && opcion != 'N')
    {
        cout << "ERROR! La letra ingresada es incorrecta. Intentelo nuevamente: ";
        cin >> opcion;
        opcion = toupper(opcion);
    }

    if (opcion == 'S')
    {
        menuPrincipal(jugador1, jugador2, mazo, nombreGanadorHistorico, puntosGanadorHistorico);
    }
    else
    {

        cout << "Gracias por visitar CLUTCH!";
    }
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

// Funciones para el mazo y la mano
void cargarMazo(Mazo mazo[20])
{

    for (int j = 0; j < 20; j++)
    {
        mazo[j].carta = TIPO_CARTA[j % 5];
    }

    for (int j = 0; j < 20; j++)
    {
        mazo[j].palo = V_PALOS[j % 4];
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

void mezclarMazo(Mazo mazo[20])
{
    for (int i = 0; i < 20; i++)
    {
        string auxCarta;
        string auxPalo;
        int iCarta = generarIndice();

        auxCarta = mazo[i].carta;
        auxPalo = mazo[i].palo;

        mazo[i].carta = mazo[iCarta].carta;
        mazo[i].palo = mazo[iCarta].palo;

        mazo[iCarta].carta = auxCarta;
        mazo[iCarta].palo = auxPalo;
    }
}

void repartirCartas(Jugador &jugador, Mazo mazo[20]) //&jugador paso por referencia para modificar el valor original de la matriz
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
    if (validarMano(jugador) == 5) // Si la mano esta ordenada se vuelve a repartir.
    {
        repartirCartas(jugador, mazo);
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

void buscarPrimerTurno(Jugador &jugador1, Jugador &jugador2, string &turno)
{
    int indice_carta = 4;
    bool maximo = false;

    while (maximo == false)
    {
        int cont1 = 0;
        int cont2 = 0;

        for (int i = 0; i < 5; i++)
        {
            if (jugador1.mano[i].carta == TIPO_CARTA[indice_carta])
            {
                cont1++;
            }

            if (jugador2.mano[i].carta == TIPO_CARTA[indice_carta])
            {
                cont2++;
            }
        }
        indice_carta--;

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
    }
}

void accionarSegunDado(Jugador &jugadorActual, Jugador &jugadorAnterior, Mazo mazo[20])
{

    cout << "Presione enter para tirar el dado: ";
    getch();
    cout << endl
         << endl;

    int valor_dado = tirarDado();

    cout << "Valor del dado: " << valor_dado << endl;

    if (valor_dado == 6)
    {
        cout << "#6 Elegir una opcion de 1 a 5 o presione 0 para pasar el turno\n\n";
        cout << "-------------------------------------------\n";
        cout << "Segun el valor del dado, se pueden realizar los siguientes movimientos:\n";
        cout << "\t #1 Robar del mazo e intercambiar con una carta del corral.\n";
        cout << "\t #2 Robar del mazo e intercambiarla con una carta del contrario.\n";
        cout << "\t #3 Elegir una carta propia e intercambiarla con una del contrario.\n";
        cout << "\t #4 Intercambiar dos cartas del propio corral.\n";
        cout << "\t #5 Bloquear una carta del propio corral. El contrario no podra accionar sobre esta carta. Si la carta esta bloqueada se muestra entre [].\n";
        cout << "-------------------------------------------\n";
        cout << "Ingrese una opcion: ";
        cin >> valor_dado;
        cout << endl;
    }

    switch (valor_dado)
    {
    case 1:
        cout << "#1 Robar del mazo e intercambiar con una carta del corral(1 a 5).\n\n";
        accionarDado1(jugadorActual, mazo);
        break;
    case 2:
        cout << "#2 Robar del mazo e intercambiarla con una carta del contrario(1 a 5).\n\n";
        accionarDado2(jugadorAnterior, mazo);
        break;
    case 3:
        cout << "#3 Elegir una carta propia e intercambiarla con una del contrario (1 a 5).\n\n";
        accionarDado3(jugadorActual, jugadorAnterior);
        break;
    case 4:
        cout << "#4 Intercambiar dos cartas del propio corral(1 a 5).\n\n";
        accionarDado4(jugadorActual);
        break;
    case 5:
        cout << "#5 Bloquear una carta del propio corral. El contrario no podra accionar sobre esta carta.\n\n";
        if (contarCantCartasBlock(jugadorActual)) //  Si el jugador tiene todas sus cartas bloqueadas , vuelve a tirar el dado.
        {
            cout << "NO PUEDE REALIZAR ESTA ACCION! Todas sus cartas se encuentran bloqueadas. Tire el dado nuevamente.\n\n";
            accionarSegunDado(jugadorActual, jugadorAnterior, mazo);
        }
        else
        {
            accionarDado5(jugadorActual);
        }
        break;
    case 0:
        jugadorActual.accion.pasoTurno = true; // Cambio el estado para identificar si la accion sucedio posteriormente y sumar puntos.
        "#Turno cedido\n\n";
        break;
    }
    cout << endl;
}

bool encontrarGanador(Jugador &jugadorActual, Jugador &jugadorAnterior, bool &existeGanador, string &nombreGanadorHistorico, int &puntosGanadorHistorico)
{
    if (validarMano(jugadorActual) == 5)
    {
        jugadorActual.puntos[0] = 10; // Puntos por ganar la partida

        cout << "PARTIDA FINALIZADA!! EL GANADOR ES: " << jugadorActual.nombre << endl;
        mostrarMano(jugadorActual, jugadorAnterior);
        contarCartaMalUbicada(jugadorActual, jugadorAnterior);
        if (jugadorActual.accion.pasoTurno == false)
        {
            jugadorActual.puntos[3] = 10;
        }
        if (jugadorActual.accion.sufrioRobo == false)
        {
            jugadorActual.puntos[4] = 5;
        }
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

// Acciones
int seleccionarCarta()
{
    int carta;
    cin >> carta;
    while (validarSeleccionCarta(carta))
    {
        cout << "ERROR! La carta seleccionada es incorrrecta. Intentelo nuevamente: \n";
        cout << "Seleccione una carta: ";
        cin >> carta;
    }

    carta -= 1;

    return carta;
}

int robarDelMazo(Mazo mazo[20])
{
    int iCarta;

    iCarta = generarIndice();

    while (mazo[iCarta].carta == "0")
    {
        iCarta = generarIndice();
    }

    return iCarta;
}

void intercambiarCarta(Jugador &jugadorActual, int cartaElegida, Mazo mazo[20])
{
    int cartaRobada = robarDelMazo(mazo);

    // Guarda la carta seleccionada por el usuario para no perder su valor en la reasignacion posterior.
    string auxCarta = jugadorActual.mano[cartaElegida].carta;
    string auxPalo = jugadorActual.mano[cartaElegida].palo;

    // La nueva carta del usuario se genera mediante lo que tenga mazo en el indice correspondiente a cartaRobada.
    jugadorActual.mano[cartaElegida].carta = mazo[cartaRobada].carta;
    jugadorActual.mano[cartaElegida].palo = mazo[cartaRobada].palo;

    // La carta seleccionada para intercambiar reemplaza los valores de la carta robada.
    mazo[cartaRobada].carta = auxCarta;
    mazo[cartaRobada].palo = auxPalo;
}

void accionarDado1(Jugador &jugador, Mazo mazo[20])
{
    cout << "Seleccione una carta: ";
    int cartaElegida = seleccionarCarta();
    cout << "#Presione enter para robar del mazo: ";
    getch();
    cout << endl;

    if (jugador.accion.cartaBlock[cartaElegida])
    {
        jugador.accion.cartaBlock[cartaElegida] = false;
    }

    intercambiarCarta(jugador, cartaElegida, mazo);
}

void accionarDado2(Jugador &jugadorAnterior, Mazo mazo[20])
{
    cout << "Seleccione la carta del rival: ";
    int cartaElegida = seleccionarCarta();

    while (validarCartaBloqueada(jugadorAnterior, cartaElegida))
    {
        cout << "ACCION DENEGADA! La carta se encuentra bloqueada. Intentelo nuevamente: \n";
        cout << "Seleccione la carta del rival: ";
        cartaElegida = seleccionarCarta();
    }
    intercambiarCarta(jugadorAnterior, cartaElegida, mazo);
}

void accionarDado3(Jugador &jugadorActual, Jugador &jugadorAnterior)
{
    cout << "Seleccione una carta de su corral: ";
    int cartaElegida = seleccionarCarta();
    cout << "Seleccione una carta del corral contrario: ";
    int cartaRival = seleccionarCarta();

    while (validarCartaBloqueada(jugadorAnterior, cartaRival))
    {
        cout << "ACCION DENEGADA! La carta se encuentra bloqueada. Intentelo nuevamente: \n";
        cout << "Seleccione una carta del corral contrario: ";
        cartaRival = seleccionarCarta();
    }
    intercambiarEntreCorral(jugadorActual, jugadorAnterior, cartaElegida, cartaRival);
}

void intercambiarEntreCorral(Jugador &jugadorActual, Jugador &jugadorAnterior, int cartaElegida, int cartaRival)
{
    string auxCarta = jugadorActual.mano[cartaElegida].carta;
    string auxPalo = jugadorActual.mano[cartaElegida].palo;

    if (jugadorActual.accion.cartaBlock[cartaElegida]) // La carta que se intercambia pierde la propiedad de estar bloqueada.
    {
        jugadorActual.accion.cartaBlock[cartaElegida] = false;
    }

    jugadorActual.mano[cartaElegida].carta = jugadorAnterior.mano[cartaRival].carta;
    jugadorActual.mano[cartaElegida].palo = jugadorAnterior.mano[cartaRival].palo;

    jugadorAnterior.mano[cartaRival].carta = auxCarta;
    jugadorAnterior.mano[cartaRival].palo = auxPalo;

    // Si validarMano devuelve 5, encontramos el ganador. Sumamos 10 puntos por ganar intercambiando la carta rival.
    if (validarMano(jugadorActual) == 5)
    {
        jugadorActual.puntos[1] = 10;
    }

    // Cambio el estado para conocer si la accion sucedio y sumar o no puntos.
    jugadorAnterior.accion.sufrioRobo = true;
}

void accionarDado4(Jugador &jugadorActual)
{

    cout << "Seleccione la primer carta: ";
    int posCartaElegida = seleccionarCarta();
    cout << "Seleccione la segunda carta: ";
    int posicionCartaIntercambiar = seleccionarCarta();

    while (posicionCartaIntercambiar == posCartaElegida)
    {
        cout << "ERROR! No puede elegir 2 veces la misma carta. Intentelo nuevamente:\n";
        cout << "Seleccione la segunda carta: ";
        posicionCartaIntercambiar = seleccionarCarta();
    }

    if (jugadorActual.accion.cartaBlock[posCartaElegida] || jugadorActual.accion.cartaBlock[posicionCartaIntercambiar]) // Considero ambas opciones en el caso de que el usuario ingrese primero la carta que no esta bloqueada.
    {
        // Si la carta esta bloqueada, se intercambia la carta junto el estado en cartaBlock[].
        swap(jugadorActual.accion.cartaBlock[posCartaElegida], jugadorActual.accion.cartaBlock[posicionCartaIntercambiar]); // swap() intercambia los valores de 2 elementos, en este caso un array.
        swap(jugadorActual.mano[posCartaElegida].carta, jugadorActual.mano[posicionCartaIntercambiar].carta);
        swap(jugadorActual.mano[posCartaElegida].palo, jugadorActual.mano[posicionCartaIntercambiar].palo);
    }
    else
    {
        swap(jugadorActual.mano[posCartaElegida].carta, jugadorActual.mano[posicionCartaIntercambiar].carta);
        swap(jugadorActual.mano[posCartaElegida].palo, jugadorActual.mano[posicionCartaIntercambiar].palo);
    }
}

void accionarDado5(Jugador &jugadorActual)
{
    cout << "Seleccione la carta que desea bloquear: ";
    int cartaElegida = seleccionarCarta();
    if (jugadorActual.accion.cartaBlock[cartaElegida])
    {
        cout << "ACCION DENEGADA! La carta seleccionada ya ha sido bloqueada. Intentelo nuevamente: \n";
        accionarDado5(jugadorActual);
    }
    else
    {
        jugadorActual.accion.cartaBlock[cartaElegida] = true;
    }
}

// Sistema de puntuacion
int sumarTotalPuntos(Jugador jugador)
{
    int totalPuntos = 0;
    for (int i = 0; i < 5; i++)
    {
        totalPuntos += jugador.puntos[i];
    }

    return totalPuntos;
}

void contarCartaMalUbicada(Jugador &jugadorActual, Jugador &jugadorAnterior)
{
    int contPuntos = 0;

    for (int i = 0; i < 5; i++)
    {
        if (jugadorAnterior.mano[i].carta != TIPO_CARTA[i]) // TIPO_CARTA esta ordenado de forma correcta.
        {
            contPuntos += 5;
        }
    }
    jugadorActual.puntos[2] = contPuntos;
}

// Generadores de numeros aleatorios (dado, indices).
int generarIndice()
{

    int indice = rand() % 19; // Genera un indice para un array, por eso los valores van de 0 a 19 inclusive.

    return indice;
}

int tirarDado()
{
    int dado = rand() % 6 + 1;
    return dado;
}

// Validaciones
int validarMano(Jugador jugador)
{
    int cont = 0;
    for (int i = 0; i < 5; i++)
    {
        if (jugador.mano[i].carta == TIPO_CARTA[i]) // si el orden de las cartas en la mano es igual al orden en TIPO_CARTA la mano esta ordenado.
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

bool validarCartaBloqueada(Jugador jugadorActual, int cartaElegida)
{
    if (jugadorActual.accion.cartaBlock[cartaElegida] == true)
    {
        return true;
    }

    return false;
}

bool contarCantCartasBlock(Jugador jugador)
{
    int cont = 0;

    for (int i = 0; i < 5; i++)
    {
        if (jugador.accion.cartaBlock[i] == true)
        {
            cont++;
        }
    }

    if (cont == 5)
    {
        return true;
    }

    return false;
}

bool validarSeleccionCarta(int cartaElegida)
{
    if (cartaElegida < 1 || cartaElegida > 5)
    {
        return true;
    }

    return false;
}

// Resetear estados
void resetearEstados(Jugador &jugador)
{
    for (int i = 0; i < 5; i++)
    {
        if (jugador.accion.cartaBlock[i])
        {
            jugador.accion.cartaBlock[i] = false;
        }
    }

    jugador.accion.pasoTurno = false;
    jugador.accion.sufrioRobo = false;
}