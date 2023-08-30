                             /*  EXERCÍCIO EXTRA  */ 
                             /*     GRAFOS-T02    */

/*
    # INTERFACE OPERAÇÕES EM GRAFOS
*/

#ifndef _H_GRAFO
#define _H_GRAFO

// definições
typedef struct grafo Grafo;
typedef struct no No;

// função que cria grafo
Grafo* fCriarGrafo( int numV );

// função que insere arestas 
void fInserirAresta ( Grafo *G, int v, int w );

// função que remove arestas
void fRemoverArestas ( Grafo *A, int v, int w );

//fImprimirGrafo
void fImprimirGrafo ( Grafo* G );

// função que devolve os graus de um vértice
int fGrauV ( Grafo *G, int vertice );

// função que determina se dois vértices são vizinhos 
int fIsVizinho ( Grafo *G, int v, int w ); 

// função que devolve o número de arestas de um grafo
int fNumArestaGrafo ( Grafo *G );

// função que verifica se o grafo tem Caminho Euleriano
int fIsEuleriano ( Grafo* G ); 

// função que imprime um Caminho Euleriano (Implementação do Algoritmo de Hierholzer)
void algoritmoHierholzer ( Grafo *G,  int vert );


#endif // _H_GRAFO
