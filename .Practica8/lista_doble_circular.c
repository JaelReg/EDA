

#include <stdio.h>
#include <stdlib.h>


struct Nodo {
    int dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};


void insertarFinalCircular(struct Nodo **inicio, int valor) {
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));

    if (nuevo == NULL) {
        printf("Error: no se pudo reservar memoria.\n");
        return;
    }

    nuevo->dato = valor;

    if (*inicio == NULL) {
        
        nuevo->siguiente = nuevo;
        nuevo->anterior = nuevo;
        *inicio = nuevo;
    } else {
        struct Nodo *ultimo = (*inicio)->anterior;
        
        nuevo->siguiente = *inicio;
        nuevo->anterior = ultimo;
        ultimo->siguiente = nuevo;
        (*inicio)->anterior = nuevo;
        
    }
}


void recorrerAdelanteCircular(struct Nodo *inicio) {
    struct Nodo *actual;

    if (inicio == NULL) {
        printf("Lista circular vacia.\n");
        return;
    }

    actual = inicio;
    printf("Recorrido circular hacia adelante: ");
    do {
        printf("%d <-> ", actual->dato);
        actual = actual->siguiente;
    } while (actual != inicio);
    printf("(vuelve a inicio)\n");
}


void recorrerAtrasCircular(struct Nodo *inicio) {
    struct Nodo *actual;

    if (inicio == NULL) {
        printf("Lista circular vacia.\n");
        return;
    }

    actual = inicio->anterior; 

    printf("Recorrido circular hacia atras: ");
    do {
        printf("%d <-> ", actual->dato);
        actual = actual->anterior;
    } while (actual != inicio->anterior);
    printf("(vuelve a ultimo)\n");
}


void eliminarCircular(struct Nodo **inicio, int valor) {
    struct Nodo *actual;
    struct Nodo *ultimo;

    if (*inicio == NULL) {
        printf("La lista circular esta vacia, no se puede eliminar.\n");
        return;
    }

    actual = *inicio;
    ultimo = (*inicio)->anterior;

    
    do {
        if (actual->dato == valor) {
            break;
        }
        actual = actual->siguiente;
    } while (actual != *inicio);

    
    if (actual->dato != valor) {
        printf("Valor %d no encontrado en la lista circular.\n", valor);
        return;
    }

    
    if (actual == *inicio && actual->siguiente == actual) {
        *inicio = NULL;
    }
    
    else if (actual == *inicio) {
        ultimo = (*inicio)->anterior;
        *inicio = (*inicio)->siguiente;     
        ultimo->siguiente = *inicio;
        (*inicio)->anterior = ultimo;
    }
    
    else if (actual == (*inicio)->anterior) {
        struct Nodo *nuevoUltimo = actual->anterior;
        nuevoUltimo->siguiente = *inicio;
        (*inicio)->anterior = nuevoUltimo;
    }
    
    else {
        actual->anterior->siguiente = actual->siguiente;
        actual->siguiente->anterior = actual->anterior;
    }

    printf("Eliminando nodo circular con valor %d.\n", actual->dato);
    free(actual);
}


void liberarCircular(struct Nodo **inicio) {
    struct Nodo *actual;
    struct Nodo *sig;

    if (*inicio == NULL) {
        return;
    }

    actual = *inicio;
    do {
        sig = actual->siguiente;
        free(actual);
        actual = sig;
    } while (actual != *inicio);

    *inicio = NULL;
}

int main(void) {
    struct Nodo *inicio = NULL;
    int n, i, valor, valorEliminar;

    printf("=== PRACTICA 8: LISTA DOBLEMENTE LIGADA CIRCULAR ===\n\n");

    printf("¿Cuantos valores deseas insertar (al final) en la lista circular? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &valor);
        insertarFinalCircular(&inicio, valor);
        recorrerAdelanteCircular(inicio);
    }

    printf("\nRecorrido circular hacia adelante:\n");
    recorrerAdelanteCircular(inicio);

    printf("Recorrido circular hacia atras:\n");
    recorrerAtrasCircular(inicio);

    printf("\nValor a eliminar de la lista circular: ");
    scanf("%d", &valorEliminar);
    eliminarCircular(&inicio, valorEliminar);

    printf("Lista circular despues de la eliminacion (adelante):\n");
    recorrerAdelanteCircular(inicio);
    printf("Lista circular despues de la eliminacion (atras):\n");
    recorrerAtrasCircular(inicio);

    liberarCircular(&inicio);
    printf("\nMemoria liberada correctamente.\n");

    return 0;
}
