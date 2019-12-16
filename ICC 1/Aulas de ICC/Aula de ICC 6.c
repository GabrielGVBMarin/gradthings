#include <stdio.h>
#include <stdlib.h>

typedef unsigned int size_t; //cria um tipo de variavel, chamada positivo que sao so numeros possitivos por vir no usigned int

void *malloc(size_t size);

int main()  {
//func utilizadas para o uso de memoria dinamico
  malloc();
  calloc();
  realloc();
  free();

  int *num;
  num = (int*)malloc(50*sizeof(int));
  if ( num == NULL) {
    printf("Espaco insuficiente para alocar
    buffer \n");
    exit(1);
  }
  printf("espaco alocado para num \n");             // precisa marca um espaco de bits para o malloc alocar o que quer na memoria
  // portanto ele retorna 0 se n tiver espaco suficiente

  void * calloc(size_t num, size_t size); // o calloc zera o espaco de memoria, o que eh ruim quando se trata de algo muito grande
  // pois gasta mais processamento

  void * realloc(void * ptr, size_t size); // ele expande ou diminui o tamanho do vetor

  free();//libera um espaco de memoria previamente alocado que agr n necessita mais usar aqueles dados
  //ja que com o malloc que eh criado dentro da func ele nao elimina a memoria na memoria ao sair da func 

  return 0;
}
