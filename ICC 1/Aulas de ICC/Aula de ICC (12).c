#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

union real_ou_inteiro {
  double r;
  int i;
} carro;

typedef union {
  carro c;
  fruta f;
} fruta_ou_carro;

int main()  {

  #pragma omp parallel schedule (dynamic)
  {
  
  }



  return 0;
}
