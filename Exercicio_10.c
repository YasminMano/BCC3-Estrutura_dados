//Exercício 10

//Altere a implementação, em linguagem C, da estrutura de
//dados heap de tal forma que a raiz ocupe a posição 0, e
//não a posição 1. Ou seja, ajuste o código para não
//desperdiçar a posição 0 do array/vetor

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

// Função que retorna o índice do pai de um nó
int pai(int i) {
    return (i - 1) / 2; // Ajustado para base 0
}

// Função que retorna o índice do filho à esquerda
int esq(int i) {
    return 2 * i + 1; // Ajustado para base 0
}

// Função que retorna o índice do filho à direita
int dir(int i) {
    return 2 * i + 2; // Ajustado para base 0
}

// Função para manter a propriedade do heap ao inserir um novo elemento
void subir(int *heap, int i) {
    int p = pai(i);
    if (p >= 0 && heap[i] > heap[p]) {
        int aux = heap[i];
        heap[i] = heap[p];
        heap[p] = aux;
        subir(heap, p);
    }
}

// Insere novoItem no heap e ajusta a estrutura
void inserir(int *heap, int *n, int novoItem) {
    heap[*n] = novoItem;
    subir(heap, *n);
    (*n)++;
}

// Função para manter a propriedade do heap após remoção
void descer(int *heap, int n, int i) {
    int maior = i;
    int e = esq(i);
    int d = dir(i);

    if (e < n && heap[e] > heap[maior]) maior = e;
    if (d < n && heap[d] > heap[maior]) maior = d;

    if (maior != i) {
        int aux = heap[i];
        heap[i] = heap[maior];
        heap[maior] = aux;
        descer(heap, n, maior);
    }
}

// Remove e retorna o maior elemento do heap (a raiz)
int removerMaximo(int *heap, int *n) {
    int maximo = heap[0];
    heap[0] = heap[*n - 1];
    (*n)--;
    descer(heap, *n, 0);
    return maximo;
}

// Mostra o heap em forma de árvore (visualmente)
void imprimirHeap(int *heap, int n, int i, int b) {
    if (i >= n) {
        for (int j = 0; j < b; j++) printf("-----");
        printf("NULL\n");
        return;
    }
    imprimirHeap(heap, n, dir(i), b + 1);
    for (int j = 0; j < b; j++) printf("-----");
    printf("%d\n", heap[i]);
    imprimirHeap(heap, n, esq(i), b + 1);
}

// Constrói heap descendo a partir do último nó não-folha
void construirHeapDescendo(int *heap, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        descer(heap, n, i);
}

// Ordena o vetor com HeapSort (base 0)
void heapSort(int *heap, int n) {
    construirHeapDescendo(heap, n);
    for (int i = n - 1; i > 0; i--) {
        int aux = heap[0];
        heap[0] = heap[i];
        heap[i] = aux;
        descer(heap, i, 0);
    }
}

// Programa principal
int main(void) {
    int heap[MAX];
    int n = 0;

    // Inserção de elementos manualmente no heap
    inserir(heap, &n, 17);
    inserir(heap, &n, 15);
    inserir(heap, &n, 12);
    inserir(heap, &n, 9);
    inserir(heap, &n, 10);
    inserir(heap, &n, 4);
    inserir(heap, &n, 1);
    inserir(heap, &n, 7);
    inserir(heap, &n, 3);
    inserir(heap, &n, 6);

    printf("Heap atual:\n");
    for (int i = 0; i < n; i++) printf("heap[%d] = %d\n", i, heap[i]);
    printf("\n");

    imprimirHeap(heap, n, 0, 0);

    printf("\nRemovendo maior elemento (raiz): %d\n\n", removerMaximo(heap, &n));

    printf("Heap após remoção:\n");
    for (int i = 0; i < n; i++) printf("heap[%d] = %d\n", i, heap[i]);
    printf("\n");

    imprimirHeap(heap, n, 0, 0);

    // Exemplo com HeapSort
    int m;
    printf("\nQuantidade de elementos para ordenar: ");
    scanf("%d", &m);

    int vetor[m];
    srand((unsigned)time(NULL));

    for (int i = 0; i < m; i++) 
        vetor[i] = 1 + (rand() % 100);

    printf("\nAntes de ordenar:\n");
    for (int i = 0; i < m; i++) printf("vetor[%d] = %d\n", i, vetor[i]);

    heapSort(vetor, m);

    printf("\nDepois de ordenar com HeapSort:\n");
    for (int i = 0; i < m; i++) printf("vetor[%d] = %d\n", i, vetor[i]);

    return 0;
}
