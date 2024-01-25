# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "listaEnlazada.h"

// Definimos el constructor del nodo
Nodo *nuevoNodo(char *elemento){
    // Reservamos memoria para el nodo
    Nodo *nuevo = malloc(sizeof(Nodo));
    // Asignamos el elemento al nodo
    nuevo->elemento = elemento;
    // Asignamos el siguiente nodo a NULL
    nuevo->siguiente = NULL;
    // Devolvemos el nodo
    return nuevo;
}

// Definimos las funciones del nodo

// Devolver el elemento del nodo. Complejidad: O(1)
char *obtenerElemento(Nodo *nodo){
    // Devolvemos el elemento del nodo
    return nodo->elemento;
}

// Devolver el siguiente nodo. Complejidad: O(1)
Nodo *obtenerSiguiente(Nodo *nodo){
    // Devolvemos el siguiente nodo
    return nodo->siguiente;
}

// Asignar el elemento del nodo. Complejidad: O(1)
void asignarElemento(Nodo *nodo, char *elemento){
    // Asignamos el elemento al nodo
    nodo->elemento = elemento;
}

// Asignar el siguiente nodo. Complejidad: O(1)
void asignarSiguiente(Nodo *n, Nodo *sig){
    // Asignamos el siguiente nodo
    n->siguiente = sig;
}

// Definimos el constructor de la lista
lista *nuevaLista(){
    // Reservamos memoria para la lista
    lista *nueva = malloc(sizeof(lista));
    // Asignamos el primer y ultimo nodo a NULL
    nueva->primero = NULL;
    nueva->ultimo = NULL;
    // Asignamos la longitud a 0
    nueva->longitud = 0;
    // Devolvemos la lista
    return nueva;
}

// Definimos las funciones de la lista

// Agregar un elemento a la lista. Complejidad: O(1)
void agregar(lista *lista, char *elemento){
    // Creamos el nodo
    Nodo *nuevo = nuevoNodo(elemento);
    // Si la lista esta vacia
    if(lista->longitud == 0){
        // Asignamos el nodo como primero y ultimo
        lista->primero = nuevo;
        lista->ultimo = nuevo;
    }
    // Si la lista no esta vacia
    else{
        // Asignamos el nodo como ultimo
        lista->ultimo->siguiente = nuevo;
        lista->ultimo = nuevo;
    }
    // Aumentamos la longitud de la lista
    lista->longitud++;
}

// Eliminar un elemento de la lista. Complejidad: O(n)
void eliminar(lista *lista, char *elemento){
    int encontrado = 0;
    // Si la lista esta vacia
    if(longitud(lista) == 0){
        // Salimos de la funcion
        return;
    }
    // Si la lista no esta vacia
    
    // Creamos un nodo auxiliar
    Nodo *aux = lista->primero;
    // Si el elemento a eliminar es el primero
    if(aux->elemento == elemento){
        // Asignamos el segundo nodo como primero
        lista->primero = aux->siguiente;
        // Liberamos el nodo
        free(aux);
        // Reducimos la longitud de la lista
        lista->longitud--;
        return;
    }
    // Si el elemento a eliminar no es el primero
    // Mientras el siguiente nodo no sea NULL
    while(aux->siguiente != NULL){
        // Si el siguiente nodo es el elemento a eliminar
        if(aux->siguiente->elemento == elemento){
            // Creamos un nodo auxiliar para el nodo a eliminar
            Nodo *aux2 = aux->siguiente;
            // Asignamos el siguiente nodo como siguiente del nodo a eliminar
            aux->siguiente = aux->siguiente->siguiente;
            // Liberamos el nodo
            free(aux2);
            free(aux2);
            // Reducimos la longitud de la lista
            lista->longitud--;
            // Salimos del ciclo
            return;
        }
        // Si el siguiente nodo no es el elemento a eliminar
        aux = aux->siguiente;
    }
    // Si el elemento a eliminar no esta en la lista
    // Liberamos el nodo
    free(aux);

}

// Decidir si la lista esta vacia. Complejidad: O(1)
int estaVacia(lista *lista){
    // Si la lista esta vacia
    if(lista->longitud == 0){
        // Devolvemos 1
        return 1;
    }
    // Si la lista no esta vacia
    // Devolvemos 0
    return 0;
}

