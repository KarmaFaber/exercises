/*Ejercicio 1: Definición y Acceso a Miembros
Descripción: Define una estructura llamada Libro que contenga los siguientes miembros:

titulo (cadena de caracteres de tamaño 100)
autor (cadena de caracteres de tamaño 50)
anio_publicacion (entero)
precio (flotante)

Declara una variable de tipo struct Libro, inicializa sus miembros y luego imprime los valores de cada miembro.

Pista: Utiliza strcpy para copiar cadenas en los miembros titulo y autor.*/

#include <string.h>
#include <stdio.h>

struct Libro
{
    char titulo[100];
    char autor[50];
    int anio_publicacion;
    float precio;
};

void imprimir_libro(struct Libro l)
{
    printf("titulo: %s\n", l.titulo);
    printf("autor: %s\n", l.autor);
    printf("año: %i\n", l.anio_publicacion);
    printf("precio: %.2f\n", l.precio );
}

// Función para modificar el título
void modificar_titulo(struct Libro *l, const char *nuevo_titulo) {
    strcpy(l->titulo, nuevo_titulo);
}

// Función para modificar el autor
void modificar_autor(struct Libro *l, const char *nuevo_autor) {
    strcpy(l->autor, nuevo_autor);
}

// Función para modificar el año de publicación
void modificar_anio_publicacion(struct Libro *l, int nuevo_anio) {
    l->anio_publicacion = nuevo_anio;
}

// Función para modificar el precio
void modificar_precio(struct Libro *l, float nuevo_precio) {
    l->precio = nuevo_precio;
}

int main()
{
    struct Libro libro1;
    
    strcpy(libro1.titulo, "hola");
    strcpy(libro1.autor, "desconocido");
    libro1.anio_publicacion =1000;
    libro1.precio= 1.20;
    
    struct Libro libro2;
    
    strcpy(libro2.titulo, "hola caracola");
    strcpy(libro2.autor, "desconocido o no");
    libro2.anio_publicacion =1056;
    libro2.precio= 3.2056;
    
    
    imprimir_libro(libro1);
    //imprimir_libro(libro2);
    
    printf("\n\n");
    modificar_titulo(&libro1, "caracola loca");
    imprimir_libro(libro1);
    

    return 0;
}