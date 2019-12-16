#include <stdio.h>
#include <math.h>
#include <string.h>

void lemat(int mat[5][5]);
int analise_de_ponto(int mat[5][5], int pontos, int player);

int main()  {

int mat[5][5], player, pontos = 0;

scanf("%d", &player);

lemat(mat);

pontos = analise_de_ponto(mat, pontos, player);
printf("%d", pontos);


  return 0;
}



void lemat(int mat2[5][5]) {
  for( int i = 0; i < 5; i++) {
    for ( int j = 0; j < 5; j++)  {
      scanf("%d", &mat2[i][j]);
    }
  }
}

int analise_de_ponto(int mat3[5][5], int pontos, int player)  {
  for( int i = 5; i > 1; i--) {
    for ( int j = 0; j < 5; j++)  {
      if ( mat3[i][j] == player && mat3[i-1][j] == player && mat3[i-2][j] == player ) {
        pontos = pontos + 100;
      }
      else if ( mat3[i][j] == player && mat3[i-1][j] == player && (mat3[i-2][j] == 0 || mat3[i-2][j] == player) )  {
        pontos = pontos + 50;

      }
      else if ( mat3 [i][j] == player && mat3[i-1][j] == 0 && mat3[i-2][j] == 0) {
        pontos = pontos + 10;
      }
    }
  }
  return pontos;
}
