/*
Escriba un programa que fije un manejador para SIGALRM que imprima, 
fije una alarma, y realice impresiones inútiles mientras la espera
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
    alarm(5);
    while(1){
        printf("Esperando...\n");
        sleep(1);
    }
    return 0;
}