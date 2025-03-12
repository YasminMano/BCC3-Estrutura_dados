#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um nó da lista
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Função para criar a lista circular com nó cabeça
Node* criarLista() {
    Node* head = (Node*)malloc(sizeof(Node));
    if (head == NULL) {
        printf("Erro ao alocar memória para a lista.\n");
        exit(1);
    }
    head->next = head; // Inicialmente aponta para si mesma
    return head;
}

// Função para inserir um novo elemento na lista
void inserirElemento(Node* head, int valor) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    if (novoNo == NULL) {
        printf("Erro ao alocar memória para o novo nó.\n");
        return;
    }
    novoNo->data = valor;
    novoNo->next = head->next;
    head->next = novoNo;
}

// Função para buscar um elemento na lista
Node* buscarElemento(Node* head, int valor) {
    Node* atual = head->next;
    while (atual != head) { // Percorre a lista até encontrar ou retornar ao início
        if (atual->data == valor)
            return atual;
        atual = atual->next;
    }
    return NULL;
}

// Função para remover um elemento da lista
void removerElemento(Node* head, int valor) {
    Node* atual = head;
    while (atual->next != head) {
        if (atual->next->data == valor) {
            Node* temp = atual->next;
            atual->next = temp->next;
            free(temp);
            return;
        }
        atual = atual->next;
    }
}

// Função para exibir os elementos da lista
void exibirLista(Node* head) {
    Node* atual = head->next;
    printf("Lista: ");
    while (atual != head) {
        printf("%d -> ", atual->data);
        atual = atual->next;
    }
    printf("(head)\n");
}

// Função principal para testar as operações da lista
int main() {
    Node* head = criarLista();
    
    inserirElemento(head, 10);
    inserirElemento(head, 20);
    inserirElemento(head, 30);
    
    printf("Lista após inserções:\n");
    exibirLista(head);
    
    printf("Buscando elemento 20...\n");
    if (buscarElemento(head, 20)) {
        printf("Elemento 20 encontrado!\n");
    } else {
        printf("Elemento 20 não encontrado.\n");
    }
    
    printf("Buscando elemento 40...\n");
    if (buscarElemento(head, 40)) {
        printf("Elemento 40 encontrado!\n");
    } else {
        printf("Elemento 40 não encontrado.\n");
    }
    
    printf("Removendo elemento 20...\n");
    removerElemento(head, 20);
    
    printf("Lista após remoção:\n");
    exibirLista(head);
    
    return 0;
}
