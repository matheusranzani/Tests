#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Funcionario {
    char nome[50];
    int codigo;
    float salario_inicial;
    float salario_novo;
    struct Funcionario* proximo;
} Funcionario;

typedef struct Lista {
    Funcionario* primeiro;
    Funcionario* ultimo;
} Lista;

void cria_lista(Lista* l) {
    l->primeiro = NULL;
    l->ultimo = NULL;
}

int esta_vazia(Lista* l) {
    return l->primeiro == NULL && l->ultimo == NULL;
}

void insere(Lista* l, Funcionario f) {
    Funcionario* novo_funcionario = (Funcionario*) malloc(sizeof(Funcionario));
    strcpy(novo_funcionario->nome, f.nome);
    novo_funcionario->codigo = f.codigo;
    novo_funcionario->salario_inicial = f.salario_inicial;
    novo_funcionario->salario_novo = f.salario_novo;
    novo_funcionario->proximo = NULL;

    if (esta_vazia(l)) {
        l->primeiro = novo_funcionario;
        l->ultimo = novo_funcionario;
    } else {
        l->ultimo->proximo = novo_funcionario;
        l->ultimo = novo_funcionario;
    }
}

void espera() {
    int c;

    do {
        c = getchar();
    } while(c != '\n' && c != EOF);

    if (c == EOF) {
        return;
    } else {
        printf("Pressione qualquer tecla para continuar. . .");
        getchar();
    }
}

void limpa_tela() {
    #if defined _WIN32
        system("cls");
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        system("clear");
    #elif defined (__APPLE__)
        system("clear");
    #endif
}

Funcionario* retorna_funcionario(Lista* l, char nome[]) {
    Funcionario* f = l->primeiro;

    do {
        if (strcmp(f->nome, nome) == 0) {
            return f;
        }

        f = f->proximo;
    } while (f != NULL);

    return NULL;
}

void opcao1(Lista* l) {
    Funcionario f;

    printf("=== Inserir informações ===\n\n");
    printf("Nome: ");
    while (getchar() != '\n');
    fgets(f.nome, 50, stdin);
    printf("Código: ");
    scanf("%d", &f.codigo);
    printf("Salário: ");
    scanf("%f", &f.salario_inicial);

    if (f.codigo == 1) {
        f.salario_novo = f.salario_inicial * 1.1;
    } else if (f.codigo == 2) {
        f.salario_novo = f.salario_inicial * 1.2;
    } else if (f.codigo == 3) {
        f.salario_novo = f.salario_inicial * 1.3;
    } else {
        f.salario_novo = f.salario_inicial * 1.4;
    }

    insere(l, f);

    printf("\nDados salvos com sucesso!\n\n");
    espera();
    limpa_tela();
}

