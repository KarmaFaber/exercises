#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("1_ex_text.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error al abrir el archivo");
        return 1;
    }

    char buffer[100];       //puntero a buffer donde se almacena los datos leidos
    ssize_t bytes_leidos = read(fd, buffer, sizeof(buffer) - 1); // funcion read
    if (bytes_leidos == -1) {
        perror("Error al leer el archivo");
        close(fd);
        return 1;
    }

    buffer[bytes_leidos] = '\0'; // Aseguramos que sea una cadena válida
    printf("Leído: %s\n", buffer);

    close(fd); // fucnion close fd
    return 0;
}

