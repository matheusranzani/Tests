#include <stdio.h>
#include "pilha.h"
#include "fila.h"

int main() {
    int N;
    int K;
    char C;
    int I;
    int resultado_pilha;
    int resultado_fila;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        t_pilha pilha;
        t_fila fila;
        int eh_pilha = 1;
        int eh_fila = 1;

        scanf("%d", &K);

        criar_pilha(&pilha);
        criar_fila(&fila);

        while (K--) {
            scanf(" %c", &C);
            scanf("%d", &I);

            if (C == 'i') {
                empilhar(&pilha, I);
                inserir(&fila, I);
            } else {
                resultado_pilha = desempilhar(&pilha);
                resultado_fila = remover(&fila);

                if (resultado_pilha == I && eh_pilha) {
                    eh_pilha = 1;
                } else {
                    eh_pilha = 0;
                }

                if (resultado_fila == I && eh_fila) {
                    eh_fila = 1;
                } else {
                    eh_fila = 0;
                }
            }
        }

        if (!eh_pilha && !eh_fila) {
            printf("impossivel\n");
        } else if (eh_pilha && eh_fila) {
            printf("indefinido\n");
        } else if (eh_pilha && !eh_fila) {
            printf("pilha\n");
        } else {
            printf("fila\n");
        }
    }

    return 0;
}
