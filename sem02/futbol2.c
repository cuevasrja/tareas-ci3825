/*
Escriba un programa que cargue dos equipos de futbol en memoria, preguntándole 
al usuario por cada posición, luego imprima la alineación. La forma de guardar 
en memoria debe garantizar que solo haya un jugador en cada posición. Suponga 
que ambos equipos usan la misma formación (mismo número de delanteros y defensas 
que el otro). Un ejemplo de impresión se muestra a continuación luego de haber 
cargado todos los jugadores.

                 Real Madrid  Manchester United 
                 ------------ ----------------- 
Arquero          Casillas     Amos
Defens. Izq.     Ramos        Buttner
Defens. Der.     Varane       Evans
Mediocam. Izq.   Coentrao     Giggs
Mediocam. Centr. Khedira      Fellaini
Mediocam. Der.   Carvajal     Fletcher
Centrocam Izq.   Modric       Cleverley
Centrocam Der.   Di Maria     Carrick
Delant. Izq.     Bale         Nani
Delant. Der.     Ronaldo      Lawrence
Delant. Centr.   Benzema      Hernandez
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EQUIPOS 2
#define MAX_JUGADORES 11

char* POSICIONES[] = {
    "Arquero",
    "Defens. Izq.",
    "Defens. Der.",
    "Mediocam. Izq.",
    "Mediocam. Centr.",
    "Mediocam. Der.",
    "Centrocam Izq.",
    "Centrocam Der.",
    "Delant. Izq.",
    "Delant. Der.",
    "Delant. Centr."
};

typedef struct jugador {
    char* nombre;
} Jugador;

// Constructor de Jugador
Jugador* nuevoJugador(char* nombre) {
    Jugador* jugador = malloc(sizeof(Jugador));
    jugador->nombre = nombre;
    return jugador;
}

// Cambiar el nombre del jugador
void cambiarNombre(Jugador* jugador, char* nombre) {
    jugador->nombre = nombre;
}

typedef struct equipo {
    Jugador* jugadores[MAX_JUGADORES];
} Equipo;

// Constructor de Equipo
Equipo* nuevoEquipo() {
    Equipo* equipo = malloc(sizeof(Equipo));
    int i;
    for (i = 0; i < MAX_JUGADORES; i++) {
        equipo->jugadores[i] = NULL;
    }
    return equipo;
}

void imprimirEquipos(Equipo* equipo1, Equipo* equipo2) {
    int i;
    printf("%-16s %-16s\n", "Real Madrid", "Manchester United");
    printf("%-16s %-16s\n", "------------", "-----------------");
    for (i = 0; i < MAX_JUGADORES; i++) {
        printf("%-16s %-16s\n", equipo1->jugadores[i]->nombre, equipo2->jugadores[i]->nombre);
    }
}

int main() {
    Equipo* equipos[MAX_EQUIPOS];
    int i, j;
    for (i = 0; i < MAX_EQUIPOS; i++) {
        equipos[i] = nuevoEquipo();
        printf("Equipo %d\n", i + 1);
        for (j = 0; j < MAX_JUGADORES; j++) {
            char* nombre = malloc(sizeof(char) * 50);
            printf("Ingrese el nombre del jugador para la posicion %s: ", POSICIONES[j]);
            scanf("%s", nombre);
            equipos[i]->jugadores[j] = nuevoJugador(nombre);
        }
    }

    imprimirEquipos(equipos[0], equipos[1]);
}



