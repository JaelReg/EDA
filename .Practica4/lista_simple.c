

#include <stdio.h>
#include <stdlib.h>


void imprimir_lista(const char *titulo, int *lista, int n) {
    int i;
    printf("%s (tam = %d):\n", titulo, n);
    for (i = 0; i < n; i++) {
        printf("lista[%d] = %d\n", i, lista[i]);
    }
    printf("\n");
}

int main(void) {
    int n, m;
    int i;
    int *lista_simple = NULL;    
    int *lista_circular = NULL;  

    printf("PRÁCTICA 4 - lista_circular.c\n");
    printf("¿Cuantos enteros quieres almacenar en la 'lista circular'? ");
    scanf("%d", &n);

    
    lista_simple = (int *)malloc(n * sizeof(int));
    if (lista_simple == NULL) {
        printf("Error: no se pudo reservar memoria con malloc.\n");
        return 1;
    }

    imprimir_lista(
        "\nValores iniciales de lista_simple (malloc, sin inicializar)",
        lista_simple, n
    );

    
    lista_circular = (int *)calloc(n, sizeof(int));
    if (lista_circular == NULL) {
        printf("Error: no se pudo reservar memoria con calloc.\n");
        free(lista_simple);
        return 1;
    }

    imprimir_lista(
        "Valores iniciales de lista_circular (calloc, inicializada a 0)",
        lista_circular, n
    );

    
    printf("Introduce %d enteros para llenar la lista_circular:\n", n);
    for (i = 0; i < n; i++) {
        printf("lista_circular[%d] = ", i);
        scanf("%d", &lista_circular[i]);
    }

    imprimir_lista(
        "Contenido actual de lista_circular (antes de realloc)",
        lista_circular, n
    );

    
    printf("Nuevo tamaño para lista_circular (m): ");
    scanf("%d", &m);

    
    int *tmp = (int *)realloc(lista_circular, m * sizeof(int));
    if (tmp == NULL) {
        printf("Error: no se pudo redimensionar la memoria con realloc.\n");
        free(lista_simple);
        free(lista_circular); 
        return 1;
    }
    lista_circular = tmp;

    if (m > n) {
        printf("\nLa lista_circular ha aumentado de tamaño (%d -> %d).\n", n, m);
        printf("Introduce los %d valores adicionales:\n", m - n);
        for (i = n; i < m; i++) {
            printf("lista_circular[%d] = ", i);
            scanf("%d", &lista_circular[i]);
        }
    } else if (m < n) {
        printf("\nLa lista_circular se ha reducido de tamaño (%d -> %d).\n", n, m);
        printf("Los elementos con indices %d a %d se han perdido.\n", m, n - 1);
    } else {
        printf("\nEl tamaño de la lista_circular no cambió (m = n = %d).\n", n);
    }

    imprimir_lista(
        "Contenido final de lista_circular (después de realloc)",
        lista_circular, m
    );

    
    if (m > 0) {
        printf("Recorrido circular (2 vueltas sobre la lista_circular):\n");
        for (i = 0; i < 2 * m; i++) {
            int idx = i % m;
            printf("vuelta[%d] -> lista_circular[%d] = %d\n",
                   i, idx, lista_circular[idx]);
        }
        printf("\n");
    }

    
    free(lista_simple);
    free(lista_circular);
    printf("Memoria liberada correctamente.\n");

    return 0;
}
