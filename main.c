#include <stdio.h>
#include "include/process.h"
#include "include/scheduler.h"
#include "include/memory.h"
#include "include/io.h"

int main() {
    Process processes[3];

    // Crear procesos
    create_process(&processes[0], 1, "Proceso 1", 10, 0, 1);
    create_process(&processes[1], 2, "Proceso 2", 5, 1, 2);
    create_process(&processes[2], 3, "Proceso 3", 8, 2, 3);

    // Inicializar la memoria
    MemoryBlock memory[MEM_SIZE];
    init_memory(memory, MEM_SIZE);

    // Asignar memoria
    printf("Simulando el algoritmo de planificación FCFS\n");
    fcfs_schedule(processes, 3);

    // Simular solicitudes de E/S
    simulate_io_request(1);   // Proceso 1 solicita E/S
    simulate_io_request(2);   // Proceso 2 solicita E/S
    simulate_io_request(3);   // Proceso 3 solicita E/S

    display_io_queue();       // Mostrar el estado de la cola

    process_io_queue();       // Procesar la cola de E/S
    display_io_queue();       // Mostrar el estado de la cola

    process_io_queue();       // Procesar la cola de E/S
    display_io_queue();       // Mostrar el estado de la cola

    return 0;
}