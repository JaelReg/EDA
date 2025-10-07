#include <stdio.h> 

typedef struct {
    int dato;
} Nodo;

int main() {
    Nodo n1;          // Un nodo normal
    Nodo *p;          // Un puntero a Nodo
    p = &n1;          // 'p' apunta a 'n1'

    
    n1.dato = 10;

   
    p->dato = 20;

   
    printf("%d\n", n1.dato);

    
    printf("%d\n", p->dato);

    return 0;
}
