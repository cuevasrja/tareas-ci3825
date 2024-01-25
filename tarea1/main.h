#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "pikachu.h"

int MAX_RELACION;

char* menu[] = {
    "Salir",
    "Jugar",
    "Usar item",
    "Saludar",
    "Ir a la tienda",
    "Mostrar inventario",
};

int cantidadOpciones;

char* itemsTienda[] = {
    "Baya",
    "Bayamarga",
    "Pokeball",
    "Antiparabaya",
    "Baya misterio",
    "Baya milagro",
    "Baya dorada",
    "Baya importada",
    "Caramelo Raro",
    "Gorra de Ash",
};

int cantidadItemsTienda;

int wattsTienda[] = {
    100,
    200,
    300,
    400,
    500,
    600,
    700,
    800,
    900,
    1500,
};

int relacionTienda[] = {
    100,
    250,
    400,
    550,
    700,
    850,
    1000,
    1150,
    1300,
    5000,
};

int buscarTienda(char* arr[], char* item);
int buscarMenu(char* arr[], char* item);
char* minusculas(char* str);
void bienvenida();
char* pedirNombre();
void mostrarMenu();
void mostrarInfo(int watts, int relacionPts);
int leerOpcion();
int actualizarWatts(time_t ultimaActualizacion, time_t ahora);
void mostrarTienda(int watts);
int leerItem();
void comprar(lista *consumibles, int *watts, Pikachu *pikachu);
void mostrarPikachu(Pikachu *pikachu);
lista* listaSinRepetidos(lista *consumibles);
char* leerInventario(lista *consumibles);
char* preguntarItem(lista *items);
void usarElemento(lista *consumibles, Pikachu *pikachu, char* itemSeleccionado);
int pedirApuesta(int watts);
void compararItems(char* itemRandom, char* itemSeleccionado, Pikachu *pikachu, int *watts, int apuesta);
void mostrarInventario(lista *consumibles);

int main();
#endif