#include <stdio.h>
#include <stdlib.h>

typedef struct Pessoa {
    int idade;
    char sexo;
    int frequencia;
    struct Pessoa* proxima;
} Pessoa;

typedef struct Lista {
    Pessoa* primeira;
    Pessoa* ultima;
} Lista;

int esta_vazia(Lista* l) {
    return l->primeira == NULL && l->ultima == NULL;
}

void cria_lista(Lista* l) {
    l->primeira = NULL;
    l->ultima = NULL;
}

void insere(Lista* l, Pessoa p) {
    Pessoa* nova_pessoa = (Pessoa*) malloc(sizeof(Pessoa));
    nova_pessoa->idade = p.idade;
    nova_pessoa->sexo = p.sexo;
    nova_pessoa->frequencia = p.frequencia;

    if (esta_vazia(l)) {
        l->primeira = nova_pessoa;
        l->ultima = nova_pessoa;
        nova_pessoa->proxima = NULL;
    } else {
        l->ultima->proxima = nova_pessoa;
        l->ultima = nova_pessoa;
        nova_pessoa->proxima = NULL;
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

// Inserir informações
void opcao1(Lista* l) {
    int idade;
    char sexo;
    int frequencia;
    Pessoa p;

    printf("=== Inserir informações ===\n\n");
    printf("Idade: ");
    scanf("%d", &p.idade);
    printf("Sexo: ");
    scanf(" %c", &p.sexo);
    printf("Frequência (1 - Às vezes | 2 - Uma vez ao mês | 3 - Quinzenal | 4 - Semanal): ");
    scanf("%d", &p.frequencia);

    insere(l, p);

    printf("\nDados salvos com sucesso!\n\n");
    espera();
    limpa_tela();
}

// Buscar
void opcao2(Lista* l) {
    printf("=== Buscar ===\n\n");

    if (esta_vazia(l)) {
        printf("Não há dados cadastrados!\n\n");
        espera();
        limpa_tela();
        return;
    }

    Pessoa* p = l->primeira;

    do {
        printf("Idade: %d\n", p->idade);
        printf("Sexo: %c\n", p->sexo);
        printf("Frequência %d\n\n", p->frequencia);

        p = p->proxima;
    } while (p != NULL);

    espera();
    limpa_tela();
}

// Gerar relatório em tela ou em arquivo
void opcao3_opcao4(Lista* l, int opcao) {
    if (opcao == 3) {
        printf("=== Gerar relatório em tela ===\n\n");
    }

    if (opcao == 4) {
        printf("=== Gerar relatório em arquivo ===\n\n");
    }

    if (esta_vazia(l)) {
        printf("Não há dados cadastrados!\n\n");
        espera();
        limpa_tela();
        return;
    }

    Pessoa* p = l->primeira;

    int pessoas_maiores_de_idade = 0;
    int soma = 0;

    int pessoas_0_10_anos = 0;
    int pessoas_11_17_anos = 0;
    int pessoas_18_35_anos = 0;
    int pessoas_36_50_anos = 0;
    int pessoas_51_65_anos = 0;
    int pessoas_maiores_65_anos = 0;
    int total_pessoas = 0;

    int pessoas_quinzenalmente = 0;

    do {
        if (p->idade >= 18) {
            pessoas_maiores_de_idade++;
            soma += p->idade;
        }

        if (p->idade >= 0 && p->idade <= 10) {
            pessoas_0_10_anos++;
        } else if (p->idade <= 17) {
            pessoas_11_17_anos++;
        } else if (p->idade <= 35) {
            pessoas_18_35_anos++;
        } else if (p->idade <= 50) {
            pessoas_36_50_anos++;
        } else if (p->idade <= 65) {
            pessoas_51_65_anos++;
        } else {
            pessoas_maiores_65_anos++;
        }

        if (p->frequencia == 3) {
            pessoas_quinzenalmente++;
        }

        total_pessoas++;
        p = p->proxima;
    } while (p != NULL);

    float media_maiores_de_idade = (float) soma / pessoas_maiores_de_idade;
    if (pessoas_maiores_de_idade == 0) {
        media_maiores_de_idade = 0;
    }

    float percentual_0_10_anos = (float) pessoas_0_10_anos / total_pessoas * 100;
    float percentual_11_17_anos = (float) pessoas_11_17_anos / total_pessoas * 100;
    float percentual_18_35_anos = (float) pessoas_18_35_anos / total_pessoas * 100;
    float percentual_35_50_anos = (float) pessoas_36_50_anos / total_pessoas * 100;
    float percentual_50_65_anos = (float) pessoas_51_65_anos / total_pessoas * 100;
    float percentual_maiores_65_anos = (float) pessoas_maiores_65_anos / total_pessoas * 100;

    if (opcao == 3) {
        printf("=> Total de pessoas maiores de idade: %d", pessoas_maiores_de_idade);
        printf("\n=> Média de idade das pessoas maiores de idade: %.2f", media_maiores_de_idade);
        printf("\n=> Percentual de pessoas com 0 a 10 anos: %.2f%%", percentual_0_10_anos);
        printf("\n=> Percentual de pessoas com 11 a 17 anos: %.2f%%", percentual_11_17_anos);
        printf("\n=> Percentual de pessoas com 18 a 35 anos: %.2f%%", percentual_18_35_anos);
        printf("\n=> Percentual de pessoas com 36 a 50 anos: %.2f%%", percentual_35_50_anos);
        printf("\n=> Percentual de pessoas com 51 a 65 anos: %.2f%%", percentual_50_65_anos);
        printf("\n=> Percentual de pessoas com mais de 65 anos: %.2f%%", percentual_maiores_65_anos);
        printf("\n=> Total de pessoas que vem quinzenalmente ao cinema: %d", pessoas_quinzenalmente);
    }

    if (opcao == 4) {
        FILE* arquivo;

        arquivo = fopen("relatorio.txt", "w");

        fprintf(arquivo, "=== Relatório ===\n\n");
        fprintf(arquivo, "=> Total de pessoas maiores de idade: %d", pessoas_maiores_de_idade);
        fprintf(arquivo, "\n=> Média de idade das pessoas maiores de idade: %.2f", media_maiores_de_idade);
        fprintf(arquivo, "\n=> Percentual de pessoas com 0 a 10 anos: %.2f%%", percentual_0_10_anos);
        fprintf(arquivo, "\n=> Percentual de pessoas com 11 a 17 anos: %.2f%%", percentual_11_17_anos);
        fprintf(arquivo, "\n=> Percentual de pessoas com 18 a 35 anos: %.2f%%", percentual_18_35_anos);
        fprintf(arquivo, "\n=> Percentual de pessoas com 36 a 50 anos: %.2f%%", percentual_35_50_anos);
        fprintf(arquivo, "\n=> Percentual de pessoas com 51 a 65 anos: %.2f%%", percentual_50_65_anos);
        fprintf(arquivo, "\n=> Percentual de pessoas com mais de 65 anos: %.2f%%", percentual_maiores_65_anos);
        fprintf(arquivo, "\n=> Total de pessoas que vem quinzenalmente ao cinema: %d", pessoas_quinzenalmente);

        printf("Relatório gerado com sucesso!");

        fclose(arquivo);
    }

    printf("\n\n");
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
        printf("[2] Buscar\n");
        printf("[3] Gerar relatório em tela\n");
        printf("[4] Gerar relatório em arquivo\n");
        printf("[5] Sair\n");
        printf("\nDigite a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                limpa_tela();
                opcao1(&l);
                break;
            case 2:
                limpa_tela();
                opcao2(&l);
                break;
            case 3:
                limpa_tela();
                opcao3_opcao4(&l, 3);
                break;
            case 4:
                limpa_tela();
                opcao3_opcao4(&l, 4);
                break;
            case 5:
                printf("\nFim do programa!\n");
                break;
            default:
                printf("\nOpção inválida\n\n");
                espera();
                limpa_tela();
        }
    } while (opcao != 5);

    return 0;
}
