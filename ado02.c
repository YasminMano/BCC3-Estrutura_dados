//Implemente, em linguagem C, um algoritmo recursivo para encontrar o valor máximo em
//um vetor de inteiros, dividindo o vetor em dois subvetores de tamanho aproximadamente n / 2 cada

#include <stdio.h>
#include <stdlib.h>

void maximo(int* vetor, int tamanho, int* max_atual) {
    if (tamanho == 0) return; // Caso base: vetor vazio

    if (vetor[tamanho - 1] > *max_atual) {
        *max_atual = vetor[tamanho - 1]; // Atualiza o máximo se necessário
    }

    maximo(vetor, tamanho - 1, max_atual); // Chamada recursiva reduzindo o tamanho
}

int main() {
    int n;

    printf("Informe o tamanho do vetor: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("O vetor deve ter pelo menos um elemento.\n");
        return 1;
    }

    int arr[n];

    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max_valor = arr[0]; // Inicializa com o primeiro elemento
    maximo(arr, n, &max_valor);

    printf("Esse é o maior valor do vetor: %d\n", max_valor);

    return 0;
}
