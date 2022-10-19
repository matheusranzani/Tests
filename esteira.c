#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10 // Tamanho máximo da esteira

// Estrutura de uma caixa
typedef struct Caixa {
    int altura;
    int largura;
    float peso;
} Caixa;

// Estrutura da esteira
typedef struct Esteira {
    Caixa caixas[TAMANHO];
    int incio;
    int fim;
    int quantidade;
} Esteira;

// Cria uma esteira vazia
Esteira inicializa_esteira(Esteira e) {
    e.incio = 0;
    e.fim = 0;
    e.quantidade = 0;

    return e;
}

// Retorna se a esteira está vazia (1) ou não (0)
int esteira_vazia(Esteira e) {
    return e.quantidade == 0;
}

float calcula_peso_total(Esteira e) {
    float peso_total = 0;
    int i = e.incio;

    for (int j = 0; j < e.quantidade; j++) {
        peso_total += e.caixas[i].peso;
        i = (i + 1) % TAMANHO; // Esteira circular
    }

    return peso_total;
}

float calcula_peso_medio(Esteira e) {
    if (esteira_vazia(e)) {
        return 0;
    }

    float peso_medio = calcula_peso_total(e) / e.quantidade;

    return peso_medio;
}

// Adiciona a caixa através da referência da esteira passada como parâmetro
void inserir_caixa(Esteira *e, Caixa c) {
    float peso_total = calcula_peso_total(*e);

    if (e->quantidade == TAMANHO || (peso_total + c.peso) > 50) {
        printf("\nA esteira esta cheia ou o peso da caixa solicitada ultrapassara 50 kg!\n\n");
        return;
    }

    e->caixas[e->fim] = c;
    e->fim = (e->fim + 1) % TAMANHO; // Esteira circular
    e->quantidade++;

    printf("\nCaixa inserida com sucesso!\n");
    printf("\n==========================================\n");
    printf("Peso total atual = %.2f\n", calcula_peso_total(*e));
    printf("Quantidade atual de caixas na esteira = %d\n", e->quantidade);
    printf("Peso medio atual = %.2f\n", calcula_peso_medio(*e));
    printf("==========================================\n\n");
}

// Remove uma caixa da fila e retorna se a operação deu certo (1) ou não (0)
int remove_caixa(Esteira *e, Caixa *c) {
    if (esteira_vazia(*e)) {
        printf("A esteira esta vazia\n\n");
        return 0;
    }

    *c = e->caixas[e->incio];
    e->incio = (e->incio + 1) % TAMANHO; // Esteira circular
    e->quantidade--;

    return 1;
}

// Imprime todas as caixas presentes na esteira
void mostra_esteira(Esteira e) {
    if (esteira_vazia(e)) {
        printf("A esteira esta vazia\n\n");
        return;
    }

    int i = e.incio;

    for (int j = 0; j < e.quantidade; j++) {
        printf("Caixa na posicao %d da esteira:\n\n", j + 1);
        printf("Altura = %d cm\n", e.caixas[i].altura);
        printf("Largura = %d cm\n", e.caixas[i].largura);
        printf("Peso = %.2f kg\n\n", e.caixas[i].peso);
        i = (i + 1) % TAMANHO;
    }
}

// Função auxiliar que limpa o texto da tela
void limpa_tela() {
    #if defined _WIN32
        system("cls");
    #elif defined (__LINUX__) || defined (__gnu_linux__) || defined (__linux__)
        system("clear");
    #elif defined (__APPLE__)
        system("clear");
    #endif
}

// Função auxiliar apenas para uma melhor exibição dos dados
void espera() {
    int c;

    do {
        c = getchar();
    } while(c != '\n' && c != EOF);

    if (c == EOF) {
        return;
    } else {
        printf("Pressione ENTER para continuar. . .");
        getchar();
    }
}

int main() {
    Esteira esteira;
    int opcao;

    do {
        printf("--- Enfileiramento de caixas em uma esteira ---\n\n");
        printf("1 - Inicializar/Reinicializar esteira\n");
        printf("2 - Inserir caixa\n");
        printf("3 - Remover caixa\n");
        printf("4 - Mostrar o peso total\n");
        printf("5 - Mostrar a quantidade de caixas\n");
        printf("6 - Mostrar o peso medio\n");
        printf("7 - Mostrar esteira\n");
        printf("8 - Encerrar programa\n");

        printf("\nEscolha a opcao que deseja: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                limpa_tela();

                printf("--- Inicializar/Reinicializar esteira ---\n\n");
                esteira = inicializa_esteira(esteira);
                printf("Esteira incializada!\n\n");

                espera();
                limpa_tela();
                break;
            case 2:
                limpa_tela();

                printf("--- Inserir caixa ---\n\n");
                Caixa c;
                printf("Digite as informacoes da caixa:\n");
                printf("Altura em cm: ");
                scanf("%d", &c.altura);
                printf("Largura em cm: ");
                scanf("%d", &c.largura);
                printf("Peso em kg: ");
                scanf("%f", &c.peso);

                inserir_caixa(&esteira, c);

                espera();
                limpa_tela();
                break;
            case 3:
                limpa_tela();

                printf("--- Remover caixa ---\n\n");
                Caixa caixa_removida;
                int deu_certo = remove_caixa(&esteira, &caixa_removida);

                if (deu_certo) {
                    printf("Caixa removida:\n\n");
                    printf("Altura = %d cm\n", caixa_removida.altura);
                    printf("Largura = %d cm\n", caixa_removida.largura);
                    printf("Peso = %.2f kg\n\n", caixa_removida.peso);
                }

                printf("==========================================\n");
                printf("Peso total atual = %.2f\n", calcula_peso_total(esteira));
                printf("Quantidade atual de caixas na esteira = %d\n", esteira.quantidade);
                printf("Peso medio atual = %.2f\n", calcula_peso_medio(esteira));
                printf("==========================================\n\n");

                espera();
                limpa_tela();
                break;
            case 4:
                limpa_tela();

                printf("--- Mostrar o peso total ---\n\n");
                printf("Peso total atual = %.2f\n\n", calcula_peso_total(esteira));

                espera();
                limpa_tela();
                break;
            case 5:
                limpa_tela();

                printf("--- Mostrar a quantidade de caixas ---\n\n");
                printf("Quantidade atual de caixas na esteira = %d\n\n", esteira.quantidade);

                espera();
                limpa_tela();
                break;
            case 6:
                limpa_tela();

                printf("---  Mostrar o peso medio ---\n\n");
                printf("Peso medio atual = %.2f\n\n", calcula_peso_medio(esteira));

                espera();
                limpa_tela();
                break;
            case 7:
                limpa_tela();

                printf("--- Mostrar esteira ---\n\n");
                mostra_esteira(esteira);

                espera();
                limpa_tela();
                break;
            case 8:
                printf("\nPrograma encerrado!\n");
                break;
            default:
                limpa_tela();
                printf("--- Opcao invalida ---\n\n");
                printf("Digite uma opcao valida!\n\n");
                espera();
                limpa_tela();
        }
    } while (opcao != 8);

    return 0;
}
