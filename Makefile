CC = gcc
CFLAGS = -Iinclude -Wall
DEPS = include/process.h include/memory.h include/io.h include/scheduler.h

# Objetos individuales
OBJ = process.o memory.o io.o scheduler.o

all: main
	./main

# Regla para generar el ejecutable 'main'
main: $(OBJ)
	$(CC) -o $@ $@.c $^ $(CFLAGS)

# Reglas individuales para cada archivo objeto
process.o: process.c $(DEPS)
	$(CC) -c $< $(CFLAGS)

memory.o: memory.c $(DEPS)
	$(CC) -c $< $(CFLAGS)

io.o: io.c $(DEPS)
	$(CC) -c $< $(CFLAGS)

scheduler.o: scheduler.c $(DEPS)
	$(CC) -c $< $(CFLAGS)

# Regla para limpiar los archivos generados
clean:
	rm -f *.o main