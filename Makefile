CC = gcc
CFLAGS = -Iinclude -Wall
DEPS = include/process.h include/memory.h include/io.h include/scheduler.h

# Objetos individuales
OBJ = main.o process.o memory.o io.o scheduler.o

# Reglas individuales para cada archivo objeto
main.o: main.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

process.o: process.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

memory.o: memory.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

io.o: io.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

scheduler.o: scheduler.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# Regla para generar el ejecutable 'main'
main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

# Regla 'all' para compilar y ejecutar
all: main
	./main

# Regla para limpiar los archivos generados
clean:
	rm -f *.o main