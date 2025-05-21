
// Exercício 13
// Modifique a implementação de busca em largura em
// grafos, apresentada em aula, para utilizar uma fila
// dinâmica (com lista ligada).

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define BRANCO 0
#define CINZA 1
#define PRETO 2
#define INFINITO INT_MAX
#define NULO -1
// ---------- Estrutura do Grafo (matriz de adjacência) ----------
typedef struct {
 int numVertices;
 int **matrizAdj;
} Grafo;
Grafo *criarGrafo(int numVertices) {
 Grafo *grafo = (Grafo *)malloc(sizeof(Grafo));
 grafo->numVertices = numVertices;
 grafo->matrizAdj = (int **)malloc(numVertices * sizeof(int *));
 for (int i = 0; i < numVertices; i++) {
 
grafo->matrizAdj[i] = (int *)malloc(numVertices * sizeof(int));
 
for (int j = 0; j < numVertices; j++)
 
grafo->matrizAdj[i][j] = 0;
 }
 return grafo;
}
void adicionarAresta(Grafo *grafo, int origem, int destino) {
 grafo->matrizAdj[origem][destino] = 1;
 grafo->matrizAdj[destino][origem] = 1;
}
void imprimirGrafo(Grafo *grafo) {
 printf("Grafo não orientado (Vértices adjacentes):\n");
 for (int i = 0; i < grafo->numVertices; i++) {
 
printf("Vértice %d: ", i);
 
bool primeiro = true;
 
for (int j = 0; j < grafo->numVertices; j++) {
 
if (grafo->matrizAdj[i][j] == 1) {
 
if (!primeiro)
 
printf(", ");
 
printf("%d", j);
 
primeiro = false;
 
}
 
}
 
printf("\n");
 }
}
// ---------- Estrutura da Fila Dinâmica (Lista Ligada) ----------
typedef struct No {
 int dado;
 struct No *prox;
} No;
typedef struct {
 No *frente;
 No *tras;
} Fila;
Fila *criarFila() {
 Fila *f = (Fila *)malloc(sizeof(Fila));
 f->frente = f->tras = NULL;
 return f;
}
bool filaVazia(Fila *f) { return f->frente == NULL; }
void enfileirar(Fila *f, int valor) {
 No *novo = (No *)malloc(sizeof(No));
 novo->dado = valor;
 novo->prox = NULL;
 if (filaVazia(f)) {
 
f->frente = f->tras = novo;
 } else {
 
f->tras->prox = novo;

 
f->tras = novo;
 }
}
int desenfileirar(Fila *f) {
 if (filaVazia(f))
 
return -1;
 No *temp = f->frente;
 int valor = temp->dado;
 f->frente = f->frente->prox;
 if (f->frente == NULL)
 
f->tras = NULL;
 free(temp);
 return valor;
}
void liberarFila(Fila *f) {
 while (!filaVazia(f)) {
 
desenfileirar(f);
 }
 free(f);
}
// ---------- Função para imprimir árvore BFS ----------
void imprimirArvoreBFS(Grafo *grafo, int *pai) {
 printf("\nÁrvore BFS:\n");
 for (int i = 0; i < grafo->numVertices; i++) {
 
if (pai[i] != NULO)
 
printf("Pai de %d é %d\n", i, pai[i]);
 
else
 
printf("%d não tem pai\n", i);
 }
}
// ---------- BFS com fila dinâmica ----------
void BFS(Grafo *grafo, int origem) {
 int cor[grafo->numVertices];
 int distancia[grafo->numVertices];
 int pai[grafo->numVertices];
 for (int i = 0; i < grafo->numVertices; i++) {
 
cor[i] = BRANCO;
 
distancia[i] = INFINITO;
 
pai[i] = NULO;
 }
 cor[origem] = CINZA;
 distancia[origem] = 0;
 Fila *fila = criarFila();
 enfileirar(fila, origem);
 while (!filaVazia(fila)) {
 
int u = desenfileirar(fila);
 
printf("Visitando vértice %d\n", u);
 
for (int v = 0; v < grafo->numVertices; v++) {
 
if (grafo->matrizAdj[u][v] == 1 && cor[v] == BRANCO) {
 
cor[v] = CINZA;
 
distancia[v] = distancia[u] + 1;
 
pai[v] = u;
 
enfileirar(fila, v);
 
}
 
}
 
cor[u] = PRETO;
 }
 liberarFila(fila);
 imprimirArvoreBFS(grafo, pai);
}
// ---------- Função principal ----------
int main(void) {
 int numVertices = 8;
 Grafo *grafo = criarGrafo(numVertices);
 adicionarAresta(grafo, 0, 1); // (s,r)
 adicionarAresta(grafo, 0, 3); // (s,w)
 adicionarAresta(grafo, 1, 2); // (r,v)
 adicionarAresta(grafo, 3, 4); // (w,t)
 adicionarAresta(grafo, 3, 5); // (w,x)
 adicionarAresta(grafo, 4, 5); // (t,x)
 adicionarAresta(grafo, 4, 6); // (t,u)
 adicionarAresta(grafo, 5, 7); // (x,y)
 adicionarAresta(grafo, 6, 7); // (u,y)
 imprimirGrafo(grafo);

 printf("\nBusca em Largura (BFS):\n");
 BFS(grafo, 0);
 return 0;
}

