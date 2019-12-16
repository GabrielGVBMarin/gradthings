#include <stdio.h>
#include <math.h>
#include <string.h>

int main()  {

  int mat[5][5], save;

  for ( int i = 0; i < 5; i++)  {
    for ( int j = 0; j < 5; j++)  {
      scanf("%d", &mat[i][j]);
    }
  }

  for ( int test = 0, negat = 4; test < 5; test++, negat--) {
    save = mat[test][test];
    mat[test][test] = mat[test][negat];
    mat[test][negat] = save;

  }

  for ( int i = 0; i < 5; i++)  {
    for ( int j = 0; j < 5; j++)  {
      printf("%d ", mat[i][j]);
    }
    printf("\n");
  }

}
