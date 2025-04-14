#ifndef Jugador0_H
#define Jugador0_H

#include <stdio.h>

typedef struct {
    int x;
    int y;
} Coordenada;

// Declaraciones públicas necesarias
Coordenada jugador0(int tam_mapa);
Coordenada cazador(int tam_mapa);
char disparo(int x, int y); // esta se redefine en el test

#endif