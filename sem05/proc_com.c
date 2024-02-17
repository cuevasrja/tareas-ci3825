/*
Escriba un programa donde el padre mata al hijo por medio de la función kill 
luego de una pausa. Para asegurarse de que el proceso, en efecto, termine, 
haga que el hijo imprima constantemente.
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
        while(1){
            printf("Soy el proceso hijo con PID %d\n", getpid());
            sleep(1);
        }
    } else {
        sleep(5);
        kill(pid, SIGKILL);
    }
    return 0;
}