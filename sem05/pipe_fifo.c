/*
Escriba un programa en donde se crea un pipe FIFO, luego se crean dos hijos, 
uno de los cuales envía texto al otro para que lo imprima
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(){
    int fd;
    char *fifo = "pipe";
    char *mensaje = "Hola, soy el proceso 1\n";
    char* buffer = (char*)malloc(sizeof(mensaje));
    pid_t pid1, pid2;

    if (mkfifo(fifo, 0666) == -1){
        perror("Error al crear el pipe");
        exit(EXIT_FAILURE);
    }

    pid1 = fork();
    if (pid1 == -1){
        perror("Error al crear el proceso hijo");
        exit(EXIT_FAILURE);
    }
    if (pid1 == 0){
        // Proceso hijo 1
        fd = open(fifo, O_WRONLY);
        if (fd == -1){
            perror("Error al abrir el archivo");
            exit(EXIT_FAILURE);
        }
        printf("Soy el proceso hijo 1 con PID %d\n", getpid());
        if (write(fd, mensaje, strlen(mensaje)) == -1){
            perror("Error al escribir en el archivo");
            exit(EXIT_FAILURE);
        }
    } else {
        pid2 = fork();
        if (pid2 == -1){
            perror("Error al crear el proceso hijo");
            exit(EXIT_FAILURE);
        }
        if (pid2 == 0){
            // Proceso hijo 2
            fd = open(fifo, O_RDONLY);
            if (fd == -1){
                perror("Error al abrir el archivo");
                exit(EXIT_FAILURE);
            }
            printf("Soy el proceso hijo 2 con PID %d\n", getpid());
            if (read(fd, buffer, strlen(mensaje)) == -1){
                perror("Error al leer el archivo");
                exit(EXIT_FAILURE);
            }
            printf("Mensaje recibido: %s", buffer);
        } else {
            // Proceso padre
            wait(NULL);
            wait(NULL);
        }
    }
    free(buffer);
    return 0;
}