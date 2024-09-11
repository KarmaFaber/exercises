/*Ejercicio 5: Estructura Anidada
Descripción: Define una estructura llamada Fecha que contenga los siguientes miembros:

dia (entero)
mes (entero)
anio (entero)
Luego, define una estructura llamada Evento que contenga los siguientes miembros:

nombre (cadena de caracteres de tamaño 50)
fecha (estructura Fecha)

Crea un Evento, inicializa todos sus miembros, y luego imprime la información del evento incluyendo la fecha en el formato "DD/MM/AAAA".

Pista: Puedes acceder a los miembros de la estructura Fecha dentro de Evento usando el operador ..
*/
#include <string.h>
#include <stdio.h>

struct Fecha 
{
    int dia;
    int mes;
    int anio;
};

struct Evento
{
    char evento[50];
    struct Fecha fecha;
};

void imprimir_evento (struct Evento e)
{
    printf("evento: %s\n", e.evento);
    printf("fecha: %d/%d/%d\n", e.fecha.dia, e.fecha.mes, e.fecha.anio);
}

int main(void)
{
    struct Evento ev1;

    strcpy(ev1.evento, "cumpleanios");
    ev1.fecha.dia =10;
    ev1.fecha.mes =10;
    ev1.fecha.anio=2010;

    imprimir_evento(ev1);

    return 0;
}


