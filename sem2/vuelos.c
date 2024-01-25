/*
Defina un programa que pueda almacenar una secuencia de vuelos 
entre las Américas (donde los aeropuertos usan letras para 
definir en qué terminal queda la puerta) y Europa (donde los 
aeropuertos usan números para definirlo). Suponga que los 
vuelos son tomados por la misma persona y que no hay vuelos 
sin registrar y que sólo viaja entre américa y europa; así, 
por ejemplo, si el usuario indica que la secuencia es de 3 vuelos,

- El primero sería de américa a europa
- El segundo sería de europa a américa
- El tercero sería de américa a europa

Una vez que se han guardado todos los vuelos, imprima el itinerario 
de vuelos en formato de pase de abordo. Se muestra un formato de 
ejemplo a continuación:

VUELO 1
Salida  Llegada Vuelo   Clase   Puesto
CCS     FRA     LH714   ECON    21K
Hora de abordo                  Puerta Salida
Sun Jan 23 17:50:00 2021        I14
Hora de llegada                 Puerta Llegada
Mon Jan 24 06:55:30 2021        T1 P88

Sugerencias
- Adapte el código de las actividades anteriores.
- Diseñe un struct que use union y/o vice-versa. 
Recuerde que pueden contener miembros que sean structs.
- Asigne un arreglo de structs utilizando malloc o 
calloc y luego recórralo.
- Puede suponer que al menos una de las ciudades es la 
misma que en el vuelo anterior.
- El formato de impresión para la hora mostrado es el 
de ctime o asctime.
- Utilice tabuladores (\t) para alinear el texto.
*/

#include "vuelos.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_VUELOS 100

enum clase {
    ECONOMICA,
    EJECUTIVA,
};

union terminal {
    char letra;
    int numero;
};

typedef struct vuelo{
    time_t hora_salida;
    time_t hora_llegada;
    char* codigoIATA_salida;
    char* codigoIATA_llegada;
    union terminal terminal_salida;
    union terminal terminal_llegada;
    int puerta_salida;
    int puerta_llegada;
    char codigo_vuelo[5];
    enum clase clase;

} Vuelo;

Vuelo *crearVuelo(time_t hora_salida, time_t hora_llegada, char* codigoIATA_salida, char* codigoIATA_llegada, union terminal terminal_salida, union terminal terminal_llegada, int puerta_salida, int puerta_llegada, char codigo_vuelo[5], enum clase clase){
    Vuelo *v = malloc(sizeof(Vuelo));
    v->hora_salida = hora_salida;
    v->hora_llegada = hora_llegada;
    v->codigoIATA_salida = malloc(strlen(codigoIATA_salida) + 1);
    strcpy(v->codigoIATA_salida, codigoIATA_salida);
    v->codigoIATA_llegada = malloc(strlen(codigoIATA_llegada) + 1);
    strcpy(v->codigoIATA_llegada, codigoIATA_llegada);
    v->terminal_salida = terminal_salida;
    v->terminal_llegada = terminal_llegada;
    v->puerta_salida = puerta_salida;
    v->puerta_llegada = puerta_llegada;
    strcpy(v->codigo_vuelo, codigo_vuelo);
    v->clase = clase;
    return v;
}

void imprimirVuelo(Vuelo *v, int numero){
    printf("VUELO %d\n", numero);
    printf("Salida\tLlegada\tVuelo\tClase\tPuesto\n");
    printf("%s\t%s\t%s\t%s\t%d%c\n", v->codigoIATA_salida, v->codigoIATA_llegada, v->codigo_vuelo, v->clase == ECONOMICA ? "ECON" : "EJEC", 21, 'K');
    printf("Hora de abordo\t\t\t\tPuerta Salida\n");
    printf("%s\t\t\t\t%d%c\n", ctime(&v->hora_salida), v->puerta_salida, v->terminal_salida.letra ? v->terminal_salida.letra : v->terminal_salida.numero);
    printf("Hora de llegada\t\t\t\tPuerta Llegada\n");
    printf("%s\t\t\t\t%d%c\n", ctime(&v->hora_llegada), v->puerta_llegada, v->terminal_llegada.letra ? v->terminal_llegada.letra : v->terminal_llegada.numero);

}

