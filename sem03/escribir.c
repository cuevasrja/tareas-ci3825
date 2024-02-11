/*
Escriba un programa que tome todo lo que reciba por cónsola y lo escriba en un archivo 
(el nombre del archivo pasado previamente por cónsola).

Si recibe una línea en blanco, el programa debe imprimir todo lo que está en el archivo 
y terminar
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    FILE *f;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    // Verificar argumentos
    if (argc != 2) {
        printf("Uso: %s <archivo>\n", argv[0]);
        return 1;
    }
    
    // Abrir archivo (Si no existe, lo crea. Si existe, lo sobreescribe)
    f = fopen(argv[1], "w");
    if (f == NULL) {
        printf("No se pudo abrir el archivo\n");
        return 1;
    }

    // Leer de stdin y escribir en el archivo
    printf("Ingrese texto (línea en blanco para terminar):\n");
    while ((read = getline(&line, &len, stdin)) != -1) {
        // Si la línea es en blanco, terminar
        if (read == 1) {
            break;
        }
        fwrite(line, 1, read, f);
    }

    fclose(f);

    f = fopen(argv[1], "r");
    if (f == NULL) {
        printf("No se pudo abrir el archivo\n");
        return 1;
    }

    while ((read = getline(&line, &len, f)) != -1) {
        fwrite(line, 1, read, stdout);
    }

    fclose(f);
    free(line);

    return 0;
}