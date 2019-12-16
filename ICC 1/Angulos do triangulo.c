#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ehtriangle(int);
int tipo(int, int, int);

int main() {

int angulo[3], soma, ehoun;

for ( int i = 0; i < 3; i++)  {
  scanf("%d", &angulo[i]);
}
soma = angulo[0] + angulo[1] + angulo[2];
ehoun = ehtriangle(soma);
if (ehoun == 0) { return 0;}
switch (tipo(angulo[0], angulo[1], angulo[2])) {
  case 1: printf("Triangulo obtuso");
          break;
  case 2: printf("Triangulo agudo");
          break;
  case 3: printf("Triangulo retangulo");
          break;
}
  return 0;
}

int tipo(int ang1, int ang2, int ang3)  {
  if (ang1 > 90 || ang2 > 90 || ang3 > 90)  {
    return 1;
  }
  else if ( ang1 < 90 && ang2 < 90 && ang3 < 90)  {
    return 2;
  }
  else {  return 3; }
}

int ehtriangle(int soma) {

  if ( soma != 180)  {
    printf("Valores nao formam um triangulo");
    return 0;
  }
  else {
    return 1;
  }
}
