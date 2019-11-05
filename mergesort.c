#include <stdio.h>
int cmp, m;
void merge(int a[], int L, int h, int R, int c[]){
    int i = L;
    int j = h + 1;
    int k = L - 1;

    while ((i <= h) && (j <= R))
    {
        k = k + 1;
        cmp++;
        if (a[i] < a[j])
        {
            c[k] = a[i];
            m++;
            i = i + 1;
        }
        else
        {
            m++;
            c[k] = a[j];
            j = j + 1;
        }
    }
    while (i <= h)
    {
        k = k + 1;
        m++;
        c[k] = a[i];
        i = i + 1;
    }
    while (j <= R)
    {
        k = k + 1;
        m++;
        c[k] = a[j];
        j = j + 1;
    }
}

void mpass(int a[], int N, int p, int c[]){
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
            c[j] = a[j];
        }
    }
}

void mergesort(int a[], int N){
    int c[N+1];
    int p = 1;
    while (p < N)
    {
        mpass(a, N, p, c);
        p = 2 * p;
        mpass(c, N, p, a);
        p = 2 * p;
    }
    printf("Merge Sort: %i comparações e %i movimentações.\n", cmp, m);
}
