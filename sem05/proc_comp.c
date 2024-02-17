/*
Escriba un programa en donde dos procesos utilicen un archivo compartido (creado antes del fork) 
para enviar mensajes que el otro proceso tendrá la missión de imprimir.

Anote cualquier comportamiento inesperado que observe.

Sugerencias
- Para asegurar de que el proceso receptor está realizando la impresión, puede incluir el ID del 
proceso actual, obtenido con getpid()
- Realice la lectura y escritura en órdenes diferentes en el padre que en el hijo
- Coloque una impresión intermedia antes de realizar la lectura o escritura para saber si se está 
realizado ya que esta llamada puede ser bloqueante
- Coloque instrucciones sleep para dar tiempo a los programas de llegar al mismo punto
- Ejecute el programa varias veces para ver si, al ser seleccionados los procesos en órdenes 
diferentes por el despachador, el comportamiento varía
- Si el programa deja de mostrar progreso, no dude en matarlo con Ctrl+C
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
    char *archivo = "archivo.txt";
    char *mensaje = "Hola, soy el proceso 1\n";
    char* buffer = (char*)malloc(sizeof(mensaje));
    pid_t pid1, pid2;

    fd = open(archivo, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1){
        perror("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }

    pid1 = fork();
    if (pid1 == -1){
        perror("Error al crear el proceso hijo");
        exit(EXIT_FAILURE);
    }
    if (pid1 == 0){
    // Proceso hijo
    close(fd);
    fd = open(archivo, O_RDONLY);
    if (fd == -1){
        perror("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }
    sleep(1);
    printf("Soy el proceso hijo con PID %d\n", getpid());
    if (read(fd, buffer, strlen(mensaje)) == -1){
        perror("Error al leer el archivo");
        exit(EXIT_FAILURE);
    }
        printf("Mensaje recibido: %s", buffer);
    } else {
        // Proceso padre
        printf("Soy el proceso padre con PID %d\n", getpid());
        if (write(fd, mensaje, strlen(mensaje)) == -1){
            perror("Error al escribir en el archivo");
            exit(EXIT_FAILURE);
        }
        wait(NULL);
    }

    close(fd);
    return 0;
}