#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "bubblesort.c"
//#include "mergesort.c"
//#include "binaryinsertionsort.c" chamadas de outros arquivos não querem funcionar ;-;

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
	Operacao o1[101], o2[501], o3[1001], o4[5001], o5[10001];
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

	i = 0;
	j = 1;
	while (fgets(linha, 11, mes1)){
		if (i % 2 == 0){
			//printf("%i, %i: %s \n", i, j, linha);
			strcpy(o1[j].cod, strtok(linha, "\n"));
			o1[j].mes = 1;
			j++;
		}
		i++;
	}
	printf("Fim do primeiro arquivo.\n");

	i = 0;
	j = 1;
	while (fgets(linha, 11, mes2)){
		if (i % 2 == 0){
			//printf("%i, %i: %s \n", i, j, linha);
			strcpy(o2[j].cod, strtok(linha, "\n"));
			o2[j].mes = 1;
			j++;
		}
		i++;
	}
	printf("Fim do segundo arquivo.\n");

	i = 0;
	j = 1;
	while (fgets(linha, 11, mes3)){
		if (i % 2 == 0){
			//printf("%i, %i: %s \n", i, j, linha);
			strcpy(o3[j].cod, strtok(linha, "\n"));
			o3[j].mes = 1;
			j++;
		}
		i++;
	}
	printf("Fim do terceiro arquivo.\n");

	i = 0;
	j = 1;
	while (fgets(linha, 11, mes4)){
		if (i % 2 == 0){
			//printf("%i, %i: %s \n", i, j, linha);
			strcpy(o4[j].cod, strtok(linha, "\n"));
			o4[j].mes = 1;
			j++;
		}
		i++;
	}
	printf("Fim do quarto arquivo.\n");

	i = 0;
	j = 1;
	while (fgets(linha, 11, mes5)){
		if (i % 2 == 0){
			//printf("%i, %i: %s \n", i, j, linha);
			strcpy(o5[j].cod, strtok(linha, "\n"));
			o5[j].mes = 1;
			j++;
		}
		i++;
	}
	printf("Fim do quinto arquivo.\n");

	bubblesort(o1, 100);


	printf("\nLista de operações ordenada: \n");
	for(i=1; i<=100; i++)
		printf("%s, mes %i \n", o1[i].cod, o1[i].mes);
	printf("\n");
}

void bubblesort(Operacao v[], int N){
    int i, j, aux;
		long int cmp, m;
    char auxc[11];
		cmp = 0;
		m = 0;
    for(i=1; i<=N; i++){
        for(j=1; j<=N-1; j++){
            cmp++;
            if(strcmp(v[j].cod, v[j+1].cod) > 0){
                aux = v[j].mes;
                v[j].mes = v[j+1].mes;
                v[j+1].mes = aux;

                strcpy(auxc, v[j].cod);
                strcpy(v[j].cod, v[j+1].cod);
                strcpy(v[j+1].cod, auxc);
                m+=3;
            }
        }
    }
    printf("Bubble Sort: %li comparações e %li movimentações.\n", cmp, m);
}
