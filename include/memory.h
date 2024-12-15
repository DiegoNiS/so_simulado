#ifndef MEMORY_H
#define MEMORY_H

#define MEM_SIZE 1024

// Bloque de memoria
typedef struct {
    int allocated;       // 0 = libre, 1 = ocupado
    int pid;             // Identificador del proceso
} MemoryBlock;

// Funciones
void init_memory(MemoryBlock *memory, int size); // Inicializar la memoria
int allocate_memory(MemoryBlock *memory, int size, int pid, int blocks_neded); // Asignar memoria
void free_memory(MemoryBlock *memory, int size, int pid);  // Liberar memoria 

#endif