#include <stdio.h>
#include <string.h>
#include <math.h>

int main()  {

  int mat[3][3], positivo, negativo, det;

    for ( int i = 0; i < 3; i++)  {
      for ( int j = 0; j < 3; j++)  {
        scanf("%d", &mat[i][j]);
      }
    }

    positivo = mat[0][0]*mat[1][1]*mat[2][2] + mat[0][1]*mat[1][2]*mat[2][0] + mat[0][2]*mat[1][0]*mat[2][1];
    negativo = mat[0][1]*mat[1][0]*mat[2][2] + mat[0][0]*mat[1][2]*mat[2][1] + mat[0][2]*mat[1][1]*mat[2][0];

    det = positivo - negativo;

    printf("%d", det);



  return 0;
}
