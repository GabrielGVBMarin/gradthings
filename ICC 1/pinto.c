#include <string.h>
#include <stdio.h>

int vepontos(char[3]);

int main(void) {
char aux[3];
char aux2[3];

int pinto1 = 301;
int pinto2 = 301;
int x,y;
while(pinto1!=0 && pinto2!=0){
  scanf("%s", aux);
  x = vepontos(aux);
  pinto1 -= x;
  if (pinto1 < 0){
    pinto1 += x;
  }
  if (pinto1 == 0){
    printf("1 %d", pinto2);
    break;
  }
  //////////////
  scanf("%s", aux);
  x = vepontos(aux);
  pinto1 -= x;
  if (pinto1 < 0){
    pinto1 += x;
  }

  if (pinto1 == 0){
    printf("1 %d",pinto2);
    break;
  }
  ///////////
  scanf("%s", aux);
  x = vepontos(aux);
  pinto1 -= x;
  if (pinto1 < 0){
    pinto1 += x;
  }

  if (pinto1 == 0){
    printf("1 %d", pinto2);
    break;
  }

  /////////////////////////
  ///// JOGADOR DOIS ///////
  scanf("%s", aux2);
  y = vepontos(aux2);
  pinto2 -= y;
  if (pinto2 < 0){
    pinto2 += y;
  }
  if (pinto2 == 0){
    printf("2 %d", pinto1);
    break;
  }
  //////////////
  scanf("%s", aux2);
  y = vepontos(aux2);
  pinto2 -= y;
  if (pinto2 < 0){
    pinto2 += y;
  }
  if (pinto2 == 0){
    printf("2 %d", pinto1);
    break;
  }
  //////////////////////
  scanf("%s", aux2);
  y = vepontos(aux2);
  pinto2 -= y;
  if (pinto2 < 0){
    pinto2 += y;
  }
  if (pinto2 == 0){
    printf("2 %d", pinto1);
    break;
  }

  }


  return 0;
}


int vepontos(char str[3]){
int dez = (str[1] - '0')* 10;
int uni = str[2] - '0';
int num = dez + uni;
if (str[0] == 'S')  {
  num = num;
}
if (str[0] == 'D')  {
  num = num*2;
}
if (str[0] == 'T')  {
  num = num*3;
}
if (str[0] == 'X')  {
  num = num*0;
}
if (str[0] == 'M')  {
  num = num*25;
}

return num;
}
