#include <stdio.h>
#include <stdlib.h>

int main() {
	int N;
	scanf("%d", &N);

	int numero;
	int indice = 0;
	int *numeros = (int *)malloc(sizeof(int));

	for (int i = 0; i < N; i++) {
		scanf("%d", &numero);

		if (numero == 0) {
			numeros[--indice] = 0;
		} else {
			numeros = realloc(numeros, (indice + 1) * sizeof(int));
			numeros[indice++] = numero;
		}
	}

	int soma = 0;
	for (int i = 0; i <= indice; i++) {
		soma += numeros[i];
	}

	printf("%d\n", soma);

	return 0;
}
