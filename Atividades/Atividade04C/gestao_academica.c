/*
 * RESPOSTA TEORICA:
 * Em char nome[50], o ultimo byte precisa ficar reservado para o caractere
 * terminador '\0', que marca o fim da string em C. Por isso sobram apenas
 * 49 posicoes uteis para caracteres reais. Em int M[3][4], o primeiro
 * indice representa a LINHA (3 linhas, de 0 a 2) e o segundo representa a
 * COLUNA (4 colunas, de 0 a 3). Na memoria, o C guarda os elementos de forma
 * contigua, linha apos linha (row-major): M[0][0], M[0][1], M[0][2], M[0][3],
 * depois M[1][0], e assim por diante, sem lacunas entre eles.
 */

#include <stdio.h>
#include <string.h>

#define TOTAL_ALUNOS 5
#define LINHAS_BOLETIM 3
#define TOTAL_PROVAS 4

int main(void) {
    char alunos[TOTAL_ALUNOS][50];
    float notas_finais[TOTAL_ALUNOS];
    float boletim[LINHAS_BOLETIM][TOTAL_PROVAS];
    float soma, media, soma_linha, maior;
    int acima_media = 0;
    int opcao;
    int quantidade_cadastrada = 0;
    int notas_lidas = 0;
    int indice_maior;
    int i, j;

    do {
        printf("\n===== SISTEMA DE GESTAO ACADEMICA =====\n");
        printf("1 - Cadastrar Lista de Alunos\n");
        printf("2 - Estatisticas de Desempenho\n");
        printf("3 - Matriz de Notas da Turma\n");
        printf("4 - Consultar Aluno em Destaque\n");
        printf("0 - Encerrar\n");
        printf("========================================\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\n--- CADASTRO DE ALUNOS ---\n");
                getchar(); /* consome o '\n' deixado pelo scanf */
                for (i = 0; i < TOTAL_ALUNOS; i++) {
                    printf("Digite o nome do aluno %d: ", i + 1);
                    fgets(alunos[i], sizeof(alunos[i]), stdin);
                    alunos[i][strcspn(alunos[i], "\n")] = '\0';
                }
                quantidade_cadastrada = TOTAL_ALUNOS;

                printf("\n--- ALUNOS CADASTRADOS ---\n");
                for (i = 0; i < quantidade_cadastrada; i++) {
                    printf("Aluno %d: %s\n", i + 1, alunos[i]);
                }
                break;

            case 2:
                printf("\n--- ESTATISTICAS DE DESEMPENHO ---\n");
                for (i = 0; i < TOTAL_ALUNOS; i++) {
                    printf("Digite a nota final do aluno %d: ", i + 1);
                    scanf("%f", &notas_finais[i]);
                }
                notas_lidas = 1;

                soma = 0;
                for (i = 0; i < TOTAL_ALUNOS; i++) {
                    soma += notas_finais[i];
                }
                media = soma / TOTAL_ALUNOS;

                acima_media = 0;
                for (i = 0; i < TOTAL_ALUNOS; i++) {
                    if (notas_finais[i] >= media) {
                        acima_media++;
                    }
                }
                printf("\nMedia da turma: %.2f\n", media);
                printf("Alunos com nota maior ou igual a media: %d\n", acima_media);
                break;

            case 3:
                printf("\n--- MATRIZ DE NOTAS DA TURMA ---\n");
                for (i = 0; i < LINHAS_BOLETIM; i++) {
                    for (j = 0; j < TOTAL_PROVAS; j++) {
                        printf("Digite a nota do aluno %d no bimestre %d: ", i + 1, j + 1);
                        scanf("%f", &boletim[i][j]);
                    }
                }

                printf("\n--- BOLETIM COMPLETO ---\n");
                printf("Aluno\tB1\tB2\tB3\tB4\tMedia\n");
                for (i = 0; i < LINHAS_BOLETIM; i++) {
                    soma_linha = 0;
                    printf("%d\t", i + 1);
                    for (j = 0; j < TOTAL_PROVAS; j++) {
                        printf("%.2f\t", boletim[i][j]);
                        soma_linha += boletim[i][j];
                    }
                    printf("%.2f\n", soma_linha / TOTAL_PROVAS);
                }
                break;

            case 4:
                printf("\n--- CONSULTA DA MAIOR NOTA ---\n");
                if (!notas_lidas) {
                    printf("Nenhuma nota registrada. Use a opcao 2 primeiro.\n");
                    break;
                }
                maior = notas_finais[0];
                indice_maior = 0;
                for (i = 1; i < TOTAL_ALUNOS; i++) {
                    if (notas_finais[i] > maior) {
                        maior = notas_finais[i];
                        indice_maior = i;
                    }
                }
                printf("Maior nota da turma: %.2f\n", maior);
                printf("Indice no vetor: %d (aluno numero %d)\n", indice_maior, indice_maior + 1);
                if (quantidade_cadastrada > 0) {
                    printf("Aluno: %s\n", alunos[indice_maior]);
                }
                break;

            case 0:
                printf("\nEncerrando o sistema...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}