/*
formatting.c
Macros for color, blink text and make code readable
*/
#include "header3r.h"

/* 
source:
https://misc.flogisoft.com/bash/tip_colors_and_formatting
https://stackoverflow.com/questions/3219393/stdlib-and-colored-output-in-c
*/

#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_BLUE     "\x1b[34m"
#define ANSI_COLOR_MAGENTA  "\x1b[35m"
#define ANSI_COLOR_CYAN     "\x1b[36m"
#define ANSI_COLOR_RESET    "\x1b[0m"
#define CLEAR_SCREEN        "\e[1;1H\e[2J"
#define BLINK               "\e[5m"

#define BLINK_I             1
#define NOBLINK_I           0

#define RED_I               0
#define GREEN_I             1
#define BLUE_I              2
#define MAGENTA_I           3    
#define CYAN_I              4
