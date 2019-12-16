#include <stdio.h>
#include <math.h>

void maior(char *numero, char*fs, int n); // Calcula o maior número
void imprime(char * numero, int n);  //imprime o maior número

int main()  {

  int quant;
  char core[100], f[9];

  scanf("%d\n", &quant);
  scanf("%s", &*core);
  for ( int i = 0; i < 9; i++)  {
    scanf("%c\n", &f[i]);
  }

  maior(core, f, quant);
  imprime(core, quant);

  return 0;
}

void maior(char *numero, char *fs, int quant) {
  for ( int i = 0; i < quant; i++)  {
    if ( numero[i] < fs[numero[i] - '0']) {
      numero[i] = fs[numero[i] - '0'];
      //printf("%c\n", numero[i]);
    }
  }

}

void imprime(char *numero, int quant)  {
  for ( int i = 0; i < quant; i++)  {
    printf("%c", numero[i]);
  }
}
