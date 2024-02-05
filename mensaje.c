/*
mensaje.c
Función de mostrar mensaje con color y efecto
*/

#include "header3r.h"

/// función mostrar mensaje, recibe texto, color y efecto
void    mostrar_mensaje(char *texto, int color, int efecto)
{
    char *scolor;
    char *sefecto;
    switch (color)
    {
    case 0:
        scolor = ANSI_COLOR_RED;
        break;
    case 1:
        scolor = ANSI_COLOR_GREEN;
        break;
    case 2:
        scolor = ANSI_COLOR_BLUE;
        break;
    case 3:
        scolor = ANSI_COLOR_MAGENTA;
        break;
    case 4:
        scolor = ANSI_COLOR_CYAN;
        break;
    default:
        break;
    }
    sefecto = (efecto) ? BLINK : "";
    /// mostrar texto con color y efecto
    printf("%s%s%s%s", scolor, sefecto , texto, ANSI_COLOR_RESET); 
}