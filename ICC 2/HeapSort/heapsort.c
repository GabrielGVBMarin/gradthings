#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void HeapSort(int, int*);
static void fazHeap(int, int*);
static void ordena(int, int*);

int trocas = 0;
int cmp = 0;

int main(void)  {

  srand(time(NULL));
  int *v = (int*) malloc(15*sizeof(int));
  int i;
  for (i = 1; i <= 15; i++)  {
    v[i] = rand()%20;
    printf("%d ", v[i]);
  }
  printf("\n");

  HeapSort(15, v);

  for (i = 1; i <= 15; i++)  {
    printf("%d ", v[i]);
  }
  printf("\n\nTROCAS : %d\n\n", trocas);


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

 static void fazHeap(int m, int *v) {

  int aux, k, f;

  for (k = 1; k < m; ++k) {

    f = k+1;

    while (f > 1 && v[f/2] < v[f]) {
      aux = v[f/2];
      v[f/2] = v[f];
      v[f] = aux;
      trocas++;
      f /= 2;
    }

  }

}

static void ordena(int m, int *v)  {

  int p = 1, f = 2, x = v[1];

  while (f <= m) {

    if (f < m && v[f] < v[f+1] && (f = f + 1))
    ;
    if (x >= v[f]) break;
    v[p] = v[f];
    trocas++;
    p = f, f = 2*p;

  }

   v[p] = x;
}
