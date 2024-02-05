/*
Game made after watching https://www.youtube.com/@CodingIsThinking
list "C Language - Complete Course" up to video 38.
*/

/*
main.c
Punto de entrada del programa
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header3r.h"

/// main
int main()
{
    /// mensaje de bienvenida
    mostrar_mensaje("Bienvenide al juego del tres en raya\n", GREEN_I, NOBLINK_I);
    mostrar_mensaje("====================================\n", RED_I, NOBLINK_I);
    mostrar_mensaje("Pula ENTER para continuar...", BLUE_I, BLINK_I);
    getchar();
    system("clear");
    /// bucle que pregunta si se quiere jugar una partida
    while(1)
    {
        /*borrar consola por si vienes de partida anterior*/
        /// mostrar pregunta si se quiere jugar una partida
        mostrar_mensaje("¿Quieres jugar una nueva partida? (s/n)\n", GREEN_I, NOBLINK_I);
        /// leer respuesta
        char respuesta[2];
        scanf("%s", respuesta);
        if(strcmp(respuesta, "s") == 0)
        {
            system("clear");
            /// si se quiere jugar una partida, se llama a la funcion nueva partida
            nueva_partida();
        }
        else if(strcmp(respuesta, "n") == 0)
        {
            /// si no se quiere jugar una partida, se sale del bucle
            mostrar_mensaje("Hasta la próxima!\n", BLUE_I, NOBLINK_I);
            break;
        }else
        {
            system("clear");
            /// si la respuesta no es valida, se vuelve a preguntar
            mostrar_mensaje("Respuesta no valida\n", RED_I, NOBLINK_I);
        }
    }/// fin bucle que pregunta si se quiere jugar una partida
    /// fin del programa
    return (0);
}