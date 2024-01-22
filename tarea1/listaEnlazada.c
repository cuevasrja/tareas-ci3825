# include <stdio.h>
# include <stdlib.h>

// Creamos la estructura de un nodo
typedef struct nodo{
    char *elemento;
    struct nodo *siguiente;
} nodo;

// Definimos el constructor del nodo
nodo *nuevoNodo(char *elemento){
    // Reservamos memoria para el nodo
    nodo *nuevo = malloc(sizeof(nodo));
    // Asignamos el elemento al nodo
    nuevo->elemento = elemento;
    // Asignamos el siguiente nodo a NULL
    nuevo->siguiente = NULL;
    // Devolvemos el nodo
    return nuevo;
}

// Definimos las funciones del nodo

// Devolver el elemento del nodo. Complejidad: O(1)
char *obtenerElemento(nodo *nodo){
    // Devolvemos el elemento del nodo
    return nodo->elemento;
}

// Devolver el siguiente nodo. Complejidad: O(1)
nodo *obtenerSiguiente(nodo *nodo){
    // Devolvemos el siguiente nodo
    return nodo->siguiente;
}

// Asignar el elemento del nodo. Complejidad: O(1)
void asignarElemento(nodo *nodo, char *elemento){
    // Asignamos el elemento al nodo
    nodo->elemento = elemento;
}

// Asignar el siguiente nodo. Complejidad: O(1)
void asignarSiguiente(nodo *n, nodo *sig){
    // Asignamos el siguiente nodo
    n->siguiente = sig;
}

// Creamos la estructura de una lista
typedef struct lista{
    nodo *primero;
    nodo *ultimo;
    int longitud;
} lista;

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
    nodo *nuevo = nuevoNodo(elemento);
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
    if(lista->longitud == 0){
        // Salimos de la funcion
        return;
    }
    // Si la lista no esta vacia
    
    // Creamos un nodo auxiliar
    nodo *aux = lista->primero;
    // Si el elemento a eliminar es el primero
    if(aux->elemento == elemento){
        // Asignamos el segundo nodo como primero
        lista->primero = aux->siguiente;
        // Liberamos el nodo
        free(aux);
        // Reducimos la longitud de la lista
        lista->longitud--;
    }
    // Si el elemento a eliminar no es el primero
    else{
        // Mientras el siguiente nodo no sea NULL
        while(aux->siguiente != NULL){
            // Si el siguiente nodo es el elemento a eliminar
            if(aux->siguiente->elemento == elemento){
                // Creamos un nodo auxiliar para el nodo a eliminar
                nodo *aux2 = aux->siguiente;
                // Asignamos el siguiente nodo como siguiente del nodo a eliminar
                aux->siguiente = aux->siguiente->siguiente;
                // Liberamos el nodo
                free(aux2);
                // Reducimos la longitud de la lista
                lista->longitud--;
                // Salimos del ciclo
                return;
            }
            // Si el siguiente nodo no es el elemento a eliminar
            else{
                // Asignamos el siguiente nodo como nodo actual
                aux = aux->siguiente;
            }
        }
    }
}

// Decidir si la lista esta vacia. Complejidad: O(1)
int estaVacia(lista *lista){
    // Si la lista esta vacia
    if(lista->longitud == 0){
        // Devolvemos 1
        return 1;
    }
    // Si la lista no esta vacia
    else{
        // Devolvemos 0
        return 0;
    }
}

// Mostrar la lista. Complejidad: O(n)
void mostrarLista(lista *lista){
    // Si la lista esta vacia
    if (estaVacia(lista)){
        return;
    }
    // Si la lista no esta vacia
    // Creamos un nodo auxiliar
    nodo *aux = lista->primero;
    int i = 1;
    // Mientras el siguiente nodo no sea NULL
    while(aux->siguiente != NULL){
        // Mostramos el elemento del nodo
        printf("\033[92m%d.\033[0m %s\n", i, aux->elemento);
        // Asignamos el siguiente nodo como nodo actual
        aux = aux->siguiente;
        // Aumentamos el contador
        i++;
    }
    // Mostramos el elemento del nodo
    printf("\033[92m%d.\033[0m %s\n", i, aux->elemento);
}

// Revisar si un elemento esta en la lista. Complejidad: O(n)
int esta(lista *lista, char *elemento){
    // Si la lista esta vacia
    if(lista->longitud == 0){
        // Devolvemos 0
        return 0;
    }
    // Si la lista no esta vacia
    else{
        // Creamos un nodo auxiliar
        nodo *aux = lista->primero;
        // Mientras el siguiente nodo no sea NULL
        while(aux->siguiente != NULL){
            // Si el elemento esta en la lista
            if(aux->elemento == elemento){
                // Devolvemos 1
                return 1;
            }
            // Asignamos el siguiente nodo como nodo actual
            aux = aux->siguiente;
        }
        // Si el ultimo elemento esta en la lista
        if(aux->elemento == elemento){
            // Devolvemos 1
            return 1;
        }
    }
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
    nodo *aux = lista->primero;
    // Recorremos la lista hasta la posicion indicada
    for(int i = 0; i < posicion; i++){
        // Asignamos el siguiente nodo como nodo actual
        aux = aux->siguiente;
    }
    // Devolvemos el elemento del nodo
    return aux->elemento;
}

// Devolver el primer nodo de la lista. Complejidad: O(1)
nodo *obtenerPrimero(lista *lista){
    // Devolvemos el primer nodo de la lista
    return lista->primero;
}

// Devolver el ultimo nodo de la lista. Complejidad: O(1)
nodo *obtenerUltimo(lista *lista){
    // Devolvemos el ultimo nodo de la lista
    return lista->ultimo;
}

// Devolver el nodo en la posicion indicada. Complejidad: O(n)
nodo *obtenerNodo(lista *lista, int posicion){
    // Si la posicion es mayor o igual a la longitud de la lista
    if(posicion >= lista->longitud || posicion < 0){
        // Devolvemos NULL
        return NULL;
    }
    // En caso contrario
    // Creamos un nodo auxiliar
    nodo *aux = lista->primero;
    // Recorremos la lista hasta la posicion indicada
    for(int i = 0; i < posicion; i++){
        // Asignamos el siguiente nodo como nodo actual
        aux = aux->siguiente;
    }
    // Devolvemos el nodo
    return aux;
}