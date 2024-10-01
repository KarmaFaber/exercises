/*5.Lectura de líneas: Crea un programa que lea un archivo línea por línea usando read. 
Define un tamaño fijo para las líneas y utiliza un búfer.

    Desglosemos lo que debes hacer:
    1. Leer el archivo línea por línea:
        Aunque en C existen funciones como fgets() para leer líneas completas, 
        en este ejercicio debes usar la función read(). 
        Esta función no "sabe" lo que es una línea, solo lee una cantidad fija de bytes. 
        Por lo tanto, tendrás que procesar manualmente el contenido que lees para detectar las líneas, 
        identificadas por el carácter de salto de línea ('\n').
    2. Tamaño fijo para las líneas:
        Debes definir un tamaño máximo para cada línea. 
        Por ejemplo, si decides que las líneas tienen un tamaño máximo de 100 caracteres, 
        entonces necesitas leer el archivo en bloques que no superen esa longitud y 
        detenerte cuando encuentres un salto de línea (\n) o cuando llenes ese espacio.
    3. Utilizar un búfer:
        Un búfer es un espacio temporal en memoria que usas para almacenar datos que estás procesando. 
        En este caso, deberás usar un búfer para almacenar los datos que 
        lees del archivo y procesarlos línea por línea.

    Pasos para resolver el ejercicio:
    OK- 1. Abrir el archivo con la función open() y gestionar posibles errores.

    OK -2. Leer el archivo con la función read(), utilizando un tamaño fijo de bloque para el búfer.

    3. Procesar lo leído: A medida que lees el archivo, 
    debes ir revisando los bytes leídos para detectar el carácter de salto de línea ('\n'). 
    Cuando encuentres una línea completa, la imprimes en stdout. 

    4. Manejar líneas incompletas: A veces, la lectura puede 
    terminar justo en medio de una línea (por ejemplo, si el búfer es demasiado pequeño). 
    Tendrás que manejar estos casos para que las líneas no se corten abruptamente.

    OK -5. Cerrar el archivo cuando termines de leerlo.

    Ejemplo de cómo podría funcionar:
    OK -1. Definimos un tamaño de línea máximo (digamos 100 bytes).
    OK -2. Usamos un búfer de lectura para leer el archivo en bloques.
    3. Mientras lees, vas acumulando los caracteres en otro búfer 
    hasta que encuentres un salto de línea ('\n') o llenes el búfer.
    4. Cada vez que encuentres un salto de línea o llenes el búfer, 
    imprimes la línea y comienzas a acumular la siguiente.
*/

// gcc -Wall -Wextra -Werror 5_line_read.c -o 5_line_read
//valgrind --leak-check=full ./5_line_read
//valgrind --leak-check=full --show-leak-kinds=all ./5_line_read

#include <unistd.h>         // open, read, write, close
#include <errno.h>          // errno
#include <stdio.h>          // perror, printf
#include <fcntl.h>          // O_RDONLY
#include <stdlib.h>         // malloc, free

#define BUFFER_SIZE 10

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*s_dup;
	size_t	i;

	i = 0;
	s_dup = (char *)malloc(ft_strlen(s) + 1);
	if (!s_dup)
		return (NULL);
	while (s[i])
	{
		s_dup[i] = s[i];
		i++;
	}
	s_dup[i] = '\0';
	return (s_dup);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if ((start + len) > ft_strlen(s))
		len = ft_strlen(s) - start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	return (substr);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

void	ft_bzero(void *str, unsigned long int n)
{
	char *s;
    unsigned long int i;

    s = (char *)str;
    i = 0;
    while (i < n)
    s[i++] = '\0';
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pointer;
	size_t	total_mem;

	total_mem = nmemb * size;
	pointer = malloc(total_mem);
	if (!pointer)
		return (NULL);
	ft_bzero(pointer, total_mem);
	return (pointer);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = (char *)malloc(s1_len + s2_len + 1);
	if (!new_str)
		return (NULL);
	while (s1[i])
		new_str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new_str[j++] = s2[i];
	new_str[s1_len + s2_len] = '\0';
	return (new_str);
}


static char *ft_process_line (int fd)
{
    char *readed_buffer;
    char *line;
    char *temp;
    ssize_t i = 0;
    ssize_t readed_bytes;
    
    
    line =NULL;
    //en vez de buffer random hacemos directamente calloc para el buffer de lectura
    readed_buffer =ft_calloc (BUFFER_SIZE + 1, sizeof(char));
    if (!readed_buffer)
        return (NULL);
    
    readed_bytes = read (fd, readed_buffer, BUFFER_SIZE);
    // Manejo de errores en la lectura: -1 o 0:
    /*ya hemos reservado memoria para readed_buffer, si readed_bytes ==0 (EOF)
    o readed_bytes = -1 (error), deberemos linerart la memoria para no tener leaks de memoria. 
    y retornamos NULL. */
    if (readed_bytes <= 0)
    {
        free(readed_buffer);
        return (NULL);
    }

    i = 0;
    while (i < readed_bytes)
    {
        if (readed_buffer[i] == '\n')
        {
            temp =ft_substr(readed_buffer, 0, i);
            line = ft_strjoin (line, temp);
            free(temp);
            free(readed_buffer);
            return (line);
        }
        i++;
    }
    
    temp=ft_substr(readed_buffer, 0, readed_bytes);
    line = ft_strjoin(line, temp);

    free(temp);
    free(readed_buffer);
    
    return (line); 
}



int main (void)
{
    int fd;
    int count;
    char *line;

    count = 0;
    fd = open("0_ex_text.txt", O_RDONLY);
    // Manejo de errores al abrir
    if (fd == -1)
    {
        perror("Error al abrir el archivo");
        return 1;
    }
    /*while (1) -> es un bucle infinito que se utoliza para leer archivo de manera continua en bloques 
    hasta que se detecte el final del archivo (readed_bytes ==0) o ocurra un error (readed_bytes < 0), 
    en cuyo caso el bucle se ropme con un break; Es una forma de leer archivos sin saber de antemano cuantos bloques 
    habra en dicho archivo. */
    while (1)   //
    {
        line = ft_process_line(fd);
        if (line == NULL)
            break ;
        count++;
        printf("[%d]: %s\n", count, line);
        free(line);
        line=NULL;
    }

    // Manejo de errores al cerrar
    if (close(fd) == -1)
    {
        perror("Error al cerrar el archivo");
        return 1;
    }
    return (0);
}
