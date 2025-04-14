#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "jugador0.h"

#define TAM_MAPA 9
#define MAX_DISPAROS 100

char mapa[TAM_MAPA][TAM_MAPA];  // Mapa del juego: '.' agua, 'B' barco
char resultado_disparo(Coordenada c);

// Simula barcos en el mapa
void inicializar_mapa() {
    memset(mapa, '.', sizeof(mapa));

    // Barcos horizontales
    mapa[2][3] = 'B';
    mapa[2][4] = 'B';
    mapa[2][5] = 'B';

    // Barcos verticales
    mapa[6][1] = 'B';
    mapa[7][1] = 'B';
    mapa[8][1] = 'B';

    // Barco diagonal
    mapa[0][0] = 'B';
    mapa[1][1] = 'B';
    mapa[2][2] = 'B';
}

// Disparo simulado según el mapa real
char resultado_disparo(Coordenada c) {
    if (c.x < 0 || c.x >= TAM_MAPA || c.y < 0 || c.y >= TAM_MAPA)
        return 'a'; // fuera de límites = agua

    if (mapa[c.x][c.y] == 'B') {
        mapa[c.x][c.y] = 'X';

        // Verificamos si el barco está completamente hundido
        int tocado = 0;
        for (int i = 0; i < TAM_MAPA; i++) {
            for (int j = 0; j < TAM_MAPA; j++) {
                if (mapa[i][j] == 'B')
                    tocado++;
            }
        }

        return (tocado == 0) ? 'h' : 't';
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

    for (int turno = 0; turno < MAX_DISPAROS; ++turno) {
        Coordenada c = cazador(TAM_MAPA);
        if (c.x == 10 && c.y == 10) {
            printf("La IA no tiene más coordenadas válidas.\n");
            break;
        }
    }

    printf("=== FIN DEL TEST ===\n");
    return 0;
}