// Mostrar la lista. Complejidad: O(n)
void mostrarLista(lista *lista){
    // Si la lista esta vacia
    if (estaVacia(lista) == 1){
        return;
    }
    // Si la lista no esta vacia
    // Creamos un nodo auxiliar
    Nodo *aux = lista->primero;
    int i = 1;
    // Mientras aux no sea NULL y el siguiente nodo no sea NULL
    while(aux->siguiente != NULL){
        // Mostramos el elemento del nodo
        printf("\033[92m%d.\033[0m %s\n", i, aux->elemento);
        // Asignamos el siguiente nodo como nodo actual
        aux = aux->siguiente;
        // Aumentamos el contador
        i++;
    }
    // Si aux no es NULL, mostramos el elemento del nodo
    if (aux != NULL) {
        printf("\033[92m%d.\033[0m %s\n", i, aux->elemento);
    }
}

// Revisar si un elemento esta en la lista. Complejidad: O(n)
int esta(lista *lista, char *elemento){
    // Si la lista esta vacia
    if(lista->longitud == 0){
        // Devolvemos 0
        return 0;
    }
    // Si la lista no esta vacia
    // Creamos un nodo auxiliar
    Nodo *aux = lista->primero;
    // Mientras el siguiente nodo no sea NULL
    while(aux != NULL){
        // Si el elemento esta en la lista
        if(strcmp(aux->elemento, elemento) == 0){
            // Devolvemos 1
            return 1;
        }
        // Asignamos el siguiente nodo como nodo actual
        aux = aux->siguiente;
    }
    // Liberamos el nodo
    free(aux);
    // Si el elemento no esta en la lista
    // Devolvemos 0
    return 0;
}

// Devolver la longitud de la lista. Complejidad: O(1)
int longitud(lista *lista){
    // Devolvemos la longitud de la lista
    return lista->longitud;
}

// Devolver el primer elemento de la lista. Complejidad: O(1)
char *primero(lista *lista){
    // Devolvemos el primer elemento de la lista
    return lista->primero->elemento;
}

// Devolver el ultimo elemento de la lista. Complejidad: O(1)
char *ultimo(lista *lista){
    // Devolvemos el ultimo elemento de la lista
    return lista->ultimo->elemento;
}

// Devolver el elemento en la posicion indicada. Complejidad: O(n)
char *obtener(lista *lista, int posicion){
    // Si la posicion es mayor o igual a la longitud de la lista
    if(posicion >= lista->longitud || posicion < 0){
        // Devolvemos NULL
        return NULL;
    }
    // En caso contrario
    // Creamos un nodo auxiliar
    Nodo *aux = lista->primero;
    // Recorremos la lista hasta la posicion indicada
    for(int i = 0; i < posicion; i++){
        // Asignamos el siguiente nodo como nodo actual
        aux = aux->siguiente;
    }
    // Devolvemos el elemento del nodo
    return aux->elemento;
}

// Devolver el primer nodo de la lista. Complejidad: O(1)
Nodo *obtenerPrimero(lista *lista){
    // Devolvemos el primer nodo de la lista
    return lista->primero;
}

// Devolver el ultimo nodo de la lista. Complejidad: O(1)
Nodo *obtenerUltimo(lista *lista){
    // Devolvemos el ultimo nodo de la lista
    return lista->ultimo;
}

// Devolver el nodo en la posicion indicada. Complejidad: O(n)
Nodo *obtenerNodo(lista *lista, int posicion){
    // Si la posicion es mayor o igual a la longitud de la lista
    if(posicion >= lista->longitud || posicion < 0){
        // Devolvemos NULL
        return NULL;
    }
    // En caso contrario
    // Creamos un nodo auxiliar
    Nodo *aux = lista->primero;
    // Recorremos la lista hasta la posicion indicada
    for(int i = 0; i < posicion; i++){
        // Asignamos el siguiente nodo como nodo actual
        aux = aux->siguiente;
    }
    // Devolvemos el nodo
    return aux;
}

// Calcular la cantidad de veces que aparece un elemento en la lista. Complejidad: O(n)
int contar(lista *lista, char *elemento){
    // Si la lista esta vacia
    if(lista->longitud == 0){
        // Devolvemos 0
        return 0;
    }
    // Si la lista no esta vacia
    // Creamos un nodo auxiliar
    Nodo *aux = lista->primero;
    int contador = 0;
    // Mientras el siguiente nodo no sea NULL
    while(aux != NULL){
        // Si el elemento esta en la lista
        if(strcmp(aux->elemento, elemento) == 0){
            // Aumentamos el contador
            contador++;
        }
        // Asignamos el siguiente nodo como nodo actual
        aux = aux->siguiente;
    }
    // Liberamos el nodo
    free(aux);
    // Devolvemos el contador
    return contador;
}