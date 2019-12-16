#include <stdio.h>
#include <stdlib.h>

void selectionSort(int*, int);

long int trocas = 0;
long int cmp = 0;

int main(void)  {
  int i = 0, tamanho;

  scanf("%d\n", &tamanho);
  int *v = (int*) calloc(tamanho, sizeof(int));

  for ( i = 0; i < tamanho; i++)  {
    scanf("%d", &v[i]);
  }

  selectionSort(v, tamanho);

  for ( i = 0; i < tamanho; i++)  {
    printf("%d ", v[i]);
  }

  printf("\n\nTROCAS : %ld\nCOMPARAÇÕES : %ld\n\n", trocas, cmp);

  return 0;

}

void selectionSort(int *ptr, int tamanho) {

  printf("\n\n ENTROU \n\n");
  printf("%d\n\n", tamanho);
  int i, j, aux, min;

  for(i = 0; i < tamanho; i++) {
    min = i;
    for ( j = i + 1; j < tamanho; j++)  {
      cmp++;
      if ( ptr[j] < ptr[min])  {
        min = j;
      }
    }
    if ( i != min ) {
      aux = ptr[i];
      ptr[i] = ptr[min];
      ptr[min] = aux;
      trocas++;
    }
  }
}
