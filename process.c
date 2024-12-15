#include <stdio.h>
#include <string.h>
#include "include/process.h"

void create_process(Process *p, int pid, char *name, int burst_time, int arrival_time, int priority) {
    p->pid = pid;
    strncpy(p->name, name, 20);
    p->burst_time = burst_time;
    p->arrival_time = arrival_time;
    p->priority = priority;
    p->state = NEW;
}

void display_process(const Process *p) {
    printf("PID: %d, Nombre: %s, Estado: %d, Prioridad: %d\n", p->pid, p->name, p->state, p->priority);
}