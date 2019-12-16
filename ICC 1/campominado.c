#include <stdio.h>
#include <math.h>
#include <string.h>

void marcaponto(char [100][100], int, int);
int daprint(char[100][100], int, int);

int main()  {

  char campo[100][100] = {0};
  int lin, col;

  scanf("%d %d", &lin, &col);

  for ( int i = 0; i < lin; i++)  {
    for ( int j = 0; j < col; j++)  {
      scanf("%s", &campo[i][j]);
    }
  }

  marcaponto(campo,lin,col);
  daprint(campo, lin, col);


  return 0;
}


void marcaponto(char mat[100][100], int lin, int col) {
  for ( int i = 0; i < lin; i++)  {
    for ( int j = 0; j < col; j++)  {
      if ( mat[i][j] == '*')  {
        if ( mat[i-1][j] == '.')  {
          mat[i-1][j] = '1';
        }
        else if ( mat[i-1][j] != '*') {
          mat[i-1][j]++;
        }
        if ( mat[i+1][j] == '.')  {
          mat[i+1][j] = '1';
        }
        else if ( mat[i+1][j] != '*'){
          mat[i+1][j]++;
        }
        if ( mat[i-1][j+1] == '.')  {
          mat[i-1][j+1] = '1';
        }
        else if ( mat[i-1][i+1] != '*') {
          mat[i-1][j+1]++;
        }
        if ( mat[i-1][j-1] == '.')  {
          mat[i-1][j-1] = '1';
        }
        else if ( mat[i-1][j-1] != '*') {
          mat[i-1][j-1]++;
        }
        if ( mat[i+1][j+1] == '.')  {
          mat[i+1][j+1] = '1';
        }
        else if ( mat[i+1][j+1] != '*') {
          mat[i+1][j+1]++;
        }
        if ( mat[i+1][j-1] == '.')  {
          mat[i+1][j-1] = '1';
        }
        else if ( mat[i+1][j-1] != '*') {
          mat[i+1][j-1]++;
        }
        if ( mat[i][j-1] == '.')  {
          mat[i][j-1] = '1';
        }
        else if ( mat[i][j-1] != '*') {
          mat[i][j-1]++;
        }
        if ( mat[i][j+1] == '.')  {
          mat[i][j+1] = '1';
        }
        else if ( mat[i][j+1] != '*') {
          mat[i][j+1]++;
        }
      }
    }
  }
}

int daprint(char mat[100][100], int lin, int col) {
  for ( int i = 0; i < lin; i++)  {
    for ( int j = 0; j < col; j++)  {
      if ( mat[i][j] == '.')  {
        printf("0 ");
      }
      else  {
        printf("%c ", mat[i][j]);
      }
    }
    printf("\n");
  }
  return 0;
}
