#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp, m;

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
			o2[j].mes = 2;
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
			o3[j].mes = 3;
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
			o4[j].mes = 4;
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
			o5[j].mes = 5;
			j++;
		}
		i++;
	}
	printf("Fim do quinto arquivo.\n");

/*
	bubblesort(o1, 100);
	bubblesort(o2, 500);
	bubblesort(o3, 1000);
	bubblesort(o4, 5000);
	bubblesort(o5, 10000);

	binaryinsertionsort(o1, 100);
	binaryinsertionsort(o2, 500);
	binaryinsertionsort(o3, 1000);
	binaryinsertionsort(o4, 5000);
	binaryinsertionsort(o5, 10000);

	mergesort(o1, 100);
	mergesort(o2, 500);
	mergesort(o3, 1000);
	mergesort(o4, 5000);
	mergesort(o5, 10000);
*/

/*bloco para testar se o método de fato está ordenando
	printf("\nLista de operações ordenada: \n");
	for(i=1; i<=100; i++)
	printf("%s, mes %i \n", o1[i].cod, o1[i].mes);
	printf("\n");
*/
}

void binaryinsertionsort(Operacao v[], int N){
	int j, m, L, R, cmp = 0, mov = 0, xmes;
	char xcod[11];
	for (int i = 2; i <= N; i++) {

		strcpy(xcod, v[i].cod);
		xmes = v[i].mes;

		mov++;
		L = 1;
		R = i;
		while (L < R) {
			m = (L + R) / 2;
			cmp++;
			//v[m] <= x é a comparação original
			if (strcmp(v[m].cod, xcod) <= 0 )
			L = m + 1;
			else
			R = m;
		}
		j = i;
		while (j > R) {
			mov ++;

			strcpy(v[j].cod, v[j-1].cod);
			v[j].mes = v[j-1].mes;

			j = j - 1;
		}

		strcpy(v[R].cod, xcod);
		v[R].mes = xmes;

		mov++;
	}
	printf("Binary Insertion Sort: %i comparações e %i movimentações.\n", cmp, mov);

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
