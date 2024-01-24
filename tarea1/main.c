#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "pikachu.c"
#include "pikachus_ascii.c"

int MAX_RELACION = 10000;

char* menu[] = {
    "Salir",
    "Jugar",
    "Usar item",
    "Saludar",
    "Ir a la tienda",
};

int cantidadOpciones = sizeof(menu) / sizeof(menu[0]);

char* itemsTienda[] = {
    "Baya",
    "Bayamarga",
    "Pokeball",
    "Antiparabaya",
    "Baya misterio",
    "Baya milagro",
    "Baya dorada",
    "Baya importada",
    "Caramelo Raro",
    "Gorra de Ash",
};

int cantidadItemsTienda = sizeof(itemsTienda) / sizeof(itemsTienda[0]);

int wattsTienda[] = {
    100,
    200,
    300,
    400,
    500,
    600,
    700,
    800,
    900,
    1500,
};

int relacionTienda[] = {
    100,
    250,
    400,
    550,
    700,
    850,
    1000,
    1150,
    1300,
    5000,
};

int buscar(char* arr[], char* item){
    for (int i = 0; i < cantidadItemsTienda; i++){
        if (strcmp(arr[i], item) == 0) return i;
    }
    return -1;
}

void bienvenida(){
    printf("\033[1mBienvenido a...\n");
    /*   
    Imprimimos el siguiente ASCII Art de color amarillo

    
  ______  __  __  __   ______  ______  __  __  __  __    
 /\  == \/\ \/\ \/ /  /\  __ \/\  ___\/\ \_\ \/\ \/\ \   
 \ \  _-/\ \ \ \  _"-.\ \  __ \ \ \___\ \  __ \ \ \_\ \  
  \ \_\   \ \_\ \_\ \_\\ \_\ \_\ \_____\ \_\ \_\ \_____\ 
   \/_/    \/_/\/_/\/_/ \/_/\/_/\/_____/\/_/\/_/\/_____/ 
                                                        
    */
    printf("\033[93m");
    printf(" ______  __  __  __   ______  ______  __  __  __  __    \n");
    printf("/\\  == \\/\\ \\/\\ \\/ /  /\\  __ \\/\\  ___\\/\\ \\_\\ \\/\\ \\/\\ \\   \n");
    printf("\\ \\  _ -\\ \\ \\ \\  _\"-.\\ \\  __ \\ \\ \\___\\ \\  __ \\ \\ \\_\\ \\  \n");
    printf(" \\ \\_\\   \\ \\_\\ \\_\\ \\_\\\\ \\_\\ \\_\\ \\_____\\ \\_\\ \\_\\ \\_____\\ \n");
    printf("  \\/_/    \\/_/\\/_/\\/_/ \\/_/\\/_/\\/_____/\\/_/\\/_/\\/_____/ \n");
    printf("\033[0m \n");
    
}

char* pedirNombre(){
    char* nombre = malloc(100 * sizeof(char)); // Asigna memoria para 100 caracteres
    char opcion = 'n';
    printf("Quieres ponerle un nombre a tu Pikachu? (s/n): \033[92;1m");
    scanf(" %c", &opcion);
    printf("\033[0m");
    if (opcion == 's'){
        printf("Como quieres llamarlo? \033[92;1m");
        scanf("%s", nombre);
        printf("\033[0m");
        return nombre;
    }
    free(nombre); // Libera la memoria si no se usa
    return "Pikachu";
}

void mostrarMenu(){
    for (int i = 0; i < cantidadOpciones; i++){
        printf("\033[92m%d.\033[0m %s\n", i, menu[i]);
    }
}

void mostrarInfo(int watts, int relacionPts){
    printf("--------------------\n");
    printf("\033[92mWatts\033[0m: %d\n", watts);
    printf("\033[92mRelacion\033[0m: %d/%d\n", relacionPts, MAX_RELACION);
    printf("--------------------\n");
}

int leerOpcion(){
    int opcion = -1;
    printf("Ingrese una opcion (Escriba el numero de la opcion): \033[92;1m");
    scanf("%d", &opcion);
    printf("\033[0m");
    if (opcion < 0 || opcion >= cantidadOpciones){
        printf("\033[91mOpcion invalida\033[0m\n");
        opcion = leerOpcion();
    }
    printf("\n");
    return opcion;
}

