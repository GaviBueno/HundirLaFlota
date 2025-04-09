#include "jugador0.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

static int indice = 0;
static Coordenada coord[81]; // Tamaño máximo para tam_mapa = 9
static bool inicializado = false;

// Simulación del resultado del disparo
char disparo(int x, int y) {
    // Esta función debe conectarse con la lógica del juego.
    // Aquí se simula el resultado para propósitos de prueba:
    return "atahundido"[rand() % 3]; // 'a', 't' o 'h'
}

Coordenada jugador0(int tam_mapa) {
    // Devuelve una coordenada aleatoria no usada aún
    if (!inicializado) {
        srand(time(0));
        inicializar(tam_mapa);
        inicializado = true;
    }
    while (indice < tam_mapa * tam_mapa && coord[indice].x == 10 && coord[indice].y == 10) {
        ++indice;
    }
    if (indice < tam_mapa * tam_mapa) {
        return coord[indice++];
    } else {
        return {10, 10}; // No quedan coordenadas válidas
    }
}

Coordenada cazador(int tam_mapa) {
    // Modo cazador (más inteligente tras un acierto)
    Coordenada c = jugador0(tam_mapa);
    char res = disparo(c.x, c.y);
    if (res == 'a') {
        // Marcamos como usado
        for (int i = 0; i < tam_mapa * tam_mapa; ++i) {
            if (coord[i].x == c.x && coord[i].y == c.y) {
                coord[i] = {10, 10};
                break;
            }
        }
    } else if (res == 't') {
        Coordenada z = coord[80];
        // Aquí podrías insertar una lógica de búsqueda más avanzada
        if(z.x>=0){
            reordenarDespuesDeTocado(tam_mapa, c);
            indice = 0;
            cazador(int tam_mapa);
        }   else    {
            if(c.y==abs(z.y)){
                if(z.y<0){
                    //Reordenar vectorial para disparar hacia abajo de la y
                }   else    {
                    //Reordenar vectorial para disparar hacia arriba de la y
                    z.y = -z.y;
                }
            }
            if(c.x==abs(z.x)){
                if(z.y<0){
                    //Reordenar horizontal para disparar hacia abajo de la x
                }   else    {
                    //Reordenar horizontal para disparar hacia arriba de la x
                    z.y = -z.y;
                }
            }   else    {
                if(z.y<0){
                    //Reordenar diagonal para disparar hacia abajo de la y
                }   else    {
                    //Reordenar diagonal para disparar hacia arriba de la y
                    z.y = -z.y;
                }
            }
        }

        // Priorizar en la lista para el siguiente disparo, etc.
    }
    return c;
}



//__Metodos_Auxiliares__

void inicializar(int tam_mapa)  {
    // Función para inicializar coordenadas aleatorias
    int total_coord = tam_mapa * tam_mapa;
    for (int i = 0; i < tam_mapa; ++i) {
        for (int j = 0; j < tam_mapa; ++j) {
            coord[i * tam_mapa + j].x = i;
            coord[i * tam_mapa + j].y = j;
        }
    }
    barajar(coord, total_coord);
    indice = 0;
}   void barajar(Coordenada *xy, int total) {
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

void reordenarDespuesDeTocado(int tam_mapa, Coordenada tocada) {
    vector<Coordenada> alrededor = obtenerAlrededor(tocada.x, tocada.y, tam_mapa);
    vector<Coordenada> aleatorios;
    vector<Coordenada> agua;
    // Clasificamos el contenido actual de coord[]
    for (int i = 0; i < tam_mapa * tam_mapa; ++i) {
        Coordenada actual = coord[i];
        if (actual.x == 10 && actual.y == 10) {
            agua.push_back(actual);
        } else if (actual.x == tocada.x && actual.y == tocada.y) {
            continue; // Saltamos la tocada, se pone al final
        } else {
            bool esAlrededor = false;
            for (const auto& a : alrededor) {
                if (actual.x == a.x && actual.y == a.y) {
                    esAlrededor = true;
                    break;
                }
            }
            if (!esAlrededor) {
                aleatorios.push_back(actual);
            }
        }
    }
    // Reconstruimos el vector coord[]
    int index = 0;
    for (const auto& a : alrededor) {
        coord[index++] = a;
    }
    for (const auto& a : aleatorios) {
        coord[index++] = a;
    }
    for (const auto& a : agua) {
        coord[index++] = a;
    }
    Coordenada fin= [-tocada.x,tocada.y];
    coord[index++] = fin;
}   vector<Coordenada> obtenerAlrededor(int x, int y, int tam) {
    // Obtiene las coordenadas alrededor de una celda
    vector<Coordenada> alrededor;
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < tam && ny >= 0 && ny < tam) {
            alrededor.push_back({nx, ny});
        }
    }
    return alrededor;
}