//ADO 04

// Implemente, em linguagem C, uma função que encontre o nó com o conteúdo de valor
// mínimo em uma lista simplesmente encadeada/ligada sem cabeça de valores inteiros. Faça duas
// versões: uma iterativa e uma recursiva.

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista encadeada
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Função para criar um novo nó
Node* criarNo(int data) {
    Node* novo = (Node*)malloc(sizeof(Node)); 
    novo->data = data; 
    novo->next = NULL;  
    return novo;        
}

// Função para adicionar um nó ao final da lista
void inserirFim(Node** head, int data) {
    Node* novo = criarNo(data); 

    if (*head == NULL) { 
        *head = novo;
        return;
    }

    // Percorremos a lista até encontrar o último nó
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = novo; 
}

// Função iterativa para encontrar o menor valor
Node* encontrarMinIterativo(Node* head) {
    if (head == NULL) return NULL; 

    Node* minNode = head; 
    Node* temp = head->next; 

    while (temp != NULL) { 
        if (temp->data < minNode->data) { 
            minNode = temp;
        }
        temp = temp->next; 
    }

    return minNode;
}

// Função recursiva para encontrar o menor valor
Node* encontrarMinRecursivo(Node* head) {
    if (head == NULL || head->next == NULL) return head;

    Node* minRestante = encontrarMinRecursivo(head->next);

    return (head->data < minRestante->data) ? head : minRestante; 
}

// Função principal para testar
int main() {
    Node* lista = NULL; 

    inserirFim(&lista, 10);
    inserirFim(&lista, 5);
    inserirFim(&lista, 3);
    inserirFim(&lista, 8);
    inserirFim(&lista, 1); // Mínimo esperado

    // Chamando as funções para encontrar o menor valor
    Node* minIterativo = encontrarMinIterativo(lista);
    Node* minRecursivo = encontrarMinRecursivo(lista);

    if (minIterativo)
        printf("Mínimo (Iterativo): %d\n", minIterativo->data);
    if (minRecursivo)
        printf("Mínimo (Recursivo): %d\n", minRecursivo->data);

    return 0;
}
