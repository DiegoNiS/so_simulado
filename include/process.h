#ifndef PROCESS_H
#define PROCESS_H

typedef enum { NEW, READY, RUNNING, WAITING, TERMINATED } ProcessState;

typedef struct {
    int pid;                // Identificador unique del proceso
    char name[20];          // Nombre del proceso
    ProcessState state;     // Estado actual del proceso
    int priority;           // Prioridad del proceso
    int burst_time;         // Tiempo de ráfaga del proceso
    int arrival_time;       // Tiempo en que llega el proceso
} Process;

// Funciones
void create_process(Process *process, int pid, char *name, int burst_time, int arrival_time, int priority); // Crear un proceso
void display_process(const Process *p); // Mostrar información importante de un proceso

#endif