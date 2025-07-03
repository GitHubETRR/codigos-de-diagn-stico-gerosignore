#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRE 100
#define AGREGAR_NOM 1
#define MOSTRAR_NOM 2
#define SALIR 3

void guardar_nombre(const char* archivo, const char* nombre);
void mostrar_nombres(const char* archivo);

int main() {
    int opcion;
    char nombre[MAX_NOMBRE];
    const char* archivo = "nombres.txt";

    do {
        printf("\n--- MENÚ ---\n");
        printf("1. Agregar nombre\n");
        printf("2. Mostrar nombres\n");
        printf("3. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);
        getchar(); 

        switch (opcion) {
            case AGREGAR_NOM:
                printf("Ingrese el nombre: ");
                fgets(nombre, MAX_NOMBRE, stdin);
                nombre[strcspn(nombre, "\n")] = '\0';  
                guardar_nombre(archivo, nombre);
                break;
            case MOSTRAR_NOM:
                mostrar_nombres(archivo);
                break;
            case SALIR:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción inválida.\n");
        }
    } while (opcion != 3);

    return 0;
}

void guardar_nombre(const char* archivo, const char* nombre) {
    FILE* f = fopen(archivo, "a"); 
    if (f == NULL) {
        perror("Error al abrir el archivo para escribir");
        return;
    }
    fprintf(f, "%s\n", nombre);
    fclose(f);
}

void mostrar_nombres(const char* archivo) {
    FILE* f = fopen(archivo, "r");
    if (f == NULL) {
        perror("Error al abrir el archivo para leer");
        return;
    }

    char linea[MAX_NOMBRE];
    printf("\n--- Nombres guardados ---\n");
    while (fgets(linea, sizeof(linea), f)) {
        printf("%s", linea);
    }
    fclose(f);
}
