#include <stdio.h>
#include "include/memory.h"


void init_memory(MemoryBlock *memory, int size) {
    for (int i = 0; i < size; i++) {
        memory[i].allocated = 0;
        memory[i].pid = -1;
    }
}

int allocate_memory(MemoryBlock *memory, int size, int pid, int blocks_needed) {
    int blocks_found = 0;

    for (int i = 0; i < size; i++) {
        // Si el bloque está libre, incrementar el contador de bloques encontrados
        if (memory[i].allocated == 0) {
            blocks_found++;
        } else {
            blocks_found = 0;
        }

        // Si se encontraron suficientes bloques, asignar memoria
        if (blocks_found == blocks_needed) {
            for (int j = i - blocks_needed + 1; j <= i; j++) {
                memory[j].allocated = 1;
                memory[j].pid = pid;
            }
            return 1;
        }
    }

    return 0;
}

void free_memory(MemoryBlock *memory, int size, int pid) {
    for (int i = 0; i < size; i++) {
        if (memory[i].pid == pid) {
            memory[i].allocated = 0;
            memory[i].pid = -1;
        }
    }
}