# include <stdio.h>
# include <stdlib.h>
# include "listaEnlazada.h"
# include "pikachu.h"

// Definimos el constructor del Pikachu
Pikachu *nuevoPikachu(char *nombre){
    // Reservamos memoria para el Pikachu
    Pikachu *nuevo = malloc(sizeof(Pikachu));
    // Asignamos el nombre al Pikachu
    nuevo->nombre = nombre;
    // Asignamos la relacion inicial del Pikachu
    nuevo->relacion = 0;
    // Asignamos la lista de consumidos
    nuevo->consumidos = nuevaLista();
    // Devolvemos el Pikachu
    return nuevo;
}

// Definimos las funciones del Pikachu

// Devolver el nombre del Pikachu. Complejidad: O(1)
char *obtenerNombre(Pikachu *pikachu){
    // Devolvemos el nombre del Pikachu
    return pikachu->nombre;
}

// Devolver la relacion del Pikachu. Complejidad: O(1)
int obtenerRelacion(Pikachu *pikachu){
    // Devolvemos la relacion del Pikachu
    return pikachu->relacion;
}

// Devolver la lista de consumidos del Pikachu. Complejidad: O(1)
lista *obtenerConsumidos(Pikachu *pikachu){
    // Devolvemos la lista de consumidos del Pikachu
    return pikachu->consumidos;
}

// Aumentar la relacion del Pikachu. Complejidad: O(1)
void aumentarRelacion(Pikachu *pikachu, int relacion){
    // Aumentamos la relacion del Pikachu
    pikachu->relacion += relacion;
}

// Agregar un elemento a la lista de consumidos del Pikachu. Complejidad: O(1)
void agregarConsumido(Pikachu *pikachu, char *elemento){
    // Agregamos el elemento a la lista de consumidos del Pikachu
    agregar(pikachu->consumidos, elemento);
}

// Pikachu habla. Complejidad: O(1)
void hablar(Pikachu *pikachu, char *mensaje){
    // Imprimimos el nombre del Pikachu
    printf("\033[93m%s\033[0m: ", pikachu->nombre);
    // Imprimimos el mensaje del Pikachu
    printf("%s\n", mensaje);
}

// Revisar si Pikachu uso un elemento. Complejidad: O(n)
int usoElemento(Pikachu *pikachu, char *elemento){
    return esta(pikachu->consumidos, elemento);
}

// Revisar cuantos elementos uso Pikachu. Complejidad: O(1)
int elementosUsados(Pikachu *pikachu){
    return longitud(pikachu->consumidos);
}
