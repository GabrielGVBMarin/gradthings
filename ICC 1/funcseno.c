#include <stdio.h>
#include <math.h>
#include <string.h>

long double fatorial();
long double potencia();

int main()  {

long double x=0, k = 0;
int quants = 0;

scanf("%lf", &x);
scanf("%d", &quants);
 k = x;
 for( int n = 0; n < quants; n++) {

k = n*fatorial(n - 1);

 }
potencia();



  return 0;
}

long double fatorial (int fator)  {

  

}

long double potencia() {





}
