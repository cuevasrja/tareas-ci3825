/*
Escriba un programa que pida al usuario la fecha y hora de su vuelo, 
e imprima cuántos minutos, horas, días, meses y (si aplica) años, 
faltan para el mismo.

Sugerencias
- Puede obtener la diferencia entre ambas fecha-horas con difftime
- El resultado de difftime, a pesar de ser un double, también está 
en segundos, por lo que puede ser casteado a time_t para pasárselo 
a localtime; sin embargo, obsérvese que el resultado 5,1 millones 
(59 días, 40 minutos) será convertido a 2 meses y 40 minuts, ya 
que uno de esos meses es febrero de 1970.
*/

#include <stdio.h>
#include <time.h>

int main() {
    time_t ahora = time(NULL);
    struct tm *ahora_tm = localtime(&ahora);

    int anio, mes, dia, hora, minuto;
    printf("Ingrese la fecha y hora de su vuelo (AAAA MM DD hh mm): ");
    scanf("%d %d %d %d %d", &anio, &mes, &dia, &hora, &minuto);

    struct tm vuelo_tm = {
        .tm_year = anio - 1900,
        .tm_mon = mes - 1,
        .tm_mday = dia,
        .tm_hour = hora,
        .tm_min = minuto,
    };

    time_t vuelo = mktime(&vuelo_tm);
    double diferencia = difftime(vuelo, ahora);

    int dias = diferencia / 86400;
    int horas = (diferencia - dias * 86400) / 3600;
    int minutos = (diferencia - dias * 86400 - horas * 3600) / 60;

    printf("Faltan %d dias, %d horas y %d minutos\n", dias, horas, minutos);

    return 0;
}