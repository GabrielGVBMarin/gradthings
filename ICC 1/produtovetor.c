#include <stdio.h>
#include <string.h>
#include <math.h>

int main()  {

  int mat[3][3], parte1, parte2, parte3, negativo1, negativo2, negativo3, prod[3];

  mat[0][1] = 1; mat[0][2] = 1; mat[0][0] = 1;
    for ( int i = 1; i < 3; i++)  {
      for ( int j = 0; j < 3; j++)  {
        scanf("%d", &mat[i][j]);
      }
    }

    parte1 = mat[0][0]*mat[1][1]*mat[2][2];
    parte2 =  mat[0][1]*mat[1][2]*mat[2][0];
    parte3 = mat[0][2]*mat[1][0]*mat[2][1];
    negativo1 = mat[0][1]*mat[1][0]*mat[2][2];
    negativo2 = mat[0][0]*mat[1][2]*mat[2][1];
    negativo3 = mat[0][2]*mat[1][1]*mat[2][0];

    prod[0] = parte1 - negativo2;
    prod[1] = parte2 - negativo1;
    prod[2] = parte3 - negativo3;

    for ( int i = 0; i < 3; i++)  {
      printf("%d ", prod[i]);
    }


  return 0;
}
