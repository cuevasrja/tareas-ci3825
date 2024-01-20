# include <stdio.h>

// Definimos TRUE y FALSE para que sean 1 y 0 respectivamente
# define TRUE (1==1)
# define FALSE !TRUE

int preguntarYoN(){
    // Por casos:
    switch(getc(stdin)){
        // Si es Y o y, devolvemos TRUE
        case 'Y':
        case 'y':
            return TRUE;
        // Si es N o n, devolvemos FALSE
        case 'N':
        case 'n':
            return FALSE;
        // Si no es ninguna de las anteriores, volvemos a preguntar
        default:
            printf("Invalid, try again: ");
            return preguntarYoN();
    }
}

int main() {
    printf("Continue? (y/n): ");
    if (preguntarYoN()) {
        printf("Continuing...\n");
    } else {
        printf("Exiting...\n");
    }
    return 0;
}
