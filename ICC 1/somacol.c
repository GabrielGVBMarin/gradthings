#include <stdio.h>
#include <string.h>

int main()  {

  int mat[4][5], soma = 0;

  for ( int i = 0; i < 4; i++)  {
    for ( int j = 0; j < 5; j++)  {
      scanf("%d", &mat[i][j]);
    }
  }

  for ( int j = 0; j < 5; j++)  {
    for ( int i = 0; i < 4; i++)  {
      soma = soma + mat[i][j];
    }
    printf("%d ", soma);
    soma = 0;
  }


  return 0;
}
