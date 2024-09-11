/*Ejercicio 2: Concatenación de argumentos
Descripción:
Crea un programa que tome todos los argumentos proporcionados (excepto el nombre del programa) y los concatene en una sola cadena, 
separando cada argumento con un espacio. Imprime la cadena resultante.

Objetivo:
Practicar el manejo de cadenas y la iteración sobre los elementos de argv.*/


#include <stdio.h>
int main (int argc, char *argv[])
{
    printf("numero de argumentos: %d\n", argc);
    printf("el nombre del programa: %s\n\n", argv[0]);
    
    if (argc > 1)
    {
        printf("la cadena es:");
        int i=1;
        while (i < argc)
        {
            printf(" %s", argv[i]);
            i++;
        }
        printf("\n");
    }
    else 
        printf("no ha mas argumentos que el nombre del programa\n");
    

    return 0;
}