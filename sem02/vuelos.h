/*
Cree un archivo .h para cualquiera de sus programas anteriores que permita que sea 
utilizado en otro programa. Puede requerir separar funcionalidades del main.
*/

#ifndef VUELOS
#define VUELOS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

enum clase;

union terminal;

typedef struct vuelo Vuelo;

Vuelo* crearVuelo(time_t hora_salida, time_t hora_llegada, char* codigoIATA_salida, char* codigoIATA_llegada, union terminal terminal_salida, union terminal terminal_llegada, int puerta_salida, int puerta_llegada, char codigo_vuelo[5], enum clase clase);

void imprimirVuelo(Vuelo *v, int numero);
#endif