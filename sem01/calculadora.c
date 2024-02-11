/*
Calculadora Sencilla
Se desea un programa que reciba cada dígito introducido por el usuario, y muestre el número resultante alineado a la derecha, y su resultado

ejemplo: el usuario presiona 1,7,3,+,5,4,\n
Impresión esperada:

    173
  +  54
  ------
    237

Debe tener soporte para suma '+', resta '-', multipliación '*' y división entera '/'
*/

# include <stdio.h>
# include <stdlib.h>

int pedirNumero(){
    // Variables
    int numero = 0;
    char caracter = ' ';
    printf("Introduce un numero: ");
    // Mientras el caracter introducido no sea un salto de linea
    while((caracter = getc(stdin)) != '\n'){
        // Si el caracter es un numero
        if(caracter >= '0' && caracter <= '9'){
            // Multiplicamos el numero anterior por 10 y le sumamos el nuevo numero
            numero = numero * 10 + atoi(&caracter);
        }
        // Si no es un numero
        else{
            // Mostramos un error
            printf("Error: '%c' no es un numero\n", caracter);
            // Salimos del programa
            return -1;
        }
    }
    // Devolvemos el numero
    return numero;
}

char pedirOperacion(){
    // Variables
    char operacion = ' ';
    // Pedimos la operacion
    printf("Introduce la operacion: ");
    // Mientras el caracter introducido no sea un salto de linea
    while((operacion = getc(stdin)) != '\n'){
        // Si el caracter es un operador
        if(operacion == '+' || operacion == '-' || operacion == '*' || operacion == '/' || operacion == '%' || operacion == '^'){
            // Salimos del bucle
            break;
        }
        // Si no es un operador
        else{
            // Mostramos un error
            printf("Error: '%c' no es un operador\n", operacion);
            // Salimos del programa
            return -1;
        }
    }
    // Devolvemos la operacion
    return operacion;
}

int potencia(int base, int exponente){
    if (exponente == 0) {
        return 1;
    }
    else if (exponente == 1) {
        return base;
    }
    else if (exponente % 2 == 0) {
        return potencia(base * base, exponente / 2);
    }
    else{
        return base * potencia(base * base, (exponente - 1) / 2);
    }
    
}

int operar(int num1, int num2, char operacion){
    // Revisamos los casos de los operadores
    switch(operacion){
        // Si es una suma
        case '+':
            // Sumamos los numeros
            return num1 + num2;
        // Si es una resta
        case '-':
            // Restamos los numeros
            return num1 - num2;
        // Si es una multiplicacion
        case '*':
            // Multiplicamos los numeros
            return num1 * num2;
        // Si es una division
        case '/':
            // Dividimos los numeros
            return num1 / num2;
        // Si es un modulo
        case '%':
            // Hacemos el modulo de los numeros
            return num1 % num2;
        // Si es una potencia
        case '^':
            // Hacemos la potencia de los numeros
            return potencia(num1, num2);
    }
}

void mostrarResultado(int num1, int num2, char operacion, int resultado){
    // Mostramos el primer numero
    printf("%6d\n", num1);
    // Mostramos el operador
    printf("%c%5d\n", operacion, num2);
    // Mostramos la linea
    printf("------\n");
    // Mostramos el resultado
    printf("%6d\n", resultado);
}

int main(){
    // Variables
    int num1 = 0, num2 = 0, resultado = 0;
    char operacion = ' ';
    // Pedimos el primer numero
    num1 = pedirNumero();
    // Si el numero es invalido
    if (num1 == -1) {
        return 1;
    }

    // Pedimos el segundo numero
    num2 = pedirNumero();
    // Si el numero es invalido
    if (num2 == -1) {
        return 1;
    }

    // Pedimos la operacion
    operacion = pedirOperacion();
    // Si la operacion es invalida
    if (operacion == -1) {
        return 1;
    }
    
    resultado = operar(num1, num2, operacion);
    // Mostramos el resultado
    mostrarResultado(num1, num2, operacion, resultado);
    // Salimos del programa
    return 0;
}