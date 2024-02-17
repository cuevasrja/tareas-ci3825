/*
Escriba un programa en donde dos procesos utilicen un archivo compartido 
(pipe, creado antes del fork) para enviar mensajes que el otro proceso 
tendrá la misión de imprimir.
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main(){
    int fd[2];  // 0 para ir de hijo a padre, 1 para ir de padre a hijo
    char *mensaje = "Hola, soy el proceso 1\n";
    char* buffer = (char*)malloc(sizeof(mensaje));
    pid_t pid;

    if (pipe(fd) == -1){
        perror("Error al crear el pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid == -1){
        perror("Error al crear el proceso hijo");
        exit(EXIT_FAILURE);
    }
    if (pid == 0){
        // Proceso hijo
        close(fd[1]);
        printf("Soy el proceso hijo con PID %d\n", getpid());
        if (read(fd[0], buffer, strlen(mensaje)) == -1){
            perror("Error al leer el archivo");
            exit(EXIT_FAILURE);
        }
        printf("Mensaje recibido: %s", buffer);
    } else {
        // Proceso padre
        close(fd[0]);
        printf("Soy el proceso padre con PID %d\n", getpid());
        if (write(fd[1], mensaje, strlen(mensaje)) == -1){
            perror("Error al escribir en el archivo");
            exit(EXIT_FAILURE);
        }
        wait(NULL);
    }
    free(buffer);
    return 0;
}

