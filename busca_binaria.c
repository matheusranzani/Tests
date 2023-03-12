#include <stdio.h>

void merge(int *vetor, int esquerda, int meio, int direita) {
    int i = esquerda, j = meio + 1, k = 0;

    int tamanho = (direita - esquerda) + 1;
    int w[tamanho];

    while (i <= meio && j <= direita) {
        if (vetor[i] <= vetor[j]) {
            w[k++] = vetor[i++];
        } else {
            w[k++] = vetor[j++];
        }
    }

    while (i <= meio) {
        w[k++] = vetor[i++];
    }

    while (j <= direita) {
        w[k++] = vetor[j++];
    }

    for (i = 0; i < tamanho; i++) {
        vetor[esquerda + i] = w[i];
    }
}

void merge_sort(int *vetor, int esquerda, int direita) {
    if (esquerda >= direita) {
        return;
    }

    int meio = (esquerda + direita) / 2;

    merge_sort(vetor, esquerda, meio);
    merge_sort(vetor, meio + 1, direita);
    merge(vetor, esquerda, meio, direita);
}

int busca_binaria(int *vetor, int valor, int esquerda, int direita) {
    if (esquerda > direita) {
        return - 1;
    }

    int meio = (esquerda + direita) / 2;

    if (valor == vetor[meio]) {
        return meio;
    } else if (valor > vetor[meio]) {
        return busca_binaria(vetor, valor, meio + 1, direita);
    } else {
        return busca_binaria(vetor, valor, esquerda, meio - 1);
    }

    return - 1;
}

int main() {
    int tamanho;
    scanf("%d", &tamanho);

    int vetor[tamanho];

    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
    }

    printf("\n");

    merge_sort(vetor, 0, tamanho - 1);

    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    int valor;

    while (1) {
        scanf("%d", &valor);

        if (valor == 999) break;

        int posicao = busca_binaria(vetor, valor, 0, tamanho - 1);
        posicao == -1 ? printf("Não encontrou\n") : printf("%d\n", posicao);
    }

    return 0;
}
