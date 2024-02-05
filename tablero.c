/*
tablero.c
Funciones que atañen a las casillas y selecciones
de les jugadores
*/
#include "header3r.h"

// typedefs
typedef int i_casilla[2];
typedef int i_tablero[3][3];

// función que transforma un int de casilla a typedef casilla
void seleccion_posicion(i_casilla posicion, int seleccion)
{
    switch (seleccion)
    {
    case 1:
        posicion[0] = 0;
        posicion[1] = 0;
        break;
    case 2:
        posicion[0] = 0;
        posicion[1] = 1;
        break;
    case 3:
        posicion[0] = 0;
        posicion[1] = 2;
        break;
    case 4:
        posicion[0] = 1;
        posicion[1] = 0;
        break;
    case 5: 
        posicion[0] = 1;
        posicion[1] = 1;
        break; 
    case 6:
        posicion[0] = 1;
        posicion[1] = 2;
        break;
    case 7:
        posicion[0] = 2;
        posicion[1] = 0;
        break;
    case 8:
        posicion[0] = 2;
        posicion[1] = 1;
        break;
    case 9:
        posicion[0] = 2;
        posicion[1] = 2;
        break;
    default:
        posicion[0] = -1;
        posicion[1] = -1;
        break;
    }
}

// función evalua si es válida la casilla (recibe el tablero, la casilla int y el jugador), la modifica y devuelve true o false
int     evaluar_casilla(i_tablero tablero, int *casilla, int jugador)
{
    if(tablero[casilla[0]][casilla[1]] == -1)
    {
        tablero[casilla[0]][casilla[1]] = jugador;
        return 1;
    }else
    {
        return 0;
    }
}
