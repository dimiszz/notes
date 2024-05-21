#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0 

typedef int bool;

typedef struct _lista_{
    int vertice;
    struct _lista_* prox;
} ElemLista;

typedef struct _grafo_{
    int numVertices;
    int numArestas;
    ElemLista** A;
} Grafo;

char* convertBoolean(bool x){
    if (x) return "True";
    return "False";
}

bool inicializaGrafo(Grafo *g, int vertices){
    if(g == NULL || vertices<1) return false;
    g->A = (ElemLista**) malloc(sizeof(ElemLista**)*vertices);
    g->numVertices = vertices;
    g->numArestas = 0;
    int x;
    for(x = 0; x < g->numVertices; x++){
        g->A[x] = NULL;
    }
    return true;
}

void imprimeGrafo(Grafo *g){
    if(g == NULL || g->A == NULL) return;
    int x, y;
    printf("Imprimindo grafo... vertices: %i; arestas: %i\n", g->numVertices, g->numArestas);
    ElemLista* atual;
    for(x = 0; x < g->numVertices; x++){
        printf("[%2i]", x);
        atual = g->A[x];
        while(atual){
            printf(" ->%3i ", atual->vertice);
            atual = atual->prox;
        }
        printf("\n");
    }
}

bool liberaGrafo(Grafo *g){
    if(g == NULL) return false;
    int i;
    ElemLista* atual, *apagar;
    for(i = 0; i < g->numVertices; i++){
        atual = g->A[i];
        while(atual){
            apagar = atual;
            atual = atual->prox;
            free(apagar);
        }
    }
    free(g->A);
    g->numArestas = 0;
    g->numVertices = 0;
    g->A = NULL;
    return true;
}

int numeroDeArestasGrafo(Grafo *g){
    if (g == NULL) return -1;
    return g->numArestas;
}


int numeroDeVerticesGrafo(Grafo *g){
    if (g == NULL) return -1;
    return g->numVertices;
}

// insere aresta ordenadamente.
bool insereAresta(Grafo *g, int de, int para){
    if(g == NULL || g->A == NULL || 
        de >= g->numVertices || para >= g->numVertices || de < 0 || para<0) return false;
    
    ElemLista *novo, *ant;
    ElemLista *atual = g->A[de];
    // Itera sobre os vizinhos até encontrar o vértice que será o próximo de PARA.
    // Ou seja, ele será colocado entre o ANT e o ATUAL.
    while(atual && atual->vertice < para){
        ant = atual;
        atual = atual->prox;
    }
    if(atual && atual->vertice == para) return false;

    // lógica para colocar NOVO entre ANT e ATUAL.
    novo = (ElemLista*) malloc(sizeof(ElemLista));
    novo->vertice = para;
    novo->prox = atual;
    if(ant) ant->prox = novo;
    else g->A[de] = novo;
    g->numArestas++;
    return true;
}

bool removeAresta(Grafo *g, int de, int para){
    if(g == NULL || g->A == NULL || 
    de >= g->numVertices || para >= g->numVertices) return false;
    
    ElemLista* ant = NULL;
    ElemLista* atual = g->A[de];

    while (atual && atual->vertice < para){
        ant = atual;
        atual = atual->prox;
    }

    if(atual && atual->vertice == para){
        if(ant) ant->prox = atual->prox;
        else g->A[de] = atual->prox;
        free(atual);
        g->numArestas--;
        return true;
    }
    return false;
}

bool existeAresta(Grafo *g, int de, int para){
    if(g == NULL || g->A == NULL ||
    de >= g->numVertices || para >= g->numVertices) return false;
    
    ElemLista* atual = g->A[de];
    while(atual && atual->vertice < para){
        atual = atual->prox;
    }

    if(atual && atual->vertice == para) return true;
    return false;
}

bool possuiVizinhos(Grafo *g, int vertice){
    if(g == NULL || vertice < 0 || g->A == NULL ||
    vertice >= g->numVertices || !g->A[vertice]) return false;
    return true;
}

int grauVertice(Grafo *g, int vertice){
    if(g == NULL || g->A == NULL || vertice < 0 || vertice >= g->numVertices) return false;
    int x, grau = 0;
    ElemLista* atual = g->A[vertice];
    while(atual){
        atual = atual->prox;
        grau++;
    }
    return grau;
}

int main(){
    Grafo g;
    inicializaGrafo(&g, 3);
    imprimeGrafo(&g);

    printf("Inserindo aresta de 0 para 2:\n");
    insereAresta(&g, 0, 2);
    imprimeGrafo(&g);

    printf("Inserindo aresta de 0 para 1:\n");
    insereAresta(&g, 0, 1);
    imprimeGrafo(&g);

    printf("Inserindo aresta de 1 para 2:\n");
    insereAresta(&g, 1, 2);
    imprimeGrafo(&g);

    printf("\n");

    printf("Removendo aresta de 0 para 2:\n");
    removeAresta(&g, 0, 2);
    imprimeGrafo(&g);

    printf("\n");

    printf("Inserindo aresta de 1 para 2:\n");
    insereAresta(&g, 0, 2);
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