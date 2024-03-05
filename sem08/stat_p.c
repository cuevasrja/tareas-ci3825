/*
Escriba un programa que reciba un archivo e imprima todos los miembros de stat.h para ese archivo
*/

#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    struct stat fileStat;
    if(argc != 2) {
        printf("Uso: %s <archivo>\n", argv[0]);
        return 1;
    }
    if(stat(argv[1],&fileStat) < 0) {
        perror(argv[1]);
        return 2;
    }

    printf("Información para %s\n",argv[1]);
    printf("---------------------------\n");
    printf("ID del dispositivo: \t\t%ld\n",fileStat.st_dev);
    printf("Número de i-nodo: \t\t%ld\n",fileStat.st_ino);
    printf("Modo: \t\t\t\t%d\n",fileStat.st_mode);
    printf("Número de enlaces duros: \t%ld\n",fileStat.st_nlink);
    printf("ID de usuario: \t\t\t%d\n",fileStat.st_uid);
    printf("ID de grupo: \t\t\t%d\n",fileStat.st_gid);
    printf("ID del dispositivo (si es especial): %ld\n",fileStat.st_rdev);
    printf("Tamaño total en bytes: \t\t%ld\n",fileStat.st_size);
    printf("Bloque de asignación: \t\t%ld\n",fileStat.st_blksize);
    printf("Número de bloques asignados: \t%ld\n",fileStat.st_blocks);
    printf("Hora del último acceso: \t\t%ld\n",fileStat.st_atime);
    printf("Hora de la última modificación: \t%ld\n",fileStat.st_mtime);
    printf("Hora del último cambio: \t\t%ld\n",fileStat.st_ctime);

    return 0;
}