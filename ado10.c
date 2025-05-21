
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
int pai(int i) {
 
return (i - 1) / 2;
}
int esq(int i) {
 
return 2 * i + 1;
}
int dir(int i) {
 
return 2 * i + 2;
}
void subir(int *heap, int i) {
 
int p = pai(i);
 
if (i > 0 && heap[i] > heap[p]) {
 
int aux = heap[i];
 
heap[i] = heap[p];
 
heap[p] = aux;
 
subir(heap, p);
 
}
}
void inserir(int *heap, int *n, int novoItem) {
 
heap[*n] = novoItem;
 
subir(heap, *n);
 
(*n)++;
}
void descer(int *heap, int n, int i) {
 
int maior = i;
 
int e = esq(i);
 
int d = dir(i);
 
if (e < n && heap[e] > heap[maior])
 
maior = e;
 
if (d < n && heap[d] > heap[maior])
 
maior = d;
 
if (maior != i) {
 
int aux = heap[i];
 
heap[i] = heap[maior];
 
heap[maior] = aux;
 
descer(heap, n, maior);
 
}
}
int removerMaximo(int *heap, int *n) {
 
int maximo = heap[0];
 
heap[0] = heap[*n - 1];
 
(*n)--;
 
descer(heap, *n, 0);
 
return maximo;
}
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
void construirHeapDescendo(int *heap, int n) {
 
for (int i = n / 2 - 1; i >= 0; i--)
 
descer(heap, n, i);
}
void heapSort(int *heap, int n) {
 
construirHeapDescendo(heap, n);
 
for (int i = n - 1; i > 0; i--) {
 
int aux = heap[0];
 
heap[0] = heap[i];
 
heap[i] = aux;
 
descer(heap, i, 0);
 
}

}
int heapMaximo(int *heap, int n) {
 
for (int i = 0; i <= (n - 2) / 2; i++) {
 
int e = esq(i);
 
int d = dir(i);
 
if (e < n && heap[i] < heap[e]) return 0;
 
if (d < n && heap[i] < heap[d]) return 0;
 
}
 
return 1;
}
int main(void) {
 
int heap[MAX];
 
int n = 0;
 
// Inserções manuais
 
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
 
printf("\nHeap (vetor):\n");
 
for (int i = 0; i < n; i++) {
 
printf("heap[%d] = %d\n", i, heap[i]);
 
}
 
if (heapMaximo(heap, n)) {
 
printf("\nO vetor representa um heap de máximo.\n");
 
} else {
 
printf("\nO vetor NÃO representa um heap de máximo.\n");
 
}
 
printf("\nHeap como árvore:\n");
 
imprimirHeap(heap, n, 0, 0);
 
printf("\nExtração do maior elemento: %d\n", removerMaximo(heap, &n));
 
printf("\nHeap após remoção:\n");
 
for (int i = 0; i < n; i++) {
 
printf("heap[%d] = %d\n", i, heap[i]);
 
}
 
printf("\nHeap como árvore após remoção:\n");
 
imprimirHeap(heap, n, 0, 0);
 
// Teste com heapsort
 
int m;
 
printf("\nQuantidade de elementos para ordenar: ");
 
scanf("%d", &m);
 
int vetor[m];
 
srand(time(NULL));
 
for (int i = 0; i < m; i++)
 
vetor[i] = rand() % 100 + 1;
 
printf("\nAntes de ordenar:\n");
 
for (int i = 0; i < m; i++)
 
printf("vetor[%d] = %d\n", i, vetor[i]);
 
heapSort(vetor, m);
 
printf("\nDepois de ordenar com Heap Sort:\n");
 
for (int i = 0; i < m; i++)
 
printf("vetor[%d] = %d\n", i, vetor[i]);
 
return 0;
}

