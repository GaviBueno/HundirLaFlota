#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5;

    // Reserva de memoria para una matriz de 3x3
    int** matriz = (int**)malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        matriz[i] = (int*)malloc(n * sizeof(int));
    }

    // Asignar valores
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = i + j;
        }
    }

    // Mostrar la matriz
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Liberar memoria
    for (int i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}