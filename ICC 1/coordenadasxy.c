#include <stdio.h>
#include <math.h>
#include <string.h>



int main()  {

double comp = 0, ang, angsen, angcos, vety,vetx;

scanf("%lf", &comp);
scanf("%lf", &ang);

angsen = sin(ang);
angcos = cos(ang);

vety = comp*angsen;
vetx = comp*angcos;

printf("%.2lf 0.00\n", vetx);
printf("0.00 %.2lf", vety);




  return 0;
}
