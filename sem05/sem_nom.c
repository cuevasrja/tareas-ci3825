/*
Escriba un programa donde dos hilos escriben en un arreglo compartido y 
controlan su acceso al mismo por medio de Mutex.
Modifique su programa anterior para usar semáforos nombrados y procesos en vez de hilos
*/

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>

#define N 10

int *arreglo;
sem_t *sem;

void *hijo1(void *arg){
    int i;
    for(i = 0; i < N; i++){
        sem_wait(sem);
        arreglo[i] = i;
        sem_post(sem);
        sleep(1);
    }
    pthread_exit(NULL);
}

void *hijo2(void *arg){
    int i;
    for(i = 0; i < N; i++){
        sem_wait(sem);
        printf("%d\n", arreglo[i]);
        sem_post(sem);
        sleep(1);
    }
    pthread_exit(NULL);
}

int main(){
    int fd;
    pthread_t tid1, tid2;
    fd = shm_open("/shm", O_CREAT | O_RDWR, 0600);
    ftruncate(fd, sizeof(int) * N);
    arreglo = (int *)mmap(NULL, sizeof(int) * N, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    sem = sem_open("/sem", O_CREAT, 0600, 1);
    pthread_create(&tid1, NULL, hijo1, NULL);
    pthread_create(&tid2, NULL, hijo2, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    sem_close(sem);
    sem_unlink("/sem");
    munmap(arreglo, sizeof(int) * N);
    shm_unlink("/shm");
    return 0;
}