#include <stdio.h>

int main()  {
  float x;
  int *var; // uma variavel com ponteiro indica a memoria em que a variavel esta
  // independente de ser float ou int ocupa o mesmo espaço de memoria\
  var = &x; // para que o endereco do ponteiro var receba o valor de x

  void swap(int*, int*);
  int j,k;
  swap(&j, &k); // passa o endereço de memoria para a função no bagui ai ja muda na hora



  return 0;
}
