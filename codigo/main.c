                             /*  EXERCÍCIO EXTRA  */ 
                             /*     GRAFOS-T02    */
                      /* Aluno: Anderson Costa Moreira Santana */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "grafo.h"

/**
 * Arquivo main onde são chamadas todas as funções
*/

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "portuguese");

    printf(" ------ GRAFO 1 ------ \n");
    
    Grafo *G1 = fCriarGrafo( 10 );
    
    fInserirAresta( G1, 0, 1);
    fInserirAresta( G1, 0, 2);
    fInserirAresta( G1, 0, 3);
    fInserirAresta( G1, 0, 4);
    fInserirAresta( G1, 1, 2);
    fInserirAresta( G1, 1, 5);
    fInserirAresta( G1, 1, 8);
    fInserirAresta( G1, 2, 3);
    fInserirAresta( G1, 2, 5);
    fInserirAresta( G1, 3, 4);
    fInserirAresta( G1, 3, 7);
    fInserirAresta( G1, 4, 7);
    fInserirAresta( G1, 4, 9);
    fInserirAresta( G1, 5, 8);
    fInserirAresta( G1, 5, 6);
    fInserirAresta( G1, 6, 7);
    fInserirAresta( G1, 6, 8);
    fInserirAresta( G1, 6, 9);
    fInserirAresta( G1, 8, 9);
    fInserirAresta( G1, 7, 9);

    fImprimirGrafo ( G1 );
    printf("\n");

    printf("O grau do vertice %d e %d \n", 6, fGrauV ( G1, 6 ));

    if ( fIsVizinho ( G1, 4, 9 ) ) { printf("4 e 9 Sao vizinhos \n"); }
    else { printf("4 e 9 Nao sao vizinhos \n"); } 

    printf("Numero de Arestas de G1 e %d \n", fNumArestaGrafo( G1 ));

    if (fIsEuleriano ( G1 )) { 
        printf("\nCiclo Euleriano baseado no algoritmo Hierholzer \n"); 
        algoritmoHierholzer ( G1,  0 );  //como argumento da função pode ser passado um grafo euleriano e qualquer vértice desse grafo.
        printf("\n");
    }
    else {
        printf("Nao e um grafo Euleriano \n");
    } 
    
    fRemoverArestas ( G1, 1, 8);
    // sem a aresta
    printf("Sem a aresta (1, 8) - deixa de ser um grafo euleriano  \n");
    fImprimirGrafo ( G1 );

    if (fIsEuleriano ( G1 )) { 
        printf("\nCiclo Euleriano baseado no algoritmo Hierholzer \n"); 
        algoritmoHierholzer ( G1,  0 );  //como argumento da função pode ser passado um grafo euleriano e qualquer vértice desse grafo.
        printf("\n");
    }
    else {
        printf("\nNao e um grafo Euleriano \n");
    }
    printf("---------------------------------------------\n\n");


    printf(" ------ GRAFO 2 ------ \n");
    Grafo *G2 = fCriarGrafo( 9 );
    fInserirAresta( G2, 0, 1);
    fInserirAresta( G2, 0, 2);
    fInserirAresta( G2, 0, 6);
    fInserirAresta( G2, 0, 7);
    fInserirAresta( G2, 1, 6);
    fInserirAresta( G2, 1, 5);
    fInserirAresta( G2, 1, 2);
    fInserirAresta( G2, 6, 5);
    fInserirAresta( G2, 6, 7);
    fInserirAresta( G2, 5, 7);
    fInserirAresta( G2, 5, 8);
    fInserirAresta( G2, 7, 8);
    fInserirAresta( G2, 8, 4);
    fInserirAresta( G2, 8, 3);
    fInserirAresta( G2, 4, 3);
    fInserirAresta( G2, 5, 4);
    fInserirAresta( G2, 5, 2);
    fInserirAresta( G2, 2, 4);
    fInserirAresta( G2, 2, 3);
    fInserirAresta( G2, 2, 3);
    
    fImprimirGrafo ( G2 );
    printf("\n");

    printf("O grau do vertice %d e %d \n", 5, fGrauV ( G2, 5 ));

    if ( fIsVizinho ( G2, 5, 0 ) ) { printf("5 e 0 Sao vizinhos \n"); }
    else { printf("5 e 0 Nao sao vizinhos \n"); } 

    printf("Numero de Arestas de G2 e %d \n", fNumArestaGrafo( G2 ));

    if (fIsEuleriano ( G2 )) { 
        printf("\nCiclo Euleriano baseado no algoritmo Hierholzer \n"); 
        algoritmoHierholzer ( G2,  1 );  //como argumento da função pode ser passado um grafo euleriano e qualquer vértice desse grafo.
        printf("\n");
    }
    else {
        printf("Nao e um grafo Euleriano \n");
    } 
    
    fRemoverArestas ( G2, 5, 4);
    // sem a aresta
    printf("Sem a aresta (5, 4) - deixa de ser um grafo euleriano  \n");
    fImprimirGrafo ( G2 );
    printf("---------------------------------------------\n\n");


    printf(" ------ GRAFO 3 ------ \n");
    Grafo *G3 = fCriarGrafo( 8 );
    fInserirAresta( G3, 0, 1);
    fInserirAresta( G3, 0, 4);
    fInserirAresta( G3, 1, 2);
    fInserirAresta( G3, 1, 4);
    fInserirAresta( G3, 1, 3);
    fInserirAresta( G3, 2, 3);
    fInserirAresta( G3, 3, 4);
    fInserirAresta( G3, 3, 5);
    fInserirAresta( G3, 5, 4);
    fInserirAresta( G3, 4, 6);
    fInserirAresta( G3, 4, 7);
    fInserirAresta( G3, 7, 6);

    fImprimirGrafo ( G3 );
    printf("\n");

    printf("O grau do vertice %d e %d \n", 7, fGrauV ( G3, 7 ));

    if ( fIsVizinho ( G3, 5, 3 ) ) { printf("5 e 3 Sao vizinhos \n"); }
    else { printf("5 e 3 Nao sao vizinhos \n"); } 

    printf("Numero de Arestas de G3 e %d \n", fNumArestaGrafo( G3 ));

    if (fIsEuleriano ( G3 )) { 
        printf("\nCiclo Euleriano baseado no algoritmo Hierholzer \n"); 
        algoritmoHierholzer ( G3,  2 );  //como argumento da função pode ser passado um grafo euleriano e qualquer vértice desse grafo.
        printf("\n");
    }
    else {
        printf("Nao e um grafo Euleriano \n");
    } 
    
    fRemoverArestas ( G3, 1, 2);
    // sem a aresta
    printf("Sem a aresta (1, 2) - deixa de ser um grafo euleriano  \n");
    fImprimirGrafo ( G3 );
    printf("---------------------------------------------\n\n");


    printf(" ------ GRAFO 4 ------ \n");
    Grafo *G4 = fCriarGrafo( 7 );
    fInserirAresta( G4, 0, 1);
    fInserirAresta( G4, 0, 2);
    fInserirAresta( G4, 0, 3);
    fInserirAresta( G4, 0, 4);
    fInserirAresta( G4, 1, 2);
    fInserirAresta( G4, 1, 3);
    fInserirAresta( G4, 1, 4);
    fInserirAresta( G4, 2, 3);
    fInserirAresta( G4, 2, 4);
    fInserirAresta( G4, 3, 4);
    fInserirAresta( G4, 4, 5);
    fInserirAresta( G4, 4, 6);
    fInserirAresta( G4, 5, 6);

    fImprimirGrafo ( G4 );
    printf("\n");

    printf("O grau do vertice %d e %d \n", 1, fGrauV ( G4, 1 ));

    if ( fIsVizinho ( G2, 5, 0 ) ) { printf(" 5 e 0 Sao vizinhos \n"); }
    else { printf("5 e 0 Nao sao vizinhos \n"); } 

    printf("Numero de Arestas de G4 e %d \n", fNumArestaGrafo( G4 ));

    if (fIsEuleriano ( G4 )) { 
        printf("\nCiclo Euleriano baseado no algoritmo Hierholzer \n"); 
        algoritmoHierholzer ( G4,  3 );  //como argumento da função pode ser passado um grafo euleriano e qualquer vértice desse grafo.
        printf("\n");
    }
    else {
        printf("Nao e um grafo Euleriano \n");
    } 

    // Aqui eu removo uma aresta depois tento imprimir o ciclo euleriano
    fRemoverArestas ( G4, 1, 3);
    // sem a aresta
    printf("Sem a aresta (1, 3) - deixa de ser um grafo euleriano \n");
    fImprimirGrafo ( G2 );
    printf("\n");
   
    if (fIsEuleriano ( G4 )) { 
        printf("\nCiclo Euleriano baseado no algoritmo Hierholzer \n"); 
        algoritmoHierholzer ( G4,  3 );  //como argumento da função pode ser passado um grafo euleriano e qualquer vértice desse grafo.
        printf("\n");
    }
    else {
        printf("Nao e um grafo Euleriano \n");
    } 
    printf("---------------------------------------------\n\n");


    return 0;
}


