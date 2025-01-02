/*
2. **Crear y escribir en un archivo:**
    - Implementa un programa que cree un archivo `output.txt` y escriba "Hola, mundo!" en él.

Consejos para Practicar
Experimenta con Flags de open: Usa diferentes flags como O_RDWR, O_TRUNC, y O_CREAT para ver cómo afectan las operaciones de archivo.
Prueba con Diferentes Tamaños de Buffers: Experimenta con buffers de diferentes tamaños en operaciones de lectura y escritura.
Manejo de Errores: Asegúrate de manejar errores de forma adecuada para todas las operaciones de archivo

cc -Wall -Werror -Wextra 2_ejerc.c -o 2_ejerc
*/

#include <stdio.h> //perror
#include <unistd.h> // read
#include <fcntl.h> // open

//int open(const char *pathname, int flags, .../* mode_t mode */ );
//O_TRUNC causes the file to be truncated if it exists.

//O_TRUNC: Si el archivo ya existe, su tamaño se truncará a 0 (es decir, se borra el contenido previo).
//O_APPEND causes writes to append to the end of the file instead of overwrite at the start. 
//This flag is persistent. If you move the cursor elsewhere to read data it's always repositioned to the end of the file before each write.

//0644 = ---xr-xr-x

int main (void)
{
	int fd;
	char text[100] = "Hola, mundo!\n Hola caracola\n Hola C\n";

	//open
	//fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);      //solo para escritura (O_WRONLY) y  resrteo del contenido del archivo(O_TRUNC)
	fd = open("output.txt", O_RDWR | O_CREAT | O_APPEND, 0644);     	//escritura y lectura (O_RDWR) con añadir datos al archivo (APPEND)
	if (fd == -1)
	{
		perror ("error al abrir el archivo o crearlo");
		return (1);
	}

	//	write
	int i=0;
	while(text[i] != '\0')
	{
		write(fd, &text[i], 1);
		i++;
	}

	//close
	if (close (fd) == -1)
	{
		perror("error al cerrar fd");
		return (1);
	}

	return (0);
}

