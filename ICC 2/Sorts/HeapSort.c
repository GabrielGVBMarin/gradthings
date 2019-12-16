#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void HeapSort(int, int*);
static void fazHeap(int, int*);
static void ordena(int, int*);

long int trocas = 0;
long int cmp = 0;

int main(void)  {

  int i = 0, tamanho;
  scanf("%d\n", &tamanho);
  int *v = (int*) calloc(tamanho+1, sizeof(int));

  for ( i = 1; i <= tamanho; i++)  {
    scanf("%d", &v[i]);
  }

  HeapSort(tamanho+1, v);

  for ( i = 0; i < tamanho; i++)  {
    printf("%d ", v[i]);
  }

  printf("\n\nTROCAS : %ld\nCOMPARAÇÕES : %ld\n\n", trocas, cmp);

  return 0;

}

void HeapSort(int n, int *v)  {

  int aux, m;

  fazHeap(n, v);
  for (m = n; m >= 2; --m) {
    aux = v[1];
    v[1] = v[m];
    v[m] = aux;
    trocas++;
    ordena(m-1, v);
  }

}

void fazHeap(int m, int *v) {

  int aux, k, f;

  for (k = 1; k < m; ++k) {
    f = k+1;
    while ((cmp = cmp + 1) && f > 1 && v[f/2] < v[f]) {
      aux = v[f/2];
      v[f/2] = v[f];
      v[f] = aux;
      trocas++;
      f /= 2;
    }
  }
}

void ordena(int m, int *v)  {

  int p = 1, f = 2, x = v[1];

  while ((cmp = cmp + 1) && f <= m) {
    if (f < m && v[f] < v[f+1]) f++;
    if (x >= v[f]) break;
    v[p] = v[f];
    trocas++;
    p = f, f = 2*p;
  }
   v[p] = x;
   trocas++;
}
