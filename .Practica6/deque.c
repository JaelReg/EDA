

#include <stdio.h>

#define MAX 5

typedef struct {
    int datos[MAX];
    int front;   
    int size;    
} Deque;



void inicializarDeque(Deque *d) {
    d->front = 0;
    d->size  = 0;
    printf("Deque inicializado (front = %d, size = %d)\n\n", d->front, d->size);
}

int isEmptyDeque(Deque *d) {
    return (d->size == 0);
}

int isFullDeque(Deque *d) {
    return (d->size == MAX);
}

int getRearIndex(Deque *d) {
    if (isEmptyDeque(d)) return -1;
    return (d->front + d->size - 1) % MAX;
}


int insert_front(Deque *d, int valor) {
    if (isFullDeque(d)) {
        printf("  [ERROR] No se puede insert_front(%d): deque lleno.\n", valor);
        return 0;
    }
    d->front = (d->front - 1 + MAX) % MAX;  
    d->datos[d->front] = valor;
    d->size++;
    return 1;
}


int insert_rear(Deque *d, int valor) {
    int rear;
    if (isFullDeque(d)) {
        printf("  [ERROR] No se puede insert_rear(%d): deque lleno.\n", valor);
        return 0;
    }
    rear = (d->front + d->size) % MAX;  
    d->datos[rear] = valor;
    d->size++;
    return 1;
}


int delete_front(Deque *d, int *valor) {
    if (isEmptyDeque(d)) {
        printf("  [ERROR] No se puede delete_front: deque vacio.\n");
        return 0;
    }
    *valor = d->datos[d->front];
    d->front = (d->front + 1) % MAX;
    d->size--;
    return 1;
}


int delete_rear(Deque *d, int *valor) {
    int rear;
    if (isEmptyDeque(d)) {
        printf("  [ERROR] No se puede delete_rear: deque vacio.\n");
        return 0;
    }
    rear = getRearIndex(d);
    *valor = d->datos[rear];
    
    d->size--;
    return 1;
}

int peek_front(Deque *d, int *valor) {
    if (isEmptyDeque(d)) {
        printf("  [ERROR] No se puede peek_front: deque vacio.\n");
        return 0;
    }
    *valor = d->datos[d->front];
    return 1;
}

int peek_rear(Deque *d, int *valor) {
    int rear;
    if (isEmptyDeque(d)) {
        printf("  [ERROR] No se puede peek_rear: deque vacio.\n");
        return 0;
    }
    rear = getRearIndex(d);
    *valor = d->datos[rear];
    return 1;
}


void printDeque(Deque *d, const char *titulo) {
    int i, idx, rear;

    printf("%s\n", titulo);
    rear = getRearIndex(d);
    printf("  front = %d, rear = %d, size = %d\n", d->front, rear, d->size);

    if (isEmptyDeque(d)) {
        printf("  Deque vacio.\n\n");
        return;
    }

    printf("  Contenido (front -> rear, indices circulares):\n  ");
    for (i = 0; i < d->size; i++) {
        idx = (d->front + i) % MAX;
        printf("[i=%d | idx=%d | val=%d] ", i, idx, d->datos[idx]);
    }
    printf("\n\n");
}



int main(void) {
    Deque d;
    int x;

    inicializarDeque(&d);

    
    printf("=== insert_front(10) ===\n");
    insert_front(&d, 10);
    printDeque(&d, "Estado despues de insert_front(10):");

    
    printf("=== insert_rear(15), insert_rear(20) ===\n");
    insert_rear(&d, 15);
    insert_rear(&d, 20);
    printDeque(&d, "Estado despues de insert_rear(15) y insert_rear(20):");

    
    printf("=== insert_front(30) ===\n");
    insert_front(&d, 30);
    printDeque(&d, "Estado despues de insert_front(30):");

    
    printf("=== insert_rear(40) ===\n");
    insert_rear(&d, 40);
    printDeque(&d, "Estado despues de insert_rear(40):");

    
    printf("=== delete_front() y delete_rear() ===\n");
    if (delete_front(&d, &x)) {
        printf("  delete_front: salio %d\n", x);
    }
    if (delete_rear(&d, &x)) {
        printf("  delete_rear: salio %d\n", x);
    }
    printDeque(&d, "Estado despues de delete_front y delete_rear:");

    
    printf("=== Nuevas inserciones para observar indices ===\n");
    insert_rear(&d, 50);
    insert_front(&d, 60);
    printDeque(&d, "Estado final del deque:");

    
    if (peek_front(&d, &x)) {
        printf("peek_front: %d\n", x);
    }
    if (peek_rear(&d, &x)) {
        printf("peek_rear: %d\n", x);
    }

    printf("\nFin de pruebas de deque.\n");
    return 0;
}
