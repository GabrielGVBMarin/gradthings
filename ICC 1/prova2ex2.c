#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()  {

  int *vetorA, *vetorB, *vetorC, tamA, tamB, maior;

  // comeca a fazer a leitura do vetorA
  scanf("%d", &tamA);
  vetorA = (int*) malloc(tamA*sizeof(int));
  if ( vetorA == NULL)  {
    printf("ERRO NA ALOC DO VETORA");
    exit(1);
  }
  for ( int i = 0; i < tamA; i++) {
    scanf("%d", &vetorA[i]);
  }
  //termina a leitura do vetorA

  // comeca a fazer a leitura do vetorB
  scanf("%d", &tamB);
  vetorB = (int*) malloc(tamB*sizeof(int));
  if (vetorB == NULL) {
    printf("ERRO NA ALOC DO VETORB");
    exit(1);
  }
  for ( int i = 0; i < tamB; i++) {
    scanf("%d", &vetorB[i]);
  }
  // termina a leitura do vetor B

  if ( tamA > tamB) maior=tamA; // define qual vetor eh o maior
  else if ( tamB > tamA) maior=tamB;  // define qual vetor eh o maior

  // Realoca o menor vetor
  if ( maior == tamA) {
    vetorB = (int*) realloc(vetorB, maior*sizeof(int));
    if ( vetorB == NULL)  {
      printf("ERRO NO REALLOC DO VETORB");
      exit(1);
    }
    for ( int u = tamB; u < tamA; u++)  {
      vetorB[u] = 0;
    }
  }
  else if ( maior == tamB ) {
    vetorA = (int*) realloc(vetorA, maior*sizeof(int));
    if ( vetorA == NULL)  {
      printf("ERRO NO REALLOC DO VETORA");
      exit(1);
    }
    for ( int u = tamA; u < tamB; u++)  {
      vetorA[u] = 0;
    }
  }
  // Realoca o menor vetor

  // Cria o vetorC com o tamanho do maior vetor
  vetorC = (int*) calloc(maior, sizeof(int));
  if ( vetorC == NULL ) {
    printf("ERRO NA ALOC DO VETORC");
    exit(1);
  }

  // Comeca a fazer a soma dos vetores
  for ( int v = 0; v < maior; v++)  {
    vetorC[v] = vetorA[v] + vetorB[v];
  }
  // termina e ja que n vai usar mais o vetorA e o vetorB da free neles
  free(vetorA); free(vetorB);
  // printa o vetorC
  for ( int h = 0; h < maior; h++)  {
    printf("%d ", vetorC[h]);
  }
  // livera a memoria do vetorC
  free(vetorC);

  return 0;
}
