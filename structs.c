#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int m, cmp;
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
	FILE *mes1, *mes2, *mes3, *mes4, *mes5, *saida;
  int i, j, k;
  char linha[11];
  Operacao o[16601]; //ao total tem-se 16600 operacoes em todos os arquivos mas começamos a armazenar do 1

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
  j = 1;
  while (fgets(linha, 11, mes1)){
    if (i % 2 == 0){
      //printf("%i, %i: %s \n", i, j, linha); //para acompanhar os índices de i e j. pode ser apagado depois
      strcpy(o[j].cod, strtok(linha, "\n")); //strtok pra tirar o \n do final da linha lida
      o[j].mes = 1;
      j++;
    }
    i++;
  }
	fclose(mes1);
  printf("Fim do primeiro arquivo.\n");

  i = 0;
  j = 1;
  while (fgets(linha, 11, mes2)){
    if (i % 2 == 0){
      k = j + 100;
      //printf("%i, %i: %s \n", i, k, linha); //+100 pois ja tem 100 registros no struct
      strcpy(o[k].cod, strtok(linha, "\n"));
      o[k].mes = 2;
      j++;
    }
    i++;
  }
	fclose(mes2);
  printf("Fim do segundo arquivo.\n");

  i = 0;
  j = 1;
  while (fgets(linha, 11, mes3)){
    if (i % 2 == 0){
      k = j + 100 + 500;
      //printf("%i, %i: %s \n", i, k, linha); //+100 + 500 pois ja tem 600 registros no struct
      strcpy(o[k].cod, strtok(linha, "\n"));
      o[k].mes = 3;
      j++;
    }
    i++;
  }
	fclose(mes3);
  printf("Fim do terceiro arquivo.\n");

  i = 0;
  j = 1;
  while (fgets(linha, 11, mes4)){
    if (i % 2 == 0){
      k = j + 100 + 500 + 1000;
      //printf("%i, %i: %s \n", i, k, linha); //+100 + 500 + 1000 pois ja tem 1600 registros no struct
      strcpy(o[k].cod, strtok(linha, "\n"));
      o[k].mes = 4;
      j++;
    }
    i++;
  }
	fclose(mes4);
  printf("Fim do quarto arquivo.\n");

  i = 0;
  j = 1;
  while (fgets(linha, 11, mes5)){
    if (i % 2 == 0){
      k = j + 100 + 500 + 1000 + 5000;
      //printf("%i, %i: %s \n", i, k, linha); //ja tem 6600 registros no struct
      strcpy(o[k].cod, strtok(linha, "\n"));
      o[k].mes = 5;
      j++;
    }
    i++;
  }
	fclose(mes5);
  printf("Fim do quinto arquivo.\n");

	mergesort(o, 16600);

	saida = fopen("ordenados.txt", "w");
	verificarAbertura(saida);

  // codigo pra imprimir os registros
  i = 1;
  while (i <= 16600) {
    fprintf(saida, "%s;%i\n", o[i].cod, o[i].mes);
    i++;
  }
	fclose(saida);
}

void merge(Operacao a[], int L, int h, int R, Operacao c[]){
    int i = L;
    int j = h + 1;
    int k = L - 1;

    while ((i <= h) && (j <= R))
    {
        k = k + 1;
        cmp++;
        if (strcmp(a[i].cod, a[j].cod) < 0)
        {
            //c[k] = a[i];
						c[k].mes = a[i].mes;
						strcpy(c[k].cod, a[i].cod);
						m++;
            i = i + 1;
        }
        else
        {
            m++;
						c[k].mes = a[j].mes;
						strcpy(c[k].cod, a[j].cod);
            //c[k] = a[j];
            j = j + 1;
        }
    }
    while (i <= h)
    {
        k = k + 1;
        m++;
        //c[k] = a[i];
				c[k].mes = a[i].mes;
				strcpy(c[k].cod, a[i].cod);
        i = i + 1;
    }
    while (j <= R)
    {
        k = k + 1;
        m++;
        //c[k] = a[j];
				c[k].mes = a[j].mes;
				strcpy(c[k].cod, a[j].cod);
				j = j + 1;
    }
}

void mpass(Operacao a[], int N, int p, Operacao c[]){
    int i = 1;
    while (i <= (N-2*p+1))
    {
        merge(a, i, i+p-1, i+2*p-1, c);
        i = i + 2*p;
    }
    if ((i+p-1) < N)
        merge(a, i, i+p-1, N, c);
    else
    {
        for (int j = i; j <= N; j++)
        {
            m++;
            //c[j] = a[j];
						c[j].mes = a[j].mes;
						strcpy(c[j].cod, a[j].cod);
        }
    }
}

void mergesort(Operacao a[], int N){
    Operacao c[N+1];
    int p = 1;
		m = 0;
		cmp = 0;
    while (p < N)
    {
        mpass(a, N, p, c);
        p = 2 * p;
        mpass(c, N, p, a);
        p = 2 * p;
    }
    printf("Merge Sort: %i comparações e %i movimentações.\n", cmp, m);
}
