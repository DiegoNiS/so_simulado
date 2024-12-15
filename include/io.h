# ifndef IO_H
# define IO_H


// Funciones para manejar la cola de E/S
void simulate_io_request(int pid); // Simular una solicitud de E/S
void process_io_queue(); // Procesar la cola de E/S
void display_io_queue(); // Mostrar el estado de la cola de E/S

# endif