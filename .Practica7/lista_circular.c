

#include <stdio.h>
#include <stdlib.h>


struct Nodo {
    int dato;
    struct Nodo *siguiente;
};


struct Nodo *cabeza = NULL;
struct Nodo *ultimo = NULL;


void insertarInicioCircular(int valor) {
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("Error: no se pudo reservar memoria para el nodo.\n");
        return;
    }
    nuevo->dato = valor;

    if (cabeza == NULL) {
        
        cabeza = nuevo;
        ultimo = nuevo;
        nuevo->siguiente = nuevo;
    } else {
        
        nuevo->siguiente = cabeza;
        ultimo->siguiente = nuevo;
        cabeza = nuevo;
    }
}


void recorrerCircular(void) {
    struct Nodo *actual;

    if (cabeza == NULL) {
        printf("Lista circular vacia.\n");
        return;
    }

    actual = cabeza;
    printf("Lista circular: ");
    do {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    } while (actual != cabeza);
    printf("(vuelve a cabeza)\n");
}


void eliminarCircular(int valor) {
    struct Nodo *actual = cabeza;
    struct Nodo *anterior = ultimo;  

    if (cabeza == NULL) {
        printf("La lista esta vacia, no se puede eliminar.\n");
        return;
    }

    
    do {
        if (actual->dato == valor) {
            break;
        }
        anterior = actual;
        actual = actual->siguiente;
    } while (actual != cabeza);

    
    if (actual == cabeza && actual->dato != valor) {
        printf("Valor %d no encontrado en la lista circular.\n", valor);
        return;
    }

    
    if (actual == cabeza && actual == ultimo) {
        cabeza = NULL;
        ultimo = NULL;
    }
    
    else if (actual == cabeza) {
        cabeza = cabeza->siguiente;
        ultimo->siguiente = cabeza;
    }
    
    else if (actual == ultimo) {
        anterior->siguiente = cabeza;
        ultimo = anterior;
    }
    
    else {
        anterior->siguiente = actual->siguiente;
    }

    printf("Eliminando nodo con valor %d.\n", actual->dato);
    free(actual);
}


void liberarCircular(void) {
    struct Nodo *actual;
    struct Nodo *sig;

    if (cabeza == NULL) {
        return;
    }

    actual = cabeza;
    do {
        sig = actual->siguiente;
        free(actual);
        actual = sig;
    } while (actual != cabeza);

    cabeza = NULL;
    ultimo = NULL;
}

int main(void) {
    int n, i, valor, valorEliminar;

    printf("=== PRACTICA 7: LISTA ENLAZADA CIRCULAR ===\n\n");

    printf("¿Cuantos valores deseas insertar en la lista circular? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &valor);
        insertarInicioCircular(valor);
        printf("Despues de insertar al inicio %d:\n", valor);
        recorrerCircular();
    }

    printf("\nRecorrido final de la lista circular:\n");
    recorrerCircular();

    printf("\nValor que deseas eliminar de la lista circular: ");
    scanf("%d", &valorEliminar);

    eliminarCircular(valorEliminar);

    printf("Lista circular despues de la eliminacion:\n");
    recorrerCircular();

    liberarCircular();
    printf("\nMemoria liberada correctamente.\n");

    return 0;
}
