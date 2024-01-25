/*
Escriba un programa que convierta el texto recibido como parámetro por cónsola a minúsculas o mayúsculas 
(indicado por un segundo parámetro). Cree una función que efectúe el cambio. No suponga que todos los 
caracteres del texto están en mayúsculas o minúsculas.

Sugerencias
- Revise si el caracter que está convirtiendo es menor o mayor que 'a'
- Documente su código en detalle para poder volver a él luego de descansar (no hay puntos por astucia)
- Escriba un mensaje de error usage para los casos en que el usuario no especifique correctamente si 
desea mayúsculas o minúsculas
*/

#include <stdio.h>

void mayMin(char *texto, char *mayMin){
    int i = 0;
    while(texto[i] != '\0'){
        if(mayMin[0] == 'm'){
            if(texto[i] >= 'A' && texto[i] <= 'Z'){
                texto[i] += 32;
            }
        }else if(mayMin[0] == 'M'){
            if(texto[i] >= 'a' && texto[i] <= 'z'){
                texto[i] -= 32;
            }
        }else{
            printf("usage: ./mayMin <texto> <mayMin>\n");
            return;
        }
        i++;
    }
    printf("%s\n", texto);
}

int main(int argc, char *argv[]){
    if(argc != 3){
        printf("usage: ./mayMin <texto> <mayMin>\n");
        return 0;
    }
    mayMin(argv[1], argv[2]);
    return 0;
}