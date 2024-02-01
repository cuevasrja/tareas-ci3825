# Tarea 1 - Sistemas Operativos 1 (CI-3825)
# Juan Andres Cuevas 19-10056

# Variables
CC = gcc
CFLAGS = -c
LFLAGS = -o
TARGET = main.out
SRC = listaEnlazada.c pikachu.c pikachus_ascii.c main.c
SRC_H = listaEnlazada.h pikachu.h pikachus_ascii.h main.h

# Reglas
.PHONY : all clean

all:
	$(CC) $(LFLAGS) $(TARGET) $(SRC) $(SRC_H) 

clean :
	rm -rf $(TARGET) *.o