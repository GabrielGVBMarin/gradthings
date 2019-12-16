#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(int*, int, int);

long int trocas = 0;
long int cmp = 0;

int main(void)  {
  int i = 0, tamanho;

  scanf("%d\n", &tamanho);
  int *v = (int*) malloc(tamanho*sizeof(int));

  for ( i = 0; i < tamanho; i++)  {
    scanf("%d", &v[i]);
  }

  quickSort(v, 0, tamanho);

  for ( i = 0; i < tamanho; i++)  {
    printf("%d ", v[i]);
  }

  printf("\n\nTROCAS : %ld\nCOMPARAÇÕES : %ld\n\n", trocas, cmp);

  return 0;

}

void quickSort(int *vet, int start, int end) {

  int aux;

	if(start < end) {
    srand(time(NULL));
		int p = start + rand() % (end - start + 1);
		int pivo = vet[p], left = start + 1, right = end;
		vet[p] = vet[start];
		vet[start] = pivo;
    trocas++;

		while(left <= right) {
			while(left <= right && vet[left] <= pivo) {
				left++;
			}

			while(left <= right && vet[right] >= pivo) {
				right--;
			}

      cmp++;
			if(left < right) {
        aux = vet[left];
        vet[left] = vet[right];
        vet[right] = aux;
        trocas++;
      }
		}
    aux = vet[right];
    vet[right] = vet[start];
    vet[start] = aux;
    trocas++;
		quickSort(vet, start, right - 1);
		quickSort(vet, right + 1, end);
	}
}
