#include <stdio.h>
#include <stdlib.h>

void insertionSort(int*, int);

long int trocas = 0;
long int cmp = 0;

int main(void)  {
  int i = 0, tamanho;

  scanf("%d\n", &tamanho);
  int *v = (int*) calloc(tamanho, sizeof(int));

  for ( i = 0; i < tamanho; i++)  {
    scanf("%d", &v[i]);
  }

  insertionSort(v, tamanho);

  for ( i = 0; i < tamanho; i++)  {
    printf("%d ", v[i]);
  }

  printf("\n\nTROCAS : %ld\nCOMPARAÇÕES : %ld\n\n", trocas, cmp);

  return 0;
}


void insertionSort(int *vetor, int tamanho)  {
 int i, j, aux;

   for ( i = 1; i < tamanho; i++) {
     aux = vetor[i];
     j = i - 1;
     while ((cmp = cmp + 1) && j >= 0 && vetor[j] > aux) {
       vetor[j+1] = vetor[j];
       j--;
       trocas++;
     }
     vetor[j+1] = aux;
   }
}
