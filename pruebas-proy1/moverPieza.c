/*
Hacer un programa que mediante el uso de memoria compartida y semáforos, simule el movimiento de una pieza de ajedrez en un tablero de ajedrez.
El programa deberá crear un proceso hijo que simulará el movimiento de la pieza, y el proceso padre deberá simular el tablero de ajedrez.
El proceso hijo deberá mover la pieza de la siguiente manera:
1. El proceso hijo deberá mover la pieza a una casilla aleatoria.
2. El proceso hijo deberá dormir 5 segundos.
3. Repetir los pasos 1 y 2, 10 veces.
La pieza sera representada por un entero que puede tomar los valores de 1 a 6, y el tablero será representado por un arreglo de 8x8.
La casilla vacía será representada por un 0.
*/
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>

#define N 8
#define M 8

int tablero[N * M];
sem_t *sem;

void *hijo(void *arg){
    if (*(int *)arg == 10) pthread_exit(NULL);
    int i, j, x = 0, y = 0;
    int pieza = 1;
    srand(time(NULL));
    while(1){
        tablero[x * N + y] = 0;
        x = rand() % N;
        y = rand() % M;
        tablero[x * N + y] = pieza;
        sem_post(sem);
        if (*(int *)arg == 10){
            pthread_exit(NULL);
            break;
        }
        else{
            sleep(5);
        }
    }
}

void printOptions(){
    printf("\n\n");
    printf("1. Mostar tablero\n");
    printf("2. Salir\n");
    printf("\n\n");

}

void printTablero(int k){
    int i, j;
    printf("\033[92;1mTablero de ajedrez %d\033[0m\n\n", k);
    for(i = 0; i < N; i++){
        for(j = 0; j < M; j++){
            printf("%d ", tablero[i * N + j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(){
    int fd, i, j, k = 1;
    pthread_t tid;
    fd = shm_open("/shm", O_CREAT | O_RDWR, 0600);
    ftruncate(fd, sizeof(int) * N * M);
    sem = sem_open("/sem", O_CREAT, 0600, 1);
    for(i = 0; i < N; i++){
        for(j = 0; j < M; j++){
            tablero[i * N + j] = 0;
        }
    }
    // Pasamos k como argumento
    pthread_create(&tid, NULL, hijo, (void *)&k);
    int option = 0;
    while(k < 10){
        sem_wait(sem);
        printOptions();
        scanf("%d", &option);
        while (option < 1 || option > 2){
            printf("Opción no válida\n");
            printOptions();
            scanf("%d", &option);
        }
        if (option == 1) printTablero(k++);
        else if (option == 2){
            k = 10;
            sem_post(sem);
            break;
        }
        sem_post(sem);
    }
    pthread_join(tid, NULL);
    sem_close(sem);
    sem_unlink("/sem");
    shm_unlink("/shm");
    return 0;
}

// gcc -o moverPieza.o moverPieza.c -lpthread -lrt