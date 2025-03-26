//Exercício 07

// Exercício
// Implemente, em linguagem C, um contador binário, ou seja,
// dado um valor n apresente a lista de todos os valores binários
// que correspondem aos decimais de 1 até n. Neste exercício,
// utilize, obrigatoriamente, a estrutura de dados fila.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do nó da fila
typedef struct Node {
    char bin[20];  // Armazena o número binário como string
    struct Node* next;
} Node;

// Estrutura da fila
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Função para criar uma fila 
Queue* criarFila() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Função para enfileirar (inserir na fila)
void enfileirar(Queue* q, const char* bin) {
    Node* novo = (Node*)malloc(sizeof(Node));
    strcpy(novo->bin, bin);
    novo->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = novo;
    } else {
        q->rear->next = novo;
        q->rear = novo;
    }
}

// Função para desenfileirar (remover da fila)
void desenfileirar(Queue* q, char* bin) {
    if (q->front == NULL) return;

    Node* temp = q->front;
    strcpy(bin, temp->bin);  // Copia o valor antes de liberar a memória

    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL; 

    free(temp);
}

void gerarBinarios(int n) {
    Queue* q = criarFila();
    enfileirar(q, "1");

    char bin[20];

    for (int i = 0; i < n; i++) {
        desenfileirar(q, bin);
        printf("%s\n", bin);

        // Criar os próximos números binários
        char bin0[20], bin1[20];
        sprintf(bin0, "%s0", bin);
        sprintf(bin1, "%s1", bin);

        enfileirar(q, bin0);
        enfileirar(q, bin1);
    }

    free(q);
}

int main() {
    int n;
    printf("Digite um número: ");
    scanf("%d", &n);
    gerarBinarios(n);
    return 0;
}
