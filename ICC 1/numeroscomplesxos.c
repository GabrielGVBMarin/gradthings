#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  float imaginario;
  float real;
} tComplexo;

tComplexo soma(tComplexo c1, tComplexo c2);
tComplexo dividir(tComplexo c1, tComplexo c2);
void mult(tComplexo c1, tComplexo c2, tComplexo *c3);
void printa_result(tComplexo);

int main()  {

  int opt = 24;
  tComplexo vetor1, vetor2, result;
  //vetor = (tComplexo*) malloc(1*sizeof(tComplexo));

  while(opt)  {
    scanf("%d", &opt);
    switch (opt) {
      case 0:
      break;
      case 1:
      scanf("%f %f", &vetor1.real, &vetor1.imaginario);
      scanf("%f %f", &vetor2.real, &vetor2.imaginario);

      result = soma(vetor1, vetor2);
      break;
      case 2:
      scanf("%f %f", &vetor1.real, &vetor1.imaginario);
      scanf("%f %f", &vetor2.real, &vetor2.imaginario);

      result = dividir(vetor1, vetor2);
      break;
      case 3:
      scanf("%f %f", &vetor1.real, &vetor1.imaginario);
      scanf("%f %f", &vetor2.real, &vetor2.imaginario);

      mult(vetor1, vetor2, &result);

      break;
      case 4:
      printa_result(result);
      break;
    }
  }

  return 0;
}

tComplexo soma(tComplexo c1, tComplexo c2) {

  tComplexo resultado;
  resultado.real = c1.real + c2.real;
  resultado.imaginario = c1.imaginario + c2.imaginario;

  return resultado;
}

tComplexo dividir(tComplexo c1, tComplexo c2)  {

  tComplexo resultado;
  resultado.real = (c1.real*c2.real + c1.imaginario*c2.imaginario)/(c2.real*c2.real + c2.imaginario*c2.imaginario);
  resultado.imaginario = (c1.imaginario*c2.real - c1.real*c2.imaginario)/(c2.real*c2.real + c2.imaginario*c2.imaginario);

  return resultado;
}

void mult(tComplexo c1, tComplexo c2, tComplexo *c3)  {

  c3->real = (c1.real*c2.real) - (c1.imaginario*c2.imaginario);
  c3->imaginario = (c1.real*c2.imaginario) + (c1.imaginario*c2.real);

}

void printa_result(tComplexo c){
    printf("%.2f", c.real);
    if (c.imaginario >= 0){
        printf("+");
    }
    printf("%.2fi\n", c.imaginario);
}
