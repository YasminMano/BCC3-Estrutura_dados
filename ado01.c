// Implemente, em linguagem C, um programa que utilize ponteiro de ponteiro para
// manipular um vetor de palavras (strings). Seu programa deve: (a) Pedir ao
// usuário que informe a quantidade de palavras que deseja inserir; (b) Alocar
// dinamicamente um vetor de ponteiros para char, para armazenar as palavras,
// com no máximo 100 caracteres cada; (c) Solicitar ao usuário que insira as
// palavras, alocando dinamicamente memória para cada uma delas; (d) Codi car
// uma função chamada converterParaMaiusculo, que recebe um ponteiro de ponteiro
// e a quantidade de palavras, convertendo todas para maiúsculas (CAIXA ALTA);
// (e) Exibir as palavras informadas pelo usuário antes e depois da conversão;
// (f ) Liberar (desalocar) toda a memória alocada dinamicamente ao nal do
// programa.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CARACTERES 100 // Definição do tamanho máximo de cada palavra

// Função para converter todas as palavras para maiúsculas
void converterParaMaiusculo(char** palavras, int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        char* letra = palavras[i]; // Obtém o endereço da palavra atual
        while (*letra) { // Percorre cada caractere da palavra
            *letra = toupper(*letra); // Converte para maiúsculo
            letra++; // Avança para o próximo caractere
        }
    }
}

int main() {
    int quantidade;

    // Pedir ao usuário a quantidade de palavras
    printf("Informe a quantidade de palavras: ");
    scanf("%d", &quantidade);
    getchar(); // Limpar o buffer do teclado

    // Alocar memória para armazenar os ponteiros das palavras
    char** palavras = (char**)malloc(quantidade * sizeof(char*));
    if (palavras == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1; // Encerra o programa se houver erro de alocação
    }

    // Recebendo as palavras do usuário
    for (int i = 0; i < quantidade; i++) {
        palavras[i] = (char*)malloc(MAX_CARACTERES * sizeof(char)); // Aloca memória para cada palavra
        if (palavras[i] == NULL) {
            printf("Erro ao alocar memória para a palavra %d!\n", i + 1);
            return 1;
        }

        printf("Informe a palavra %d: ", i + 1);
        fgets(palavras[i], MAX_CARACTERES, stdin); // Lê a palavra
        palavras[i][strcspn(palavras[i], "\n")] = '\0'; // Remove o '\n' do final da string
    }

    // Exibir palavras antes da conversão
    printf("\nPalavras antes da conversão:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("%s\n", palavras[i]);
    }

    // Converter para maiúsculas
    converterParaMaiusculo(palavras, quantidade);

    // Exibir palavras depois da conversão
    printf("\nPalavras depois da conversão:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("%s\n", palavras[i]);
    }

    // Liberar memória alocada
    for (int i = 0; i < quantidade; i++) {
        free(palavras[i]); // Libera a memória de cada palavra
    }
    free(palavras); // Libera a memória do vetor de ponteiros

    return 0;
}

