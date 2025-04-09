#include "Jugador0.h"
#include <iostream>
#include <cstdio>
#include <stdlib.h>

Coordenada jugador0(int tam_mapa = 9){
    // Inicializa el Modo Automatico y baraja la lista de coordenadas que usaremos para buscar los barcos
    int total_coord = tam_mapa*tam_mapa;
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

Coordenada cazador(Coordenada coord[], int *indice = 0, int tam_mapa = 9){
    //Respuesta del disparo
    Coordenada agua = Coordenada[10, 10];
    while(coord[*indice] == agua){
        *indice++;
    }
    int x = coord[*indice].x;
    int y = coord[*indice].y;
    /*
    Se envia a la seccion de jugabilidad las coordenadas para que esta indique a MAto si es agua, tocado o hundido
    TODO
    char res = disparo(x,y);
    */
    if(res=="a"){
        coord[0].x = 10;
        coord[0].y = 10;
    }
    if(res=="t"){
        if(coord[0] == agua){
            //Reordenamos
            //{Alrededor, Aleatorio, {10,10}, {x,y}}
            coord[]=cazador(coord[]);
        }   else    {
            /*Seguimos estrategia
                -> Horizontal
                -> Vertical
                -> Diagonal
                Sino -> Disparamos de nuevo con *indice++
            Reordenamos
            buscarEstrategia
                -> {x,y}
                -> -{x,y}
            Poner -{x,y}
            */
        }
    }
    return coord[];
}

//__Metodos_Auxiliares__
// *Función para reorganizar el vector coord
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