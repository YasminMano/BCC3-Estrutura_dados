//ADO 06

// Dizemos que uma sequência de parênteses e colchetes é bem formada se para cada (
// ou [ existe um correspondente ) ou ]. Por exemplo, ( ( ) [ ] ) é bem formada, mas ( [ ) ]
// não é. Sabendo disso, implemente em linguagem C uma função que utiliza uma pilha estática para
// determinar se uma sequência é bem formada ou não.

#include <stdio.h>

#define MAX 100

char pilha[MAX];
int topo = -1;

void empilhar(char c) {
    topo++;
    pilha[topo] = c;
}

char desempilhar() {
    char c = pilha[topo];
    topo--;
    return c;
}

int verificarSequencia(char* seq) {
    for (int i = 0; seq[i] != '\0'; i++) {
        char c = seq[i];

        // Verifica se o caractere é um parêntese ou colchete
        if (c == '(' || c == '[') {
            empilhar(c);
        } else if (c == ')' || c == ']') {
            if (topo == -1) return 0; 
            char topoPilha = desempilhar();
            if ((c == ')' && topoPilha != '(') || (c == ']' && topoPilha != '[')) {
                return 0; 
            }
        } else {
            continue;
        }
    }

    return topo == -1; // Se a pilha estiver vazia, está bem formada
}

int main() {
    char seq[MAX];

    printf("Digite a sequência de parênteses e colchetes (sem espaços): ");
    fgets(seq, sizeof(seq), stdin);  // Usar fgets para capturar a linha inteira

    // Remover o caractere de nova linha (\n) que o fgets pode adicionar
    for (int i = 0; seq[i] != '\0'; i++) {
        if (seq[i] == '\n') {
            seq[i] = '\0';  // Substitui o \n por \0 (final da string)
            break;
        }
    }

    // Verifica se a sequência contém caracteres inválidos
    for (int i = 0; seq[i] != '\0'; i++) {
        if (!(seq[i] == '(' || seq[i] == ')' || seq[i] == '[' || seq[i] == ']')) {
            printf("A sequência contém caracteres inválidos. Apenas parênteses e colchetes são permitidos.\n");
            return 0;
        }
    }

    if (verificarSequencia(seq)) {
        printf("A sequência é bem formada.\n");
    } else {
        printf("A sequência não é bem formada.\n");
    }

    return 0;
}
