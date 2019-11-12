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
	FILE *mes1;
  int i = 0, j  = 0;
  char linha[11];
  Operacao o[100];

  mes1 = fopen("../mes_1.txt", "r");
  verificarAbertura(mes1);

  //o i e o j são necessários pra separar uma "linha válida" de uma "vazia", que o fgets tava achando
  while (fgets(linha, 11, mes1)){
    if (i % 2 == 0){
      printf("%i, %i: %s \n", i, j, linha); //para acompanhar os índices de i e j. pode ser apagado depois
      strcpy(o[j].cod, strtok(linha, "\n")); //strtok pra tirar o \n do final da linha lida
      o[j].mes = 1;
      j++;
    }
    i++;
  }

  i = 0;
  while (i < 100) {
    printf("%i : %s\n", i, o[i].cod);
    i++;
  }

}
