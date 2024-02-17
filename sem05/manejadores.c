/*
Escriba un programa que imprima cada segundo por 20 segundos 
y sólo pueda ser matado durante 10 de ellos
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

int main(){
    pid_t pid;
    pid = fork();
    if (pid == -1){
        perror("Error al crear el proceso hijo");
        exit(EXIT_FAILURE);
    }
    if (pid == 0){
        // Proceso hijo
        for (int i = 0; i < 20; i++){
            printf("Soy el proceso hijo con PID %d\n", getpid());
            sleep(1);
        }
    } else {
        sleep(10);
        kill(pid, SIGKILL);
    }
    return 0;
}