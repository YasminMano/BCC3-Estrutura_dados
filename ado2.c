//Implemente, em linguagem C, um algoritmo recursivo para encontrar o valor máximo em
//um vetor de inteiros, dividindo o vetor em dois subvetores de tamanho aproximadamente n / 2 cada

#include <stdio.h>
#include <stdlib.h>

int max(int* vetor, int inicio, int fim) {
	if (inicio == fim) {
		return vetor[inicio];
	}
	int meio = (inicio + fim) / 2;
	int max1 = max(vetor, inicio, meio);
	int max2 = max(vetor, meio + 1, fim);
	return max1 > max2 ? max1 : max2;
}

int main() {
	int n;

	printf("Informe o tamanho do vetor: ");
	scanf("%d", &n);

	int arr[n];

	printf("Digite os elementos do vetor:\n");
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	int maximo = max(arr, 0, n - 1);

	printf("Esse é o maior valor do vetor: %d\n", maximo);

	return 0;
}