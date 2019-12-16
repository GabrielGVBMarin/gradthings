#include <stdio.h>
#include <ctype.h>
#include <string.h>

void somabit (char, char, int , int *, int *);

  int main()  {

    int carryout, soma, carryin = 0, set = 0, tamanho1, tamanho2;
    char b1[9], b2[9], result[9], save;

    scanf("%s\n", &*b1);
    scanf("%s", &*b2);
    
    tamanho1 = strlen(b1);
    tamanho2 = strlen(b2);

    for ( int i = tamanho1, j = 7; tamanho1 > -1; j--, i--) {
      save = b1[tamanho1];
      b1[tamanho1] = b1[j];
      b1[j] = save;
    }
    for ( int i = tamanho2, j = 7; tamanho2 > -1; j--, i--) {
      save = b2[tamanho2];
      b2[tamanho1] = b2[j];
      b2[j] = save;
    }
    for ( int i = 0; i < 9; i++)  {
      if ( b1[i] != '0' && b1[i] != '1')  {
        b1[i] = '0';
      }
      if ( b2[i] != '0' && b2[i] != '1')  {
        b2[i] = '0';
      }
    }
    printf("%s\n", b1);
    printf("%s\n", b2);

    for ( int i = 9, j = 0; i > -1; j++,i--)  {
      somabit( b1[i], b2[i], carryin, &carryout, &soma);
      printf("%d carry\n", carryout);
      carryin = carryout;
      result[j] = soma + 48;
      printf("%c result\n", result[j]);
    }

    printf("%s\n", result);

    for ( int i = 0; i < 8; i++)  {
      if ( result[i] == '0' & set == 0) {
        continue;
      }
      else if ( result[i] == '1' || set == 1) {
        printf("%c creu\n", result[i]);
        set = 1;
      }
    }
    return 0;

  }

void somabit(char b1, char b2, int carryin, int *carryout, int *soma) {
  if ( b1 == 48 || b1 == 49 ) {
    b1 = b1 - '0';
  }
  if ( b2 == 48 || b2 == 49)  {
    b2 = b2 - '0';
  }
   int num = 0;
  printf("%d b1\n", b1);
  printf("%d b2\n", b2);
  printf("%d carryin\n", carryin);
  num = b1 + b2 + carryin;
  printf("%d\n", num);
  if ( num == 0) {
    *soma = 0;
    *carryout = 0;
  }
  else if ( num == 1) {
    *soma = 1;
    *carryout = 0;
  }
  else if ( num == 2) {
    *soma = 0;
    *carryout = 1;
  }
  else if ( num == 3) {
    *soma = 1;
    *carryout = 1;
  }
  printf("%d o que tem que somar\n", *soma);
}
