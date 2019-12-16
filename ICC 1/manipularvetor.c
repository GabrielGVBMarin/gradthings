#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int menorvalor(int*, int, int, int);
int maiorvalor(int*, int, int, int);
int media(int*, int, int, int);

int main()  {

  int tamanho, opt, operacao;
  scanf("%d %d", &tamanho, &opt);
  int (*pt)(int*, int, int, int);
  int *vetor = NULL;

  for ( int i = 0; i < tamanho; i++)  {
    vetor = (int*) realloc(vetor, (i+1)*sizeof(int));
    scanf("%d", &vetor[i]);
  }

  switch (opt) {
    case 1:
    pt = menorvalor;
    break;
    case 2:
    pt = maiorvalor;
    break;
    case 3:
    pt = media;
    break;
  }

  operacao = vetor[0];
  operacao = pt(vetor, tamanho, operacao, tamanho);

   printf("%d", operacao);

  return 0;
}

int menorvalor(int *vetor, int tamanho, int menor, int contador) {
  tamanho = tamanho -1;
  if ( menor > vetor[tamanho])  {
    menor = vetor[tamanho];
  }
  return tamanho==0 ? menor:menorvalor(vetor, tamanho, menor, contador);
}

int maiorvalor(int *vetor, int tamanho, int maior, int contador) {
  tamanho = tamanho -1;
  if ( maior < vetor[tamanho])  {
    maior = vetor[tamanho];
  }
  return tamanho==0 ? maior:maiorvalor(vetor, tamanho, maior, contador);
}

int media(int *vetor, int tamanho, int mediar, int contador)  {
  tamanho = tamanho - 1;
  mediar = (mediar + vetor[tamanho]);
  return tamanho==1 ? mediar/contador:media(vetor, tamanho, mediar, contador);
}
