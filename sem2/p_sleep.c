/*
Escriba un programa que cree un proceso, cada uno de los cuales termine 
luego de una llamada a sleep. Asegúrese de que el tiempo de sleep sea 
suficiente para poder llamar a ps antes de que terminen.

Ejecútelo en background y llame a ps suficientes veces para ver que el 
hijo termine y el padre no.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {

    pid_t pid;
    int status;

    if ((pid = fork()) == 0) {
        sleep(10);
        printf("Soy el hijo, mi pid es %d\n", getpid());
        exit(0);
    }

    printf("Soy el padre, mi pid es %d\n", getpid());
    wait(&status);
    printf("Mi hijo terminó con estado %d\n", status);

    return 0;
}