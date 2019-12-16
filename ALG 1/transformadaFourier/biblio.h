// Gabriel Guimarães Vilas Boas Marin NUSP: 11218521
#ifndef _BIBLIO_
#define _BIBLIO_

#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>

typedef struct complexo COMPLEXO;

// ESTRUTURA PARA O AUDIO
struct vetor  {
  char *nome;
  unsigned char *vetor;
  int size, maxValue, minValue, C;
};
typedef struct vetor VETOR;

VETOR* leArquivo();
_Complex double* calculaFourier(VETOR*);
void geraVetorNovo(VETOR*, _Complex double*, int*, int*);
void selection_sortMag(_Complex double*, double*, int*, int);
void selection_sortPos(_Complex double*, double*, int*, int);
unsigned char* inverseFourierTransform(VETOR*, _Complex double*);
void freeAll(VETOR*, _Complex double*, unsigned char*, int*);


#endif
