#include <stdio.h>

/* Constantes: valores fixos do problema (preços não mudam) */
#define PRECO_REFEICAO 12.50
#define PRECO_CAFE 4.00

int main(void) {    /*listas*/
    int qtd_refeicoes, qtd_cafes;
    float disponivel, gasto_refeicoes, gasto_cafes, gasto_total, saldo;

    /* Entrada de dados */
    printf("Quantidade de refeicoes: ");
    scanf("%d", &qtd_refeicoes);

    printf("Quantidade de cafes: ");
    scanf("%d", &qtd_cafes);

    printf("Valor disponivel no cartao: ");
    scanf("%f", &disponivel);

    /* Processamento: gasto = quantidade x preco unitario; saldo = disponivel - total */
    gasto_refeicoes = qtd_refeicoes * PRECO_REFEICAO;
    gasto_cafes = qtd_cafes * PRECO_CAFE;
    gasto_total = gasto_refeicoes + gasto_cafes;
    saldo = disponivel - gasto_total;

    /* Saida organizada */
    printf("\n");
    printf("Gasto refeicoes: %.2f\n", gasto_refeicoes);
    printf("Gasto cafes: %.2f\n", gasto_cafes);
    printf("Gasto total: %.2f\n", gasto_total);
    printf("Saldo restante: %.2f\n", saldo);

    return 0;
}
