#include <stdio.h>
#include <math.h>
#include <string.h>

int esparsa(int [100][100], int);
int identidade(int [100][100], int);
int simetrica(int [100][100], int);

int main()  {

int matriz[100][100], save, opt;
scanf("%d", &save);
for ( int i = 0; i < save; i++) {
  for ( int k = 0; k < save; k++) {
    scanf("%d", &matriz[i][k]);
  }
}
scanf("%d", &opt);

  switch (opt) {
    case 1:
      esparsa(matriz, save);

    break;
    case 2:
      identidade(matriz, save);

    break;
    case 3:
      simetrica(matriz, save);

    break;
  }
  return 0;
}

int esparsa(int matriz[100][100], int save) {
  int quant = 0;
  for(int i = 0; i < save; i++) {
    for( int k = 0; k < save; k++)  {
      if (matriz[i][k] == 0)  {
        quant += 1;
      }
    }
  }
  if ( save*save/2 < quant)  {
    printf("SIM");
    return 1;
  }
  else {
    printf("NAO");
    return 0;
  }
}

int identidade(int matriz[100][100], int save)  {
  int quants = 0;
  for(int k = 0,  i = 0; k < save; k++, i++) {
    if(matriz[i][k] == 1) {
      quants += 1;
      matriz[i][k] = 0;
    }
  }
  for( int i = 0; i < save; i++)  {
    for(int k = 0; k < save; k++) {
      if(matriz[i][k] != 0) {
        quants += 1;
      }
    }
  }
  if ( quants == save)  {
    printf("SIM");
    return 1;
  }
  else {
    printf("NAO");
    return 0;
  }
}

int simetrica(int matriz[100][100], int save) {
  int max = save, quants = 0;
  for ( int i = 0; i < save; i++) {
    for ( int k = 0; k < save/2; k++, max--) {
      if (matriz[i][k] == matriz[i][max -1]) {
        quants += 1;
      }
    }
  }
  if ( quants == save + save/2) {
    printf("SIM");
    return 1;
  }
  else {
    printf("NAO");
    return 0;
  }
}
