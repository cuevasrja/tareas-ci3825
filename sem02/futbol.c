#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Creamos la estructura de jugador
typedef struct Jugador
{
    char nombre[20];
    char posicion[20];
} Jugador;

// Creamos el constructor de jugador
Jugador* crearJugador(char nombre[20], char posicion[20])
{
    Jugador* j = malloc(sizeof(Jugador));
    strcpy(j->nombre, nombre);
    strcpy(j->posicion, posicion);
    return j;
}

int main(){
    int n = 11;
    // Creamos nuestro array de jugadores (11 jugadores)
    Jugador* jugadores[n];
    // Creamos los jugadores
    for (int i = 0; i < n; i++){
        char nombre[20];
        char posicion[20];
        printf("Nombre del jugador %d: ", i+1);
        scanf("%s", nombre);
        printf("Posicion del jugador %d: ", i+1);
        scanf("%s", posicion);
        jugadores[i] = crearJugador(nombre, posicion);
    }
    // Mostramos los jugadores
    printf("\nJugadores:\n");
    for (int i = 0; i < n; i++){
        printf("Jugador %d: %s, %s\n", i+1, jugadores[i]->nombre, jugadores[i]->posicion);
    }
    return 0;
}