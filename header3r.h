#ifndef RAYA_H
# define RAYA_H
// Según leo en chatgpt esto es como el include_once de php
// por lo que esoty organizando el código con algún error

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tablero.c"
#include "formatting.c"
#include "mensaje.c"
#include "partida.c"

typedef int i_tablero[3][3];
typedef int i_casilla[2];


void    seleccion_posicion(i_casilla posicion, int seleccion);
void    mostrar_mensaje(char *texto, int color, int efecto);
void    nueva_partida();
void    iniciar_tablero(i_tablero tablero);
void    mostrar_tablero(i_tablero tablero);
int     evaluar_tablero(i_tablero tablero, int turno);
int     evaluar_casilla(i_tablero tablero, int *casilla, int jugador);
int     tablas(i_tablero tablero);




#endif
