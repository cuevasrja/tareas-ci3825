/*
Escriba el programa Hola Mundo con hilos, donde un hilo escribe "hola" y el otro escribe "mundo"
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *hola(void *arg) {
    printf("Hola ");
    pthread_exit(NULL);
}

void *mundo(void *arg) {
    printf("Mundo\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t h1, h2;
    pthread_create(&h1, NULL, hola, NULL);
    pthread_create(&h2, NULL, mundo, NULL);
    pthread_join(h1, NULL);
    pthread_join(h2, NULL);
    return 0;
}