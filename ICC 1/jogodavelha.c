#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int analisa(char[3][3]);

int main()  {

char matk[3][3] = {0};

for ( int i = 0; i < 3; i++)  {
  for ( int j = 0; j < 3; j++)  {
    scanf(" %c", &matk[i][j]);
  }
}

//printf("\n%c", matk[2][2]);

analisa(matk);

  return 0;
}

int analisa(char jogo[3][3])  {

  if( jogo[0][0] == jogo[1][1] && jogo[1][1] == jogo[2][2] && jogo[0][0] != '-') {
    printf("%c ganhou", jogo[0][0]);
    return 0;
  }
  else if (jogo[0][2] == jogo[1][1] && jogo[1][1] == jogo[2][0] && jogo[0][2] != '-') {
    printf("%c ganhou", jogo[1][1]);
    return 0;
  }
  for ( int i = 0; i < 3; i++)  {
    if ( jogo[i][0] == jogo[i][1] && jogo[i][1] == jogo[i][2] && jogo[i][0] != '-')  {
      printf("%c ganhou", jogo[i][0]);
      return 0;
    }
    else if (jogo[0][i] == jogo[1][i] && jogo[1][i] == jogo[2][i] && jogo[0][i] != '-')  {
      printf("%c ganhou", jogo[0][i]);
      return 0;
    }
  }

for ( int i = 0; i < 3; i++)  {
  for ( int j = 0; j < 3; j++)  {
    if ( jogo[i][j] == '-')  {
      printf("em jogo");
      return 0;
    }
  }
}

printf("empate");

return 0;
}
