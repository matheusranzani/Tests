#ifndef FILA_H
#define FILA_H

#include "util.h"

typedef struct {
    t_apontador primeiro;
    t_apontador ultimo;
} t_fila;

void criar_fila(t_fila *fila);
int fila_vazia(t_fila *f);
void inserir(t_fila *fila, t_valor valor);
int remover(t_fila *fila);

#endif
