#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int chave;
    int altura;
    struct Node* esq;
    struct Node* dir;
} Node;


int altura(Node* n) {
    if (n == NULL) return -1;
    return n->altura;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node* rotacaoDireita(Node* y) {
    Node* x = y->esq;
    Node* T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    y->altura = max(altura(y->esq), altura(y->dir)) + 1;
    x->altura = max(altura(x->esq), altura(x->dir)) + 1;

    return x;
}

Node* rotacaoEsquerda(Node* x) {
    Node* y = x->dir;
    Node* T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    x->altura = max(altura(x->esq), altura(x->dir)) + 1;
    y->altura = max(altura(y->esq), altura(y->dir)) + 1;

    return y;
}

int getBalance(Node* n) {
    if (n == NULL) return 0;
    return altura(n->esq) - altura(n->dir);
}

Node* minimo(Node* node) {
    Node* atual = node;
    while (atual->esq != NULL)
        atual = atual->esq;
    return atual;
}

Node* novoNo(int chave) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->chave = chave;
    node->esq = node->dir = NULL;
    node->altura = 0;
    return node;
}


Node* inserir(Node* raiz, int chave) {
    if (raiz == NULL)
        return novoNo(chave);

    if (chave < raiz->chave)
        raiz->esq = inserir(raiz->esq, chave);
    else if (chave > raiz->chave)
        raiz->dir = inserir(raiz->dir, chave);
    else 
        return raiz;

    raiz->altura = 1 + max(altura(raiz->esq), altura(raiz->dir));

    int balance = getBalance(raiz);

  
    if (balance > 1 && chave < raiz->esq->chave)
        return rotacaoDireita(raiz);

  
    if (balance < -1 && chave > raiz->dir->chave)
        return rotacaoEsquerda(raiz);

 
    if (balance > 1 && chave > raiz->esq->chave) {
        raiz->esq = rotacaoEsquerda(raiz->esq);
        return rotacaoDireita(raiz);
    }

   
    if (balance < -1 && chave < raiz->dir->chave) {
        raiz->dir = rotacaoDireita(raiz->dir);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}


Node* remover(Node* raiz, int chave) {
    if (raiz == NULL)
        return raiz;

    if (chave < raiz->chave)
        raiz->esq = remover(raiz->esq, chave);
    else if (chave > raiz->chave)
        raiz->dir = remover(raiz->dir, chave);
    else {
        if ((raiz->esq == NULL) || (raiz->dir == NULL)) {
            Node* temp = raiz->esq ? raiz->esq : raiz->dir;

            if (temp == NULL) {
                temp = raiz;
                raiz = NULL;
            }
            else {
                *raiz = *temp;
            }

            free(temp);
        }
        else {
            Node* temp = minimo(raiz->dir);
            raiz->chave = temp->chave;
            raiz->dir = remover(raiz->dir, temp->chave);
        }
    }

    if (raiz == NULL)
        return raiz;

    raiz->altura = 1 + max(altura(raiz->esq), altura(raiz->dir));

    int balance = getBalance(raiz);

   
    if (balance > 1 && getBalance(raiz->esq) >= 0)
        return rotacaoDireita(raiz);

    
    if (balance > 1 && getBalance(raiz->esq) < 0) {
        raiz->esq = rotacaoEsquerda(raiz->esq);
        return rotacaoDireita(raiz);
    }


    if (balance < -1 && getBalance(raiz->dir) <= 0)
        return rotacaoEsquerda(raiz);

   
    if (balance < -1 && getBalance(raiz->dir) > 0) {
        raiz->dir = rotacaoDireita(raiz->dir);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}


void preOrdem(Node* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->chave);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}


int main() {
    Node* raiz = NULL;

   
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 25);
    raiz = inserir(raiz, 35);
    raiz = inserir(raiz, 50);

    printf("Árvore AVL (Pré-Ordem) antes da remoção:\n");
    preOrdem(raiz);
    printf("\n");

    
    raiz = remover(raiz, 20);

    printf("Árvore AVL (Pré-Ordem) depois de remover 20:\n");
    preOrdem(raiz);
    printf("\n");

    return 0;
}
