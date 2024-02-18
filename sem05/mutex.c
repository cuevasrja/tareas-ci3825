/*
Escriba un programa donde dos hilos escriben en un arreglo compartido y 
controlan su acceso al mismo por medio de Mutex
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define N 10

int arreglo[N];
pthread_mutex_t mutex;

void *hilo1(void *arg){
    int i;
    for(i = 0; i < N; i++){
        pthread_mutex_lock(&mutex);
        arreglo[i] = i;
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    pthread_exit(NULL);
}

void *hilo2(void *arg){
    int i;
    for(i = 0; i < N; i++){
        pthread_mutex_lock(&mutex);
        printf("%d\n", arreglo[i]);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    pthread_exit(NULL);
}

int main(){
    pthread_t tid1, tid2;
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&tid1, NULL, hilo1, NULL);
    pthread_create(&tid2, NULL, hilo2, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_mutex_destroy(&mutex);
    return 0;
}