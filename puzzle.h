/* LIBRERIAS */
#include <stdlib.h> //
#include <stdio.h>
#include <ncurses.h>
#include <time.h>

/* DEFINICION DE CONSTANTES */
#define N 4        // DIMENSIONES DE LA MATRIZ
#define MAXP 10    // MAXIMO DE PARTIDAS
#define TRUE 1
#define FALSE 0
#define MAXPU 1200 // PUNTOS MAXIMOS
#define MP 1000    // PUNTOS MEDIOS
#define MINP 500   // PUNTOS MINIMOS
#define RPUN 10    // RANGO DE PUNTOS
#define AMIN 40    // APUESTA MINIMA
#define AMAX 200   // APUESTA MAXIMA

/*PROTOTIPOS DE FUNCIONES*/
void matrizValida(int [][N], int);                       // FUNCION QUE CARGA UNA MATRIZ "SOLUCIONABLE"
int noRepetidos(int []);                                 // FUNCION PARA GENERAR NUMEROS AL AZAR NO REPETIDOS
void imprimirM (int [][N]);                              // FUNCION PARA IMPRIMIR UNA MATRIZ 
void desplazamientos (int [][N], int, int *);            // FUNCION DONDE SE REALIZAN LOS DESPLAZAMIENTOS
int solucion (int [][N]);                                // FUNCION QUE CHEQUEA SI EL JUGADOR LOGRO EL PUZZLE
int puntajesObtenidos (int cont_mov, int mov,int puntos);// FUNCION PARA OBTENER LOS PUNTAJES
void historiales (int [],int [],int );                   // FUNCION QUE MUESTRA LOS HISTORIALES
int finalizarPartida ();                                 // FUNCION QUE PREGUNTA AL USUARIO SI DESEA REALIZAR UNA NUEVA PARTIDA O FINALIZAR