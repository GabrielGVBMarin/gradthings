#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <omp.h>

typedef struct {
  int nfilhos;
  float salario;
} dados;
typedef struct  {
  char nome[100];
  int idade;
  dados outros;
} reg;

reg *cadastro(int*);
reg pDados();
void imprimeDados(reg*);

int main()  {

  reg *cadReg;
  int size;

  cadReg = cadastro(&size);

  for ( int i = 0; i < size; i++) {
    imprimeDados(&cadReg[i]);
  }

  return 0;
}

reg *cadastro(int *tam)  {

  int flag;
  reg *vReg;
  vReg = NULL;
  *tam = 0;
  printf("Digite 0 para sair: "); scanf("%d", &flag);
  while (flag)  {
    *tam += 1;
    vReg = (reg*) realloc(vReg, (*tam)*sizeof(reg));
    vReg[*tam-1] = pDados();
    imprimeDados(&vReg[*tam-1]);
    printf("\n\nDigite 0 para sair: "); scanf("%d", &flag);
  }
  return vReg;
}

reg pDados()  {

  reg cadTemp;
  printf("\nNome: "); scanf(" %[a-z A-Z]s", cadTemp.nome);
  printf("\nIdade: "); scanf("%d", &cadTemp.idade);
  printf("\nNumero de filhos: "); scanf(" %d", &cadTemp.outros.nfilhos);
  printf("\nSalario: "); scanf(" %f", &cadTemp.outros.salario);

  return cadTemp;
}

void imprimeDados(reg *pRg) {

  printf("\n Nome: %s", pRg->nome);
  printf("\n Idade: %d", pRg->idade);
  printf("\n Numero de filhos: %d", pRg->outros.nfilhos);
  printf("\n Salario: %.2f\n", pRg->outros.salario);

}
