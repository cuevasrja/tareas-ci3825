/*
La pantalla del punto de venta es demasiado pequeña: sólo puede mostrar 5 dígitos y sólo recibe int, 
pero puede desplazar los números hacia la derecha si recibe otro número con el cual reemplazarlo. 
Escriba un programa que reciba un número grande como parámetro de cónsola y lo almacene en un long, 
luego, lo imprima como tantos int como sea necesario para imprimir, separados por \n, y ordenados 
desde el menos significativo al más significativo (para así funcionar correctamente al desplazar 
hacia la derecha). 

Sugerencias
- Puede convertir strings en long usando atol. Encontrará más información sobre estos comandos en el 
apéndice B5
- Puede imprimir long para efectos de diagnóstico usando printf("%ld", v) done v es la variable de 
tipo long. Encontrará más información sobre estos comandos en el apéndice B1.2
- Recuerde que el valor máximo de un int es 32767. Si el residuo es menor a este valor, puede usar 
los 5 dígitos completos de la pantalla
- Recuerde que el resultado de un long y un int es un long (ejemplo: long+int=long)
- Los ciclos en C funcionan como en todos los lenguajes posteriores; no es necesario crear un array de int
*/

#include <stdio.h>

void numero(){
    long numero;
    int i = 0;
    printf("Ingrese un numero: ");
    scanf("%ld", &numero);
    while(numero > 0){
        printf("%d\n", (int)numero%32767);
        numero /= 32767;
    }

}

int main(){
    numero();
    return 0;
}