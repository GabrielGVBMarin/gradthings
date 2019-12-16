#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

//valdemar vc eh mt legal
//Luan vc tb, n fica com ciumes do valdemar
//moça monitora, vc tb eh mt legal

void muda(char*, char*);
char *sobrenome(char*);
char **pega_nomes(int*);

int main(void) {
  int tamanho, i;
  char **nomes = NULL;

  nomes = pega_nomes(&tamanho);

  if(tamanho%2 == 0){
    for(i=0;i<tamanho;i+=2)
      muda(nomes[i], nomes[i+1]);
  }

  else  {
    for(i=0;i<tamanho-1;i+=2)
      muda(nomes[i], nomes[i+1]);
  }

  for(i=0; i<tamanho;i++){
    printf("%s\n", nomes[i]);
  }

  free(nomes);
  return 0;
}

char **pega_nomes(int *tamanho) {
  char letra, **nomes=NULL;
  int numero_letras = 0, quantidade_nomes = 1;
  letra = getchar();
  while(letra != '$'){
    numero_letras++;
    nomes = (char**)  realloc(nomes, quantidade_nomes*sizeof(char*));
    nomes[quantidade_nomes-1] = (char*) realloc(nomes[quantidade_nomes-1], numero_letras*sizeof(char));
    if((int)letra == 10)  {
      nomes[quantidade_nomes-1][numero_letras-1] = '\0';
      quantidade_nomes++;
      numero_letras = 0;
    }
    else {
      nomes[quantidade_nomes-1][numero_letras-1] = letra;
    }
    letra = getchar();
  }
  nomes[quantidade_nomes-1] = (char*) realloc(nomes[quantidade_nomes-1], numero_letras+1*sizeof(char));
  nomes[quantidade_nomes-1][numero_letras] = '\0';
  *tamanho = quantidade_nomes;
  return nomes;
}

char *sobrenome(char *nome){
    char *sobrenome = NULL;
    int i, tamanho;

    tamanho = strlen(nome);

    for( i=tamanho-1; i>= 0; i--){
        if(nome[i] == ' '){
            sobrenome = &nome[i+1];
            break;
        }
    }
    return sobrenome;
}

void muda(char *comeco, char *dest){
    char *sobnomeorigem = sobrenome(comeco);
    strcat(dest, " ");
    strcat(dest, sobnomeorigem);
}
