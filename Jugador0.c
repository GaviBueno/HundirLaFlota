#include "Jugador0.h"
#include <iostream>
#include <cstdio>
#include <stdlib.h>

Coordenada jugador0(int tam_mapa){
    // Inicializa el Modo Automatico y baraja la lista de coordenadas que usaremos para buscar los barcos
    int total_coord=tam_mapa*tam_mapa;
    Coordenada coord[total_coord];
    for (int i = 0; i < tam_mapa; i++) {
        for (int j = 0; j < tam_mapa; j++) {
            coord[i * tam_mapa + j].x = i;
            coord[i * tam_mapa + j].y = j;
        }
    }
    barajar(coord, total_coord);
    return coord[];
}

Coordenada cazador(int barcos[], int tam_mapa, Coordenada coord[],int *indice){
    //Respuesta del disparo
    int x = coord[*indice].x;
    int y = coord[*indice].y;

    // Se envia a la seccion de jugabilidad las coordenadas para que esta indique a MAto si es agua, tocado o hundido
    //TODO
    //char res = disparo(x,y);
    if(res=="a"){
        coord[*indice].x = -1;
        coord[*indice].y = -1;
        *indice++;
    }
    if(res=="t"){
        /*
        t
        Comprobamos la ultima
        if({10,10})
            {Alrededor, Aleatorio, {10,10}, {x,y}}
        else
            buscarEstrategia
                -> {x,y}
                -> -{x,y}
            Poner -{x,y}
        */
    }
    return coord[];
}

//__Metodos_Auxiliares__
// Función para reorganizar el vector A
void barajar(Coordenada *xy, int total) {
    // Algoritmo Fisher-Yates para barajar las coordenadas
    for (int i = total - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        intercambiar(&xy[i], &xy[j]);
    }
}   void intercambiar(Coordenada *a, Coordenada *b) {
    // Función para intercambiar dos elementos
    Coordenada aux = *a;
    *a = *b;
    *b = aux;
}

int enRango(int x, int y, int tam_mapa) {
    return x >= 0 && x < tam_mapa && y >= 0 && y < tam_mapa;
}

    void reorganizar(Coordenada A[], int tamA, Coordenada B[], int tamB) {
        Coordenada resultado[tamA];
        int indice = 0;
    
        // Primero, agregar las coordenadas de A que están en B
        for (int i = 0; i < tamA; i++) {
            if (estaEnB(A[i], B, tamB)) {
                resultado[indice++] = A[i];
            }
        }
    
        // Luego, agregar las coordenadas restantes que no sean {0,0}
        for (int i = 0; i < tamA; i++) {
            if (!estaEnB(A[i], B, tamB) && !(A[i].x == 0 && A[i].y == 0)) {
                resultado[indice++] = A[i];
            }
        }
    
        // Finalmente, agregar las coordenadas {0,0}
        for (int i = 0; i < tamA; i++) {
            if (A[i].x == 0 && A[i].y == 0) {
                resultado[indice++] = A[i];
            }
        }
    
        // Copiar el resultado a A
        for (int i = 0; i < tamA; i++) {
            A[i] = resultado[i];
        }
    }
    
    

// Función para verificar si una coordenada está en B
int estaEnB(Coordenada coord, Coordenada B[], int tamB) {
    for (int i = 0; i < tamB; i++) {
        if (coord.x == B[i].x && coord.y == B[i].y) {
            return 1; // Encontrado en B
        }
    }
    return 0; // No encontrado en B
}