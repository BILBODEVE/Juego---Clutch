#include <iostream>
#include <conio.h>
#include "funciones.h"

using namespace std;

Mazo mazo[20];
Jugador jugador1;
Jugador jugador2;
GanadorHistorico ganador;
int iCarta;
int ronda = 1;
bool estado = false;
string turno;
string warning = "\u26A0";

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

void menuPrincipal()
{
    int opcion = mostrarMenu();

    while (opcion < 0 || opcion > 4)
    {
        cout << warning << " Opcion incorrecta. Intentelo nuevamente: \n\n";
        opcion = mostrarMenu();
    }

    switch (opcion)
    {
    case 1:
        jugar(mazo);
        volverAlMenu();
        break;
    case 2:
        mostrarEstadisticas();
        volverAlMenu();
        break;
    case 3:
        mostrarCreditos();
        volverAlMenu();
        break;
    case 4:
        mostrarInstrucciones();
        volverAlMenu();
        break;
    case 0:
        cout << "Gracias por visitar CLUTCH!";
        break;
    default:
        menuPrincipal();
        break;
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
        mazo[j].carta = TIPO_CARTA[j % 5];
    }

    for (int j = 0; j < 20; j++)
    {
        mazo[j].palo = V_PALOS[j % 4];
    }
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

void repartirCartas(Jugador &jugador) //&jugador paso por referencia para modificar el valor original de la matriz
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
        if (jugador.mano[i].carta == TIPO_CARTA[i]) // si el orden de las cartas en la mano es igual a TIPO_CARTA quiere decir que el corral esta ordenado.
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
        if (jugador1.accion.cartaBlock[i] == true) // Si la carta esta bloqueada se muestra una x al lado de la carta.
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

void determinarJugadorActual()
{
    if (turno == jugador1.nombre)
    {
        accionarSegunDado(jugador1);
        encontrarGanador(jugador1);
        turno = jugador2.nombre; // El valor de turno se modifica una vez que se ejecute la accion del jugador actual y se valide si el corral esta ordenado.
    }
    else
    {
        accionarSegunDado(jugador2);
        encontrarGanador(jugador2);
        turno = jugador1.nombre;
    }
}

int tirarDado()
{
    int dado = rand() % 6 + 1;
    return dado;
}

void accionarSegunDado(Jugador &jugador)
{
    cout << "Presione enter para tirar el dado: ";
    getch();
    cout << endl
         << endl;

    int valor_dado = tirarDado();

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
        cout << "#2 Robar del mazo e intercambiarla con una carta del contrario(1 a 5).\n\n";
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
        if (validarCantCartasBlock(jugador)) //  Si el jugador tiene todas sus cartas bloqueadas , vuelve a tirar el dado.
        {
            cout << warning << "Todas sus cartas se encuentran bloqueadas. Tire el dado nuevamente.\n";
            accionarSegunDado(jugador);
        }
        else
        {
            bloquearCarta(jugador);
        }
        break;
    case 0:
        // cambio el estado para identificar si la accion sucedio posteriormente y sumar o no puntos.
        jugador.accion.pasoTurno = true;
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
    while (validarSeleccionCarta(carta))
    {
        cout << warning << warning << "La carta seleccionada es incorrrecta" << warning << warning << " Intentelo nuevamente: \n";
        cout << "Seleccione una carta: ";
        cin >> carta;
    }

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
    cout << "Seleccione una carta: ";
    int cartaElegida = seleccionarCarta();
    cout << "#Presione enter para robar del mazo: ";
    getch();
    cout << endl;

    if (jugador.accion.cartaBlock[cartaElegida])
    {
        jugador.accion.cartaBlock[cartaElegida] = false;
    }

    intercambiarCarta(jugador, cartaElegida);
}

void intercambiarCartaRival()
{
    cout << "Seleccione la carta del rival: ";
    int cartaElegida = seleccionarCarta();

    if (turno == jugador1.nombre)
    {
        while (validarCartaBloqueada(jugador2, cartaElegida))
        {
            cout << warning << warning << " La carta se encuentra bloqueada " << warning << warning << " Intentelo nuevamente: \n";
            cout << "Seleccione la carta del rival: ";
            cartaElegida = seleccionarCarta();
        }
        intercambiarCarta(jugador2, cartaElegida);
    }
    else
    {
        while (validarCartaBloqueada(jugador1, cartaElegida))
        {
            cout << warning << warning << " La carta se encuentra bloqueada" << warning << warning << " Intentelo nuevamente: \n";
            cout << "Seleccione la carta del rival: ";
            cartaElegida = seleccionarCarta();
        }
        intercambiarCarta(jugador1, cartaElegida);
    }
}

void intercambioEntreJugadores()
{
    cout << "Seleccione una carta de su corral: ";
    int cartaElegida = seleccionarCarta();
    cout << "Seleccione una carta del corral contrario: ";
    int cartaRival = seleccionarCarta();

    if (turno == jugador1.nombre)
    {
        while (validarCartaBloqueada(jugador2, cartaRival))
        {
            cout << warning << warning << " La carta se encuentra bloqueada " << warning << warning << " Intentelo nuevamente: \n";
            cout << "Seleccione una carta del corral contrario: ";
            cartaRival = seleccionarCarta();
        }
        intercambiarEntreCorral(jugador1, jugador2, cartaElegida, cartaRival);
    }
    else
    {
        while (validarCartaBloqueada(jugador1, cartaRival))
        {
            cout << warning << warning << " La carta se encuentra bloqueada " << warning << warning << " Intentelo nuevamente: \n";
            cout << "Seleccione una carta del corral contrario: ";
            cartaRival = seleccionarCarta();
        }
        intercambiarEntreCorral(jugador2, jugador1, cartaElegida, cartaRival);
    }
}

void intercambiarEntreCorral(Jugador &jugadorActual, Jugador &jugador, int cartaElegida, int cartaRival)
{
    string auxCarta = jugadorActual.mano[cartaElegida].carta;
    string auxPalo = jugadorActual.mano[cartaElegida].palo;

    if (jugadorActual.accion.cartaBlock[cartaElegida]) // La carta que se intercambia pierde la propiedad de estar bloqueada.
    {
        jugadorActual.accion.cartaBlock[cartaElegida] = false;
    }

    jugadorActual.mano[cartaElegida].carta = jugador.mano[cartaRival].carta;
    jugadorActual.mano[cartaElegida].palo = jugador.mano[cartaRival].palo;

    jugador.mano[cartaRival].carta = auxCarta;
    jugador.mano[cartaRival].palo = auxPalo;

    // Si al intercambiar la carta buscarGanador() devuelve true, el jugadorActual = ganador , entonces se suman 10 puntos
    if (encontrarGanador(jugadorActual))
    {
        jugadorActual.puntos[1] = 10;
    }

    // Cambio el estado para conocer si la accion sucedio y sumar o no puntos.
    jugador.accion.sufrioRobo = true;
}

void intercambiarCorralPropio(Jugador &jugador)
{
    cout << "Seleccione la primer carta: ";
    int cartaElegida = seleccionarCarta();
    cout << "Seleccione la segunda carta: ";
    int cartaIntercambiar = seleccionarCarta();

    while (cartaIntercambiar == cartaElegida)
    {
        cout << warning << " No puede elegir 2 veces la misma carta " << warning << " Intentelo nuevamente:\n";
        cout << "Seleccione la segunda carta: ";
        cartaIntercambiar = seleccionarCarta();
    }

    // Validacion en caso de que esta carta se bloquee en la accion5.
    if (jugador.accion.cartaBlock[cartaElegida])
    {
        jugador.accion.cartaBlock[cartaIntercambiar] = true;
        jugador.accion.cartaBlock[cartaElegida] = false;
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
    if (jugador.accion.cartaBlock[cartaElegida])
    {
        cout << warning << warning << " La carta seleccionada ya ha sido bloqueada. " << warning << warning << " Intentelo nuevamente: \n";
        bloquearCarta(jugador);
    }
    else
    {
        jugador.accion.cartaBlock[cartaElegida] = true;
    }
}

bool validarCartaBloqueada(Jugador jugador, int cartaElegida)
{
    if (jugador.accion.cartaBlock[cartaElegida] == true)
    {
        return true;
    }

    return false;
}

bool encontrarGanador(Jugador jugador)
{
    if (validarMano(jugador) == 5)
    {
        estado = true;
        jugador.puntos[0] = 10; // Puntos por ganar
        mostrarMano();
        cartaMalUbicada(jugador);
        if (jugador.accion.pasoTurno == false)
        {
            jugador.puntos[3] = 10;
        }
        if (jugador.accion.sufrioRobo == false)
        {
            jugador.puntos[4] = 5;
        }
        mostrarGanador(jugador);
        calcularGanadorHistorico(jugador);
    }

    return estado; // innecesario porque estado es global?
}

void cartaMalUbicada(Jugador jugador)
{
    if (jugador.nombre == jugador1.nombre)
    {
        jugador1.puntos[2] = contarCartaMalUbicada(jugador2);
    }
    else
    {
        jugador2.puntos[2] = contarCartaMalUbicada(jugador1);
    }
}

int contarCartaMalUbicada(Jugador jugador)
{
    int contPuntos = 0;
    for (int i = 0; i < 5; i++)
    {
        if (jugador.mano[i].carta != TIPO_CARTA[i])
        {
            contPuntos += 5;
        }
    }

    return contPuntos;
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

void mostrarGanador(Jugador jugador)
{
    cout << "******** GANADOR: " << jugador.nombre << " ********\n";
    cout << "-------------------------------------------\n";
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

void mostrarEstadisticas()
{
    cout << "******** GANADOR HISTORICO: " << ganador.nombre << " ********\n";
    cout << "-------------------------------------------\n";
    cout << "PUNTAJE: \n";
    cout << "-------------------------------------------\n";
    cout << "Ganar la partida: " << ganador.puntos[0] << endl;
    cout << "Robo ultima carta al jugador rival: " << ganador.puntos[1] << endl;
    cout << "Cartas mal ubicadas del rival: " << ganador.puntos[2] << endl;
    cout << "Sin pasar de turno: " << ganador.puntos[3] << endl;
    cout << "Sin haber sufrido robos: " << ganador.puntos[4] << endl;
    cout << "-------------------------------------------\n";
    cout << "TOTAL: " << ganador.puntajeTotal;
}

void calcularGanadorHistorico(Jugador jugador)
{
    if (sumarTotalPuntos(jugador) > ganador.puntajeTotal)
    {
        ganador.nombre = jugador.nombre;
        ganador.puntajeTotal = sumarTotalPuntos(jugador);

        for (int i = 0; i < 5; i++) // Al ser struct de distinto tipos no puedo asignar jugador.puntos a ganador.puntos.
        {
            ganador.puntos[i] = jugador.puntos[i];
        }
    }
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

    cout << "NOTA: la mano de cartas es denominada \"Corral\".\n\n";

    cout << "BUENA SUERTE!\n";
    cout << "-------------------------------------------------------------";
}

int generarIndice()
{

    int indice = rand() % 19;

    return indice;
}

bool validarCantCartasBlock(Jugador jugador)
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

void mostrarMazo(Mazo mazo[20])
{
    for (int i = 0; i < 20; i++)
    {
        cout << mazo[i].carta << mazo[i].palo << endl;
    }

    cout << endl;
}

void volverAlMenu()
{
    char opcion;
    cout << "\n\nDesea volver al menu principal? S(Si)/N(No): ";
    cin >> opcion;
    opcion = toupper(opcion);

    if (opcion != 'S' && opcion != 'N')
    {
        cout << warning << " La letra ingresada es incorrecta. Intentelo nuevamente: ";
        cin >> opcion;
        opcion = toupper(opcion);
    }

    if (opcion == 'S')
    {
        menuPrincipal();
    }
    else
    {

        cout << "Gracias por visitar CLUTCH!";
    }
}
