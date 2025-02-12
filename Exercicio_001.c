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
    int ***matriz;
    int i, j, k;

    // Pegando as dimensões da matriz
    printf("Digite o tamanho de x: ");
    scanf("%d", &x);
    printf("Digite o tamanho de y: ");
    scanf("%d", &y);
    printf("Digite o tamanho de z: ");
    scanf("%d", &z);

    // Criando a matriz (alocação de memória)
    matriz = malloc(x * sizeof(int **));
    for (i = 0; i < x; i++) {
        matriz[i] = malloc(y * sizeof(int *));
        for (j = 0; j < y; j++) {
            matriz[i][j] = malloc(z * sizeof(int));
        }
    }

    // Preenchendo a matriz com valores do usuário
    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++) {
            for (k = 0; k < z; k++) {
                printf("Digite o valor para matriz[%d][%d][%d]: ", i, j, k);
                scanf("%d", &matriz[i][j][k]);
            }
        }
    }

    // Mostrando os valores da matriz
    printf("\nMatriz 3D:\n");
    for (i = 0; i < x; i++) {
        printf("Camada %d:\n", i);
        for (j = 0; j < y; j++) {
            for (k = 0; k < z; k++) {
                printf("%d ", matriz[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    // Liberando a memória
    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++) {
            free(matriz[i][j]);
        }
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
