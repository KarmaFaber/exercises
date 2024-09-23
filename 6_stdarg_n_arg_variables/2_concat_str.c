/*Ejercicio 2: Concatenación de cadenas
Escribe una función que acepte un número indefinido de cadenas 
y devuelva una nueva cadena que sea la concatenación de todas ellas. 
Usa memoria dinámica para almacenar el resultado -> malloc. ft_strlcat.c ? 
Prototipo: char *concat_strings(int count, ...);*/

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int ft_lenght(int count, va_list args)
{
    int i;
    int total_len;
    va_list temp_args; // declaramos va_list como temporal para poder reutilizarla en ft_allocate y ft_write_str
    
    i=0;
    total_len = 0;
    va_copy(temp_args, args); // copiamos la lista de argumentos para no cunsumirla
    while (i < count)
    {
        total_len += strlen(va_arg(temp_args, char *));
        i++;
    }
    va_end(temp_args);
    return (total_len);
}
static char *ft_allocate(int count, va_list args)
{
    
    int total_len;
    char *new_array;
    
    total_len = ft_lenght(count, args);
    new_array = (char *)malloc((total_len + 1)*(sizeof(char)));
    if(!new_array)
        return (NULL);
        
    return (new_array);
}

static char *ft_write_str(int count, va_list args)
{
    int i;      // args_counter: contador de cadenas que pasaran por args
    int x;      //indice para new_arrray
    char *current_str;
    char *new_array;
    va_list temp_args;
    
    i=0;
    x=0; 
    new_array=ft_allocate(count, args);
    if (!new_array)
        return (NULL);
    va_copy(temp_args, args);  
    while (i < count)
    {
        current_str=va_arg(temp_args, char *);
        while (*current_str)
            new_array[x++] = *current_str++;
        i++;
    }
    va_end(temp_args);
    new_array[x]='\0';
    return (new_array);
}

char *concat_strings(int count, ...)
{
    va_list args;
    char *result;       //string copiado que decolvemos

    va_start(args, count);

    result =ft_write_str(count, args);

    va_end(args);
    return(result);
}

int main (void)
{
    char *new_array=concat_strings(4, "hola", "ll", "xxxxx", "000000");
    
    printf("concat_str: %s\n", new_array); // el primer argumento es el numero de argumentos que vamos a pasar. 
    
    free(new_array);
    return (0); 
}