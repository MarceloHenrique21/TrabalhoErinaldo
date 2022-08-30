#include <stdio.h>

int particao(int *x, int p, int r) {
  int pivo, i, j;
  i = p - 1;
  j = r + 1;
  while (i < j) {
    do {
      j--;
    } while (x[j] > pivo);
    do {
      i++;
    } while (x[i] < pivo);
    if (i < j)
      troca(x, i, j);
  }
  return j;
}
