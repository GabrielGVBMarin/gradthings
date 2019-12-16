#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main()  {

  char string[50] = {0}, sub[30] = {0};
  int tamanhosub,cont = 0, set = 0;

  fgets(string, 50, stdin);
  fgets(sub, 30, stdin);

  tamanhosub = strlen(sub) - 1;
  //printf("%d", tamanhosub);

  for ( int i = 0, k = 0; i < tamanhosub; i++) {
    if ( string[i] == sub[k] && sub[k] != '\0') {
      cont = cont+1;
    }
    else { goto fim;}
    if ( string[i+1] == sub[k+1] && cont != tamanhosub && sub[k+1] != '\0')  {
      cont = cont+1;
    }
    else { goto fim;}
    if ( string[i+2] == sub[k+2] && cont != tamanhosub && sub[k+2] != '\0')  {
      cont = cont+1;
    }
    else { goto fim;}
    if ( string[i+3] == sub[k+3] && cont != tamanhosub && sub[k+3] != '\0')  {
      cont = cont+1;
    }
    else { goto fim;}
    if ( string[i+4] == sub[k+4] && cont != tamanhosub && sub[k+4] != '\0')  {
      cont = cont+1;
    }
    else { goto fim;}
    if ( string[i+5] == sub[k+5] && cont != tamanhosub && sub[k+5] != '\0')  {
      cont = cont+1;
    }
    else { goto fim;}
    if ( string[i+6] == sub[k+6] && cont != tamanhosub && sub[k+6] != '\0')  {
      cont = cont+1;
    }
    else { goto fim;}
    if ( string[i+7] == sub[k+7] && cont != tamanhosub && sub[k+7] != '\0')  {
      cont = cont+1;
    }
    else { goto fim;}
    if ( string[i+8] == sub[k+8] && cont != tamanhosub && sub[k+8] != '\0')  {
      cont = cont+1;
    }
    else { goto fim;}
    if ( string[i+9] == sub[k+9] && cont != tamanhosub && sub[k+9] != '\0')  {
      cont = cont+1;
    }
    else { goto fim;}
    if ( string[i+10] == sub[k+10] && cont != tamanhosub && sub[k+10] != '\0')  {
      cont = cont+1;
    }
    else { goto fim;}
    if ( string[i+11] == sub[k+11] && cont != tamanhosub && sub[k+11] != '\0')  {
      cont = cont+1;
    }
    else { goto fim;}
    if ( string[i+12] == sub[k+12] && cont != tamanhosub && sub[k+12] != '\0')  {
      cont = cont+1;
    }
    else { goto fim;}
    if ( string[i+13] == sub[k+13] && cont != tamanhosub && sub[k+13] != '\0')  {
      cont = cont+1;
    }
    else { goto fim;}
    if ( string[i+14] == sub[k+14] && cont != tamanhosub && sub[k+14] != '\0')  {
      cont = cont+1;
    }
    else { goto fim;}
    //printf("\n %d \n", cont);
    if ( cont == tamanhosub)  {
      printf("A frase contem a substring %s", sub);
      set = 1;
      break;
    }
    fim:
    cont = 0;
  }

  if ( set == 0 ) {
    printf("A frase nao contem a substring %s", sub);
  }

  return 0;

}
