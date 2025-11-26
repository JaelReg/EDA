

#include <stdio.h>
#include <stdlib.h>


struct Nodo {
    int dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};


void insertarInicio(struct Nodo **inicio, int valor) {
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("Error: no se pudo reservar memoria.\n");
        return;
    }

    nuevo->dato = valor;
    nuevo->anterior = NULL;
    nuevo->siguiente = *inicio;

    if (*inicio != NULL) {
        (*inicio)->anterior = nuevo;
    }

    *inicio = nuevo;
}


void insertarFinal(struct Nodo **inicio, int valor) {
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    struct Nodo *actual;

    if (nuevo == NULL) {
        printf("Error: no se pudo reservar memoria.\n");
        return;
    }

    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;

    if (*inicio == NULL) {
        
        *inicio = nuevo;
        return;
    }

    
    actual = *inicio;
    while (actual->siguiente != NULL) {
        actual = actual->siguiente;
    }

    
    actual->siguiente = nuevo;
    nuevo->anterior = actual;
}


void recorrerAdelante(struct Nodo *inicio) {
    struct Nodo *actual = inicio;
    printf("Recorrido hacia adelante: ");
    while (actual != NULL) {
        printf("%d <-> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}


void recorrerAtras(struct Nodo *inicio) {
    struct Nodo *actual = inicio;

    if (actual == NULL) {
        printf("Recorrido hacia atras: lista vacia.\n");
        return;
    }

    
    while (actual->siguiente != NULL) {
        actual = actual->siguiente;
    }

    printf("Recorrido hacia atras: ");
    while (actual != NULL) {
        printf("%d <-> ", actual->dato);
        actual = actual->anterior;
    }
    printf("NULL\n");
}


void eliminar(struct Nodo **inicio, int valor) {
    struct Nodo *actual = *inicio;

    if (actual == NULL) {
        printf("La lista esta vacia, no se puede eliminar.\n");
        return;
    }

    
    while (actual != NULL && actual->dato != valor) {
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        printf("Valor %d no encontrado en la lista.\n", valor);
        return;
    }

    
    if (actual->anterior == NULL) {
        *inicio = actual->siguiente;
        if (*inicio != NULL) {
            (*inicio)->anterior = NULL;
        }
    }
    
    else if (actual->siguiente == NULL) {
        actual->anterior->siguiente = NULL;
    }
    
    else {
        actual->anterior->siguiente = actual->siguiente;
        actual->siguiente->anterior = actual->anterior;
    }

    printf("Eliminando nodo con valor %d.\n", actual->dato);
    free(actual);
}


void liberar(struct Nodo *inicio) {
    struct Nodo *actual = inicio;
    struct Nodo *sig;

    while (actual != NULL) {
        sig = actual->siguiente;
        free(actual);
        actual = sig;
    }
}

int main(void) {
    struct Nodo *inicio = NULL;
    int n, i, valor, valorEliminar;

    printf("=== PRACTICA 8: LISTA DOBLEMENTE LIGADA ===\n\n");

    
    printf("¿Cuantos valores deseas insertar al inicio? ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Valor %d (inicio): ", i + 1);
        scanf("%d", &valor);
        insertarInicio(&inicio, valor);
        recorrerAdelante(inicio);
    }

    
    printf("\n¿Cuantos valores deseas insertar al final? ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Valor %d (final): ", i + 1);
        scanf("%d", &valor);
        insertarFinal(&inicio, valor);
        recorrerAdelante(inicio);
    }

    printf("\nRecorrido completo hacia adelante:\n");
    recorrerAdelante(inicio);

    printf("Recorrido completo hacia atras:\n");
    recorrerAtras(inicio);

    
    printf("\nValor a eliminar: ");
    scanf("%d", &valorEliminar);
    eliminar(&inicio, valorEliminar);

    printf("Lista despues de eliminar:\n");
    recorrerAdelante(inicio);
    recorrerAtras(inicio);

    
    liberar(inicio);
    printf("\nMemoria liberada correctamente.\n");

    return 0;
}
