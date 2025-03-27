//ADO 05

// Implemente, em linguagem C, uma lista circular duplamente ligada/encadeada, com
// cabeça, com as seguintes operações/funções: inserir (um elemento na lista), imprimir/exibir (a lista),
// buscar (um elemento na lista), alterar/trocar (um elemento da lista), remover (um elemento da lista).

#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da lista
typedef struct Node {
    int dado;
    struct Node* prox;
    struct Node* ant;
} Node;

// Estrutura da lista circular duplamente ligada
typedef struct {
    Node* cabeca; 
} Lista;

// Função para criar a lista
Lista* criarLista() {
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    lista->cabeca = (Node*)malloc(sizeof(Node));
    lista->cabeca->prox = lista->cabeca;
    lista->cabeca->ant = lista->cabeca;
    return lista;
}

// Função para inserir um número na lista
void inserir(Lista* lista, int num) {
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->dado = num;

    Node* ultimo = lista->cabeca->ant;  

    // Ligação do novo nó na lista
    novo->prox = lista->cabeca;
    novo->ant = ultimo;
    ultimo->prox = novo;
    lista->cabeca->ant = novo;
}

// Função para mostrar os números da lista
void exibir(Lista* lista) {
    Node* atual = lista->cabeca->prox;
    if (atual == lista->cabeca) {
        printf("A lista está vazia!\n");
        return;
    }
    printf("Lista: ");
    while (atual != lista->cabeca) {
        printf("%d ", atual->dado);
        atual = atual->prox;
    }
    printf("\n");
}

// Função para procurar um número na lista
Node* buscar(Lista* lista, int num) {
    Node* atual = lista->cabeca->prox;
    while (atual != lista->cabeca) {
        if (atual->dado == num) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}

// Função para alterar um número na lista
void alterar(Lista* lista, int antigo, int novo) {
    Node* encontrado = buscar(lista, antigo);
    if (encontrado) {
        encontrado->dado = novo;
        printf("Número %d alterado para %d!\n", antigo, novo);
    } else {
        printf("Número %d não encontrado!\n", antigo);
    }
}

// Função para remover um número da lista
void remover(Lista* lista, int num) {
    Node* atual = buscar(lista, num);
    if (atual) {
        atual->ant->prox = atual->prox;
        atual->prox->ant = atual->ant;
        free(atual);
        printf("Número %d removido!\n", num);
    } else {
        printf("Número %d não está na lista!\n", num);
    }
}

int main() {
    Lista* lista = criarLista();

    inserir(lista, 5);
    inserir(lista, 10);
    inserir(lista, 15);

    exibir(lista);

    alterar(lista, 10, 12);
    exibir(lista);

    remover(lista, 5);
    exibir(lista);

    remover(lista, 50); 

    return 0;
}
