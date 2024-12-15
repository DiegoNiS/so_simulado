#include <stdio.h>
#include <stdlib.h>
#include "include/io.h"
#include "include/process.h"

// Nodo de la cola de E/S
typedef struct IOQueueNode {
    int pid;                    // Identificador del proceso
    struct IoQueueNode *next;   // Siguiente nodo
} IOQueueNode;

static IOQueueNode *io_queue_head = NULL; // Inicializar la cola de E/S
static IOQueueNode *io_queue_tail = NULL; // Inicializar la cola de E/S

void simulate_io_request(int pid) {
    IOQueueNode *new_node = (IOQueueNode *)malloc(sizeof(IOQueueNode));
    if(new_node == NULL) {
        fprintf(stderr, "Error: No se pudo asignar memoria para el nodo de la cola de E/S\n");
        exit(EXIT_FAILURE);
    }

    // Inicializar el nodo
    new_node->pid = pid;
    new_node->next = NULL;

    // Agregar el nodo a la cola de E/S
    if (io_queue_head == NULL) { // La cola está vacía
        io_queue_head = new_node;
        io_queue_tail = new_node;
    } else { // Agregar al final de la cola
        io_queue_tail->next = new_node;
        io_queue_tail = new_node;
    }

    printf("Proceso %d agregado a la cola de E/S\n", pid);
}

void process_io_queue() {
    if (io_queue_head == NULL) {
        printf("Cola de E/S vacía\n");
        return;
    }

    IOQueueNode *node_to_process = io_queue_head;
    printf("Procesando solicitud de E/S para el proceso %d\n", node_to_process->pid);

    io_queue_head = io_queue_head->next; // Actualizar la cabeza de la cola
    if(io_queue_head == NULL) {          // Si la cola queda vacía
        io_queue_tail = NULL;
    }

    free(node_to_process); // Liberar el nodo procesado
}

void display_io_queue() {
    IOQueueNode *current = io_queue_head;
    printf("Estado actual de la cola de E/S: \n");
    if (current == NULL) {
        printf("Cola de E/S vacía\n");
        return;
    }
    

    while (current != NULL) {
        printf("PID: %d ->", current->pid);
        current = current->next;
    }
    printf("NULL\n");
}