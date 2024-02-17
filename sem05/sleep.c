/*
Escriba un programa que fije un manejador para SIGALRM que imprima, 
fije una alarma, y realice impresiones inútiles mientras la espera
Modifique el programa anterior para simular "alarm" usando "raise" 
y "sleep"
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

void manejador(int sig){
    printf("Alarma recibida\n");
}

int main(){
    signal(SIGALRM, manejador);
    while(1){
        printf("Esperando...\n");
        sleep(1);
        raise(SIGALRM);
    }
    return 0;
}