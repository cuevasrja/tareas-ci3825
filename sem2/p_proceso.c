/*
Escriba un programa que haga sleep y luego imprima 
el tiempo que realmente pasó en nanosegundos
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main() {
    pid_t pid;
    int status;
    // Inicializamos las variables para medir el tiempo (en milisegundos)
    struct timespec start, finish;
    double elapsed;

    clock_gettime(CLOCK_MONOTONIC, &start);

    if ((pid = fork()) == 0) {
        sleep(10);
        printf("Soy el hijo, mi pid es %d\n", getpid());
        exit(0);
    }

    printf("Soy el padre, mi pid es %d\n", getpid());
    wait(&status);
    printf("Mi hijo terminó con estado %d\n", status);

    clock_gettime(CLOCK_MONOTONIC, &finish);
    
    // Calculamos el tiempo transcurrido
    elapsed = (finish.tv_sec - start.tv_sec);
    elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
    printf("Tiempo transcurrido: %f\n", elapsed);

    return 0;
}