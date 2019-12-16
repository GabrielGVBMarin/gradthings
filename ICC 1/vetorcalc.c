#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void soma(float[3], float[3], int, int);
void produtovet(float[3], float[3], float[3], int, int);
void multiplica(float[3], float, int, int);

int main()  {

  float seed, *escalar, vetor1[3], vetor2[3], result[3];
  int *ops, numop, min, max;
  scanf("%d", &numop); scanf("%f", &seed);
  scanf("%d.0", &min); scanf("%d.0", &max);
  ops = (int*) calloc(numop, sizeof(int));
  escalar = (float*) calloc(numop, sizeof(float));
  for ( int i = 0; i < numop; i++)  {
    scanf("%d", &ops[i]);
    if ( ops[i] == 3) {
      scanf("%f", &escalar[i]);
    }
  }
  srand(seed);

  for ( int i = 0; i < numop; i++) {
    switch (ops[i]) {
      case 1:
      soma(vetor1, vetor2, min, max);
      break;
      case 2:
      produtovet(vetor1, vetor2, result, min, max);
      break;
      case 3:
      multiplica(vetor1, escalar[i], min, max);
      break;
      default:  break;
    }
  }

  return 0;
}

void multiplica(float vetor1[3], float escalar, int min, int max) {
  for ( int i = 0; i < 3; i++)  {
      //vetor1[i] = (float) (rand()%(max-min+1) + min) / ((max-min+1) + min);
      vetor1[i] = min + ((float)rand()/(float)RAND_MAX)*(max-min);
  }
  for ( int i = 0; i < 3; i++)  {
    printf("%f ", vetor1[i]);
  }
  printf("\n");
  vetor1[0] = vetor1[0]*escalar;
  vetor1[1] = vetor1[1]*escalar;
  vetor1[2] = vetor1[2]*escalar;

  for ( int i = 0; i < 3; i++)  {
    printf("%f ", vetor1[i]);
  }
  printf("\n");

}

void soma(float vetor1[3], float vetor2[3], int min, int max) {
  for ( int i = 0; i < 3; i++)  {
      //vetor1[i] = (float) (rand()%(max-min+1) + min) / ((max-min+1) + min);
      vetor1[i] = min + ((float)rand()/(float)RAND_MAX)*(max-min);
  }
  for ( int i = 0; i < 3; i++)  {
      //vetor2[i] = (float) (rand()%(max-min+1) + min) / ((max-min+1) + min);
      vetor2[i] = min + ((float)rand()/(float)RAND_MAX)*(max-min);
  }

    for ( int j = 0; j < 3; j++)  {
      printf("%f ", vetor1[j]);
    }
    printf("\n");
    for ( int j = 0; j < 3; j++)  {
      printf("%f ", vetor2[j]);
    }
    printf("\n");
    for ( int j = 0; j < 3; j++)  {
      printf("%f ", vetor1[j]+vetor2[j]);
    }
    printf("\n");
}

void produtovet(float vetor1[3], float vetor2[3], float result[3], int min, int max) {
  for ( int i = 0; i < 3; i++)  {
      //vetor1[i] = (float) (rand()%(max-min+1) + min) / ((max-min+1) + min);
      vetor1[i] = min + ((float)rand()/(float)RAND_MAX)*(max-min);
  }
  for ( int i = 0; i < 3; i++)  {
      //vetor2[i] = (float) (rand()%(max-min+1) + min) / ((max-min+1) + min);
      vetor2[i] = min + ((float)rand()/(float)RAND_MAX)*(max-min);
  }
  for ( int j = 0; j < 3; j++)  {
    printf("%f ", vetor1[j]);
  }
  printf("\n");
  for ( int j = 0; j < 3; j++)  {
    printf("%f ", vetor2[j]);
  }
  printf("\n");

    result[0] = (vetor1[1]*vetor2[2]) - (vetor1[2]*vetor2[1]);
    result[1] = (vetor1[2]*vetor2[0]) - (vetor1[0]*vetor2[2]);
    result[2] = (vetor1[0]*vetor2[1]) - (vetor1[1]*vetor2[0]);

    for ( int j = 0; j < 3; j++)  {
      printf("%f ", result[j]);
    }
    printf("\n");
  }
