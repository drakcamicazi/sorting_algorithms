#include <stdio.h>
void bubblesort(int v[], int N){
    int i, j, aux, cmp, m;
    for(i=0; i<N; i++){
        for(j=0; j<N-1; j++){
            cmp++;
            if(v[j] > v[j+1]){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
                m++;
            }
        }
    }
    printf("Bubble Sort: %i comparações e %i movimentações.\n", cmp, m);
}
