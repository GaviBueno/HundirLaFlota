#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "jugador0.h"

#define TAM_MAPA 9
#define MAX_DISPAROS 100

char mapa[TAM_MAPA][TAM_MAPA];  // Mapa del juego: '.' agua, 'B' barco
int inicializado = 0;

// Simula barcos en el mapa
void inicializar_mapa() {
    memset(mapa, '.', sizeof(mapa));

    // Barcos horizontales
    mapa[2][1] = 'B';
    mapa[2][2] = 'B';
    mapa[2][3] = 'B';

    // Barcos verticales
    mapa[6][1] = 'C';
    mapa[7][1] = 'C';
    mapa[8][1] = 'C';
    mapa[5][1] = 'C';

    // Barco diagonal
    mapa[6][5] = 'D';
    mapa[4][3] = 'D';
    mapa[5][4] = 'D';

    mapa[0][8] = 'E';
    mapa[1][7] = 'E';
}

// Disparo simulado según el mapa real
char resultado_disparo(Coordenada c) {
    int x = c.x;
    int y = c.y;

    if (x < 0 || x >= TAM_MAPA || y < 0 || y >= TAM_MAPA)
        return 'a'; // fuera de límites = agua

    if (mapa[x][y] == 'B') {
        mapa[x][y] = 'X';

        // Verificamos si el barco está completamente hundido
        for (int i = 0; i < TAM_MAPA; i++) {
            for (int j = 0; j < TAM_MAPA; j++) {
                if (mapa[i][j] == 'B')
                    return 't';  // aún quedan partes
            }
        }
        return 'h';  // todos los barcos fueron hundidos
    }

    if (mapa[x][y] == 'C') {
        mapa[x][y] = 'X';

        // Verificamos si el barco está completamente hundido
        for (int i = 0; i < TAM_MAPA; i++) {
            for (int j = 0; j < TAM_MAPA; j++) {
                if (mapa[i][j] == 'C')
                    return 't';  // aún quedan partes
            }
        }
        return 'h';  // todos los barcos fueron hundidos
    }

    if (mapa[x][y] == 'D') {
        mapa[x][y] = 'X';

        // Verificamos si el barco está completamente hundido
        for (int i = 0; i < TAM_MAPA; i++) {
            for (int j = 0; j < TAM_MAPA; j++) {
                if (mapa[i][j] == 'D')
                    return 't';  // aún quedan partes
            }
        }
        return 'h';  // todos los barcos fueron hundidos
    }
    if (mapa[x][y] == 'E') {
        mapa[x][y] = 'X';
        for (int i = 0; i < TAM_MAPA; i++) {
            for (int j = 0; j < TAM_MAPA; j++) {
                if (mapa[i][j] == 'E')  return 't';  // aún quedan partes
            }
        }
        return 'h';  // todos los barcos fueron hundidos
    }

    if (mapa[x][y] == 'X') {
        return 't';
    }
    return 'a'; // Agua
}

// Redefinimos la función `disparo` usada por la IA
char disparo(int x, int y) {
    Coordenada c = { x, y };
    char r = resultado_disparo(c);
    printf("Disparo en (%d, %d): %c\n", x, y, r);
    return r;
}

int main() {
    inicializar_mapa();
    printf("=== INICIO DEL TEST DE LA IA ===\n");

    Coordenada coord[81];
    inicializar(TAM_MAPA, coord);  // Inicializa coordenadas
    for (int i = 0; i < 81; i++) {
        printf("%d:(%d, %d), ", i, coord[i].x, coord[i].y);
    }
    for (int turno = 0; turno < MAX_DISPAROS; turno++) {
        printf("%d -> ",turno);
        cazador(TAM_MAPA, coord);
        int point = 0;
        for (int i = 0; i < TAM_MAPA; i++) {
            for (int j = 0; j < TAM_MAPA; j++) {
                if (mapa[i][j] == 'B' || mapa[i][j] == 'C' || mapa[i][j] == 'D' || mapa[i][j] == 'E')
                    point++;  // aún quedan partes
            }
        }
        if (point == 0) {
            for (int i = 0; i < 81; i++) {
                printf("%d:(%d, %d), ", i, coord[i].x, coord[i].y);
            }
            printf("=== FIN DEL TEST ===\n");
            return 0;
        }
    }
    return 0;
}