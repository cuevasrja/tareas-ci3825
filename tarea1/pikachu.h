#ifndef PIKACHU_H
#define PIKACHU_H
# include <stdio.h>
# include <stdlib.h>
# include "listaEnlazada.h"

// Creamos la estructura de un Pikachu
typedef struct Pikachu{
    char *nombre;
    int relacion;
    lista *consumidos;
} Pikachu;

// Definimos el constructor del Pikachu
Pikachu *nuevoPikachu(char *nombre);

// Definimos las funciones del Pikachu
// Devolver el nombre del Pikachu. Complejidad: O(1)
char *obtenerNombre(Pikachu *pikachu);
// Devolver la relacion del Pikachu. Complejidad: O(1)
int obtenerRelacion(Pikachu *pikachu);
// Devolver la lista de consumidos del Pikachu. Complejidad: O(1)
lista *obtenerConsumidos(Pikachu *pikachu);
// Aumentar la relacion del Pikachu. Complejidad: O(1)
void aumentarRelacion(Pikachu *pikachu, int relacion);
// Agregar un elemento a la lista de consumidos del Pikachu. Complejidad: O(1)
void agregarConsumido(Pikachu *pikachu, char *elemento);
// Pikachu habla. Complejidad: O(1)
void hablar(Pikachu *pikachu, char *mensaje);
// Revisar si Pikachu uso un elemento. Complejidad: O(n)
int usoElemento(Pikachu *pikachu, char *elemento);
// Revisar cuantos elementos uso Pikachu. Complejidad: O(1)
int elementosUsados(Pikachu *pikachu);
#endif