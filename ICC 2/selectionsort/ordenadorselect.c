#include <biblio.h>

int main(void)  {

  int *vetor = NULL, tamanho, i;
  scanf("%d", &tamanho);

  vetor = (int*) malloc(tamanho*sizeof(int));

  for ( i = 0; i < tamanho; i++)  {
    scanf("%d", &vetor[i]);
  }

  selectionSort(vetor, tamanho);

  for ( i = 0; i < tamanho; i++)  {
    printf("%d\n", vetor[i]);
  }

  return 0;

}
