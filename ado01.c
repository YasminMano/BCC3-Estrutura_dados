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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CARACTERES 100 // Defini��o do tamanho m�ximo de cada palavra

// Fun��o para converter todas as palavras para mai�sculas
void converterParaMaiusculo(char** palavras, int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        char* letra = palavras[i]; // Obt�m o endere�o da palavra atual
        while (*letra) { // Percorre cada caractere da palavra
            *letra = toupper(*letra); // Converte para mai�sculo
            letra++; // Avan�a para o pr�ximo caractere
        }
    }
}

int main() {
    int quantidade;

    // Pedir ao usu�rio a quantidade de palavras
    printf("Informe a quantidade de palavras: ");
    scanf("%d", &quantidade);
    getchar(); // Limpar o buffer do teclado

    // Alocar mem�ria para armazenar os ponteiros das palavras
    char** palavras = (char**)malloc(quantidade * sizeof(char*));
    if (palavras == NULL) {
        printf("Erro ao alocar mem�ria!\n");
        return 1; // Encerra o programa se houver erro de aloca��o
    }

    // Recebendo as palavras do usu�rio
    for (int i = 0; i < quantidade; i++) {
        palavras[i] = (char*)malloc(MAX_CARACTERES * sizeof(char)); // Aloca mem�ria para cada palavra
        if (palavras[i] == NULL) {
            printf("Erro ao alocar mem�ria para a palavra %d!\n", i + 1);
            return 1;
        }

        printf("Informe a palavra %d: ", i + 1);
        fgets(palavras[i], MAX_CARACTERES, stdin); // L� a palavra
        palavras[i][strcspn(palavras[i], "\n")] = '\0'; // Remove o '\n' do final da string
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
        free(palavras[i]); // Libera a mem�ria de cada palavra
    }
    free(palavras); // Libera a mem�ria do vetor de ponteiros

    return 0;
}

