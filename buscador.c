#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char cod[11];
    int mes;
} Operacao;

int buscar(Operacao o[], int tam){
  char x[11];
  int L = 1;
  int R = tam;
  int m, sucesso = 0;

  printf("Código da operação a encontrar: ");
  scanf("%s", &x);

  while ((L <= R) && (sucesso == 0)) {
    m = (L + R) / 2;
    if (strcmp(o[m].cod, x) == 0){
      sucesso = 1;
    }
    else {
      if (strcmp(o[m].cod, x) < 0)
        L = m+1;
      else
        R = m-1;
    }
  }

  if (R < L)
    m = -1;

  return m;
}

int recuperar(Operacao o[]){
  FILE *a;
  int i = 1;
  char linha[15], *token;

  if ((a = fopen("ordenados.txt", "r")) == NULL){
    return 0;
  }

  while (fscanf(a, "%s", linha)!=EOF){
    token = strtok(linha, ";");
    strcpy(o[i].cod, token);

    token = strtok(NULL, ";");
    o[i].mes = atoi(token);

    i++;
  }

  fclose(a);
  return 1;
}

int main(){
  int indice;
  char op[11];
  Operacao o[16601];
  if(!recuperar(o)){
    printf("Erro ao abrir arquivo.\n");
    return 1; //parar a execução caso falhe em recuperar dados do arquivo
  }
  do
  {
    printf("Digite (b) para buscar uma operação por código ou (s) para sair. \n");
    scanf("%s", &op);
    if(strcmp(op, "b") == 0){
      indice = buscar(o, 16600);
      if (indice == -1)
      printf("Operação não encontrada.\n");
      else
      {
        printf("Operação encontrada! \n");
        printf("Código %s: mês %i, na posição %i do vetor.\n", o[indice].cod, o[indice].mes, indice);
      }
    }
    else {
      if (strcmp(op, "s") == 0) {
        printf("Encerrando...\n");
      }
      else
        printf("Digite apenas b ou s!\n");
    }
  } while (strcmp(op, "s") != 0);
  return 0;
}
