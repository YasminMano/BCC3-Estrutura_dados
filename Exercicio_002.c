//Exerc�cio
//O c�digo - fonte a seguir implementa, em linguagem C, uma vers�o
//iterativa do algoritmo Bubble Sort
//Implemente, em linguagem C, uma vers�o recursiva do Bubble Sort.
//N�o esque�a de testar seu c�digo com vetores gerados de forma
//(pseudo) aleat�ria.

#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, n = 10;
	int vetor[n];
	for (i = 0; i < n; i++) {
		vetor[i] = rand() % 100;
	}
	printf("Vetor desordenado pseudo aleatorio:\n");
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