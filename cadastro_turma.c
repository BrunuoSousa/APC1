#include <stdio.h>
#include <string.h>

#define MAX 30

enum StatusAluno { REPROVADO = 0, RECUPERACAO = 1, APROVADO = 2 };

struct Aluno {
    int matricula;
    char nome[41];
    float a1;
    float a2;
    enum StatusAluno status;
};

float calcular_media(float a1, float a2) {
    return 0.4f * a1 + 0.6f * a2;
}

enum StatusAluno calcular_status(float media) {
    if (media >= 5.0f) return APROVADO;
    if (media >= 3.0f) return RECUPERACAO;
    return REPROVADO;
}

const char* status_nome(enum StatusAluno s) {
    switch (s) {
        case APROVADO:    return "APROVADO";
        case RECUPERACAO: return "RECUPERACAO";
        case REPROVADO:   return "REPROVADO";
        default:          return "?";
    }
}

void imprimir_aluno(struct Aluno a) {
    float media = calcular_media(a.a1, a.a2);
    printf("%-10d | %-40s | %.1f | %.1f | %.1f | %s\n",
           a.matricula, a.nome, a.a1, a.a2, media, status_nome(a.status));
}

int main(void) {
    struct Aluno turma[MAX];
    int qtd = 0;
    int opcao;

    do {
        printf("\n===== MINI CADASTRO DE TURMAS =====\n");
        printf("1 - Cadastrar aluno\n");
        printf("2 - Listar alunos\n");
        printf("3 - Buscar por matricula\n");
        printf("4 - Buscar por trecho do nome\n");
        printf("5 - Estatisticas\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                if (qtd >= MAX) {
                    printf("Turma cheia! Limite de %d alunos.\n", MAX);
                    break;
                }

                struct Aluno *a = &turma[qtd];

                printf("Matricula: ");
                scanf("%d", &a->matricula);
                getchar(); /* limpa o \n deixado pelo scanf */

                printf("Nome: ");
                fgets(a->nome, sizeof(a->nome), stdin);
                a->nome[strcspn(a->nome, "\n")] = '\0';

                printf("Nota A1: ");
                scanf("%f", &a->a1);
                printf("Nota A2: ");
                scanf("%f", &a->a2);

                a->status = calcular_status(calcular_media(a->a1, a->a2));
                qtd++;

                printf("Aluno cadastrado com sucesso!\n");
                break;
            }

            case 2: {
                if (qtd == 0) {
                    printf("Nenhum aluno cadastrado.\n");
                    break;
                }
                printf("\n%-10s | %-40s | %-4s | %-4s | %-5s | %s\n",
                       "Matricula", "Nome", "A1", "A2", "Media", "Status");
                for (int i = 0; i < qtd; i++) {
                    imprimir_aluno(turma[i]);
                }
                break;
            }

            case 3: {
                int mat;
                int achou = 0;
                printf("Matricula a buscar: ");
                scanf("%d", &mat);

                for (int i = 0; i < qtd; i++) {
                    if (turma[i].matricula == mat) {
                        imprimir_aluno(turma[i]);
                        achou = 1;
                    }
                }
                if (!achou) {
                    printf("nao encontrado\n");
                }
                break;
            }

            case 4: {
                char trecho[41];
                int achou = 0;
                printf("Trecho do nome: ");
                getchar(); /* limpa o \n deixado pelo scanf do menu */
                fgets(trecho, sizeof(trecho), stdin);
                trecho[strcspn(trecho, "\n")] = '\0';

                for (int i = 0; i < qtd; i++) {
                    if (strstr(turma[i].nome, trecho) != NULL) {
                        imprimir_aluno(turma[i]);
                        achou = 1;
                    }
                }
                if (!achou) {
                    printf("nao encontrado\n");
                }
                break;
            }

            case 5: {
                if (qtd == 0) {
                    printf("Nenhum aluno cadastrado.\n");
                    break;
                }

                int reprovados = 0, recuperacao = 0, aprovados = 0;
                float soma = 0.0f;

                for (int i = 0; i < qtd; i++) {
                    switch (turma[i].status) {
                        case APROVADO:    aprovados++;    break;
                        case RECUPERACAO: recuperacao++;  break;
                        case REPROVADO:   reprovados++;   break;
                    }
                    soma += calcular_media(turma[i].a1, turma[i].a2);
                }

                printf("Aprovados: %d\n", aprovados);
                printf("Recuperacao: %d\n", recuperacao);
                printf("Reprovados: %d\n", reprovados);
                printf("Media geral da turma: %.2f\n", soma / qtd);
                break;
            }

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
