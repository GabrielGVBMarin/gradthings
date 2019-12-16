#include <stdio.h>
#include <stdlib.h>
#include <biblio.h>

// NUMERO SEPARADO POR BLOCOS 10X10
//  -------------------------
//  |       |       |       |
//  |------------------------     O QUE É FEITO AQUI SERÁ PEGAR A ÁREA DO NUMERO,
//  |       |       |       |     EM SEGUIDA IREMOS ANALISAR OS QUADRANTES SEPARADOS
//  |------------------------     EM 10X10, IDENTIFICANDO OS BLOCOS PREENCHIDOS COM 1
//  |       |       |       |     E COM 0. A PARTIR DISSO, IREMOS CHECAR AS COMBINAÇÕES
//  |------------------------     DOS QUADRANTES PREENCHIDOS E DESCOBRIR QUAL NÚMERO ESTA
//  |       |       |       |     NAQUELA POSIÇÃO. POR FIM, O NÚMERO SERA ADICIONADO EM UMA
//  |------------------------     STRING, FORMANDO DE 1 EM 1 A SAIDA ESPERADA :D
//  |       |       |       |
//  -------------------------


int main(int argc, char **argv)  {

  // DECLARANDO O ARQUIVO | STRING DOS NUMEROS | MATRIZ DA IMAGEM | TAMANHO DA IMAGEM
  FILE *arq;
  char *nome = NULL, *numerosIdentificados = NULL;
  int **imagem, height = 0, width = 0;

  // LENDO O NOME DO ARQUIVO NO STDIN
  nome = leNomeArquivo();
  // ABRINDO O ARQUIVO
  arq = fopen(nome, "r");

  // LENDO O ARQUIVO DE IMAGEM E RETORNANDO A MATRIZ PARA PEGARMOS OS NUMEROS POSTERIORMENTE
  imagem = leImagem(arq, &height, &width);
  // IDENTIFICA OS NUMEROS NA MATRIZ E RETORNA UMA STRING CONTENDO OS NUMEROS ENCONTRADOS
  numerosIdentificados = leNumerosNaImagem(imagem, height, width);

  // PRINTA A STRING FINAL
  printf("%s", numerosIdentificados);

  return 0;
}
