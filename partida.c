/*
partida.c
Funciones para una nueva partida, centradas en lo que 
atañe a la partida y el tablero.
*/
#include "header3r.h"

// typedefs
typedef int i_tablero[3][3];
typedef int i_casilla[2];

// función void que inicializa el tablero (devuelve el tablero)
void iniciar_tablero(i_tablero tablero)
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3 ; j++)
        {
            tablero[i][j] = -1;
        }
    }
}
// función que muestra el tablero con los números 1 a nueve 
void     mostrar_tablero_mockup()
{
    printf("-------------\n");
    printf("| 1 | 2 | 3 |\n");
    printf("-------------\n");
    printf("| 4 | 5 | 6 |\n");
    printf("-------------\n");
    printf("| 7 | 8 | 9 |\n");
    printf("-------------\n");
}
// función que muestra el tablero actual (recibe el tablero)
void mostrar_tablero(i_tablero tablero){
    for(int i = 0; i < 3; i++)
    {
        printf("-------------\n");
        for(int j = 0; j < 3 ; j++)
        {
            if(tablero[i][j] == -1)
            {
                printf("|   ");
            }else if(tablero[i][j] == 0)
            {
                printf("| O ");
            }else if(tablero[i][j] == 1)
            {
                printf("| X ");
            }
        }
        printf("|\n");
    }
    printf("-------------\n");
}
// función que evalúa si ha terminado la partida
int evaluar_tablero(i_tablero tablero, int turno)
{
    // horizontales
    if (tablero[0][0] == turno && tablero[0][1] == turno && tablero[0][2] == turno)
    {
        return 1;
    }
    if (tablero[1][0] == turno && tablero[1][1] == turno && tablero[1][2] == turno)
    {
        return 1;
    }
    if (tablero[2][0] == turno && tablero[2][1] == turno && tablero[2][2] == turno)
    {
        return 1;
    }
    // verticales
    if (tablero[0][0] == turno && tablero[1][0] == turno && tablero[2][0] == turno)
    {
        return 1;
    }
    if (tablero[0][1] == turno && tablero[1][1] == turno && tablero[2][1] == turno)
    {
        return 1;
    }
    if(tablero[0][2] == turno && tablero[1][2] == turno && tablero[2][2] == turno)
    {
        return 1;
    }
    // diagonales
    if (tablero[0][0] == turno && tablero[1][1] == turno && tablero[2][2] == turno)
    {
        return 1;
    }
    if (tablero[0][2] == turno && tablero[1][1] == turno && tablero[2][0] == turno)
    {
        return 1;
    }
    return 0;
}
int tablas(i_tablero tablero)
{
    int contador = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3 ; j++)
        {
            if(tablero[i][j] != -1)
            {
                contador++;
            }
        }
    }
    if(contador == 9)
    {
        return 1;
    }else
    {
        return 0;
    }
}
// función para una nueva partida
void nueva_partida()
{
    i_tablero tablero;
    i_casilla casilla;
    iniciar_tablero(tablero);
    int turno = 1;
    getchar();
    mostrar_mensaje("Instrucciones:\n", GREEN_I, NOBLINK_I);
    mostrar_tablero_mockup();
    mostrar_mensaje("\nPula ENTER para continuar...", RED_I, BLINK_I);
    getchar();
    system("clear");
    /// se muestra el tablero
    mostrar_tablero(tablero);
    mostrar_mensaje("Turno del O (magentas)\n", MAGENTA_I, BLINK_I);
    /// bucle que pregunta una selección al usuario
    while(1)
    {
        /// mostrar mensaje de selección
        mostrar_mensaje("Seleccione una casilla\n", GREEN_I, BLINK_I);
        /// leer selección
        int seleccion;
        scanf("%d", &seleccion);
        /// evaluar si la selección es válida
        if(seleccion > 0 && seleccion < 10)
        {
            /// si la selección es válida, se llama a la función que transforma la selección en casilla
            seleccion_posicion(casilla, seleccion);

                /// si la casilla es válida, se evalúa si la casilla está ocupada
                if(tablero[casilla[0]][casilla[1]] == -1)
                {
                    /// si la casilla no está ocupada, se pone la ficha
                    tablero[casilla[0]][casilla[1]] = turno;
                    /// se limpia la pantalla
                    system("clear");
                    /// se muestra el tablero
                    mostrar_tablero(tablero);
                    /// se evalúa si se ha terminado la partida
                    if(evaluar_tablero(tablero, turno) == 1)
                    {
                        /// si se ha terminado la partida, se muestra el mensaje de ganador
                        mostrar_mensaje(((turno == 0) ? "Ganaron magentas (O)\n" : "Ganaron cyanes (X)\n"), GREEN_I, NOBLINK_I);
                        break;
                    }
                    else if(tablas(tablero) == 1)
                    {
                        mostrar_mensaje("Quedaron empate!\n", RED_I, BLINK_I);
                        break;
                    }
                    /// se cambia de turno
                    turno = (turno == 1) ? 0 : 1;
                    /// si no se ha terminado la partida, se muestra el mensaje de turno del jugadore 2
                    mostrar_mensaje("Turno de X (cyanes)\n", CYAN_I, BLINK_I);
                }else
                {
                    /// si la casilla está ocupada, se muestra el mensaje de casilla ocupada
                    mostrar_mensaje("Casilla ocupada\n", RED_I, NOBLINK_I);
                }
        }else
        {
            /// si la selección no es válida, se muestra el mensaje de selección no válida
            mostrar_mensaje("Selección no válida\n", RED_I, NOBLINK_I);
        }
    }/// fin bucle que pregunta una selección al usuario
}

