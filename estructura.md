# Estructura de Archivos

La estructura que se plantea para el siguiente SO simulado, consideranto los temas vistos en clase es el siguiente

```markdown

- so_simulado/
    - main.c            // Pinto de entrada del programa
    - process.c         // Gestion y planificacion de procesos
    - memory.c          // Manejo de memoria simulada
    - io.c              // Simulacion de entrada/salida
    - scheduler.c       // Planificador de Procesos
    - utils.c           // Otras funciones auxiliares
    - include/
        - process.h
        - memory.h
        - io.h
        - scheduler.h
        - utils.h
    - Makefile          // Para compilar el proyecto
```