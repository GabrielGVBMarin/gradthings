#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()  {

  int coluna, linha, padding;
  int **matriz, **padded;

  scanf("%d %d", &coluna, &linha);
  //cria matriz
  matriz = (int**) calloc(linha, sizeof(int*));
  if ( matriz == NULL)  {
    printf("Erro na memoria");
    exit(1);
  }
  for ( int i = 0; i < linha; i++) {
    matriz[i] = (int*) calloc(coluna, sizeof(int));
    if ( matriz[i] == NULL)  {
      printf("Erro na memoria");
      exit(1);
    }
  }
  // cria matriz
  //le matriz e o padding
  for ( int i = 0; i < linha; i++)  {
    for ( int j = 0; j < coluna; j++) {
      scanf("%d\n", &matriz[i][j]);
    }
  }
  scanf("%d", &padding);
//le matriz e o padding

//cria 2 matriz com o padding
  padded = (int**)  calloc((linha+(padding*2)), sizeof(int*));
  if ( padded == NULL)  {
    printf("Erro na memoria");
    exit(1);
  }
  for ( int i = 0; i < linha+(padding*2); i++)  {
    padded[i] = (int*) calloc((coluna+(padding*2)), sizeof(int));
    if ( padded[i] == NULL)  {
      printf("Erro na memoria");
      exit(1);
    }
  }
  //cria 2 matriz com o padding

  for ( int i = 0; i < linha; i++)  {
    for ( int j = 0; j < coluna; j++) {
      padded[i + padding][j + padding] = matriz[i][j];
    }
  }

  for ( int i = 0; i < linha+(padding*2); i++)  {
    for ( int j = 0; j < coluna+(padding*2); j++) {
      printf("%d ", padded[i][j]);
    }
    printf("\n");
  }
  for ( int i = 0; i < linha+(padding*2); i++)  {
    free(padded[i]);
  }
  free(padded);
  printf("\n");
  for ( int i = 0; i < linha; i++)  {
    for ( int j = 0; j < coluna; j++) {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
  for ( int i = 0; i < linha; i++)  {
    free(matriz[i]);
  }
  free(matriz);
  return 0;
}
