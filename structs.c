#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//função para verificar se abriu o arquivo
void verificarAbertura(FILE *f){
	if(f == NULL){
		printf("Erro na abertura do arquivo.");
		exit(0);
	}
}

typedef struct{
    char cod[10];
    int mes;
} Operacao;

int main(){
	FILE *mes1, *mes2, *mes3, *mes4, *mes5;
  int i, j, k;
  char linha[11];
  Operacao o[16600]; //ao total tem-se 16600 operacoes em todos os arquivos

  mes1 = fopen("../mes_1.txt", "r");
  verificarAbertura(mes1);
  mes2 = fopen("../mes_2.txt", "r");
  verificarAbertura(mes2);
  mes3 = fopen("../mes_3.txt", "r");
  verificarAbertura(mes3);
  mes4 = fopen("../mes_4.txt", "r");
  verificarAbertura(mes4);
  mes5 = fopen("../mes_5.txt", "r");
  verificarAbertura(mes5);

  //o i e o j são necessários pra separar uma "linha válida" de uma "vazia", que o fgets tava achando
  i = 0;
  j = 0;
  while (fgets(linha, 11, mes1)){
    if (i % 2 == 0){
      printf("%i, %i: %s \n", i, j, linha); //para acompanhar os índices de i e j. pode ser apagado depois
      strcpy(o[j].cod, strtok(linha, "\n")); //strtok pra tirar o \n do final da linha lida
      o[j].mes = 1;
      j++;
    }
    i++;
  }
  printf("Fim do primeiro arquivo.\n");

  i = 0;
  j = 0;
  while (fgets(linha, 11, mes2)){
    if (i % 2 == 0){
      k = j + 100;
      printf("%i, %i: %s \n", i, k, linha); //+100 pois ja tem 100 registros no struct
      strcpy(o[k].cod, strtok(linha, "\n")); 
      o[k].mes = 2;
      j++;
    }
    i++;
  }
  printf("Fim do segundo arquivo.\n");
  
  i = 0;
  j = 0;
  while (fgets(linha, 11, mes3)){
    if (i % 2 == 0){
      k = j + 100 + 500;
      printf("%i, %i: %s \n", i, k, linha); //+100 + 500 pois ja tem 600 registros no struct
      strcpy(o[k].cod, strtok(linha, "\n")); 
      o[k].mes = 3;
      j++;
    }
    i++;
  }
  printf("Fim do terceiro arquivo.\n");
  
  i = 0;
  j = 0;
  while (fgets(linha, 11, mes4)){
    if (i % 2 == 0){
      k = j + 100 + 500 + 1000;
      printf("%i, %i: %s \n", i, k, linha); //+100 + 500 + 1000 pois ja tem 1600 registros no struct
      strcpy(o[k].cod, strtok(linha, "\n")); 
      o[k].mes = 4;
      j++;
    }
    i++;
  }
  printf("Fim do quarto arquivo.\n");
  
  i = 0;
  j = 0;
  while (fgets(linha, 11, mes5)){
    if (i % 2 == 0){
      k = j + 100 + 500 + 1000 + 5000;
      printf("%i, %i: %s \n", i, k, linha); //ja tem 6600 registros no struct
      strcpy(o[k].cod, strtok(linha, "\n")); 
      o[k].mes = 5;
      j++;
    }
    i++;
  }
  printf("Fim do quinto arquivo.\n");
  
  /* codigo pra imprimir os registros
  i = 0;
  while (i < 16600) {
    printf("%i : %s\n", i, o[i].cod);
    i++;
  }
  */
}
