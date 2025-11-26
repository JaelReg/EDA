
#include <stdio.h>

#define MAX 5

typedef struct {
    int datos[MAX];
    int frente;   
    int final;    
    int size;     
} ColaCircular;



void inicializarColaCircular(ColaCircular *c) {
    c->frente = 0;
    c->final  = 0;
    c->size   = 0;
    printf("Cola circular inicializada (frente = %d, final = %d, size = %d)\n\n",
           c->frente, c->final, c->size);
}

int isEmpty(ColaCircular *c) {
    return (c->size == 0);
}

int isFull(ColaCircular *c) {
    return (c->size == MAX);
}


int enqueue(ColaCircular *c, int valor) {
    if (isFull(c)) {
        printf("  [ERROR] No se puede encolar %d: cola llena.\n", valor);
        return 0;
    }
    c->datos[c->final] = valor;
    c->final = (c->final + 1) % MAX;  
    c->size++;
    return 1;
}


int dequeue(ColaCircular *c, int *valor) {
    if (isEmpty(c)) {
        printf("  [ERROR] No se puede desencolar: cola vacia.\n");
        return 0;
    }
    *valor = c->datos[c->frente];
    c->frente = (c->frente + 1) % MAX;
    c->size--;
    return 1;
}


int peek(ColaCircular *c, int *valor) {
    if (isEmpty(c)) {
        printf("  [ERROR] No se puede hacer peek: cola vacia.\n");
        return 0;
    }
    *valor = c->datos[c->frente];
    return 1;
}


void printQueue(ColaCircular *c, const char *titulo) {
    int i, idx;

    printf("%s\n", titulo);
    printf("  frente = %d, final = %d, size = %d\n", c->frente, c->final, c->size);

    if (isEmpty(c)) {
        printf("  Cola vacia.\n\n");
        return;
    }

    printf("  Contenido (frente -> final, usando indices circulares):\n  ");
    for (i = 0; i < c->size; i++) {
        idx = (c->frente + i) % MAX;
        printf("[i=%d | idx=%d | val=%d] ", i, idx, c->datos[idx]);
    }
    printf("\n\n");
}


int main(void) {
    ColaCircular cola;
    int x;

    inicializarColaCircular(&cola);

    
    printf("=== Encolar 5, 10, 15 ===\n");
    enqueue(&cola, 5);
    enqueue(&cola, 10);
    enqueue(&cola, 15);
    printQueue(&cola, "Estado despues de encolar 5,10,15:");

    
    printf("=== Desencolar uno ===\n");
    if (dequeue(&cola, &x)) {
        printf("  Se desencolo: %d\n", x);
    }
    printQueue(&cola, "Estado despues de desencolar uno:");

    
    printf("=== Encolar 20, 25, 30 ===\n");
    enqueue(&cola, 20);
    enqueue(&cola, 25);
    enqueue(&cola, 30);  
    printQueue(&cola, "Estado despues de encolar 20,25,30:");

    
    if (peek(&cola, &x)) {
        printf("Elemento en el frente (peek): %d\n", x);
    }

    printf("\nFin de pruebas de cola circular.\n");
    return 0;
}
