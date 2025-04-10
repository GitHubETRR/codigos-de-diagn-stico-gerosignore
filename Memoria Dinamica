#include <stdio.h>
#include <stdlib.h>

float calcularPromedio(int *arr, int n);

int main(){
    int n;

    printf("Ingrese el número de elementos: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return 1;
    }

    printf("Ingrese %d números:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", arr + i);
    }

    printf("\nValores ingresados: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }

    float promedio = calcularPromedio(arr, n);
    printf("\nEl promedio es: %.2f\n", promedio);


    free(arr);

    return 0;
}

float calcularPromedio(int *arr, int n) {
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += *(arr + i);
    }
    return (float)suma / n;
}
