#include <stdio.h>
#include <stdlib.h>

/**
 * Escriba un programa que solicite el nombre en formato "apellido, nombre" usando scanf, 
 * y luego escriba "Hola" seguido del nombre introducido en el orden "nombre apellido"
 * 
 * Ejemplo:
 * Ingrese su nombre y apellido en el siguiente formato: Apellido, Nombre
 * Perez, Juan
 * Hola Juan Perez
*/

void saludar(){
    char* nombre = (char*)malloc(sizeof(char)*100), *apellido = (char*)malloc(sizeof(char)*100);
    printf("Ingrese su nombre y apellido en el siguiente formato: Apellido, Nombre\n");
    scanf("%[^,], %s", apellido, nombre);
    printf("Hola %s %s\n", nombre, apellido);
}

int main() {
    saludar();
    return 0;
}