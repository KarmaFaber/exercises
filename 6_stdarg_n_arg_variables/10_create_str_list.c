/*Enunciado del Ejercicio 10: Crear una Lista Enlazada Simple con Argumentos Variables

## Objetivo: Implementar una función que permita crear una lista enlazada simple utilizando una cantidad variable de argumentos, 
para almacenar una serie de cadenas de caracteres variables. 
El número de argumentos y los valores serán pasados de manera dinámica utilizando la librería stdarg.h.

## Descripción:
En este ejercicio, implementarás una lista enlazada simple que almacene números enteros. 
Los números que se insertarán en la lista se proporcionarán como una cantidad variable de argumentos al llamar a la función. 
Para esto, usarás las funciones y macros de stdarg.h para manejar los argumentos variables.

## Especificaciones:

1. Estructura del Nodo: Define una estructura llamada Node que contenga:
 - Un campo data de tipo char *content, que almacenará el valor del nodo.
 - Un puntero next de tipo Node* que apuntará al siguiente nodo en la lista enlazada.
2. Funciones a implementar:
 - Node* create_node(char *value):
Crea y devuelve un nuevo nodo que almacene cadena de caracteres pasado como argumento.
Asegúrate de asignar memoria dinámicamente para cada nodo.
 - Node* create_linked_list(int count, ...):
Esta función recibe un número variable de enteros utilizando stdarg.h.
El primer argumento es un entero que indica cuántos números enteros se pasarán a la función.
Crea una lista enlazada a partir de las cadenas de caracteres recibidas.
Devuelve un puntero al primer nodo (cabeza) de la lista enlazada.
 - void print_linked_list(Node* head):
Recorre la lista enlazada desde la cabeza y muestra los valores almacenados en los nodos en el formato: valor1 -> valor2 -> ... -> NULL.
 - void free_linked_list(Node* head):
Libera toda la memoria asignada para los nodos de la lista enlazada.
3. Uso de stdarg.h:
Dentro de la función create_linked_list, utiliza las macros va_list, va_start, va_arg, y va_end para gestionar los argumentos variables.
4. Requisitos de la Función Principal (main):
Crea una lista enlazada con al menos 5 cadenas de caracteres pasados como argumentos.
Imprime los valores de la lista utilizando la función print_linked_list.
Libera la memoria de la lista enlazada.

5. Ejemplo de Ejecución:
c:

int main() {
    // Crear una lista enlazada con 5 valores
    Node* list = create_linked_list("a ", "bbbbbbb ", "cc", "dddddddddddddddd ", "eeeeeeee");

    // Imprimir los valores de la lista
    print_linked_list(list);

    // Liberar la memoria de la lista enlazada
    free_linked_list(list);

    return 0;
}

6. Reglas:
No se permite el uso de arrays de longitud variable.
Usa correctamente la asignación dinámica de memoria para los nodos.
Gestiona la memoria asignada liberándola adecuadamente al final del programa.

7. Pistas:
Recuerda inicializar correctamente el manejo de argumentos variables con va_start y finalizarlos con va_end.
Asegúrate de que tu función create_linked_list construya correctamente la lista enlazada enlazando cada nodo al siguiente.*/

#include <stdarg.h>
#include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void create_linked_list(int count, ...)
{


}

int main (void)
{



    return (0);
}