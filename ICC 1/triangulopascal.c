#include <stdio.h>
#include <math.h>
#include <string.h>

int main()  {

  int linha, vetor[100] = {0}, j = 0, aux, set = 0;

  scanf("%d", &linha);

  vetor[0] = 1;
  

  for ( int k = 0; k < linha; k++)  {
    printf("%d\n", vetor[k]);
  }


  return 0;
}
