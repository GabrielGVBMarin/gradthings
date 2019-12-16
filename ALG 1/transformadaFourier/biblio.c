// Gabriel Guimarães Vilas Boas Marin NUSP: 11218521
#include <biblio.h>
#include <complex.h>

// LE O NOME, OS VALORES E SALVA NA STRUCT MODELADA PARA O AUDIO
VETOR* leArquivo()  {

  int i = 0, max = -9999999, min = 99999999;
  VETOR *header = (VETOR*) calloc(1, sizeof(VETOR));
  header->nome = (char*) malloc(10);

  scanf("%s", header->nome);
  scanf("%d", &header->C);

  FILE *arq = fopen(header->nome, "rb");
  header->vetor = (unsigned char*) realloc(header->vetor, 1*sizeof(unsigned char));

  while (fread(&header->vetor[i], sizeof(unsigned char), 1, arq)) {

    if (header->vetor[i] > max) max = header->vetor[i];
    else if (header->vetor[i] < min) min = header->vetor[i];
    i++;
    header->vetor = (unsigned char*) realloc(header->vetor, (i+1)*sizeof(unsigned char));

  }

  header->minValue = min;
  header->maxValue = max;
  header->size = i;

  fclose(arq);
  return header;
}

// FAZ A EQUAÇÃO DE FOURIER
_Complex double* calculaFourier(VETOR *header)  {

  _Complex double soma, aux;
  int i, j;
  double ezin;
  _Complex double *vetor = (_Complex double*) malloc(((header->size/2)+1)*sizeof(_Complex double));

  for (j = 0; j < (header->size/2)+1; j++)  {
    soma = 0;
    for (i = 0; i < header->size; i++)  {
       aux = cos(j*2*M_PI*(double)i/header->size) + I*sin(j*2*M_PI*(double)i/header->size);
       aux = 1/aux;
       aux = header->vetor[i]*aux;
       soma = soma + aux;
    }
    if (j == 0)  ezin = 1;
    else if (j > 0) ezin = 2;
    soma = ((double)ezin/header->size)*soma;
    vetor[j] = soma;
  }

  return vetor;
}

// CALCULA MAGNITUDES, ORDENA, ATRIBUI ZERO PARA OS NAO RELEVANTES
// MONTA O VETOR DOS SIGNIFICANTES, E DEVOLVE OS VALORES NO LUGAR QUE ESTAVAM
 void geraVetorNovo(VETOR *header, _Complex double *vetor, int *magCounter, int *significantes) {

  int i, *pos = (int*) malloc(((header->size/2)+1)*sizeof(int));
  double *vet = (double*) malloc(((header->size/2)+1)*sizeof(double));

  for (i = 0; i < header->size/2+1; i++)  {
    vet[i] = (double) cabs(vetor[i]);
    if (vet[i] > 0.1) {
      (*magCounter)++;
    }
  }

  selection_sortMag(vetor, vet, pos, (header->size/2)+1);
  for (i = header->C; i < (header->size/2)+1; i++)  {
    vetor[i] =  0;
    vet[i] = 0;
  }

  for (i = 0; i < header->C; i++) {
    significantes[i] = (int) vet[i];
  }

  selection_sortPos(vetor, vet, pos, (header->size/2)+1);

}

// FAZ O SELECTION SORT ORDENANDO DO MAIOR PRO MENOS PELAS MAGNITUDES
void selection_sortMag(_Complex double *vetor, double *mags, int *pos, int tam) {
  int i, j, min;
  _Complex double auxComplex;
  for (i = 0; i < tam; i++) {
    pos[i] = i;
  }
  double aux;
  for (i = 0; i < (tam-1); i++) {
     min = i;
     for (j = (i+1); j < tam; j++) {
       if(mags[j] > mags[min])
         min = j;
     }
     if (mags[i] != mags[min]) {

       auxComplex = vetor[i];
       vetor[i] = vetor[min];
       vetor[min] = auxComplex;

       aux = mags[i];
       mags[i] = mags[min];
       mags[min] = aux;

       aux = pos[i];
       pos[i] = pos[min];
       pos[min] = aux;

     }
  }
}

// FAZ O SELECTION SORT NORMAL, ORDENANDO PELAS POSIÇÕES QUE ESTAVAM ANTES
void selection_sortPos(_Complex double *vetor, double *mags, int *pos, int tam) {
  int i, j, min;
  _Complex double auxComplex;
  double aux;
  for (i = 0; i < (tam-1); i++) {
     min = i;
     for (j = (i+1); j < tam; j++) {
       if(pos[j] < pos[min])  min = j;
     }
     if (pos[i] != pos[min]) {

       auxComplex = vetor[i];
       vetor[i] = vetor[min];
       vetor[min] = auxComplex;

       aux = mags[i];
       mags[i] = mags[min];
       mags[min] = aux;

       aux = pos[i];
       pos[i] = pos[min];
       pos[min] = aux;

     }
  }
}

// FAZ A INVERSA DE FOURIER JA GUARDANDO O VALOR DO AUDIO FILTRADO
unsigned char* inverseFourierTransform(VETOR *header, _Complex double *vetor)  {

  _Complex double soma, aux;
  int j, i;
  unsigned char *vet = (unsigned char*) calloc(header->size, sizeof(unsigned char));

  for (j = 0; j < header->size; j++)  {
    soma = 0;
    for (i = 0; i <= header->size/2; i++)  {
      aux = cos(i*2*M_PI*((double)j/header->size)) + I*sin(i*2*M_PI*((double)j/header->size));
      aux = vetor[i]*aux;
      soma = soma + aux;
    }
    vet[j] = round(creal(soma));
  }

  return vet;
}

//  FAZ O FREE DE TUDO
void freeAll(VETOR *header, _Complex double *coeficientes, unsigned char *resultado, int *significantes) {

  free(coeficientes);
  free(significantes);
  free(resultado);
  free(header->nome);
  free(header->vetor);
  free(header);

}
