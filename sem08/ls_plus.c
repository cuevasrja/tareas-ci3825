/*
Linus Torvalds ha decidido que el comando ls -l (List files, long) no es lo suficientemente "long". 
Escriba un programa que enumere todos los atributos en stat.h para cada archivo del directorio 
actual en un formato compacto
*/

#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char *argv[]) {
    struct stat fileStat;
    struct dirent *dir;
    DIR *d;
    if(argc != 1) {
        printf("Uso: %s\n", argv[0]);
        return 1;
    }
    d = opendir(".");
    if(d == NULL) {
        perror(".");
        return 2;
    }
    while((dir = readdir(d)) != NULL) {
        if(stat(dir->d_name,&fileStat) < 0) {
            perror(dir->d_name);
            return 3;
        }
        printf("%s\t%ld\t%ld\t%d\t%ld\t%d\t%d\t%ld\t%ld\t%ld\t%ld\t%ld\t%ld\n",dir->d_name,fileStat.st_dev,fileStat.st_ino,fileStat.st_mode,fileStat.st_nlink,fileStat.st_uid,fileStat.st_gid,fileStat.st_rdev,fileStat.st_size,fileStat.st_blksize,fileStat.st_blocks,fileStat.st_atime,fileStat.st_mtime);
    }
    closedir(d);
    return 0;
}