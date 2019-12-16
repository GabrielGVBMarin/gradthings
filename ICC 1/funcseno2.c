#include <stdio.h>
#include <math.h>
#include <string.h>

double fatorial(double);
double potencia(double, double);

int main()  {

double x=0, result, quants, add;

scanf("%lf", &x);
scanf("%lf", &quants);

result = x;

for ( int i = 0, k = 3; i < quants; i++, k+=2) {

add = potencia(k, x)/fatorial(k);
if ( (i+1)%2 != 0)  {
  add = add*(-1);
}
result = result + add;

}

printf("%lf", result);

  return 0;
}

double fatorial (double quants)  {
  double cont;
  for(cont = 1; quants > 1; quants--)  {

      cont = cont * quants;
  }

  return cont;
}

double potencia(double pot, double num) {
  double res;
  res = pow(num,pot);
  return res;
}
