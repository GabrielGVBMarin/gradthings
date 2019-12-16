#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

void naomudanada(char[500][500], int, int);
void celulasvazias(char[500][500], int, int);
void bombasexplodidas(char[500][500], int, int);

int main()  {

 char mat[500][500];
 int lin, col, tempo;

 scanf("%d %d %d", &lin, &col, &tempo);
 for ( int i = 0; i < lin; i++) {
  // for ( int j = 0; j < col; j++) {
     scanf("%s", mat[i]);
  // }
 }
 if ( tempo > 3 ) {
   tempo = tempo%4;
 }
 switch (tempo) {
  case 0:
  naomudanada(mat, lin, col);
  break;
  case 1:
  naomudanada(mat, lin, col);
  break;
  case 2:
  celulasvazias(mat, lin, col);
  break;
  case 3:
  bombasexplodidas(mat,lin,col);
  break;
 }
  return 0;
}

void naomudanada(char mat[500][500], int lin, int col)  {
  for ( int i = 0; i < lin; i++)  {
    for ( int j = 0; j < col; j++)  {
      printf("%c", mat[i][j]);
      //if ( j == col - 1)  {
      //  printf("\n");
      //}
    }
    printf("\n");
  }
}

void celulasvazias(char mat[500][500], int lin, int col)  {
  for ( int i = 0; i < lin; i++)  {
    for ( int j = 0; j < col; j++)  {
      printf("0");
    }
    printf("\n");
  }
}

void bombasexplodidas(char mat[500][500], int lin, int col)  {
  for ( int i = 0; i < lin; i++)  {
    for ( int j = 0; j < col; j++)  {
      if ( mat[i][j] == '0'/* && mat[i][j+1] == '.' && mat[i][j-1] == '.' && mat[i+1][j] == '.' && mat[i-1][j] == '.'*/)  {
        if ( mat[i][j+1] == '.' && mat[i][j+1] != '0' ) {
        mat[i][j+1] = '9';
        }
        if ( mat[i][j-1] == '.' && mat[i][j-1] != '0') {
        mat[i][j-1] = '9';
        }
        if ( mat[i+1][j] == '.' && mat[i+1][j] != '0') {
        mat[i+1][j] = '9';
        }
        if ( mat[i-1][j] == '.' && mat[i-1][j] != '0') {
        mat[i-1][j] = '9';
        }
      }
    }
  }
  for ( int i = 0; i < lin; i++)  {
    for ( int j = 0; j < col; j++)  {
      if ( mat[i][j] == '0')  {
        mat[i][j] = '.';
      }
      else if ( mat[i][j] == '.' )  {
        mat[i][j] = '0';
      }
      if ( mat[i][j] == '9')  {
        mat[i][j] = '.';
      }
    }
  }
  for (int i = 0; i < lin; i++) {
    for ( int j = 0; j < col; j++)  {
      printf("%c", mat[i][j]);
    }
    printf("\n");
  }
}
