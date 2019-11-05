#include <stdio.h>
void binaryinsertionsort(int v[], int N){
  int j, m, x, L, R, cmp = 0, mov = 0;
  for (int i = 2; i <= N; i++) {
    x = v[i];
    mov++;
    L = 1;
    R = i;
    while (L < R) {
      m = (L + R) / 2;
      cmp++;
      if (v[m] <= x)
        L = m + 1;
      else
        R = m;
    }
    j = i;
    while (j > R) {
      mov ++;
      v[j] = v[j-1];
      j = j - 1;
    }
    v[R] = x;
    mov++;
  }
  printf("Binary Insertion Sort: %i comparações e %i movimentações.\n", cmp, mov);

}
