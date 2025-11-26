

#include <stdio.h>
#include <stdlib.h>


struct Nodo {
    int dato;
    struct Nodo *siguiente;
};


void insertarInicio(struct Nodo **cabeza, int valor) {
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("Error: no se pudo reservar memoria para el nodo.\n");
        return;
    }
    nuevo->dato = valor;
    nuevo->siguiente = *cabeza;   
    *cabeza = nuevo;              
}


void recorrer(struct Nodo *cabeza) {
    struct Nodo *actual = cabeza;
    printf("Lista: ");
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}


void eliminar(struct Nodo **cabeza, int valor) {
    struct Nodo *actual = *cabeza;
    struct Nodo *anterior = NULL;

    if (actual == NULL) {
        printf("La lista esta vacia, no se puede eliminar.\n");
        return;
    }

   
    while (actual != NULL && actual->dato != valor) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        printf("Valor %d no encontrado en la lista.\n", valor);
        return;
    }

    
    if (anterior == NULL) {
        *cabeza = actual->siguiente;  
    } else {
        
        anterior->siguiente = actual->siguiente;
    }

    printf("Eliminando nodo con valor %d.\n", actual->dato);
    free(actual);
}


void liberar(struct Nodo *cabeza) {
    struct Nodo *actual = cabeza;
    struct Nodo *sig;

    while (actual != NULL) {
        sig = actual->siguiente;
        free(actual);
        actual = sig;
    }
}

int main(void) {
    struct Nodo *cabeza = NULL;
    int n, i, valor, valorEliminar;

    printf("=== PRACTICA 7: LISTA ENLAZADA SIMPLE ===\n\n");

    printf("¿Cuantos valores deseas insertar? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &valor);
        insertarInicio(&cabeza, valor);
        printf("Despues de insertar al inicio %d:\n", valor);
        recorrer(cabeza);
    }

    printf("\nRecorrido final de la lista:\n");
    recorrer(cabeza);

    printf("\nValor que deseas eliminar: ");
    scanf("%d", &valorEliminar);

    eliminar(&cabeza, valorEliminar);

    printf("Lista despues de la eliminacion:\n");
    recorrer(cabeza);

    
    liberar(cabeza);
    printf("\nMemoria liberada correctamente.\n");

    return 0;
}
