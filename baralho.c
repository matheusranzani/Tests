#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void verifica_baralho(char cartas[], int* C, int* E, int* U, int* P,
                      char erro_C[], char erro_E[], char erro_U[], char erro_P[], int* sem_erro) {
    int i = 0;
    *C = 13, *E = 13, *U = 13, *P = 13;
    int tamanho = strlen(cartas);

    while (cartas[i] != '\0') {
        switch (cartas[i]) {
            case 'C':
                (*C)--;
                break;
            case 'E':
                (*E)--;
                break;
            case 'U':
                (*U)--;
                break;
            case 'P':
                (*P)--;
                break;
            default:
                break;
        }

        if ((i + 1) % 3 == 0) {
            char carta_atual[4];
            strncpy(carta_atual, cartas + i - 2, 3);

            char cartas_atualizadas[tamanho - i];
            strncpy(cartas_atualizadas, cartas + (i + 1), tamanho - i);

            char* teste = strstr(cartas_atualizadas, carta_atual);
            if (teste) {
                *sem_erro = 0;
                switch (carta_atual[2]) {
                    case 'C':
                        strcpy(erro_C, "erro");
                        break;
                    case 'E':
                        strcpy(erro_E, "erro");
                        break;
                    case 'U':
                        strcpy(erro_U, "erro");
                        break;
                    case 'P':
                        strcpy(erro_P, "erro");
                        break;
                    default:
                        break;
                }
            }
        }

        i++;
    }
}

void escreve_resultado(int cartas_faltando, char* erro) {
    if (strcmp(erro, "erro") == 0) {
        printf("%s\n", erro);
    } else {
        printf("%d\n", cartas_faltando);
    }
}

int main() {
    char cartas[157];
    int C, E, U, P;
    char erro_C[5];
    char erro_E[5];
    char erro_U[5];
    char erro_P[5];
    int sem_erro = 1;

    scanf("%s", cartas);

    verifica_baralho(cartas, &C, &E, &U, &P, erro_C, erro_E, erro_U, erro_P, &sem_erro);

    escreve_resultado(C, erro_C);
    escreve_resultado(E, erro_E);
    escreve_resultado(U, erro_U);
    escreve_resultado(P, erro_P);

    return 0;
}
