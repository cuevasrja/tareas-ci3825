# Tarea 1 - CI8325 (Sistemas de Operación)

## Introducción
Es 1997 y acaba de emerger un nuevo género de videojuego: la mascota virtual. Viendo el éxito que ha tenido  la  marca  Pokémon el último año,  Nintendo  le  ha encargado a  usted hacer una  adaptación de la marca para entrar  en este  nuevo  género.  Debido  a  que  los  recursos  para  desarrollar  hardware  son limitados, el juego debe ser un tanto más sencillo que el de la competencia, lo cual se espera que también lo haga atractivo a jugadores más jóvenes.El objetivo principal del juego es crear y mantener una relación con una mascota virtual Pikachu, la cual debe tener al menos 4 estados emocionales, los cuales se deben representar con ASCII Art. A continuación se  muestranunos  estadosde  ejemplo. Nose  espera que  los  estados  finales  de  su programa coincidan exactamente con ellos

<!-- Tabla -->
| Rango de ejemplo | Relación con Pikachu    | ASCII Art         |
| ---------------- | ----------------------- | ----------------- |
| 0 - 2.500        | Pikachu está triste     | `⊹⋛⋋( ՞ਊ ՞)⋌⋚⊹` |
| 2.501 - 5.000    | Pikachu está normal     | `⊹⋛⋋( ՞ਊ ՞)⋌⋚⊹` |
| 5.001 - 7.500    | Pikachu está feliz      | `⊹⋛⋋( ՞ਊ ՞)⋌⋚⊹` |
| 7.501 - 10.000   | Pikachu está emocionado | `⊹⋛⋋( ՞ਊ ՞)⋌⋚⊹` |

## Estrucutra del proyecto
El proyecto está estructurado de la siguiente manera:
```
tarea1
│   README.md
|   makefile
│   main.c
│   main.h
│   pikachu.c
│   pikachu.h
│   pikachus_ascii.c
│   pikachus_ascii.h
│   listaEnlazada.c
│   listaEnlazada.h
```

### main.c
Archivo principal del programa. Contiene la función main.
Se encarga de crear la mascota virtual Pikachu y de manejar la interacción con el usuario.

### main.h
Archivo de cabecera del archivo main.c.

### pikachu.c
Archivo que contiene la implementación de la estructura de datos de la mascota virtual Pikachu.

### pikachu.h
Archivo de cabecera del archivo pikachu.c.

### pikachus_ascii.c
Archivo que contiene el arte ASCII de Pikachu y las distintas funciones para mostar cada uno de sus estados.

### pikachus_ascii.h
Archivo de cabecera del archivo pikachus_ascii.c.

### listaEnlazada.c
Archivo que contiene la implementación de la estructura de datos de una lista enlazada.

### listaEnlazada.h
Archivo de cabecera del archivo listaEnlazada.c.

### makefile
Archivo que contiene las reglas para compilar el programa.

## Compilación
Para compilar el programa, se debe ejecutar el siguiente comando en la terminal:
```bash
make
```

## Ejecución
Para ejecutar el programa, se debe ejecutar el siguiente comando en la terminal:
```bash
./main.out
```
