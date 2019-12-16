#include <stdio.h>
#include <stdlib.h>

void BubbleSortSent(int*, int);

long int trocas = 0;
long int cmp = 0;

int main(void)  {
  int i = 0, tamanho;

  scanf("%d\n", &tamanho);
  int *v = (int*) calloc(tamanho, sizeof(int));

  for ( i = 0; i < tamanho; i++)  {
    scanf("%d", &v[i]);
  }

  BubbleSortSent(v, tamanho);

  for ( i = 0; i < tamanho; i++)  {
    printf("%d ", v[i]);
  }

  printf("\n\nTROCAS : %ld\nCOMPARAÇÕES : %ld\n\n", trocas, cmp);

  return 0;
}



void BubbleSortSent(int *vet, int size) {

	int i = size - 1, aux, sent, j;

	while(i > 0) {
		sent = -1;
		for(j = 0; j < i; j++)  {
      cmp++;
      if(vet[j] > vet[j+1]) {
        trocas++;
        aux = vet[j];
        vet[j] = vet[j+1];
        vet[j+1] = aux;
        sent = j;
      }
    }
		i = sent;
	}

}
