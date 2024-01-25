# Tarea 1 - Sistemas Operativos 1 (CI-3825)
# Juan Andres Cuevas 19-10056

# Variables
CC = gcc
CFLAGS = -c
LFLAGS = -o
TARGET = main.out
SRC = listaEnlazada.c pikachu.c pikachus_ascii.c main.c
OBJ = $(SRC:.c=.o)

# Reglas
.PHONY : all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(LFLAGS) $(TARGET) $(OBJ); rm -rf $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean :
	rm -rf $(TARGET) $(OBJ)