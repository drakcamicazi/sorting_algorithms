#include <stdio.h>

void bubblesort(Operacao v[], int N){
    int i, j, aux;
    long int cmp, m;
    char auxc[11];
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
