#include <stdio.h>
#include <stdlib.h>

void mergeSort(int*, int);

long int trocas = 0;
long int cmp = 0;

int main(void)  {
  int i = 0, tamanho;

  scanf("%d\n", &tamanho);
  int *v = (int*) calloc(tamanho, sizeof(int));

  for ( i = 0; i < tamanho; i++)  {
    scanf("%d", &v[i]);
  }

  mergeSort(v, tamanho);

  for ( i = 0; i < tamanho; i++)  {
    printf("%d ", v[i]);
  }

  printf("\n\nTROCAS : %ld\nCOMPARAÇÕES : %ld\n\n", trocas, cmp);

  return 0;

}

void mergeSort(int *vet, int size) {
	int *vetAux = (int *) malloc(size * sizeof(int));

	for(int length = 1; length < size; length *= 2) {
		int posAux = 0;
		while(posAux < size) {
			int start1 = posAux;
			int start2 = posAux + length;
			int end1 = start1 + length;
			int end2 = start2 + length;

			if(end1 > size) end1 = size;
			if(end2 > size) end2 = size;

			while(start1 < end1 && start2 < end2) {
        cmp++;
				if(vet[start1] <= vet[start2]) {
					vetAux[posAux++] = vet[start1++];
          trocas++;
				} else {
					vetAux[posAux++] = vet[start2++];
          trocas++;
				}
			}

			while((cmp = cmp + 1) && start1 < end1) {
				vetAux[posAux++] = vet[start1++];
        trocas++;
			}

			while((cmp = cmp + 1) && start2 < end2) {
				vetAux[posAux++] = vet[start2++];
        trocas++;
			}
		}

		for(int i = 0; i < size; i++, cmp++)  {
      vet[i] = vetAux[i];
      trocas++;
    }
	}

	free(vetAux);
}
