//Exercício
//O código - fonte a seguir implementa, em linguagem C, uma versão
//iterativa do algoritmo Bubble Sort.
//void bubbleSort(int vetor[], int n) {
//	int i, j, aux;
//
//	for (i = 0; i < n; i++) {
//		for (j = 0; j < n - 1; j++) {
//			if (vetor[j] > vetor[j + 1]) {
//				aux = vetor[j];
//				vetor[j] = vetor[j + 1];
//				vetor[j + 1] = aux;
//			}
//		}
//	}
//}
//Implemente, em linguagem C, uma versão recursiva do Bubble Sort.
//Não esqueça de testar seu código com vetores gerados de forma
//(pseudo) aleatória.

#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int vetor[], int n) {
	int i, aux;

	if (n == 1) {
		return;
	}

	for (i = 0; i < n - 1; i++) {
		if (vetor[i] > vetor[i + 1]) {
			aux = vetor[i];
			vetor[i] = vetor[i + 1];
			vetor[i + 1] = aux;
		}
	}

	bubbleSort(vetor, n - 1);
}

int main() {
	int i, n = 10;
	int vetor[n];
	for (i = 0; i < n; i++) {
		vetor[i] = rand() % 100;
	}
	printf("Vetor original:\n");
	for (i = 0; i < n; i++) {
		printf("%d ", vetor[i]);
	}
	printf("\n");
	bubbleSort(vetor, n);
	printf("Vetor ordenado:\n");
	for (i = 0; i < n; i++) {
		printf("%d ", vetor[i]);
	}
	printf("\n");
	return 0;
}

//O código acima implementa uma versão recursiva do Bubble Sort. 
// A função bubbleSort recebe um vetor de inteiros e o tamanho do vetor. 
// A função é recursiva e, a cada chamada, compara os elementos adjacentes do vetor e os troca de posição, caso necessário. 
// A função é chamada recursivamente até que o vetor esteja ordenado. 
// O código principal gera um vetor de inteiros de forma aleatória, imprime o vetor original, chama a função bubbleSort e imprime o vetor ordenado.