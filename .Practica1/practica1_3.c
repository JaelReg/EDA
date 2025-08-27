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


    printf("\nArreglo original:\n");
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");

    
    long long suma = 0;
    long long resta = a[0];   
    int minimo = a[0], maximo = a[0];
    int posMin = 0, posMax = 0;

    for (int i = 0; i < n; i++) {
        suma += a[i];
        if (i > 0) resta -= a[i];
        if (a[i] < minimo) { minimo = a[i]; posMin = i; }
        if (a[i] > maximo) { maximo = a[i]; posMax = i; }
    }

    double promedio = (double)suma / n;

    
    printf("\nResultados:\n");
    printf("Suma = %lld\n", suma);
    printf("Resta secuencial = %lld\n", resta);
    printf("Promedio = %.2f\n", promedio);
    printf("Minimo = %d (en la posición %d)\n", minimo, posMin);
    printf("Maximo = %d (en la posición %d)\n", maximo, posMax);

    
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    
    printf("\nArreglo invertido:\n");
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");

    return 0;
}
