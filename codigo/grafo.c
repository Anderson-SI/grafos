                             /*  EXERCÍCIO EXTRA  */ 
                             /*     GRAFOS-T02    */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "grafo.h"

// estrutura grafo
typedef struct grafo {
   int V; // Os indíce dos vértices vão de 0 a V-1, sendo V o número de Vértices;
   No **listaArestas; // matriz de adjavcência
} Grafo;

// estrutura de no
typedef struct no {
    int w;
    int flag; // flag para marcar a aresta [0 indica não visitado, -1 visitado]
    No* prox;
} No;

// função que cria no
No* fCriarNo (void) {
    No* n = malloc (sizeof ( No )); 
    n->prox = NULL;
    n->flag = 0;
    return n; 
}

// função que criar o grafo
Grafo* fCriarGrafo( int numV ) {
    Grafo *g = malloc (sizeof ( Grafo ));
    g->V = numV;
    g->listaArestas = malloc (numV * sizeof ( No ));
    for (int i = 0; i < numV; i++)
        g->listaArestas[i] = fCriarNo(); 
    return g;
}

// função que insere arestas
void inserir (Grafo *G, int v, int w) {  
    No *ver = fCriarNo ( );
    ver->w = w;
    if (G->listaArestas[v]->prox == NULL) { G->listaArestas[v]->prox = ver; }
    else {
        No* p = G->listaArestas[v];
        while (p->prox != NULL) {
            p = p->prox;
        }
        p->prox = ver;
    }
}

/*
    função que insere uma aresta a na lista de adjacência de G, sendo a = (v,w) 
    O Grafo NÃO é direcionado 
*/
void fInserirAresta (Grafo *G, int v, int w) { inserir (G, v, w); inserir (G, w, v); }

// função que devolve o g(v) de um vértice pertencente a G
int fGrauV (Grafo *G, int vertice) {
    int dv = 0;
    No *p = G->listaArestas[vertice]->prox;
    while (p != NULL)
    {
        p = p->prox;
        dv++; 
    }
    return dv;
}

// função que dado 2 vértive devolve 1 se são vizinhos
// devolve 0 caso contrário 
int fIsVizinho (Grafo *G, int v, int w) {
    int i = 0;
    No* p = G->listaArestas[v]->prox;
    while (p != NULL) {
        if (p->w == w) {
            i = 1;
            break;
        }
        p = p->prox;
    }
    return i;
}


void fRemove (Grafo *G, int v, int w) {
    No *ant = G->listaArestas[v];
    No *pro = G->listaArestas[v]->prox;
    while (pro != NULL) {
        if (pro->w == w) {
            No *lixo = pro;
            ant->prox = lixo->prox;
            free(lixo);
            break;
        }
        pro = pro->prox;
        ant = ant->prox;
    }
}

// função que remove aresta
void fRemoverArestas (Grafo *G, int v, int w) { fRemove (G, v, w); fRemove (G, w, v); }

// função que imprime o grafo
void fImprimirGrafo (Grafo* G ) {
    for (int i = 0; i < G->V; i++)
    {
        No* p = G->listaArestas[i]->prox;
       // printf("%d\n", p->w);
        printf("[%d]", i);
        while (p != NULL)
        {
            printf("->%d", p->w);
            p = p->prox;
        }
        printf("\n");
    }
}

/**
 *  Definição:
 *  Um grafo G é Euleriano, se tem um ciclo euleriano, ou seja, 
 *  passa por cada aresta de G uma única vez, e se somente se é 
 *  conexo e todos os vértices tem grau par. 
*/
int fIsEuleriano ( Grafo* G ) {
    int res = 1;
    for (int i = 0; i < G->V; i++) {
        No *p = G->listaArestas[i]->prox;
        if (p == NULL) { res = 0; break; } 
        else {
            int grauV = fGrauV ( G , i);
            if (grauV % 2 != 0) { res = 0; break; }
        }
    } 
    return res;
}

// função que recebe um grafo G
// devolve o número de aresta de G
int fNumArestaGrafo ( Grafo* G ) {
    int cont = 0;
    for (int i = 0; i < G->V; i++) // somátório dos graus dos vértices
    {
        int a = fGrauV (G, i);
        cont+= a;
    } 
    return cont / 2;
}

/**
 *  IMPLEMENTAÇÃO DOS ALGORITMOS PARA IMPRIMIR UM GRAFO EULERIANO
 *  OBS: usei a mesma estrutura do No para implementar as impilhas
 *  criei apenas as funções de inserir e remover
*/
// função que insere um elemento no topo de uma pilha
void inserirTopo (No *A, int v)
{
    No *na = malloc (sizeof ( No ));
    na->w = v;
    na->prox = A->prox;
    A->prox = na;
}

// função que remove um elemento do topo de uma pilha  
void removerTopo( No *A ) {
    No *lixo;
    if (A->prox != NULL) {
        lixo = A->prox;
        A->prox = lixo->prox;
        free(lixo);
    }
}

// função que imprime o Ciclo Euleriano
void imprimirCiclo ( No *A ) {
    No *aux = A->prox;
    printf("[");
    while(aux != NULL) {
        printf (" %d", aux->w);
    aux = aux->prox;
    }
    printf(" ]\n");
}

// função que marca arestas do grafo
void fMarcAresta ( Grafo *G, int v, int w) {
    No *p = G->listaArestas[v]->prox;
    while (p != NULL)
    {
        if (p->w == w && p->flag != -1) {
            p->flag = -1;
            break;
        }
        p = p->prox;
    }
}

// Algoritmo para imprimir um Ciclo Euleriano baseado no algoritmo de Hierholzer 
void algoritmoHierholzer ( Grafo *G,  int vert ) 
{
    No *pilhaS = fCriarNo ();
    No *pilhaT = fCriarNo ();

    inserirTopo ( pilhaS, vert );

    while(pilhaS->prox != NULL) {
        No* p = G->listaArestas[pilhaS->prox->w]->prox;
        while (p != NULL) {
            if (p->flag == 0) {
                fMarcAresta (G, pilhaS->prox->w, p->w );
                fMarcAresta (G, p->w, pilhaS->prox->w );
                inserirTopo ( pilhaS, p->w );
                break;
            } else {
                p = p->prox;
            } 
        }
        if (p == NULL) {
            inserirTopo ( pilhaT, pilhaS->prox->w );
            removerTopo ( pilhaS );
        }
    }
    imprimirCiclo ( pilhaT );
}




