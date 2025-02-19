//Exerc�cio
//O c�digo - fonte a seguir implementa, em linguagem C, uma vers�o
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
//Implemente, em linguagem C, uma vers�o recursiva do Bubble Sort.
//N�o esque�a de testar seu c�digo com vetores gerados de forma
//(pseudo) aleat�ria.

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

//O c�digo acima implementa uma vers�o recursiva do Bubble Sort. 
// A fun��o bubbleSort recebe um vetor de inteiros e o tamanho do vetor. 
// A fun��o � recursiva e, a cada chamada, compara os elementos adjacentes do vetor e os troca de posi��o, caso necess�rio. 
// A fun��o � chamada recursivamente at� que o vetor esteja ordenado. 
// O c�digo principal gera um vetor de inteiros de forma aleat�ria, imprime o vetor original, chama a fun��o bubbleSort e imprime o vetor ordenado.