void opcao2_opcao3(Lista* l, int opcao) {
    if (opcao == 2) {
        printf("=== Gerar relatório em tela ===\n\n");
    }

    if (opcao == 3) {
        printf("=== Gerar relatório em arquivo ===\n\n");
    }

    if (esta_vazia(l)) {
        printf("Não há dados cadastrados!\n\n");
        espera();
        limpa_tela();
        return;
    }

    Funcionario* f = l->primeiro;

    float menor_salario;
    float maior_salario;
    char nome_maior_salario[50];
    char nome_menor_salario[50];

    maior_salario = l->primeiro->salario_novo;
    menor_salario = l->primeiro->salario_novo;
    strcpy(nome_maior_salario, l->primeiro->nome);
    strcpy(nome_menor_salario, l->primeiro->nome);

    do {
        if (opcao == 2) {
            printf("Nome: %s", f->nome);
            printf("Código: %d\n", f->codigo);
            printf("Salário antigo: %.2f\n", f->salario_inicial);
            printf("Salário novo: %.2f\n", f->salario_novo);
            printf("Diferença: %.2f\n\n", f->salario_novo - f->salario_inicial);
        }

        if (f->salario_novo > maior_salario) {
            maior_salario = f->salario_novo;
            strcpy(nome_maior_salario, f->nome);
        }

        if (f->salario_novo < menor_salario) {
            menor_salario = f->salario_novo;
            strcpy(nome_menor_salario, f->nome);
        }

        f = f->proximo;
    } while (f != NULL);

    Funcionario* funcionario_maior_salario = retorna_funcionario(l, nome_maior_salario);
    Funcionario* funcionario_menor_salario = retorna_funcionario(l, nome_menor_salario);

    if (opcao == 2) {
        printf("=== Informações do funcionário com maior saláraio ===\n");
        printf("Nome: %s", funcionario_maior_salario->nome);
        printf("Código: %d\n", funcionario_maior_salario->codigo);
        printf("Salário antigo: %.2f\n", funcionario_maior_salario->salario_inicial);
        printf("Salário novo: %.2f\n", funcionario_maior_salario->salario_novo);
        printf("Diferença: %.2f\n\n", funcionario_maior_salario->salario_novo - funcionario_maior_salario->salario_inicial);

        printf("=== Informações do funcionário com menor saláraio ===\n");
        printf("Nome: %s", funcionario_menor_salario->nome);
        printf("Código: %d\n", funcionario_menor_salario->codigo);
        printf("Salário antigo: %.2f\n", funcionario_menor_salario->salario_inicial);
        printf("Salário novo: %.2f\n", funcionario_menor_salario->salario_novo);
        printf("Diferença: %.2f\n\n", funcionario_menor_salario->salario_novo - funcionario_menor_salario->salario_inicial);
    }

    if (opcao == 3) {
        FILE* arquivo;
        arquivo = fopen("relatorio.txt", "w");

        fprintf(arquivo, "=== Relatório ===\n\n");
        fprintf(arquivo, "=== Informações do funcionário com maior saláraio ===\n");
        fprintf(arquivo, "Nome: %s", funcionario_maior_salario->nome);
        fprintf(arquivo, "Código: %d\n", funcionario_maior_salario->codigo);
        fprintf(arquivo, "Salário antigo: %.2f\n", funcionario_maior_salario->salario_inicial);
        fprintf(arquivo, "Salário novo: %.2f\n", funcionario_maior_salario->salario_novo);
        fprintf(arquivo, "Diferença: %.2f\n\n", funcionario_maior_salario->salario_novo - funcionario_maior_salario->salario_inicial);

        fprintf(arquivo, "=== Informações do funcionário com menor saláraio ===\n");
        fprintf(arquivo, "Nome: %s", funcionario_menor_salario->nome);
        fprintf(arquivo, "Código: %d\n", funcionario_menor_salario->codigo);
        fprintf(arquivo, "Salário antigo: %.2f\n", funcionario_menor_salario->salario_inicial);
        fprintf(arquivo, "Salário novo: %.2f\n", funcionario_menor_salario->salario_novo);
        fprintf(arquivo, "Diferença: %.2f", funcionario_menor_salario->salario_novo - funcionario_menor_salario->salario_inicial);

        printf("Relatório gerado com sucesso!\n\n");

        fclose(arquivo);
    }

    espera();
    limpa_tela();
}

int main() {
    Lista l;
    cria_lista(&l);
    int opcao;

    do {
        printf("=== Menu ===\n\n");
        printf("Escolha uma das opções abaixo:\n");
        printf("[1] Inserir informações\n");
        printf("[2] Gerar relatório em tela\n");
        printf("[3] Gerar relatório em arquivo\n");
        printf("[4] Sair\n");
        printf("\nDigite a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                limpa_tela();
                opcao1(&l);
                break;
            case 2:
                limpa_tela();
                opcao2_opcao3(&l, 2);
                break;
            case 3:
                limpa_tela();
                opcao2_opcao3(&l, 3);
                break;
            case 4:
                printf("\nFim do programa!\n");
                break;
            default:
                printf("\nOpção inválida!\n\n");
                espera();
                limpa_tela();
        }
    } while (opcao != 4);

    return 0;
}
