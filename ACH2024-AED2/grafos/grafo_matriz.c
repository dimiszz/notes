#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0 

typedef int bool;

typedef struct _grafo_{
    int numVertices;
    int numArestas;
    bool** matriz;
} Grafo;

char* convertBoolean(bool x){
    if (x) return "True";
    return "False";
}

bool inicializaGrafo(Grafo *g, int vertices){
    if(vertices<1) return 0;
    g->matriz = (bool**) malloc(sizeof(bool**)*vertices);
    g->numVertices = vertices;
    g->numArestas = 0;
    int x, y;
    for(x = 0; x < g->numVertices; x++){
        g->matriz[x] = (bool*) malloc(sizeof(bool*)*vertices);
        for(y = 0; y < g->numVertices; y++){
            g->matriz[x][y] = false;
        }
    }
    return true;
}

void imprimeGrafo(Grafo *g){
    if(g == NULL || g->matriz == NULL) return;
    int x, y;

    printf("Imprimindo grafo... vertices: %i; arestas: %i", g->numVertices, g->numArestas);

    printf("\n ");
    for(x = 0; x < g->numVertices; x++){
        printf("%5i", x);
    }
    printf("\n");
    for(x = 0; x < g->numVertices; x++){
        printf("%i", x);
        for(y = 0; y < g->numVertices; y++){
            printf("%5i", g->matriz[x][y]);
        }
        printf("\n");
    }
}

bool liberaGrafo(Grafo *g){
    if(g == NULL) return 0;
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

bool insereAresta(Grafo *g, int de, int para){
    if(g == NULL || g->matriz == NULL || 
        de >= g->numVertices || para >= g->numVertices || de < 0 || para<0) return false;
    if(!g->matriz[de][para]) g->numArestas++;
    g->matriz[de][para] = true;
    return true;
}

bool removeAresta(Grafo *g, int de, int para){
    if(g == NULL || g->matriz == NULL || 
    de >= g->numVertices || para >= g->numVertices) return false;
    if(g->matriz[de][para]) g->numArestas--;
    g->matriz[de][para] = false;
    return true;
}

bool existeAresta(Grafo *g, int de, int para){
    if(g == NULL || g->matriz == NULL ||
    de >= g->numVertices || para >= g->numVertices) return false;
    return g->matriz[de][para];
}

bool possuiVizinhos(Grafo *g, int vertice){
    if(g == NULL || vertice < 0 || g->matriz == NULL ||
    vertice >= g->numVertices) return false;
    int x;
    for(x = 0; x < g->numVertices; x++) 
        if (g->matriz[vertice][x]) return true;
    return false;
}

int grauVertice(Grafo *g, int vertice){
    if(g == NULL || g->matriz == NULL || vertice < 0 || vertice >= g->numVertices) return false;
    int x, grau = 0;
    for(x = 0; x < g->numVertices; x++) if (g->matriz[vertice][x]) grau++;
    return grau;
}

int main(){
    Grafo g;
    inicializaGrafo(&g, 3);
    imprimeGrafo(&g);

    printf("Inserindo aresta de 0 para 2:\n");
    insereAresta(&g, 0, 2);
    imprimeGrafo(&g);

    printf("Inserindo aresta de 1 para 2:\n");
    insereAresta(&g, 1, 2);
    imprimeGrafo(&g);

    printf("\n");

    printf("Removendo aresta de 0 para 2:\n");
    removeAresta(&g, 0, 2);
    imprimeGrafo(&g);

    printf("\n");

    imprimeGrafo(&g);
    printf("Existe aresta de 0 para 2? %s\n", convertBoolean(existeAresta(&g, 0, 2)));
    printf("Existe aresta de 1 para 2? %s\n", convertBoolean(existeAresta(&g, 1, 2)));

    printf("\n");
    imprimeGrafo(&g);
    printf("O vertice 0 possui vizinhos? %s\n", convertBoolean(possuiVizinhos(&g, 0)));
    printf("O vertice 1 possui vizinhos? %s\n", convertBoolean(possuiVizinhos(&g, 1)));
    printf("O vertice 2 possui vizinhos? %s\n", convertBoolean(possuiVizinhos(&g, 2)));

    printf("\n");
    imprimeGrafo(&g);
    printf("grau do vertice 0: %i\n", grauVertice(&g, 0));
    printf("grau do vertice 1: %i\n", grauVertice(&g, 1));
    printf("grau do vertice 2: %i\n", grauVertice(&g, 2));
}