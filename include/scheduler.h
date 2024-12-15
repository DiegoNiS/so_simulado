#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "process.h"

// Algoritmo de planificación First Come First Serve
void fcfs_schedule(Process *processes, int n);
// Algoritmo de planificación Round Robin
void round_robin_schedule(Process *processes, int n, int quantum);

#endif