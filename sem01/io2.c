#include <stdio.h>
#include <stdlib.h>

// Definimos la macro SO para saber si estamos en Windows o Linux
#ifdef _WIN32
#define SO "Windows"
#else __linux__
#define SO "Linux"
#endif

int main(void){
    printf("Escribe un caracter: ");
    
    // En Windows, usamos pause
    if (strcmp(SO, "Windows") == 0){
        system("pause");
    }
    // En Linux, usamos read
    else{
        system("read x");
    }
    
    return 0;
}