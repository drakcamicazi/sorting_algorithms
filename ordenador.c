#include <stdio.h>
#include <stdlib.h>
#include "bubblesort.c"
#include "mergesort.c"
#include "binaryinsertionsort.c"
#define MAX 100000

int printar(int V[], int N){
  printf("\nVetor ordenado: ");
  for(int i=1; i<=N; i++)
      printf("%i ", V[i]);
  printf("\n" );
}

int main(){
  int V[MAX], N;

  printf("Digite tamanho pro vetor: ");
  scanf("%i", &N);

  for (int i = 1; i <= N; i++)
  {
      V[i] = rand() % 100;
  }

  //mergesort(V, N);
  //bubblesort(V, N);
  binaryinsertionsort(V, N);
  printar(V, N);
}
