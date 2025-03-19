//Exercício aula 06

//Digamos que nosso alfabeto contém apenas as letras a, b e c.
// Considere o seguinte conjunto de palavras (strings):
// c, aca, bcb, abcba, bacab, aacaa, bbcbb, … Qualquer string
// desse conjunto tem a forma WcM, sendo W uma sequência de
// letras que só contém a e b, e M é o inverso de W (ou seja, M é
// W lido de trás para frente). Implemente, em linguagem C, um
// programa que utiliza uma pilha dinâmica para decidir se uma
// string x pertence ou não ao conjunto, ou seja, decidir se x é da
// forma WcM.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para a pilha
typedef struct Node {
    char data;
    struct Node* next;
} Node;

// Funções para manipular a pilha
void push(Node** top, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

char pop(Node** top) {
    if (*top == NULL) return '\0';
    Node* temp = *top;
    char data = temp->data;
    *top = (*top)->next;
    free(temp);
    return data;
}

int isEmpty(Node* top) {
    return top == NULL;
}

// Função para verificar se a string contém apenas 'a', 'b' e 'c'
int stringValida(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != 'a' && str[i] != 'b' && str[i] != 'c') {
            return 0; // Caracter inválido encontrado
        }
    }
    return 1;
}

// Função para verificar se a string segue o formato WcM
int pertenceConjunto(const char* str) {
    int len = strlen(str);
    if (len < 2 || str[len/2] != 'c') return 0; // Deve conter 'c' no meio

    Node* pilha = NULL;
    int i = 0;

    // Empilha os caracteres de W
    while (str[i] != 'c') {
        push(&pilha, str[i]);
        i++;
    }

    i++; // Pula o 'c'

    // Verifica se M é o inverso de W
    while (str[i] != '\0') {
        if (isEmpty(pilha) || str[i] != pop(&pilha)) return 0;
        i++;
    }

    return isEmpty(pilha); // A pilha deve estar vazia no final
}

// Função principal
int main() {
    char str[100];

    printf("Digite a string para verificar: ");
    scanf("%s", str);

    // Verifica se a string contém apenas os caracteres permitidos
    if (!stringValida(str)) {
        printf("String inválida! Use apenas os caracteres 'a', 'b' e 'c'.\n");
        return 1;
    }

    if (pertenceConjunto(str))
        printf("A string pertence ao conjunto WcM.\n");
    else
        printf("A string NÃO pertence ao conjunto WcM.\n");

    return 0;
}
