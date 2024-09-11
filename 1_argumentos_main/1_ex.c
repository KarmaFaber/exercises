/*Ejercicio 1: Contador de argumentos
Descripción:
Escribe un programa que reciba argumentos desde la línea de comandos 
y cuente cuántos argumentos se han proporcionado. 
Luego, muestra este número en pantalla.

Objetivo:
Comprender cómo argc refleja el número de argumentos y cómo argv puede ser usado para iterar sobre los argumentos.*/

#include <stdio.h>

int main (int argc, char *argv[])
{
    printf("numero de argumentos: %d\n", argc);
    printf("el nombre del programa: %s\n\n", argv[0]);


    if (argc > 1)
    {
        int i =0;
        while (i < argc )
        {
            printf("argumento[%i]: %s\n", i+1, argv[i]);
            i++;
        }
    }
    else 
        printf("no ha mas argumentos que el nombre del programa\n");
    return 0;
}