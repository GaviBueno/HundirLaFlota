#ifndef Jugador0_H
#define Jugador0_H

#include <stdio.h>

typedef struct {
    int x;
    int y;
} Coordenada;

// Declaraciones públicas necesarias
void inicializar(int tam_mapa, Coordenada coord[]);
void cazador(int tam_mapa, Coordenada coord[]);
Coordenada jugador(int tam_mapa, Coordenada coord[]);
void barajar(Coordenada coord[], int total);
void marcarAgua(int tam_mapa, Coordenada c, Coordenada coord[]);
void reordenarDespuesDeTocado(int tam_mapa, Coordenada tocado, Coordenada coord[]);
void marcarAlrededor(int x, int y, int tam, Coordenada coord[]);
void marcarContornoBarcoHundido(Coordenada fin, Coordenada inicio, int tam_mapa, Coordenada coord[]);
char disparo(int x, int y); // esta se redefine en el test

#endif