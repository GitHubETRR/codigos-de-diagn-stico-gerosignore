#include <stdio.h>
#include <stdlib.h>

#define VALORERROR -1

typedef struct Nodo {
    int valor;
    struct Nodo* siguiente;
} Nodo;

Nodo* crearNodo(int valor) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    if(nuevo==NULL){
        printf(" Error al asignar memoria");
        exit(VALORERROR);
    }else{
        nuevo->valor = valor;
        nuevo->siguiente = NULL;
        return nuevo;
    }
}

Nodo* insertarFinal(Nodo* cabeza, int valor) {
    Nodo* nuevo = crearNodo(valor);

    if (cabeza == NULL) {
        return nuevo;
    }

    Nodo* actual = cabeza;
    while (actual->siguiente != NULL) {
        actual = actual->siguiente;
    }
    actual->siguiente = nuevo;
    return cabeza;
}

void mostrarLista(Nodo* cabeza) {
    if (cabeza == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    printf("Lista: ");
    while (cabeza != NULL) {
        printf("%d -> ", cabeza->valor);
        cabeza = cabeza->siguiente;
    }
    printf("NULL\n");
}

void contarParesImpares(Nodo* cabeza, int* pares, int* impares) {
    *pares = 0;
    *impares = 0;

    while (cabeza != NULL) {
        if (cabeza->valor % 2 == 0){
            (*pares)++;
        }    
        else{
            (*impares)++;
        }
        cabeza = cabeza->siguiente;
    }
}

void liberarLista(Nodo* cabeza) {
    Nodo* temp;
    while (cabeza != NULL) {
        temp = cabeza;
        cabeza = cabeza->siguiente;
        free(temp);
    }
}

int main() {
    Nodo* lista = NULL;
    int opcion, valor;
    int pares, impares;

    do {
        printf("\n==== MENÚ ====\n");
        printf("1. Insertar número\n");
        printf("2. Mostrar lista\n");
        printf("3. Contar pares e impares\n");
        printf("4. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese un número: ");
                scanf("%d", &valor);
                lista = insertarFinal(lista, valor); 
                break;

            case 2:
                mostrarLista(lista);
                break;

            case 3:
                contarParesImpares(lista, &pares, &impares);
                printf("Cantidad de pares: %d\n", pares);
                printf("Cantidad de impares: %d\n", impares);
                break;

            case 4:
                liberarLista(lista);
                printf("Saliendo...\n");
                break;

            default:
                printf("Opción inválida.\n");
        }
    } while (opcion != 4);

    return 0;
}
