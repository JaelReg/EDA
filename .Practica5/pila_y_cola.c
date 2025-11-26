

#include <stdio.h>
#include <stdlib.h>

#define MAX 5    


typedef struct {
    int datos[MAX];
    int tope;          
} Pila;

void inicializarPila(Pila *p) {
    p->tope = -1;
    printf("Pila inicializada vacia.\n");
}

int pilaVacia(Pila *p) {
    return (p->tope == -1);
}

int pilaLlena(Pila *p) {
    return (p->tope == MAX - 1);
}

int push(Pila *p, int valor) {
    if (pilaLlena(p)) {
        printf("  [ERROR] No se puede hacer PUSH: la pila esta llena.\n");
        return 0;  
    }
    p->tope++;
    p->datos[p->tope] = valor;
    return 1;      
}

int pop(Pila *p, int *valor) {
    if (pilaVacia(p)) {
        printf("  [ERROR] No se puede hacer POP: la pila esta vacia.\n");
        return 0;
    }
    *valor = p->datos[p->tope];
    p->tope--;
    return 1;
}

void imprimirPila(Pila *p) {
    int i;
    if (pilaVacia(p)) {
        printf("  Pila vacia.\n");
        return;
    }
    printf("  Contenido de la pila (base -> tope): ");
    for (i = 0; i <= p->tope; i++) {
        printf("%d ", p->datos[i]);
    }
    printf("\n");
}


typedef struct {
    int datos[MAX];
    int frente;    
    int final;     
} Cola;

void inicializarCola(Cola *c) {
    c->frente = 0;
    c->final  = -1;   
    printf("Cola inicializada vacia.\n");
}

int colaVacia(Cola *c) {
    return (c->frente > c->final);
}

int colaLlena(Cola *c) {
    return (c->final == MAX - 1);
}

int enqueue(Cola *c, int valor) {
    if (colaLlena(c)) {
        printf("  [ERROR] No se puede hacer ENQUEUE: la cola esta llena.\n");
        return 0;
    }
    c->final++;
    c->datos[c->final] = valor;
    return 1;
}

int dequeue(Cola *c, int *valor) {
    if (colaVacia(c)) {
        printf("  [ERROR] No se puede hacer DEQUEUE: la cola esta vacia.\n");
        return 0;
    }
    *valor = c->datos[c->frente];
    c->frente++;
    return 1;
}

void imprimirCola(Cola *c) {
    int i;
    if (colaVacia(c)) {
        printf("  Cola vacia.\n");
        return;
    }
    printf("  Contenido de la cola (frente -> final): ");
    for (i = c->frente; i <= c->final; i++) {
        printf("%d ", c->datos[i]);
    }
    printf("\n");
}


int main(void) {
    Pila pila;
    Cola cola;
    int n, i, valor;

    
    int ordenSalidaPila[MAX];
    int cantSalidaPila = 0;
    int ordenSalidaCola[MAX];
    int cantSalidaCola = 0;

    printf("==== PRACTICA 5: PILAS Y COLAS ====\n\n");

    
    printf("=== PARTE 1: PILA ===\n");
    inicializarPila(&pila);

    printf("\n¿Cuantos elementos quieres apilar? (max %d): ", MAX);
    scanf("%d", &n);

    if (n > MAX) {
        printf("  Aviso: solo se apilaran %d elementos.\n", MAX);
        n = MAX;
    }

    for (i = 0; i < n; i++) {
        printf("  Valor a PUSH [%d]: ", i + 1);
        scanf("%d", &valor);
        if (push(&pila, valor)) {
            printf("  Se hizo PUSH de %d.\n", valor);
        }
        imprimirPila(&pila);
    }

    printf("\n¿Cuantos elementos quieres desapilar (POP)? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        if (pop(&pila, &valor)) {
            printf("  Se hizo POP, salio: %d\n", valor);
            if (cantSalidaPila < MAX) {
                ordenSalidaPila[cantSalidaPila++] = valor;
            }
        } else {
            
            break;
        }
        imprimirPila(&pila);
    }

    
    printf("\n=== PARTE 2: COLA ===\n");
    inicializarCola(&cola);

    printf("\n¿Cuantos elementos quieres encolar? (max %d): ", MAX);
    scanf("%d", &n);

    if (n > MAX) {
        printf("  Aviso: solo se encolaran %d elementos.\n", MAX);
        n = MAX;
    }

    for (i = 0; i < n; i++) {
        printf("  Valor a ENQUEUE [%d]: ", i + 1);
        scanf("%d", &valor);
        if (enqueue(&cola, valor)) {
            printf("  Se hizo ENQUEUE de %d.\n", valor);
        }
        imprimirCola(&cola);
    }

    printf("\n¿Cuantos elementos quieres desencolar (DEQUEUE)? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        if (dequeue(&cola, &valor)) {
            printf("  Se hizo DEQUEUE, salio: %d\n", valor);
            if (cantSalidaCola < MAX) {
                ordenSalidaCola[cantSalidaCola++] = valor;
            }
        } else {
            
            break;
        }
        imprimirCola(&cola);
    }

    
    printf("\n=== PARTE 3: COMPARACION DE ORDEN DE SALIDA ===\n");

    printf("Orden de salida en la PILA (LIFO - ultimo en entrar, primero en salir):\n  ");
    if (cantSalidaPila == 0) {
        printf("(No se extrajeron elementos de la pila)\n");
    } else {
        for (i = 0; i < cantSalidaPila; i++) {
            printf("%d ", ordenSalidaPila[i]);
        }
        printf("\n");
    }

    printf("Orden de salida en la COLA (FIFO - primero en entrar, primero en salir):\n  ");
    if (cantSalidaCola == 0) {
        printf("(No se extrajeron elementos de la cola)\n");
    } else {
        for (i = 0; i < cantSalidaCola; i++) {
            printf("%d ", ordenSalidaCola[i]);
        }
        printf("\n");
    }

    printf("\nFin del programa.\n");
    return 0;
}
