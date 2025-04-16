//Exercício 9:

// Implemente, em linguagem C, uma função que utilize uma
// árvore AVL para ordenar um vetor de números inteiros.

//Código Fonte que foi alterado para resolver o exercício 9:

// // Função para visualização bidimensional da árvore
// void imprimirInOrdem(link p, int b) {
//      int i;
//      if (p == NULL) {
//         for (i = 0; i < b; i++) printf("-----");
//         printf("NULL\n");
//         return;
//      }
//      imprimirInOrdem(p->dir, b + 1);
//      for (i = 0; i < b; i++) printf("-----");
//      printf("%i\n", p->chave);
//      imprimirInOrdem(p->esq, b + 1);
// }

// int main(void) {
//     link Arvore = NULL; //Inicializar a árvore AVL vazia

//     Arvore = inserirAVL(Arvore, 1); // Inserir 1 na AVL
//     Arvore = inserirAVL(Arvore, 2); // Inserir 2 na AVL
//     Arvore = inserirAVL(Arvore, 3); // Inserir 3 na AVL
//     Arvore = inserirAVL(Arvore, 4); // Inserir 4 na AVL
//     Arvore = inserirAVL(Arvore, 5); // Inserir 5 na AVL
//     Arvore = inserirAVL(Arvore, 6); // Inserir 6 na AVL
//     Arvore = inserirAVL(Arvore, 7); // Inserir 7 na AVL

//     imprimirInOrdem(Arvore, 0); // Visualização bidimensional

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

// Definição do tipo link como ponteiro para struct node
typedef struct node* link;

// Definição da estrutura node
struct node {
    int chave;
    link esq;
    link dir;
    int h; // altura
};

// Função que retorna a altura de um nó
int altura(link raiz) {
    return (raiz == NULL) ? -1 : raiz->h;
}

// Função que retorna o maior entre dois inteiros
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Rotações AVL
// Rotação simples á  direita (caso LL - esq + esq)
link rotacaoDireita(link p) {
    link u = p->esq;
    p->esq = u->dir;
    u->dir = p;
    p->h = max(altura(p->esq), altura(p->dir)) + 1;
    u->h = max(altura(u->esq), p->h) + 1;
    return u;
}

// Rotação simples á esquerda (caso RR - dir + dir)
link rotacaoEsquerda(link p) {
    link z = p->dir;
    p->dir = z->esq;
    z->esq = p;
    p->h = max(altura(p->esq), altura(p->dir)) + 1;
    z->h = max(p->h, altura(z->dir)) + 1;
    return z;
}

// Rotação dupla á direita (caso LR - esq + dir)
link rotacaoEsquerdaDireita(link p) {
    p->esq = rotacaoEsquerda(p->esq);
    return rotacaoDireita(p);
}
// Rotação dupla á esquerda (caso RL - dir + esq)
link rotacaoDireitaEsquerda(link p) {
    p->dir = rotacaoDireita(p->dir);
    return rotacaoEsquerda(p);
}

// Função para inserir um elemento na árvore AVL
link inserirAVL(link raiz, int valor) {
     if (raiz == NULL) { // Verifica se a árvore está vazia
        link novoNode = (link)malloc(sizeof(struct node)); // Aloca novo nó
        novoNode->chave = valor; // Valor chave
        novoNode->esq = NULL; // Filho esquerdo
        novoNode->dir = NULL; // // Filho direito
        novoNode->h = 0; // Altura inicial do nó 0
        return novoNode; // Retorna ponteiro para o novo nó
     } 
     if (valor < raiz->chave) // Se o valor for menor que a chave da raiz
        raiz->esq = inserirAVL(raiz->esq, valor); // Inserir na sub árvore esquerda
     else // Se o valor for maior que a chave da raiz
        raiz->dir = inserirAVL(raiz->dir, valor); // Inserir na sub árvore direita

     // Atualizar a altura do não atual    
     raiz->h = max(altura(raiz->esq), altura(raiz->dir)) + 1;

     // Calcular o fator de balanceamento
     int fb = altura(raiz->esq) - altura(raiz->dir);

     if (fb == 2) { // Sub árvore esquerda desbalanceou
        if (valor < raiz->esq->chave) // Caso LL - esq + esq (reta)
           return rotacaoDireita(raiz); // Rotação simples á direita
        else // Caso LR - esq + dir (curva)
           return rotacaoEsquerdaDireita(raiz); // Rotação dupla á direita
     }
     else if (fb == -2) { // Sub árvore direita desbalanceou
        if (valor > raiz->dir->chave) // Caso RR - dir + dir (reta)
           return rotacaoEsquerda(raiz); // Rotação simples á esquerda
        else // Caso RL - dir + esq (curva)
           return rotacaoDireitaEsquerda(raiz); // Rotação dupla á esquerda
     }

     return raiz; // Se não houve desbalanceamento, retorna a raiz normalmente
}

// Alteração do código para resolver o exercício 9:

// Preenche vetor com os elementos em ordem (in-order)
void preencherVetorOrdenado(link raiz, int* vetor, int* indice) {
    if (raiz != NULL) {
        preencherVetorOrdenado(raiz->esq, vetor, indice);
        vetor[*indice] = raiz->chave;
        (*indice)++;
        preencherVetorOrdenado(raiz->dir, vetor, indice);
    }
}

// Ordena vetor com AVL
void ordenarComAVL(int* vetor, int tamanho) {
    link arvore = NULL;
    for (int i = 0; i < tamanho; i++) {
        arvore = inserirAVL(arvore, vetor[i]);
    }

    int indice = 0;
    preencherVetorOrdenado(arvore, vetor, &indice);
}

// Função para imprimir o vetor
void imprimirVetor(int* vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

// Função principal
int main(void) {
    int vetor[] = {7, 3, 1, 4, 6, 2, 5};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    printf("Vetor original:\n");
    imprimirVetor(vetor, tamanho);

    ordenarComAVL(vetor, tamanho);

    printf("Vetor ordenado com AVL:\n");
    imprimirVetor(vetor, tamanho);

    return 0;
}
