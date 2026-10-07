#include <stdio.h>
#include <string.h>

/*
    * O operador ternario (?:) e mais vantajoso quando a decisao e simples
    * e resulta diretamente em um valor, como o bonus de pontualidade
    * (5% ou 0%) — ele substitui um if-else de 4 linhas por uma unica
    * atribuicao, deixando o codigo mais enxuto.
    * Ja o if aninhado torna-se indispensavel quando a decisao depende
    * de duas condicoes em sequencia e cada ramo executa logica
    * diferente (aqui, primeiro a faixa social, depois a media dentro
    * de cada faixa) — o ternario nao conseguiria representar essa
    * hierarquia de regras com clareza.
*/

int main(void) {
    char nome[100];
    int idade;
    float renda, media, desconto_base, bonus_pontualidade, desconto_total;
    char pontualidade;
    char faixa;
    printf("Nome completo do aluno: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';
    printf("Idade do aluno: ");
    scanf("%d", &idade);
    printf("Renda familiar mensal (R$): ");
    scanf("%f", &renda);
    printf("Media academica (0.0 a 10.0): ");
    scanf("%f", &media);
    while (getchar() != '\n');
    printf("Pontualidade no pagamento (S/N): ");
    scanf("%c", &pontualidade);
    if (idade < 16 || renda <= 0) {
        printf("Erro: idade ou renda invalida. Analise encerrada.\n");
        return 0;
    }

    if (renda <= 2000) {
        faixa = 'A';
        if (media >= 8.5) {
            desconto_base = 50;
        } else {
            desconto_base = 30;
        }

    } else if (renda <= 5000) {
        faixa = 'B';
        if (media >= 9.0) {
            desconto_base = 25;
        } else {
            desconto_base = 10;
        }
    } else {
        faixa = 'C';
        if (media >= 9.5) {
            desconto_base = 10;
        } else {
            desconto_base = 0;
        }
    }
            
    bonus_pontualidade = (pontualidade == 'S') ? 5 : 0;
    desconto_total = desconto_base + bonus_pontualidade;
    printf("========================================\n");
    printf("   SISTEMA DE AVALIACAO DE DESCONTO\n");
    printf("========================================\n");
    printf("Aluno        : %s\n", nome);
    printf("Faixa Social : Faixa %c\n", faixa);
    printf("Media        : %.2f\n", media);
    printf("Desconto Base: %.1f%%\n", desconto_base);
    printf("Bonus Pontual: %.1f%%\n", bonus_pontualidade);
    printf("----------------------------------------\n");
    printf("Desconto Total: %.1f%%\n", desconto_total);
    if (desconto_total > 0) {
        printf("Status       : APROVADO PARA BOLSA\n");
    } else {
        printf("Status       : NAO APROVADO PARA BOLSA\n");
    }
    printf("========================================\n");
    return 0;
}