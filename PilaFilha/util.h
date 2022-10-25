#ifndef UTIL_H
#define UTIL_H

typedef int t_valor;

typedef struct t_no *t_apontador;
typedef struct t_no {
    t_valor valor;
    t_apontador proximo;
} t_no;

#endif
