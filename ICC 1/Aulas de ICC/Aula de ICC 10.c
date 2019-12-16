#include <stdio.h>
#include <stdlib.h>

int main()  {

  typedef struct  {
    tipo1 campo1;
    tipo2 campo2;
    ... ...;
    tipon campon;
  } nome_do_registro;
  // mesma coisa que
  struct regaluno {
    char numUSP[10];
    char nome[30];
    char sexo;
    float renda_familiar;
    struct regaluno aluno; //DA PAU ISSO AQUI
    struct regaluno *aluno; //ESSE N DA PAU, PONTEIRO PRA OUTRA STRUCT, BAGULHO DE LISTAS E PA
    struct tipo_endereco endereco; // Posso criar uma estrutura dentro de outra, se for diferente n precisa de PONTEIRO

  };

  return 0;
}
void ler(REG *dados)  { // como dados eh um ponteriro no lugar do . coloca -> pra acessar o dado requisitado;
  dados->nome = "felipe" //vai la e pega o nome do bagui dados la e faz os bang;
}