int actualizarWatts(time_t ultimaActualizacion, time_t ahora){
    return (int) difftime(ahora, ultimaActualizacion);
}

void mostrarTienda(int watts){
    printf("Bienvenido a la tienda!\n");
    printf("Tienes \033[92m%d Watts\033[0m\n", watts);
    printf("Estos son los items disponibles:\n");
    for (int i = 0; i < cantidadItemsTienda; i++){
        printf("\033[92m%d. \033[0;1m%s\033[0m - \033[94m%d Watts\033[0m - \033[95m%d Puntos de relacion\033[0m\n", i+1, itemsTienda[i], wattsTienda[i], relacionTienda[i]);
    }
}

int leerItem(){
    int opcion = 0;
    printf("Ingrese una opcion (Escriba el numero de la opcion): \033[92;1m");
    scanf("%d", &opcion);
    printf("\033[0m");
    while (opcion < 1 || opcion > cantidadItemsTienda){
        printf("\033[91mOpcion invalida\033[0m\n");
        printf("Ingrese una opcion (Escriba el numero de la opcion): \033[92;1m");
        scanf("%d", &opcion);
        printf("\033[0m");
    }
    printf("\n");
    return opcion - 1;
}

void comprar(lista *consumibles, int *watts, Pikachu *pikachu){
    printf("Que item quieres comprar? ");
    int item = leerItem();

    if (*watts < wattsTienda[item]){
        printf("\033[91mNo tienes suficientes watts\033[0m\n");
        return;
    }

    *watts -= wattsTienda[item];
    agregar(consumibles, itemsTienda[item]);
    printf("\033[92mHas comprado %s\033[0m\n", itemsTienda[item]);
}

void mostrarPikachu(Pikachu *pikachu){
    int relacionPts = obtenerRelacion(pikachu);
    if (relacionPts < 2500){
        pikachuTriste();
    } else if (relacionPts < 5000){
        pikachuFeliz();
    } else if (relacionPts < 7500){
        pikachuMuyFeliz();
    } else {
        if (usoElemento(pikachu, itemsTienda[9])){ 
            pikachuConGorra();
            hablar(pikachu, "Pika pika! (Gracias por la gorra!)");
        }
        else pikachuAmoroso();
    }
    hablar(pikachu, "Pika pika! (Hola!)");
}

lista* listaSinRepetidos(lista *consumibles){
    lista* items = nuevaLista();
    int n = longitud(consumibles);
    nodo *node = obtenerPrimero(consumibles);
    while (node != NULL){
        if (!esta(items, node->elemento)){
            agregar(items, node->elemento);
        }
        node = node->siguiente;
    }
    return items;
}

int leerInventario(lista *consumibles){
    int opcion = 0;
    printf("Ingrese una opcion (Escriba el numero de la opcion): \033[92;1m");
    scanf("%d", &opcion);
    printf("\033[0m");
    int n = longitud(consumibles);
    while (opcion < 1 || opcion > n){
        printf("\033[91mOpcion invalida\033[0m\n");
        printf("Ingrese una opcion (Escriba el numero de la opcion): \033[92;1m");
        scanf("%d", &opcion);
        printf("\033[0m");
    }
    printf("\n");
    return opcion - 1;
}

char* preguntarItem(lista *items){
    printf("Que item quieres usar? ");
    int item = leerInventario(items);
    return obtener(items, item);
}

void usarElemento(lista *consumibles, Pikachu *pikachu, char* itemSeleccionado){
    int i = buscar(itemsTienda, itemSeleccionado);
    int aumento = 0;
    if (obtenerRelacion(pikachu) == 10000){
        printf("\033[91mTu relacion ya es maxima\033[0m\n");
    }
    else if (relacionTienda[i] + obtenerRelacion(pikachu) > 10000){
        printf("\033[91mTu relacion ya es maxima\033[0m\n");
        aumento += 10000 - obtenerRelacion(pikachu);
    }
    else aumento += relacionTienda[i];
    aumentarRelacion(pikachu, aumento);
    agregarConsumido(pikachu, itemSeleccionado);
    printf("\033[92mHas usado %s\033[0m\n", itemSeleccionado);
    printf("Tu relacion ha aumentado en \033[92m%d puntos\033[0m\n", aumento);
    eliminar(consumibles, itemSeleccionado);
}

