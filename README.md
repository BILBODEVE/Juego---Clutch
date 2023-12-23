
# Experiencia personal

Clutch es el proyecto final propuesto para la cátedra de Laboratorio 1 dentro de la UTN FRGP.

Fueron varias semanas de aprendizaje en donde pude consolidar lo aprendido durante el primer cuatrimestre 💪.

### Aprendizaje

Para el desarrollo del proyecto utilicé nuevas herramientas como la librería <conio.h> para el uso de getch(), algorithm para la función swap(), y cstdlib en complemento con time para generar números aleatorios.

Utilicé el tipo de dato struct para crear plantillas con las características comunes que puede tener un juego de cartas (mazo, jugadores, acciones, etc.). A su vez, trabajé con funciones que me permitieron resolver las diferentes problemáticas del juego. Al pasar las rondas, las características del jugador (mano, acciones, etc.) se modifican, por lo cual, utilicé mucho el pasaje de estructuras, arrays y variables por referencia para poder trabajar con los valores originales y no con una copia.

Aprendí la importancia de trabajar con variables, funciones y estructuras de ámbito local para tener un mejor control del flujo del programa y evitar errores que, a la larga, son difíciles de identificar.

Trabajé con archivos de cabecera (header files) que ponen a disposición de cualquier archivo las variables, estructuras y funciones declaradas. También me permiten ordenar el código para facilitar su lectura.

Durante el desarrollo aprendí a utilizar git y github para registrar el avance del proyecto y tener un backup de respaldo.

## Juego Clutch

Clutch es un juego de cartas apto para 2 jugadores. El objetivo es completar la fase de crecimiento de una gallina mediante el orden de las cartas. El juego se desarrolla por un conjunto de acciones determinadas por el valor de un dado de 6 caras. Cada jugador dispone de una mano, denominada corral, con 5 cartas de la baraja francesa (10, J, Q, K, A) y sus respectivos palos (Corazón, Diamante, Pica, Flor).

### Fase de crecimiento

La fase de crecimiento está determinada por las cartas y es la siguiente:

- 10: Un huevo listo para ser empollado.

- J: El huevo fue empollado y se visualiza una pequeña grieta.

- Q: El huevo fue empollado aún más y de la grieta se asoma un pequeño pico.

- K: Salió un pequeño pollito del huevo.

- A: El pollito creció y ahora es una gallina senior 😄.

### Acciones según el valor del dado

- 1: Robar una carta del mazo e intercambiarla con una carta propia.

- 2: Robar una carta del mazo e intercambiarla por una del contrario.

- 3: Intercambiar una carta propia con una carta del corral contrario.

- 4: Intercambiar dos cartas del propio corral.

- 5: Bloquear una carta del propio corral, el contrario no podrá realizar la acción 2 y 3.

- 6: Elegir una acción del 1 al 5 o pasar de turno.

### Sistema de puntuación

- Ganar la partida: 15 puntos.

- Ganar la partida robándole la última carta al contrario: 10 puntos.

- Cartas mal ubicadas del corral contrario: 5 puntos por carta.

- Ganar sin haber pasado de turno: 10 puntos.

- Ganar la partida sin haber sufrido un robo del jugador contrario: 5 puntos.

---

