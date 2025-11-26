

#include <stdio.h>

#define MAX_N 94   
unsigned long long memo[MAX_N + 1];
int calculado[MAX_N + 1];  


unsigned long long fibonacci(int n) {
    if (n <= 0 || n > MAX_N) {
        return 0;  
    }

    
    if (n == 1) return 0;
    if (n == 2) return 1;

    
    if (calculado[n]) {
        return memo[n];
    }

    
    unsigned long long fn1 = fibonacci(n - 1);
    unsigned long long fn2 = fibonacci(n - 2);

    memo[n] = fn1 + fn2;
    calculado[n] = 1;

    return memo[n];
}

int main(void) {
    int n;

    printf("Secuencia de Fibonacci:\n");
    printf("F(1)=0, F(2)=1, F(n)=F(n-1)+F(n-2) para n>=3\n");
    printf("Puedes pedir cualquier posicion entre 1 y %d.\n", MAX_N);
    printf("Escribe 0 para salir.\n\n");

    while (1) {
        printf("Ingresa la posicion (1-%d, 0 para terminar): ", MAX_N);
        if (scanf("%d", &n) != 1) {
            
            printf("\nEntrada no valida. Saliendo.\n");
            break;
        }

        if (n == 0) {
            printf("Fin del programa.\n");
            break;
        }

        if (n < 1 || n > MAX_N) {
            printf("Posicion fuera de rango. Intenta de nuevo.\n\n");
            continue;
        }

        unsigned long long valor = fibonacci(n);
        printf("F(%d) = %llu\n\n", n, valor);
    }

    return 0;
}
