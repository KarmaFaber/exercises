/*Ejercicio 1: Crear y Escribir en un Archivo
Objetivo: Crea un archivo y escribe un mensaje en él.
Instrucciones:
Usa open para crear un archivo llamado testfile.txt.
Usa write para escribir el texto "Hello, World!" en el archivo.
Cierra el archivo usando close.*/

/*Consejos para Practicar
Experimenta con Flags de open: Usa diferentes flags como O_RDWR, O_TRUNC, y O_CREAT para ver cómo afectan las operaciones de archivo.
Prueba con Diferentes Tamaños de Buffers: Experimenta con buffers de diferentes tamaños en operaciones de lectura y escritura.
Manejo de Errores: Asegúrate de manejar errores de forma adecuada para todas las operaciones de archivo.*/


#include <fcntl.h>   // Para open
#include <unistd.h>  // Para write y close
#include <stdio.h>   // Para perror

int main() 
{
    
    void	ft_putendl_fd(char *s, int fd)
    {
    	if (!s)
    		return ;
    	while (*s)
    	{
    		write(fd, s++, 1);
    	}
    	write(fd, "\n", 1);
    }
    
    //declaramos s
    char s[]="hola caracola";

    // Abrir un archivo para escritura (O_WRONLY) y crear si no existe (O_CREAT)
    int fd = open("1_ex_text.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    
    // Verificar si el archivo se abrió correctamente
    if (fd < 0) {
        perror("Error al abrir el archivo");
        return 1;
    }
    
    // Escribir en el archivo consalto de linea:
    ft_putendl_fd(s, fd);
    
    
    // Cerrar el archivo
    if (close(fd) < 0) {
        perror("Error al cerrar el archivo");
        return 1;
    }
    
    
    printf("\n%i\n", fd);
    
    return 0;
}