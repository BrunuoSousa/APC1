/*
 * 1) O fall-through consciente foi mais vantajoso nos grupos de servico (1, 2 e 3 =
 *    Documento simples; 4 e 5 = Interrupcao de vinculo) e no expediente (2 a 5 = Pleno;
 *    1 e 7 = Fechado): varios cases compartilham a mesma acao, entao o bloco e escrito
 *    uma unica vez, sem repeticao e sem risco de alterar um case e esquecer os outros.
 * 2) O switch nao substituiu o if-else-if das faixas de renda porque ele so compara
 *    igualdade com constante int ou char; faixas exigem comparacao relacional (<, >=)
 *    sobre valores double, e cada valor possivel precisaria de um case proprio.
 */
#include <stdio.h>

int main(void) {
    int servico;
    char prioridade;
    int dia;

    printf("Codigo do servico: ");
    scanf("%d", &servico);

    printf("Prioridade (U/N/B): ");
    scanf(" %c", &prioridade);

    printf("Dia da semana (1=domingo ... 7=sabado): ");
    scanf("%d", &dia);

    /* Saidas do switch 1: servico */
    const char *servico_nome;
    const char *categoria;
    int prazo;
    double taxa_base;
    const char *status;

    /* Saidas do switch 2: prioridade */
    const char *prioridade_nome;
    int guiche;
    double acrescimo;

    /* Saidas dos switches 3 e 4: dia */
    const char *dia_nome;
    const char *expediente;

    /* Resultado do calculo final */
    double taxa_final;

    const char *nomes_documento[] = {
        "Historico escolar",
        "Declaracao de matricula",
        "Declaracao de vinculo"
    };
    const char *nomes_interrupcao[] = {
        "Trancamento",
        "Cancelamento"
    };

    switch (servico) {
        case 1: /* fall-through */
        case 2: /* fall-through */
        case 3:
            servico_nome = nomes_documento[servico - 1];
            categoria = "Documento simples";
            prazo = 2;
            taxa_base = 15.00;
            status = "ACEITO";
            break;

        case 4: /* fall-through */
        case 5:
            servico_nome = nomes_interrupcao[servico - 4];
            categoria = "Interrupcao de vinculo";
            prazo = 10;
            taxa_base = 0.00;
            status = "ACEITO";
            break;

        case 6:
            servico_nome = "Colacao de grau";
            categoria = "Ato solene";
            prazo = 15;
            taxa_base = 80.00;
            status = "ACEITO";
            break;

        default:
            servico_nome = "Codigo invalido";
            categoria = "-";
            prazo = 0;
            taxa_base = 0.00;
            status = "RECUSADO";
            break;
    }

        switch (prioridade) {
        case 'U': /* fall-through */
        case 'u':
            prioridade_nome = "Urgente";
            guiche = 1;
            acrescimo = 10.00;
            break;

        case 'N': /* fall-through */
        case 'n':
            prioridade_nome = "Normal";
            guiche = 2;
            acrescimo = 0.00;
            break;

        case 'B': /* fall-through */
        case 'b':
            prioridade_nome = "Balcao";
            guiche = 3;
            acrescimo = 0.00;
            break;

        default:
            prioridade_nome = "Invalida";
            guiche = 0;
            acrescimo = 0.00;
            break;
    }

        switch (dia) {
        case 1:
            dia_nome = "Domingo";
            break;

        case 2:
            dia_nome = "Segunda-feira";
            break;

        case 3:
            dia_nome = "Terca-feira";
            break;

        case 4:
            dia_nome = "Quarta-feira";
            break;

        case 5:
            dia_nome = "Quinta-feira";
            break;

        case 6:
            dia_nome = "Sexta-feira";
            break;

        case 7:
            dia_nome = "Sabado";
            break;

        default:
            dia_nome = "Dia invalido";
            break;
    }

        switch (dia) {
        case 2: /* fall-through */
        case 3: /* fall-through */
        case 4: /* fall-through */
        case 5:
            expediente = "Pleno";
            break;

        case 6:
            expediente = "Reduzido";
            break;

        case 1: /* fall-through */
        case 7:
            expediente = "Fechado";
            break;

        default:
            expediente = "Dia invalido";
            break;
    }

    taxa_final = taxa_base + acrescimo;

    printf("========================================\n");
    printf("     TRIAGEM DE PROTOCOLO ACADEMICO\n");
    printf("========================================\n");
    printf("%-32s: %s\n", "Servico", servico_nome);
    printf("%-32s: %s\n", "Categoria", categoria);
    printf("%-32s: %d dias uteis\n", "Prazo", prazo);
    printf("%-32s: R$ %.2f\n", "Taxa base", taxa_base);
        printf("%-32s: %s\n", "Prioridade", prioridade_nome);
    printf("%-32s: %d\n", "Guiche", guiche);
    printf("%-32s: R$ %.2f\n", "Acrescimo", acrescimo);
    printf("%-32s: %s\n", "Dia", dia_nome);
    printf("%-32s: %s\n", "Expediente", expediente);
    printf("----------------------------------------\n");
    printf("%-32s: R$ %.2f\n", "Taxa final", taxa_final);
    printf("%-32s: %s\n", "Status do servico", status);
    printf("========================================\n");

    return 0;
} 