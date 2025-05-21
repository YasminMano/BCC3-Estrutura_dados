// Exercício

// Modifique a implementação de busca em profundidade em
// grafos, apresentada em aula, para utilizar uma matriz de
// adjacência como representação para o grafo.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NULO -1

typedef enum { BRANCO, CINZA, PRETO } cores;

int tempo = 0;

// Representação de um grafo usando matriz de adjacência
typedef struct {
    int numVertices;
    int **matrizAdj;
} Grafo;

// Criar grafo com matriz de adjacência
Grafo *criarGrafo(int numVertices) {
    Grafo *grafo = (Grafo *)malloc(sizeof(Grafo));
    grafo->numVertices = numVertices;

    grafo->matrizAdj = (int **)malloc(numVertices * sizeof(int *));
    for (int i = 0; i < numVertices; i++) {
        grafo->matrizAdj[i] = (int *)malloc(numVertices * sizeof(int));
        for (int j = 0; j < numVertices; j++) {
            grafo->matrizAdj[i][j] = 0; // Inicializa com 0 (sem aresta)
        }
    }

    return grafo;
}

// Adicionar aresta à matriz de adjacência
void adicionarAresta(Grafo *grafo, int origem, int destino) {
    grafo->matrizAdj[origem][destino] = 1;
}

// Imprimir a matriz de adjacência
void imprimirGrafo(Grafo *grafo) {
    printf("Matriz de Adjacência:\n");
    for (int i = 0; i < grafo->numVertices; i++) {
        for (int j = 0; j < grafo->numVertices; j++) {
            printf("%d ", grafo->matrizAdj[i][j]);
        }
        printf("\n");
    }
}

// Imprimir árvore da DFS
void imprimeArvoreDFS(Grafo *grafo, int *pai) {
    printf("\nÁrvore DFS:\n");
    for (int i = 0; i < grafo->numVertices; i++) {
        if (pai[i] != -1)
            printf("Pai de %d é %d\n", i, pai[i]);
        else
            printf("Pai de %d é ninguém\n", i);
    }
}

void DFS_Visit(Grafo *grafo, int vertice, cores *cor, int *pai, int *d, int *f) {
    cor[vertice] = CINZA;
    d[vertice] = ++tempo;
    printf("Visitando vértice %d no tempo %d\n", vertice, d[vertice]);

    for (int j = 0; j < grafo->numVertices; j++) {
        if (grafo->matrizAdj[vertice][j] == 1 && cor[j] == BRANCO) {
            pai[j] = vertice;
            DFS_Visit(grafo, j, cor, pai, d, f);
        }
    }

    cor[vertice] = PRETO;
    f[vertice] = ++tempo;
    printf("** Finalizando vértice %d no tempo %d\n", vertice, f[vertice]);
}

void DFS(Grafo *grafo) {
    cores cor[grafo->numVertices];
    int pai[grafo->numVertices];
    int d[grafo->numVertices];
    int f[grafo->numVertices];

    for (int i = 0; i < grafo->numVertices; i++) {
        cor[i] = BRANCO;
        pai[i] = NULO;
        d[i] = 0;
        f[i] = 0;
    }

    for (int i = 0; i < grafo->numVertices; i++) {
        if (cor[i] == BRANCO)
            DFS_Visit(grafo, i, cor, pai, d, f);
    }

    imprimeArvoreDFS(grafo, pai);

    printf("\nTempos de Descoberta e Finalização:\n");
    for (int i = 0; i < grafo->numVertices; i++) 
        printf("Vértice %d: d[%d] = %d, f[%d] = %d\n", i, i, d[i], i, f[i]);
}

int main(void) {
    int numVertices = 8;
    Grafo *grafo = criarGrafo(numVertices);

    adicionarAresta(grafo, 0, 4);    
    adicionarAresta(grafo, 0, 3);
    adicionarAresta(grafo, 0, 1);
    adicionarAresta(grafo, 1, 3);
    adicionarAresta(grafo, 1, 2);    
    adicionarAresta(grafo, 2, 0);
    adicionarAresta(grafo, 3, 2);
    adicionarAresta(grafo, 4, 5);
    adicionarAresta(grafo, 4, 3);
    adicionarAresta(grafo, 5, 3);
    adicionarAresta(grafo, 6, 7);
    adicionarAresta(grafo, 6, 4);
    adicionarAresta(grafo, 6, 5);
    adicionarAresta(grafo, 7, 3);

    imprimirGrafo(grafo);

    printf("\nBusca em Profundidade (DFS):\n");
    DFS(grafo);

    return 0;
}
