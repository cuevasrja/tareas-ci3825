/*
Escriba un programa en C para Unix que:
- Cree dos procesos
- Haga que el proceso padre imprima que es el padre
- Haga que el proceso hijo imprima que es el hijo
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void){
    pid_t pid;
    pid = fork();
    if (pid < 0){
        fprintf(stderr, "Fork Failed");
        exit(-1);
    }
    else if (pid == 0){
        printf("Soy el hijo\n");
        printf("Mi PID es: %d\n", getpid());
    }
    else{
        printf("Soy el padre\n");
        printf("Mi PID es: %d\n", getpid());
    }
    return 0;
}