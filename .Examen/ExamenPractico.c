

#include <stdio.h>
#include <stdlib.h>   
#include <stdbool.h>  


static void capturar_calificaciones(float *arr, int inicio, int fin) {
    for (int i = inicio; i < fin; ++i) {
        float cal = 0.0f;
        int leidos = 0;
        do {
            printf("Calificacion del estudiante %d: ", i + 1);
            leidos = scanf("%f", &cal);
            if (leidos != 1 || cal < 0.0f) {
                
                int c;
                while ((c = getchar()) != '\n' && c != EOF) { }
                printf("Entrada invalida. Ingresa una calificacion >= 0 (ej. 8.5)\n");
                leidos = 0;
            }
        } while (leidos != 1);
        arr[i] = cal;
    }
}


static double promedio(const float *arr, int n) {
    if (n <= 0) return 0.0;
    double suma = 0.0;
    for (int i = 0; i < n; ++i) suma += arr[i];
    return suma / (double)n;
}

int main(void) {
    int n = 0;

    
    printf("Cuantos estudiantes deseas registrar? ");
    if (scanf("%d", &n) != 1 || n < 0) {
        fprintf(stderr, "Entrada invalida.\n");
        return 1;
    }

    
    float *califs = NULL;
    if (n > 0) {
        califs = (float *) malloc((size_t)n * sizeof(float));
        if (califs == NULL) {
            fprintf(stderr, "Error: no se pudo reservar memoria (malloc).\n");
            return 1;
        }
    }


    if (n > 0) {
        capturar_calificaciones(califs, 0, n);
        double prom = promedio(califs, n);
        printf("Promedio inicial: %.2f\n\n", prom);
    } else {
        printf("No se registraron estudiantes inicialmente.\n\n");
    }

    
    while (1) {
        int agregar = 0;
        printf("Deseas agregar mas estudiantes? (cantidad, 0 para no): ");
        if (scanf("%d", &agregar) != 1 || agregar < 0) {
            
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
            printf("Cantidad invalida. Intenta de nuevo.\n");
            continue;
        }
        if (agregar == 0) break;  

        
        int nuevo_tamano = n + agregar;
        float *tmp = (float *) realloc(califs, (size_t)nuevo_tamano * sizeof(float));
        if (tmp == NULL) {
            fprintf(stderr, "Error: no se pudo ampliar memoria (realloc).\n");
            
            free(califs);
            return 1;
        }
        califs = tmp;

        
        capturar_calificaciones(califs, n, nuevo_tamano);
        n = nuevo_tamano;

        double prom = promedio(califs, n);
        printf("\nPromedio actualizado: %.2f\n\n", prom);
    }

    
    if (n > 0) {
        printf("\n=== Calificaciones registradas ===\n");
        for (int i = 0; i < n; ++i) {
            printf("Estudiante %d: %.2f\n", i + 1, califs[i]);
        }
        printf("Promedio general: %.2f\n", promedio(califs, n));
    } else {
        printf("No hay calificaciones registradas.\n");
    }

    
    free(califs);
    printf("\nMemoria liberada correctamente.\n");


    return 0;
}
