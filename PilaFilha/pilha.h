#ifndef PILHA_H
#define PILHA_H

#include "util.h"

typedef struct {
    t_apontador topo;
} t_pilha;

void criar_pilha(t_pilha *pilha);
int pilha_vazia(t_pilha *pilha);
void empilhar(t_pilha *pilha, t_valor valor);
int desempilhar(t_pilha *pilha);

#endif
