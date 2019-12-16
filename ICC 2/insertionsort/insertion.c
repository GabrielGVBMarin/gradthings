#include <biblio.h>

int main(void)  {

  int *vetor, i, tamanho;
  scanf("%d", &tamanho);

  vetor = (int*) malloc(tamanho*sizeof(int));
  for ( i = 0; i < tamanho; i++)  {
    scanf("%d", &vetor[i]);
  }

  insertionSort(vetor, tamanho);

  for ( i = 0; i < tamanho; i++)  {
    printf("%d  ", vetor[i]);
  }

  return 0;

}
