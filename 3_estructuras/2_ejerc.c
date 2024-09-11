/*Ejercicio 2: Array de Estructuras
Descripción: Define una estructura llamada Estudiante que contenga los siguientes miembros:

nombre (cadena de caracteres de tamaño 50)
edad (entero)
promedio (flotante)
Crea un array de 3 estudiantes, inicializa sus valores y luego imprime la información de cada estudiante.

Pista: Recorre el array con un bucle while para acceder a cada estudiante.
*/
#include <stdio.h>
#include <string.h>

struct Estudiante
{
    char nombre[50];
    int edad;
    float promedio;
} ;

void imprimir_est(struct Estudiante s)
{
    printf("Nombre: %s\n", s.nombre);
    printf("autor: %i\n", s.edad);
    printf("año: %.2f\n", s.promedio);
    printf("\n\n");
}

int main (void)
{
    int i;
    
    /*
    Declaración e inicialización del array de estructuras:
    
    struct Estudiante estudiantes[3] = {
        {"Paco", 15, 7.0},    
        {"Lola", 13, 8.0},
        {"Fran", 17, 6.0}
    };*/
    
     // Declaración del array de estructuras
    struct Estudiante estudiantes[3];
    // Asignación de valores individualmente
    strcpy(estudiantes[0].nombre, "Paco");
    estudiantes[0].edad = 15;
    estudiantes[0].promedio = 7.0;
    
    strcpy(estudiantes[1].nombre, "Lola");
    estudiantes[1].edad = 13;
    estudiantes[1].promedio = 8.0;
    
    strcpy(estudiantes[2].nombre, "Fran");
    estudiantes[2].edad = 17;
    estudiantes[2].promedio = 6.0;
    
    i=0;
    while (i<3)
    {
        imprimir_est(estudiantes[i]);
        i++;
    }
    return 0;
}

