#include "jugador0.h"
#include <stdio.h>

char res;

void inicializar(int tam_mapa, Coordenada coord[])  {
    int total = tam_mapa * tam_mapa;
    // Devuelve una coordenada aleatoria no usada aún
        srand(time(0));
        // Función para inicializar coordenadas aleatorias
        for (int i = 0; i < tam_mapa; ++i) {
            for (int j = 0; j < tam_mapa; ++j) {
                coord[i * tam_mapa + j].x = i+1;
                coord[i * tam_mapa + j].y = j+1;
            }
        }
    barajar(coord, total);
}

void cazador(int tam_mapa, Coordenada coord[]) {
    // Modo cazador (más inteligente tras un acierto)
    int total = tam_mapa * tam_mapa;
    Coordenada c;
    c.x = jugador(tam_mapa, coord).x;
    c.y = jugador(tam_mapa, coord).y;
    char res = disparo(c.x-1, c.y-1);
    if (res == 'a') marcarAgua(tam_mapa, c, coord);
        // Marcamos como usado
    if (res == 't') {
        Coordenada z;
        z.x = coord[80].x;
        z.y = coord[80].y;
        int x = c.x;
        int y = c.y;
        Coordenada inicio;
        inicio.x = absolute(z.x);
        inicio.y = absolute(z.y);
        Coordenada aux;
        // Aquí podrías insertar una lógica de búsqueda más avanzada
        if(z.x>=0) {
                printf("  - inicio_cazador\n");
                reordenarDespuesDeTocado(tam_mapa, c, coord);
                printf("  - reorden\n");
                for (int i = 0; i < total; i++) {
                    printf("%d:(%d, %d), ", i, coord[i].x, coord[i].y);
                }
                printf("\n");
                cazador(tam_mapa, coord);
                printf("  - fin_cazador \n");
        }
        else    {
            if(c.y == absolute(z.y)) {
                printf("  - y\n");
                if(z.y > 0) {
                    for (int i = 1; i < tam_mapa+1; i++) {
                        x++;
                        if (x > 0 && x < tam_mapa+1) {
                            res = disparo(c.x+i-1, c.y-1);
                            if(res == 'a') {
                                coord[total-1].x = z.x;
                                coord[total-1].y = -z.y;
                                aux.x = c.x+i;
                                aux.y = c.y;
                                marcarContornoBarcoHundido(aux, inicio, tam_mapa, coord);
                                coord[0].x = c.x;
                                coord[0].y = c.y;
                                break;
                            }
                            if(res == 'h')   {
                                coord[total-1].x = 0;
                                coord[total-1].y = 0;  // Reset del estado de persecución
                                aux.x = c.x+i;
                                aux.y = c.y;
                                marcarContornoBarcoHundido(aux, inicio, tam_mapa, coord);
                                marcarAgua(tam_mapa, aux, coord);
                                barajar(coord, tam_mapa*tam_mapa);
                                cazador(tam_mapa, coord);
                                res = 'm';
                                break;
                            }
                        }
                        else {
                            z.x = z.x;
                            z.y = -z.y;
                            coord[total-1].x = z.x;
                            coord[total-1].y = z.y;
                            aux.x = c.x+i;
                            aux.y = c.y+i;
                            marcarContornoBarcoHundido(aux, inicio, tam_mapa, coord);
                            marcarAgua(tam_mapa, aux, coord);
                            break;
                        }
                    }
                }
                if(z.y < 0){
                    for (int i = 1; i < tam_mapa+1; i++) {
                        if(disparo(c.x-i-1, c.y-1) == 'h')   {
                            coord[total-1].x = 0;
                            coord[total-1].y = 0;  // Reset del estado de persecución
                            aux.x = c.x-i;
                            aux.y = c.y;
                            marcarContornoBarcoHundido(aux, inicio, tam_mapa, coord);
                            marcarAgua(tam_mapa, aux, coord);
                            barajar(coord, tam_mapa*tam_mapa);
                            cazador(tam_mapa, coord);
                            res = 'm';
                            break;
                        }
                    }
                }
            }
            else if(c.x == abs(z.x)) {
                                    printf("  - x\n");
                if(z.y > 0) {
                    for (int i = 1; i < tam_mapa+1; i++) {
                        y++;
                        if (y > 0 && y < tam_mapa+1) {
                            res = disparo(c.x-1, c.y+i-1);
                            if(res == 'a') {
                                coord[total-1].x = z.x;
                                coord[total-1].y = -z.y;
                                aux.x = c.x;
                                aux.y = c.y+i-1;
                                marcarContornoBarcoHundido(aux, inicio, tam_mapa, coord);
                                coord[0].x = c.x;
                                coord[0].y = c.y;
                                break;
                            }
                            if(res == 'h')   {
                                coord[total-1].x = 0;
                                coord[total-1].y = 0;  // Reset del estado de persecución                                aux.x = c.x+i;
                                aux.x = c.x;
                                aux.y = c.y+i-1;
                                marcarContornoBarcoHundido(aux, inicio, tam_mapa, coord);
                                marcarAgua(tam_mapa, aux, coord);
                                barajar(coord, tam_mapa*tam_mapa);
                                cazador(tam_mapa, coord);
                                res = 'm';
                                break;
                            }
                        }
                        else {
                            coord[total-1].x = z.x;
                            coord[total-1].y = -z.y;
                            aux.x = c.x;
                            aux.y = c.y+i;
                            marcarContornoBarcoHundido(aux, inicio, tam_mapa, coord);
                            marcarAgua(tam_mapa, aux, coord);
                            break;
                        }
                    }
                }
                if(z.y < 0){
                    for (int i = 1; i < tam_mapa+1; i++) {
                        if(disparo(c.x-1, c.y-i-1) == 'h')
                            coord[total-1].x = 0;
                            coord[total-1].y = 0;  // Reset del estado de persecución
                            aux.x = c.x-i;
                            aux.y = c.y;
                            marcarContornoBarcoHundido(aux, inicio, tam_mapa, coord);
                            marcarAgua(tam_mapa, aux, coord);
                            barajar(coord, tam_mapa*tam_mapa);
                            cazador(tam_mapa, coord);
                            res = 'm';
                            break;
                        }
                    }
                }
            else {
                                    printf("  - diagonal\n");
                if(z.y > 0) {
                    if (c.x+c.y != inicio.x+inicio.y) {
                            printf("  - diagonal '/' down \n");
                        for (int i = 1; i < tam_mapa+1; i++) {
                            y++;
                            x++;
                            if (y > 0 && y < tam_mapa+1 && x > 0 && x < tam_mapa+1) {
                                res = disparo(c.x+i-1, c.y+i-1);
                                if(res == 'a') {
                                    coord[total-1].x = z.x;
                                    coord[total-1].y = -z.y;
                                    aux.x = c.x+i-1;
                                    aux.y = c.y+i-1;
                                    marcarContornoBarcoHundido(aux, inicio, tam_mapa, coord);
                                    coord[0].x = c.x;
                                    coord[0].y = c.y;
                                    break;
                                }
                                if(res == 'h')   {
                                    coord[total-1].x = 0;
                                    coord[total-1].y = 0;  // Reset del estado de persecución
                                    aux.x = c.x+i;
                                    aux.y = c.y+i;
                                    marcarContornoBarcoHundido(aux, inicio, tam_mapa, coord);
                                    marcarAgua(tam_mapa, aux, coord);
                                    barajar(coord, tam_mapa*tam_mapa);
                                    cazador(tam_mapa, coord);
                                    res = 'm';
                                    break;
                                }
                            }
                            else {
                                z.x = z.x;
                                z.y = -z.y;
                                coord[total-1].x = z.x;
                                coord[total-1].y = z.y;
                                aux.x = c.x+i;
                                aux.y = c.y+i;
                                marcarContornoBarcoHundido(aux, inicio, tam_mapa, coord);
                                marcarAgua(tam_mapa, aux, coord);
                                break;
                            }
                        }
                    }
                    else {
                        printf("  - diagonal '\' down \n");
                        for (int i = 1; i < tam_mapa+1; i++) {
                            y++;
                            x--;
                            if (y > 0 && y < tam_mapa+1 && x > 0 && x < tam_mapa+1) {
                                res = disparo(c.x-i-1, c.y+i-1);
                                if(res == 'a') {
                                    coord[total-1].x = z.x;
                                    coord[total-1].y = -z.y;
                                    aux.x = c.x-i-1;
                                    aux.y = c.y+i-1;
                                    marcarContornoBarcoHundido(aux, inicio, tam_mapa, coord);
                                    coord[0].x = c.x;
                                    coord[0].y = c.y;
                                    break;
                                }
                                if(res == 'h')   {
                                    coord[total-1].x = 0;
                                    coord[total-1].y = 0;  // Reset del estado de persecución
                                    aux.x = c.x-i;
                                    aux.y = c.y+i;
                                    marcarContornoBarcoHundido(aux, inicio, tam_mapa, coord);
                                    marcarAgua(tam_mapa, aux, coord);
                                    barajar(coord, tam_mapa*tam_mapa);
                                    cazador(tam_mapa, coord);
                                    res = 'm';
                                    break;
                                }
                            }
                            else {
                                z.x = z.x;
                                z.y = -z.y;
                                coord[total-1].x = z.x;
                                coord[total-1].y = z.y;
                                aux.x = c.x-i;
                                aux.y = c.y+i;
                                marcarContornoBarcoHundido(aux, inicio, tam_mapa, coord);
                                marcarAgua(tam_mapa, aux, coord);
                                break;
                            }
                        }
                    }
                }
                if(z.y < 0){
                    if(c.x+c.y != inicio.x+inicio.y){
                        for (int i = 1; i < tam_mapa+1; i++) {
                            if(disparo(c.x-i-1, c.y-i-1) == 'h')   {
                                coord[total-1].x = 0;
                                coord[total-1].y = 0;  // Reset del estado de persecución
                                aux.x = c.x-i;
                                aux.y = c.y-i;
                                marcarContornoBarcoHundido(aux, inicio, tam_mapa, coord);
                                marcarAgua(tam_mapa, aux, coord);
                                barajar(coord, tam_mapa*tam_mapa);
                                cazador(tam_mapa, coord);
                                res = 'm';
                                break;
                            }
                        }
                    }
                    else {
                        for (int i = 1; i < tam_mapa+1; i++) {
                            if(disparo(c.x+i-1, c.y-i-1) == 'h')   {
                                coord[total-1].x = 0;
                                coord[total-1].y = 0;  // Reset del estado de persecución
                                aux.x = c.x+i;
                                aux.y = c.y-i;
                                marcarContornoBarcoHundido(aux, inicio, tam_mapa, coord);
                                marcarAgua(tam_mapa, aux, coord);
                                barajar(coord, tam_mapa*tam_mapa);
                                cazador(tam_mapa, coord);
                                res = 'm';
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    else {
        if (res == 'h') {
            Coordenada inicio;
            inicio.x = absolute(coord[total-1].x);
            inicio.y = absolute(coord[total-1].y);
            coord[total-1].x = 0;
            coord[total-1].y = 0;  // Reset del estado de persecución
            marcarContornoBarcoHundido(c, inicio, tam_mapa, coord);
            marcarAgua(tam_mapa, c, coord);
            barajar(coord, tam_mapa*tam_mapa);
            cazador(tam_mapa, coord);
        }
    }
    if (res == 'm') {
        for (int i = 0; i < total; i++) {
            printf("%d:(%d, %d), ", i, coord[i].x, coord[i].y);
        }
        printf("\n");
    }
    printf(" . ");
}



//__Metodos_Auxiliares__

void barajar(Coordenada coord[], int total) {
    Coordenada aux = {0, 0};
    // Algoritmo Fisher-Yates para barajar las coordenadas
    for (int i = total - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        aux = coord[i];
        coord[i] = coord[j];
        coord[j] = aux;
    }
}

Coordenada jugador(int tam_mapa, Coordenada coord[]) {
    int indice = 0;
    Coordenada agua;
    agua.x = 0;
    agua.y = 0;
    // Devuelve una coordenada aleatoria no usada aún
    while ((coord[indice].x == 0 || coord[indice].y == 0) && indice < tam_mapa * tam_mapa) {
        ++indice;
    }
    if (indice < tam_mapa * tam_mapa) {
        return coord[indice];
    }
    return agua; // No quedan coordenadas válidas
}

void marcarAgua(int tam_mapa, Coordenada c, Coordenada coord[]){
    for (int i = 0; i < tam_mapa * tam_mapa; ++i) {
        if (coord[i].x == c.x && coord[i].y == c.y) {
            coord[i].x = 0;
            coord[i].y = 0;
            break;
        }
    }
}

void reordenarDespuesDeTocado(int tam_mapa, Coordenada tocado, Coordenada coord[]) {
    int total = tam_mapa*tam_mapa;
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int nx = 0;
    int ny = 0;
    int a = 0;
    int b = 0;
    Coordenada aux;
    for (int i = 0; i < 8; ++i) {
        nx = tocado.x + dx[i];
        ny = tocado.y + dy[i];
        printf("%d ->(%d, %d) \n", i, nx, ny);
        if (nx > 0 && nx < tam_mapa+1 && ny > 0 && ny < tam_mapa+1) {
            a = 0;
            while((coord[a].x != nx || coord[a].y != ny) && a < total){
                a++;
                //printf("  - bucle reordenar");
            }
            if (a < total) {
                printf("  - cambio reordenar\n");
                aux = coord[a];
                coord[a] = coord[b];
                coord[b++] = aux;
            }
            for (int i = 0; i < total; i++) {
                printf("%d:(%d, %d), ", i, coord[i].x, coord[i].y);
            }
            printf("\n");
        }
    }
    for (int i = 0; i < total; ++i) {
        if (tocado.x == coord[i].x && tocado.y == coord[i].y) {
            aux = coord[total-1];
            coord[total-1].x = -tocado.x;
            coord[total-1].y = tocado.y;
            coord[i] = aux;
        }
    }
}
void marcarAlrededor(int x, int y, int tam, Coordenada coord[]) {
    // Obtiene las coordenadas alrededor de una celda
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int nx = 0;
    int ny = 0;
    Coordenada n;
    for (int i = 0; i < 8; ++i) {
        nx = x + dx[i];
        ny = y + dy[i];
        if (nx > 0 && nx < tam+1 && ny > 0 && ny < tam+1) {
            n.x = nx;
            n.y = ny;
            marcarAgua(tam, n, coord);
        }
    }
}

void marcarContornoBarcoHundido(Coordenada fin, Coordenada inicio, int tam_mapa, Coordenada coord[]) {
    int aux = 0;
    Coordenada inter;
    if (fin.x == inicio.x) {
        aux = absolute(inicio.y-fin.y);
        for (int i = 0; i < aux+1; ++i) {
            if (inicio.y < fin.y)   marcarAlrededor(inicio.x, inicio.y+i, tam_mapa, coord);
            else    marcarAlrededor(fin.x, fin.y+i, tam_mapa, coord);
        }
    }
    if (fin.y == inicio.y) {
        aux = absolute(inicio.x-fin.x);
        for (int i = 0; i < aux+1; ++i) {
            if (inicio.x < fin.x)   marcarAlrededor(inicio.x+i, inicio.y, tam_mapa, coord);
            else    marcarAlrededor(fin.x+i, fin.y, tam_mapa, coord);
        }
    }
    else {
        aux = absolute(inicio.y-fin.y);
        for (int i = 0; i < aux+1; ++i) {
            if (inicio.y < fin.y) {
                if (fin.y+fin.x != inicio.y+inicio.x)   marcarAlrededor(inicio.x+i, inicio.y+i, tam_mapa, coord);
                else    marcarAlrededor(inicio.x-i, inicio.y+i, tam_mapa, coord);
            }
            else {
                if (fin.y+fin.x != inicio.y+inicio.x) marcarAlrededor(fin.x+i, fin.y+i, tam_mapa, coord);
                else    marcarAlrededor(fin.x+i, fin.y-i, tam_mapa, coord);
            }
        }
    }
    coord[0] = fin;
}

int absolute(int num) {
    if(num >= 0) {
        return num;
    }
    return -num;
}