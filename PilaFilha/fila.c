#include <stdlib.h>
#include "fila.h"

void criar_fila(t_fila *fila) {
    fila->primeiro = NULL;
    fila->ultimo = NULL;
}

int fila_vazia(t_fila *fila) {
    return fila->primeiro == NULL;
}

void inserir(t_fila *fila, t_valor valor) {
    t_apontador novo = (t_apontador)malloc(sizeof(t_no));

    novo->valor = valor;
    novo->proximo = NULL;

    if (fila_vazia(fila)) {
        fila->primeiro = novo;
        fila->ultimo = novo;
    } else {
        fila->ultimo->proximo = novo;
        fila->ultimo = novo;
    }
}

int remover(t_fila *fila) {
    int valor = fila->primeiro->valor;

    t_apontador primeiro = fila->primeiro;

    if (fila->primeiro == fila->ultimo) {
        fila->primeiro = NULL;
        fila->ultimo = NULL;

        free(primeiro);
    } else {
        fila->primeiro = fila->primeiro->proximo;
        free(primeiro);
    }

    return valor;
}
