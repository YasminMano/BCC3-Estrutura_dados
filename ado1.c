// Implemente, em linguagem C, um programa que utilize ponteiro de ponteiro para
// manipular um vetor de palavras (strings). Seu programa deve: (a) Pedir ao
// usu�rio que informe a quantidade de palavras que deseja inserir; (b) Alocar
// dinamicamente um vetor de ponteiros para char, para armazenar as palavras,
// com no m�ximo 100 caracteres cada; (c) Solicitar ao usu�rio que insira as
// palavras, alocando dinamicamente mem�ria para cada uma delas; (d) Codi car
// uma fun��o chamada converterParaMaiusculo, que recebe um ponteiro de ponteiro
// e a quantidade de palavras, convertendo todas para mai�sculas (CAIXA ALTA);
// (e) Exibir as palavras informadas pelo usu�rio antes e depois da convers�o;
// (f ) Liberar (desalocar) toda a mem�ria alocada dinamicamente ao nal do
// programa.

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 100

// Fun��o para converter as palavras para mai�sculas
void converterParaMaiusculo(char** palavras, int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        for (int j = 0; palavras[i][j] != '\0'; j++) {
            palavras[i][j] = toupper(palavras[i][j]);
        }
    }
}

int main() {
    int quantidade;
    printf("Informe a quantidade de palavras: ");
    scanf("%d", &quantidade);
    getchar(); // Limpar o buffer do teclado

    // Aloca��o din�mica de um vetor de ponteiros para strings
    char** palavras = (char**)malloc(quantidade * sizeof(char*));
    if (palavras == NULL) {
        printf("Erro ao alocar mem�ria!\n");
        return 1;
    }

    // Receber as palavras do usu�rio
    for (int i = 0; i < quantidade; i++) {
        palavras[i] = (char*)malloc(MAX_CHAR * sizeof(char));
        if (palavras[i] == NULL) {
            printf("Erro ao alocar mem�ria para palavra %d!\n", i + 1);
            return 1;
        }
        printf("Informe a palavra %d: ", i + 1);
        fgets(palavras[i], MAX_CHAR, stdin);
        palavras[i][strcspn(palavras[i], "\n")] = '\0'; // Remover o '\n' do fgets
    }

    // Exibir palavras antes da convers�o
    printf("\nPalavras antes da convers�o:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("%s\n", palavras[i]);
    }

    // Converter para mai�sculas
    converterParaMaiusculo(palavras, quantidade);

    // Exibir palavras depois da convers�o
    printf("\nPalavras depois da convers�o:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("%s\n", palavras[i]);
    }

    // Liberar mem�ria alocada
    for (int i = 0; i < quantidade; i++) {
        free(palavras[i]);
    }
    free(palavras);

    return 0;
}