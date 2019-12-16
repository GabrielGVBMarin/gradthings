#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void insertionSort(int *vetor, int tamanho)  {
 int i, j, aux;

   for ( i = 1; i < tamanho; i++) {
     aux = vetor[i];
     j = i - 1;
     while ( j >= 0 && vetor[j] > aux) {
       vetor[j+1] = vetor[j];
       j = j - 1;
     }
     vetor[j+1] = aux;
   }
}
