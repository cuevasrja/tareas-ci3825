/*
Escriba un programa que cree dos hijos: uno que ejecute ls en el directorio actual,
 y otro que lo ejecute en el directorio padre (el directorio "..")
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t pid;
    int status;

    if ((pid = fork()) == 0) {
        execl("/bin/ls", "ls", NULL);
        exit(0);
    }

    if ((pid = fork()) == 0) {
        execl("/bin/ls", "ls", "..", NULL);
        exit(0);
    }

    wait(&status);
    wait(&status);

    return 0;
}