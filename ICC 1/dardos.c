#include <stdio.h>
#include <string.h>
#include <math.h>

void converte(char[3][3], int);
void contaponto(char[3][3], int*);

int main()  {
  char acertos[3][3];
  int pont1 = 301, pont2 = 301, set = 0, x, p1 = 0,p2 = 0;
do {
  x = scanf(" %s\n", acertos[0]);
  x = scanf(" %s\n", acertos[1]);
  x = scanf(" %s\n", acertos[2]);
  if ( set == 0)  {
  converte(acertos, p1);
  contaponto(acertos, &pont1);
  set = 1;
  //p1 += 2;
  }
  else if (set == 1)  {
    converte(acertos, p2);
    contaponto(acertos, &pont2);
    set = 0;
    //p2 += 2;
  }
} while(x);

printf("\n%d\n", pont1);
printf("\n%d\n", pont2);

return 0;
}

void converte(char hits[3][3], int p)  {
  for ( int i = 0, p; i < 3; i++, p++)  {
    for ( int j = 0; j < 1; j++)  {
      if ( hits[i][j] == 'S') {
        hits[i][j] = 1;
      }
      if ( hits[i][j] == 'D') {
        hits[i][j] = 2;
      }
      if ( hits[i][j] == 'T') {
        hits[i][j] = 3;
      }
      if ( hits[i][j] == 'M') {
        hits[i][j] = 25;
      }
      if ( hits[i][j] == 'X') {
        hits[i][j] = 0;
      }
    }
  }
  for ( int i = 0, p; i < 3; i++, p++)  {
    for ( int j = 1; j < 2; j++)  {
      hits[i][j] = (hits[i][j] - '0')*10;
    }
  }
  for ( int i = 0, p; i < 3; i++, p++)  {
    for ( int j = 2; j < 3; j++)  {
      hits[i][j] = (hits[i][j] - '0');
    }
  }
}

void contaponto(char hist[3][3], int *pont) {
  int pontos;
  for (int i = 0; i < 3; i++) {
    for ( int j = 2; j > -1; j--)  {
      if ( j == 2 || j == 1)  {
      pontos = pontos + hist[i][j];
      }
      else if ( j == 0) {
        pontos = pontos * hist[i][j];
      }
    }
  }
  if ( pontos <= *pont)  {
    *pont = *pont - pontos;
  }
}
