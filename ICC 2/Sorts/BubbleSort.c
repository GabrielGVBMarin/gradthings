#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int*, int);

long int trocas = 0;
long int cmp = 0;

int main(void)  {

  int i = 0, tamanho;

  scanf("%d\n", &tamanho);
  int *v = (int*) calloc(tamanho, sizeof(int));

  for ( i = 0; i < tamanho; i++)  {
    scanf("%d", &v[i]);
  }

  BubbleSort(v, tamanho);

  for ( i = 0; i < tamanho; i++)  {
    printf("%d ", v[i]);
  }

  printf("\n\nTROCAS : %ld\nCOMPARAÇÕES : %ld\n\n", trocas, cmp);

  return 0;

}

void BubbleSort(int *array, int size) {

	int i,j,aux;
	for(i = size-1 ; i > 0 ; i--)  {
		for(j = 0 ; j < i ; j++)  {
      cmp++;
			if(array[j] > array[j+1])  {
				aux = array[j];
				array[j] = array[j+1];
				array[j+1] = aux;
        trocas++;
			}
		}
	}
}
