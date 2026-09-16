#include <stdio.h>
#include <string.h>
/*
 * O scanf("%s") le uma string apenas ate encontrar o primeiro espaco,
 * tabulacao ou quebra de linha. Isso quebra nomes compostos como
 * "Bruno Silva Souza", pois o programa leria somente "Bruno" e
 * deixaria "Silva Souza" sobrando no buffer de entrada, corrompendo
 * as leituras seguintes.
 * Este programa usa fgets() para nomes com espaco, pois ele le a
 * linha inteira (ate o Enter) de uma vez, respeitando os espacos
 * internos do texto digitado.
 */

int main(void) {
    char nome_cliente[100];
    char nome_produto[100];
    int codigo_produto, quantidade;
    float preco_unitario, total;
    char categoria;
    
    printf("Nome do cliente: ");
    fgets(nome_cliente, sizeof(nome_cliente), stdin);
    // Remove o caractere de nova linha no final da string, se presente 
    nome_cliente[strcspn(nome_cliente, "\n")] = '\0';
    printf("Codigo do produto: ");
    scanf("%d", &codigo_produto);
    while (getchar() != '\n'); // Limpa o buffer de entrada
    printf("Nome do produto: ");
    fgets(nome_produto, sizeof(nome_produto), stdin);
    nome_produto[strcspn(nome_produto, "\n")] = '\0';
    printf("Quantidade: ");
    scanf("%d", &quantidade);
    printf("Preco unitario: ");
    scanf("%f", &preco_unitario);
    while (getchar() != '\n'); // Limpa o buffer de entrada
    printf("Categoria (A, B ou C): ");
    scanf("%c", &categoria);
    total = quantidade * preco_unitario;
    printf("========================================\n");
    printf("           RECIBO DE COMPRA\n");
    printf("========================================\n");
    printf("Cliente    : %s\n", nome_cliente);
    printf("Produto    : %s\n", nome_produto);
    printf("Codigo     : %d\n", codigo_produto);
    printf("Categoria  : %c\n", categoria);
    printf("Qtd        : %d\n", quantidade);
    printf("Unitario   : R$ %.2f\n", preco_unitario);
    printf("Total      : R$ %.2f\n", total);
    printf("========================================\n");
    
    return 0;
}