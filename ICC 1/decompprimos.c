#include <stdio.h>
#include <math.h>
#include <string.h>


int main()  {

int num = 0, set = 0;
double save = 0, fon = 0;
unsigned long int matpica[99999][2] = {0};

scanf("%d", &num);

fon = num/2;

//printf("\n%lf\n", fon);

for ( int i = 2; i < fon; i++)  {
  save = num%i;
  if ( save == 0 )  {
    num = num/i;
    matpica[i][0] = i;
    matpica[i][1]++;
    i--;
  }
}
for ( int j = 0; j < fon; j++) {
  if ( matpica[j][0] != 0 ) {
    printf("%ld %ld\n", matpica[j][0], matpica[j][1]);
    set = 1;
  }
}

if ( set == 0 ) {
  printf("%d 1", num);
}
return 0;
}
