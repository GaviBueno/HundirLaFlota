#include "MAto.h"
#include <iostream>
#include <cstdio>
#include <stdlib.h>

void setBarcos(int n, int barcos[]){

}

void cazador(int barcos[], int tam, int** mapa){
    // Generar dos números aleatorios entre 0 y n (nuestras coordenadas en la matriz)
    int x = rand() % n;       
       int y = rand() % n;
        // Se envia a la seccion de jugabilidad las dos coordenadas para que esta indique a MAto si es agua, tocado o hundido
        //TODO
        //char res = disparo(coorf, coorc);
        char res = "a";
        if (res=="t"){
            mapa[x][y] = 2;
            for (int i = x - 1; i <= x + 1; i++) {
                for (int j = y - 1; j <= y + 1; j++) {
                    // Se envia a la seccion de jugabilidad las dos coordenadas para que esta indique a MAto si es agua, tocado o hundido
                    //TODO
                     //char res = disparo(i, j);
                    char res = "t";
                    if (res=="t"){
                        mapa[i][j] = 2;
                        destruir(x,y,i,j,barcos[]);
                        break
                    }
                }
        }
}
void destruir(int x, int y, int i, int j, int barcos[]){
//destruimos al barco
    if(y==j){
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