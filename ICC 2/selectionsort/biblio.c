#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *ptr, int tamanho)
{
  printf("\n\n ENTROU \n\n");
  printf("%d\n\n", tamanho);
  int i, j, aux, min;

  for(i = 0; i < tamanho; i++) {
    min = i;
    for ( j = i + 1; j < tamanho; j++)  {
      if ( ptr[j] < ptr[min])  {
        min = j;
      }
    }
    if ( i != min ) {
      aux = ptr[i];
      ptr[i] = ptr[min];
      ptr[min] = aux;
    }
  }
}
