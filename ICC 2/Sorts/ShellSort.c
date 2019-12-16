#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ShellSort(int*, int);

long int trocas = 0;
long int cmp = 0;

int main(void)  {
  int i = 0, tamanho;

  scanf("%d\n", &tamanho);
  int *v = (int*) calloc(tamanho, sizeof(int));

  for ( i = 0; i < tamanho; i++)  {
    scanf("%d", &v[i]);
  }

  ShellSort(v, tamanho);

  for ( i = 0; i < tamanho; i++)  {
    printf("%d ", v[i]);
  }

  printf("\n\nTROCAS : %ld\nCOMPARAÇÕES : %ld\n\n", trocas, cmp);

  return 0;
}

void ShellSort(int *vet, int size) {

  int k = 0, gap, i, new, j;

  while((pow(2, k) -1) < size) k++;
  for(gap = pow(2, k) - 1; gap >= 1; gap/=2)
    for(i = 0; i < size-gap; i++) {
      new = vet[i+gap], j= i;
      while((cmp = cmp + 1) && j >= 0 && vet[j] > new) {
        vet[j+gap] = vet[j];
        trocas++;
        j -= gap;
      }
      vet[j+gap] = new;
      trocas++;
    }
}
