// Exercício
// Implemente, em linguagem C, um programa que:
// (a) Solicite ao usuário as dimensões x, y e z para uma matriz
// tridimensional (matriz 3D) de inteiros.
// (b) Aloque dinamicamente a memória para a matriz 3D utilizando
// ponteiro de ponteiro de ponteiro (int ***).
// (c) Preencha a matriz 3D com valores fornecidos pelo usuário.
// (d) Imprima a matriz 3D, exibindo os valores de cada camada, linha
// por linha, para cada uma das camadas da matriz.
// (e) Libere (desaloque) a memória alocada dinamicamente ao final.


#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, y, z;

    // Solicitar as dimensões da matriz 3D
    printf("Digite as dimensões da matriz 3D (x, y, z): ");
    scanf("%d %d %d", &x, &y, &z);

    // Alocar dinamicamente a memória para a matriz 3D
    int ***matriz = (int ***)malloc(x * sizeof(int **));  // Aloca o ponteiro para x camadas
    for (int i = 0; i < x; i++) {
        matriz[i] = (int **)malloc(y * sizeof(int *));  // Aloca o ponteiro para y linhas em cada camada
        for (int j = 0; j < y; j++) {
            matriz[i][j] = (int *)malloc(z * sizeof(int));  // Aloca o ponteiro para z colunas em cada linha
        }
    }

    // Preencher a matriz 3D com valores fornecidos pelo usuário
    printf("Preencha a matriz 3D com valores:\n");
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                printf("Digite o valor para matriz[%d][%d][%d]: ", i, j, k);
                scanf("%d", &matriz[i][j][k]);
            }
        }
    }

    // Imprimir a matriz 3D
    printf("\nMatriz 3D preenchida:\n");
    for (int i = 0; i < x; i++) {
        printf("Camada %d:\n", i + 1);
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                printf("%d ", matriz[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    // Liberar a memória alocada dinamicamente
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            free(matriz[i][j]);  // Libera cada linha de cada camada
        }
        free(matriz[i]);  // Libera cada camada
    }
    free(matriz);  // Libera o ponteiro de camadas

    return 0;
}
