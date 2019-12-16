#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// corpo da func
void DCTII(double *vetorResultante, double *vetorOrig, long tamanhoVetor)
{
  // contadores para os fors
  int n;
  int i;

  //repetidores para o vetor
  for ( i = 0; i < tamanhoVetor; i++)  {
    // repetidor para a soma
    for ( n = 0; n < tamanhoVetor; n++) {
      //estrutura da formula
      vetorResultante[i] =  vetorResultante[i] + vetorOrig[n]*cos((M_PI/(double)tamanhoVetor)*(n+0.5)*i);
    }
  }
}
