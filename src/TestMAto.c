#include <stdio.h>
#include <stdlib.h> // Para malloc y free

int main() {
    int n;
    printf("¿Cuántos elementos deseas? ");
    scanf("%d", &n);

    // Reservar memoria para 'n' elementos enteros
    int* numeros = (int*)malloc(n * sizeof(int));

    // Verificar si la asignación fue exitosa
    if (numeros == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return 1;
    }

    // Asignar valores al array
    for (int i = 0; i < n; i++) {
        numeros[i] = i * 2; // Ejemplo de datos
    }

    // Mostrar el contenido
    printf("Valores del array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", numeros[i]);
    }

    // Liberar la memoria reservada
    free(numeros);

    return 0;
}