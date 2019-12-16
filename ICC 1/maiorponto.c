#include <stdio.h>
#include <math.h>
#include <string.h>

int main()  {

  float pontos[5][2], media;
  float conta[5];
  for ( int i = 0; i < 5; i++)  {
    for ( int k = 0; k < 2; k++)  {
      scanf("%f", &pontos[i][k]);
    }
  }

  for ( int i = 0; i < 5; i++)  {
    conta[i] = 0;
    for ( int k = 0; k < 2; k++)  {
      conta[i] = conta[i] + pontos[i][k];
    }
    conta[i] = conta[i]/2;
    if ( i == 0 ) {
      media = conta[i];
    }
   else if (conta[i] > media)  {
      media = conta[i];
      conta[0] = 0;
    }
    else {
      conta[i] = 0;
    }
  }

  for ( int i = 0; i < 5; i++)  {
      if (conta[i] == media)  {
        printf("%.2f ", conta[i]);
        for ( int k = 0; k < 2; k++)  {
          printf("%.0f ", pontos[i][k]);
        }
      }
  }

  return 0;
}
