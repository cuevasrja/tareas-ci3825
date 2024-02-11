/*
Cree un programa que multiplique una matriz de 3×3 por una matriz de 3×1 usando múltiples hilos. 
Recuerde que las matrices se multiplican fila×columna, por lo que, si una matriz solo tiene una 
columna, la multiplicación será de la siguiente forma:

A	D	G       a       Aa	Da	Ga
B	E	H       b       Bb	Eb	Hb
C	F	I	×   c	=	Cc	Fc	Ic

por esta razón, se puede dividir en hilos de dos formas: 
- Un hilo para cada fila de la matriz resultante
- Un hilo para cada columna de la matriz resultante
- Puede generar los valores de las matrices usando rand() de stdlib.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define N 3
#define M 1

int A[N][N], B[N][M], C[N][N];

void *multiplicar(void *arg) {
    int fila = *((int *) arg);
    for (int i = 0; i < N; i++) {
        C[fila][i] += A[fila][i] * B[fila][0];
    }
    free(arg);
    pthread_exit(NULL);
}

void imprimirMatriz(int matriz[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void imprimirVector(int matriz[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    pthread_t hilos[N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 10;
            B[j][0] = rand() % 10;
        }
    }
    printf("Matriz A:\n");
    imprimirMatriz(A);
    printf("Matriz B:\n");
    imprimirVector(B);
    for (int i = 0; i < N; i++) {
        int *arg = malloc(sizeof(int));
        *arg = i;
        pthread_create(&hilos[i], NULL, multiplicar, arg);
    }
    for (int i = 0; i < N; i++) {
        pthread_join(hilos[i], NULL);
    }
    printf("Matriz C:\n");
    imprimirMatriz(C);
    return 0;
}