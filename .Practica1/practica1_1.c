#include <stdio.h>

#define MAX 100   

int main(void) {
    int n;        
    int a[MAX];   

    
    do {
        printf("Ingresa una cantidad (1..%d): ", MAX);
        if (scanf("%d", &n) != 1) {  
            printf("Entrada invalida. Debes ingresar un número entero.\n");
            return 1;   
        }
        if (n < 1 || n > MAX) {
            printf("Valor fuera de rango. Debe estar entre 1 y %d.\n", MAX);
        }
    } while (n < 1 || n > MAX);

    
    printf("Ingrese %d numeros (cada uno en el rango 0..%d):\n", n, MAX);
    for (int i = 0; i < n; i++) {
        int x;   
        while (1) {  
            printf("Elemento %d: ", i);
            if (scanf("%d", &x) != 1) {
                printf("Entrada invalida. Debes ingresar un número entero.\n");
                return 1;
            }
            if (x < 0 || x > MAX) {
                printf("Número no permitido. Debe estar entre 0 y %d. Intenta de nuevo.\n", MAX);
            } else {
                a[i] = x;  
                break;     
            }
        }
    }

    
    printf("\nLos elementos del arreglo son:\n");
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) printf(" "); 
    }
    printf("\n");

    return 0;   
}
