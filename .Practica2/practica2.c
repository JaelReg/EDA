#include <stdio.h>

int main(void) {
int a[5] = {2, 4, 6, 8, 10};
int *p = a; // p apunta a a[0]
printf("1) a[1] = %d\n", a[1]);// Acceso por índice. a[1] = 4. Imprime: 1) a[1] = 4 
printf("2) *(a+3) = %d\n", *(a+3));// Aritmética de apuntadores sobre el nombre del arreglo (decay a puntero). a+3 apunta a a[3]; *(a+3) = 8
printf("3) *p++ = %d\n", *p++);// Post-incremento del puntero: *p++ ≡ *(p++). Primero desreferencia p (valor a[0]=2), luego incrementa p. Imprime: 3) *p++ = 2
printf("4) *++p = %d\n", *++p);// Pre-incremento del puntero: *++p ≡ *(++p). Primero incrementa p, luego desreferencia. p estaba en a[1]; ++p → a[2]; *p = a[2] = 6. Imprime: 4) *++p = 6
printf("5) p[1] = %d\n", p[1]);//  Imprime: 5) p[1] = 8
printf("6) *(p+=2) = %d\n", *(p+=2));// p += 2 avanza dos enteros (no bytes). p estaba en a[2] → ahora a[4]; desreferencia a[4] = 10. Imprime: 6) *(p+=2) = 10
printf("7) p - a = %ld\n", p - a);// Resta de punteros → diferencia en elementos (tipo ptrdiff_t). p es a+4; a es a+0; (a+4) - (a+0) = 4. Imprime: 7) p - a = 4
return 0;
}