int main(){
    int n;
    printf("Ingrese la cantidad de vuelos: ");
    scanf("%d", &n);
    Vuelo *vuelos[n];
    for (int i = 0; i < n; i++){
        time_t hora_salida, hora_llegada;
        int anio_s, mes_s, dia_s, hora_s, minuto_s;
        int anio_l, mes_l, dia_l, hora_l, minuto_l;
        char *codigoIATA_salida = malloc(sizeof(char) * 3), *codigoIATA_llegada = malloc(sizeof(char) * 3);
        union terminal terminal_salida, terminal_llegada;
        int puerta_salida, puerta_llegada;
        char codigo_vuelo[5];
        enum clase clase;
        printf("Vuelo %d\n", i+1);
        printf("Hora de salida (AAAA MM DD hh mm): ");
        scanf("%i %i %i %i %i", &anio_s, &mes_s, &dia_s, &hora_s, &minuto_s);
        printf("Hora de llegada (AAAA MM DD hh mm): ");
        scanf("%i %i %i %i %i", &anio_l, &mes_l, &dia_l, &hora_l, &minuto_l);
        // Convertimos los enteros a time_t
        struct tm tm_salida = {
            .tm_year = anio_s - 1900,
            .tm_mon = mes_s - 1,
            .tm_mday = dia_s,
            .tm_hour = hora_s,
            .tm_min = minuto_s,
        };
        struct tm tm_llegada = {
            .tm_year = anio_l - 1900,
            .tm_mon = mes_l - 1,
            .tm_mday = dia_l,
            .tm_hour = hora_l,
            .tm_min = minuto_l,
        };
        hora_salida = mktime(&tm_salida);
        hora_llegada = mktime(&tm_llegada);
        printf("Codigo IATA de salida: ");
        scanf("%s", codigoIATA_salida);
        printf("Codigo IATA de llegada: ");
        scanf("%s", codigoIATA_llegada);
        printf("Terminal de salida (L para letra, N para numero): ");
        char tipo_terminal_salida;
        scanf(" %c", &tipo_terminal_salida);
        if (tipo_terminal_salida == 'L'){
            printf("Letra de la terminal de salida: ");
            scanf(" %c", &terminal_salida.letra);
        } else {
            printf("Numero de la terminal de salida: ");
            scanf("%d", &terminal_salida.numero);
        }
        printf("Terminal de llegada (L para letra, N para numero): ");
        char tipo_terminal_llegada;
        scanf(" %c", &tipo_terminal_llegada);
        if (tipo_terminal_llegada == 'L'){
            printf("Letra de la terminal de llegada: ");
            scanf(" %c", &terminal_llegada.letra);
        } else {
            printf("Numero de la terminal de llegada: ");
            scanf("%d", &terminal_llegada.numero);
        }
        printf("Puerta de salida: ");
        scanf("%d", &puerta_salida);
        printf("Puerta de llegada: ");
        scanf("%d", &puerta_llegada);
        printf("Codigo de vuelo: ");
        scanf("%s", codigo_vuelo);
        printf("Clase (E para economica, J para ejecutiva): ");
        char tipo_clase;
        scanf(" %c", &tipo_clase);
        if (tipo_clase == 'E'){
            clase = ECONOMICA;
        } else {
            clase = EJECUTIVA;
        }
        vuelos[i] = crearVuelo(hora_salida, hora_llegada, codigoIATA_salida, codigoIATA_llegada, terminal_salida, terminal_llegada, puerta_salida, puerta_llegada, codigo_vuelo, clase);
    }

    printf("\nItinerario de vuelos:\n");

    for (int i = 0; i < n; i++){
        imprimirVuelo(vuelos[i], i+1);
    }
    return 0;
}