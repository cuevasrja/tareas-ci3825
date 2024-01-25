#include <stdio.h>

void saludar(char *nombre) {
    printf("Hola %s\n", nombre);
}

int main() {
    saludar("Juan");
    saludar("Pedro");
    saludar("Maria");
    return 0;
}