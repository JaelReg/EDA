#include <stdio.h>
#include <stdlib.h>


int max_recursivo(int *arr, int izq, int der) {
    
    if (izq == der) {
        return arr[izq];
    }

    int mid = (izq + der) / 2;

    
    int maxIzq = max_recursivo(arr, izq, mid);
    int maxDer = max_recursivo(arr, mid + 1, der);

    
    if (maxIzq > maxDer)
        return maxIzq;
    else
        return maxDer;
}

int main() {
    int n;
    printf("Ingresa el tamaño del arreglo: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("El tamaño debe ser mayor que 0.\n");
        return 1;
    }

    
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Error al reservar memoria.\n");
        return 1;
    }

    printf("Ingresa los %d elementos:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Elemento[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    
    int maximo = max_recursivo(arr, 0, n - 1);

    printf("El valor maximo es: %d\n", maximo);

    free(arr); 
    return 0;
}
