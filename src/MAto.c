#include "MAto.h"
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
void cazador(int barcos[], int tam_mapa, Coordenada coord[],int *indice){
        if(res=="a")     *indice++;
        if(res=="t"){

        }
/*
Tocado
        -> Lo busca t cambia la lista
        tiene la lista porq lo ha encontrai
*/

    
    char res = "a";
    int x=coord[*indice].x;
    int y=coord[*indice].y;
    *indice++;
    if(enRango(x, y, tam_mapa)){
        // Se envia a la seccion de jugabilidad las coordenadas para que esta indique a MAto si es agua, tocado o hundido
        //TODO
        //char res = disparo(x,y);
    }   else    {
        
        cazador(barcos[], tam_mapa, mapa[][], coord[], *indice);
    }
    if ("t"==res){
        int dx[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
        int dy[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            // TODO Crear funcion buscar
            coord[*indice].x=-1;
            coord[*indice].y=-1;
            if (enRango(nx, ny, tam_mapa)) {
                // Se envia a la seccion de jugabilidad las dos coordenadas para que esta indique a MAto si es agua, tocado o hundido
                //TODO
                //char res = disparo(coord[*indice]);
                char res = "t";
                if (res=="t"){
                    destruir(x,y,,nx,ny,barcos[]);
                    break;
                }        
            }
        }
    }

}
void destruir(int x, int y, int nx, int ny, int barcos[]){
//destruimos al barco
    if(y==ny){
    //Horizontal
        for(g=i;g=!10000;g++){
            // Se envia a la seccion de jugabilidad las dos coordenadas para que esta indique a MAto si es agua, tocado o hundido
            //TODO
            //char res = disparo(g, j);
            if(res=="a")  for(h=i;g=!10000;g--){
                // Se envia a la seccion de jugabilidad las dos coordenadas para que esta indique a MAto si es agua, tocado o hundido
                //TODO
                //char res = disparo(g, j);
                if(res=="h"){

                }
            }if(res=="h"){
                
            }
        }
    }if(x==i){
    //Vertical
    }else
    //Diagonal
}

// __AUXILIARES__
void barajar(Coordenada *xy, int total) {
// Algoritmo Fisher-Yates para barajar las coordenadas
    for (int i = total - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        intercambiar(&xy[i], &xy[j]);
    }
}
void intercambiar(Coordenada *a, Coordenada *b) {
// Función para intercambiar dos elementos
    Coordenada aux = *a;
    *a = *b;
    *b = aux;
}
int enRango(int x, int y, int tam_mapa) {
    return x >= 0 && x < tam_mapa && y >= 0 && y < tam_mapa;
}

void setBarcos(int n, int barcos[]){

}
/*Metodo IA(proporciones, barcos){
    Proporciones => Crear matriz formada por 0 (o recibirla porq ya se ha creado)
    Crear una posicion random
    Enviar la "posicion random" al mapa y que me diga que hay alli
    Si recibo "tocado" ponemos un 2
        Ataca alrededor y para buscar al barco
        Repite el bucle hasta recibir hundido
        Elimina el barco de la lista "barcos"
    Si es agua repite el bucle 
}
*/

    //__SUCIO__
void pruebas(){
        // n es la proporcion del mapa con el que vamos a jugar
        // barcos es un vector de enteros del tamaño de los barcos
            //mapa será la matriz que usara el MAto (Modo Automatico) para seguir el juego y decidir que hacer
            int** mapa = crearMatriz(n);
            bombardeo();
        void bombardeo()
}
int** crearMatriz(int n) {
// Función para crear una matriz inicializada en ceros
    int** m = (int**)malloc(n * sizeof(int*));
    if (m == NULL) {
        printf("Error: No se pudo asignar memoria para las filas.\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        m[i] = (int*)calloc(n, sizeof(int));  // calloc inicializa en ceros
        if (m[i] == NULL) {
            printf("Error: No se pudo asignar memoria para las columnas.\n");
            exit(1);
        }
    }
    return m;
}

void modificarValor(int** m, int f, int c, int v) {
// Función para modificar un valor de la matriz
    m[f][c] = v;
}

void liberarMatriz(int** m, int n) {
// Función para liberar la memoria
    for (int i = 0; i < n; i++) {
        free(m[i]);
    }
    free(m);
}