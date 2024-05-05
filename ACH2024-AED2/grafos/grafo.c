#include <stdlib.h>;

#define true 1
#define false 0 

typedef int bool;

typedef struct _grafo_{
    int numVertices;
    int numArestas;
    bool** matriz;
} Grafo;

bool inicializaGrafo(Grafo *g, int vertices){
    if(g == NULL  || vertices<1) return 0;
    g->matriz = (bool**) malloc(sizeof(bool**)*vertices);
    g->numVertices = vertices;
    g->numArestas = 0;
    int x, y;
    for(x = 0; x < g->numVertices; x++){
        g->matriz[x] = (bool**) malloc(sizeof(bool**)*vertices);
        for(y = 0; y < g->numVertices; y++){
            g->matriz[x][y] = false;
        }
    }
    return true;
}

bool liberaGrafo(Grafo *g){
    if(g == NULL || g->matriz == NULL) return 0;
    int i;
    for(i = 0; i < g->numVertices; i++){
        free(g->matriz[i]);
    }
    free(g->matriz);
    g->numArestas = 0;
    g->numVertices = 0;
    g->matriz = NULL;
    return 1;
}

int numeroDeVerticesGrafo(Grafo *g){
    if (g == NULL || g->matriz == NULL) return -1;
    return g->numVertices;
}


int main(){

}