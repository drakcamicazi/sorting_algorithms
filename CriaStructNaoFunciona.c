#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINHA 200
#define CODIGO 10

typedef struct{
    char codigo[CODIGO];
    int mes;
}Operacao;

int contaLinhas(FILE *arq){
    char linhaLida[LINHA], *token = NULL;
    int linha = 0;
    while( fgets(linhaLida, sizeof(linhaLida), arq) != NULL )  {
        token = strtok(linhaLida,"\n"); //inicia com a linha lida em questão
        linha++; // vai para a prox linha
  }
    return linha-1;
}
/* não funciona */
void criaStruct(Operacao operacao[], int indiceInicio, FILE *arq){
    if (arq == NULL){
        printf("Erro ao abrir o arquivo\n");
    }
    char linhaLida[200], *token = NULL;printf("abcd %s efgh ", linhaLida);
    int linha = indiceInicio;
    while( fgets(linhaLida, sizeof(linhaLida), arq) != NULL )  {
        token = strtok(linhaLida,"\n");
        strcpy(operacao[linha].codigo, token);
        linha++;
        token = strtok(NULL,"\n");
        strcpy(operacao[linha].codigo, token);
        linha++;printf("a");
    }
}

int main()
{
    int i, totalCodigos;
    FILE *mes1, *mes2, *mes3, *mes4, *mes5;

    mes1 = fopen("mes_1.txt", "r");
    if (mes1 == NULL){
        printf("erro ao abrir arquivo");
        return 0;
    }

    mes2 = fopen("mes_2.txt", "r");
    if (mes2 == NULL){
        printf("erro ao abrir arquivo");
        return 0;
    }

    mes3 = fopen("mes_3.txt", "r");
    if (mes3 == NULL){
        printf("erro ao abrir arquivo");
        return 0;
    }

    mes4 = fopen("mes_4.txt", "r");
    if (mes4 == NULL){
        printf("erro ao abrir arquivo");
        return 0;
    }

    mes5 = fopen("mes_5.txt", "r");
    if (mes5 == NULL){
        printf("erro ao abrir arquivo");
        return 0;
    }

    totalCodigos = (contaLinhas(mes1) + contaLinhas(mes2) + contaLinhas(mes3) + contaLinhas(mes4) + contaLinhas(mes5));
    Operacao *operacao = malloc(totalCodigos * sizeof(int));

    criaStruct(operacao, 0, mes1);

   /* for (i = 0; i < 10; i++){
        printf("%s\n", operacao[i].codigo);
    }*/

    free (operacao);
    return 0;
}