int pedirApuesta(int watts){
    int apuesta = 0;
    printf("Cuanto quieres apostar?: \033[92;1m");
    scanf("%d", &apuesta);
    printf("\033[0m");
    if (apuesta > watts){
        printf("\033[91mNo tienes suficientes watts\033[0m\n");
        apuesta = pedirApuesta(watts);
    }
    return apuesta;
}

int adivinarItem(lista *items){
    int opcion = 0;
    printf("Que item crees que es?: \033[92;1m");
    scanf("%d", &opcion);
    printf("\033[0m");
    if (opcion < 1 || opcion > longitud(items)){
        printf("\033[91mOpcion invalida\033[0m\n");
        opcion = adivinarItem(items);
    }
    return opcion;
}

void compararItems(char* itemRandom, char* itemSeleccionado, Pikachu *pikachu, int *watts, int apuesta){
    // Si el item seleccionado es el mismo que el item random
    if (strcmp(itemRandom, itemSeleccionado) == 0){
        // Imprimimos el mensaje del Pikachu
        hablar(pikachu, "Pika pika! (Ganaste!)");
        // Aumentamos los watts
        *watts += apuesta;
    }
    // Si el item seleccionado no es el mismo que el item random
    else{
        // Imprimimos el mensaje del Pikachu
        hablar(pikachu, "Pika... (Perdiste!)");
        // Disminuimos los watts
        *watts -= apuesta;
        // Aumentamos la relacion (Pikachu esta feliz de ganarle a su entrenador)
        aumentarRelacion(pikachu, apuesta);
    }
}

int main(int argc, char const *argv[]) {
    // Inicializar variables
    int watts = 0;
    char* nombrePikachu = pedirNombre();
    Pikachu *pikachu = nuevoPikachu(nombrePikachu);
    lista *consumibles = nuevaLista();
    // Guardar el tiempo de inicio
    time_t inicio;
    time(&inicio);
    time_t ultimaActualizacion = inicio;
    // Mostrar bienvenida a Pikachu Virtual
    bienvenida();
    // Mostrar ASCII Art de Pikachu
    mostrarPikachu(pikachu);
    int opcion = -1;
    // Mientras la opcion no sea salir
    while(opcion != 0){
        mostrarInfo(watts, obtenerRelacion(pikachu));
        // Mostrar menu
        mostrarMenu();
        // leer opcion
        opcion = leerOpcion();
        switch(opcion){
            case 0: // Salir
                hablar(pikachu, "Pikaaa! (Adios!)");
                break;
            case 1: // Jugar (Se apuesta)
                if (watts == 0 || longitud(consumibles) < 2) {
                    printf("\033[91;1mNo tienes suficientes watts o consumibles\033[0m\n");
                    printf("\033[91mNecesitas al menos 2 consumibles y 1 watt\033[0m\n");
                }
                else{
                    // Primero, preguntamos de cuanto va a ser la apuesta
                    int apuesta = pedirApuesta(watts);
                    // Creamos una lista de consumibles sin repetidos
                    lista* items = listaSinRepetidos(consumibles);
                    // Escogemos un item al azar
                    char* itemRandom = obtener(items, rand() % longitud(items));
                    // Mostramos los items
                    mostrarLista(items);
                    // Preguntamos por el item
                    int i = adivinarItem(items) - 1;
                    char* itemSeleccionado = obtener(items, i);
                    compararItems(itemRandom, itemSeleccionado, pikachu, &watts, apuesta);
                }
                break;
            case 2: // Usar consumible
                printf("Cantidad de consumibles: \033[92;1m%d\033[0m\n", longitud(consumibles));
                if (estaVacia(consumibles)) printf("\033[91mNo tienes consumibles\033[0m\n");
                else{
                    lista* items = listaSinRepetidos(consumibles);
                    mostrarLista(items);
                    char* itemSeleccionado = preguntarItem(items);
                    usarElemento(consumibles, pikachu, itemSeleccionado);
                }
                break;
            case 3: // Saludar
                printf("\033[96mTu\033[0m: Hola!\n\n");
                mostrarPikachu(pikachu);
                break;
            case 4: // Ir a la tienda
                mostrarTienda(watts);
                comprar(consumibles, &watts, pikachu);
                break;
        }
        if (opcion > 1 || opcion < 4) watts += 10;
        time_t ahora;
        time(&ahora);
        watts += actualizarWatts(ultimaActualizacion, ahora);
        ultimaActualizacion = ahora;
        printf("\n");
    }
    return 0;
}
