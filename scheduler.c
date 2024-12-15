#include <stdio.h>
#include "include/scheduler.h"

void fcfs_schedule(Process *processes, int n) {
    printf("Ejecutando procesos en orden FCFS\n");
    for(int i = 0; i < n; i++) {
        printf("Ejecutando proceso %d (%s)\n", processes[i].pid, processes[i].name);
        processes[i].state = RUNNING;

        // Simulacion de tiempo
        printf("Proceso %d terminado\n", processes[i].pid);
        processes[i].state = TERMINATED;
    }
}