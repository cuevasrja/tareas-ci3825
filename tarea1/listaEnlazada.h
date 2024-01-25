#ifndef LISTAENLAZADA
#define LISTAENLAZADA

// Estructura de un nodo
typedef struct nodo{
    char *elemento;
    struct nodo *siguiente;
} Nodo;

// Constructor de un nodo
Nodo *nuevoNodo(char *elemento);

// Definimos las funciones del nodo
// Devolver el elemento del nodo. Complejidad: O(1)
char *obtenerElemento(Nodo *nodo);
// Devolver el siguiente nodo. Complejidad: O(1)
Nodo *obtenerSiguiente(Nodo *nodo);
// Asignar el elemento del nodo. Complejidad: O(1)
void asignarElemento(Nodo *nodo, char *elemento);
// Asignar el siguiente nodo. Complejidad: O(1)
void asignarSiguiente(Nodo *n, Nodo *sig);

// Estructura de la lista enlazada
// Creamos la estructura de una lista
typedef struct lista{
    Nodo *primero;
    Nodo *ultimo;
    int longitud;
} lista;

// Constructor de una lista
lista *nuevaLista();

// Definimos las funciones de la lista
// Agregar un elemento a la lista. Complejidad: O(1)
void agregar(lista *lista, char *elemento);
// Eliminar un elemento de la lista. Complejidad: O(n)
void eliminar(lista *lista, char *elemento);
// Decidir si la lista esta vacia. Complejidad: O(1)
int estaVacia(lista *lista);
// Mostrar la lista. Complejidad: O(n)
void mostrarLista(lista *lista);
// Revisar si un elemento esta en la lista. Complejidad: O(n)
int esta(lista *lista, char *elemento);
// Devolver la longitud de la lista. Complejidad: O(1)
int longitud(lista *lista);
// Devolver el primer elemento de la lista. Complejidad: O(1)
char *primero(lista *lista);
// Devolver el ultimo elemento de la lista. Complejidad: O(1)
char *ultimo(lista *lista);
// Devolver el elemento en la posicion indicada. Complejidad: O(n)
char *obtener(lista *lista, int posicion);
// Devolver el primer nodo de la lista. Complejidad: O(1)
Nodo *obtenerPrimero(lista *lista);
// Devolver el ultimo nodo de la lista. Complejidad: O(1)
Nodo *obtenerUltimo(lista *lista);
// Devolver el nodo en la posicion indicada. Complejidad: O(n)
Nodo *obtenerNodo(lista *lista, int posicion);
// Calcular la cantidad de veces que aparece un elemento en la lista. Complejidad: O(n)
int contar(lista *lista, char *elemento);
#endif