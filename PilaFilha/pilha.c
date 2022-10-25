#include <stdlib.h>
#include "pilha.h"

void criar_pilha(t_pilha *pilha) {
    pilha->topo = NULL;
}

int pilha_vazia(t_pilha *pilha) {
    return pilha->topo == NULL;
}

void empilhar(t_pilha *pilha, t_valor valor) {
    t_apontador novo = (t_apontador)malloc(sizeof(t_no));

    novo->valor = valor;
    novo->proximo = pilha->topo;
    pilha->topo = novo;
}

int desempilhar(t_pilha *pilha) {
    t_apontador no;

    int valor = pilha->topo->valor;
    no = pilha->topo;
    pilha->topo = pilha->topo->proximo;

    free(no);

    return valor;
}
