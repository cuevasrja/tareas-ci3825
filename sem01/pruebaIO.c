# include <stdio.h>

int main(){
    // Diferencia entre system("read"), getc(), getchar(), scanf(), putc(), putchar() y printf()
    // system("read") -> Espera a que el usuario pulse enter
    // getc() -> Lee un caracter del buffer de entrada
    // getchar() -> Lee un caracter del buffer de entrada
    // scanf() -> Lee un caracter del buffer de entrada
    // putc() -> Escribe un caracter en el buffer de salida
    // putchar() -> Escribe un caracter en el buffer de salida
    // printf() -> Escribe un caracter en el buffer de salida

    printf("Escribe un caracter: ");
    char c = getc(stdin);
    printf("El caracter es: %c\n", c);
    return 0;
}