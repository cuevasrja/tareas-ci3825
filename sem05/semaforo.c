/*
Escriba un programa donde dos hilos escriben en un arreglo compartido y 
controlan su acceso al mismo por medio de Mutex.
Modifique su programa anterior para usar semáforos en vez de mutex
*/
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 10

int arreglo[N];
sem_t sem;

void *hilo1(void *arg){
    int i;
    for(i = 0; i < N; i++){
        sem_wait(&sem);
        arreglo[i] = i;
        sem_post(&sem);
        sleep(1);
    }
    pthread_exit(NULL);
}

void *hilo2(void *arg){
    int i;
    for(i = 0; i < N; i++){
        sem_wait(&sem);
        printf("%d\n", arreglo[i]);
        sem_post(&sem);
        sleep(1);
    }
    pthread_exit(NULL);
}

int main(){
    pthread_t tid1, tid2;
    sem_init(&sem, 0, 1);
    pthread_create(&tid1, NULL, hilo1, NULL);
    pthread_create(&tid2, NULL, hilo2, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    sem_destroy(&sem);
    return 0;
}