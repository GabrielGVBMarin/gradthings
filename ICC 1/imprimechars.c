#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main()  {

  char *vetor = NULL;

  char sup;
  int k = 1, *ponteiro;

  while(1){
    vetor = (char*) realloc(vetor, k*sizeof(char));
    scanf("%c",&vetor[k-1]);
     if (vetor[k-1] == '\n'){
       continue;
    }
    if  (vetor[k-1] == 'x') {
      k += 1; // o lugar do x e do /0
      vetor[k-1] = '\0';
      //vetor = (char*) realloc(vetor, k*sizeof(char));
      break;
    }

    k++;
}
  //vetor = NULL;

  //vetor = NULL;
  //*ponteiro = &*vetor;
  for ( int i = strlen(vetor)-1; i > 0; i--)  {
    for ( int j = 0; j < i; j++)  {
      if ( vetor[j+1] < vetor[j]) {
        sup = vetor[j];
        vetor[j] = vetor[j+1];
        vetor[j+1] = sup;
      }
    }
  }
  //ponteiro = NULL;
  ponteiro = (int*)vetor;
  if ( ponteiro == NULL)  {
    printf("Falha no realloc do ponteiro");
    exit(1);
  }
  //ponteiro = NULL;
  //printf("%s\n", vetor);
  for ( int k = 0; k < (strlen(vetor)/4); k++)  {
    if ( k != 0 && k%4 == 0)  {
      //printf("\n");
    }
    printf("%d\n", ponteiro[k]);
  }
  free(vetor);
  return 0;
}
