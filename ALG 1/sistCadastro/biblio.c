#include <biblio.h>
#include <stdio.h>
#include <stdlib.h>

// Gabriel Guimarães Vilas Boas Marin NUSP: 11218521

// ALOCA DINAMICAMENTE A OPERAÇÃO A SER FEITA
char leOperation() {
  int i = 0;
  char *read = NULL;

  do {

    read = (char*) realloc(read, (i+1)*sizeof(char));
    scanf("%c", &read[i]);
    if ( read[i] == ' ')  {
      read[i] = '\n';
    }

  } while( read[i] != '\n' && (i = i + 1));

  read[i] = '\0';

  return read[0];
}

// LE STRINGS ALOCANDO DINAMICAMENTE
char* leStringsAlocaDin() {
  int i = 0;
  char *read = NULL;

  do {

    read = (char*) realloc(read, (i+1)*sizeof(char));
    scanf("%c", &read[i]);

  } while( read[i] != '\n' && (i = i + 1));

  read[i] = '\0';

  return read;
}

// FAZ UM CADASTRO DE UMA NOVA PESSOA
void makeCadastro(MENU *List) {

  CADASTRO *new = (CADASTRO*) calloc(1, sizeof(CADASTRO));
  CADASTRO **p = &List->last;

  // RECEBENDO A ENTRADA DA NOVA PESSOA
  new->firstName = leStringsAlocaDin();
  new->lastName = leStringsAlocaDin();
  scanf("%ld\n", &new->CPF);
  new->telefone = leStringsAlocaDin();
  new->next = NULL; new->prev = NULL;

  // VERIFICA SE EH O 1 DA LISTA
  if (List->counter == 0) {

    List->first = new;
    List->last = new;
    (*p) = new;
    List->counter++;

  } else  {

    new->prev = (*p)->prev;
    new->next = (*p);
    (*p)->prev = new;
    (*p) = new;
    List->last = new;
    List->counter++;

  }

}

// BUSCA O CPF DE ALGUMA PESSOA SE EXISTIR CADASTRADA
void buscaCPF(MENU *List)  {

  long int buscado;
  int contador = 0;
  CADASTRO **p = &List->last;

  scanf("%ld", &buscado);

  // RODA A LISTA TODA, COMPARANDO O CPF BUSCADO COM OS EXISTENTES
  while (contador < List->counter) {
    // QUANDO ENCONTRA, PRINTA A PESSOA ATUAL E SAI DO WHILE
    if ((*p)->CPF == buscado) {
      printf("Primeiro Nome: %s\n", (*p)->firstName);
      printf("Ultimo Nome: %s\n", (*p)->lastName);
      printf("CPF: %011ld\n", (*p)->CPF);
      printf("Telefone: %s\n", (*p)->telefone);
      printf("-----------------------------\n");
      break;
    } else  {
      p = &(*p)->next;
      contador++;
    }
  }
}

// PRINTA TODOS OS CADASTROS EXISTENTES
void makeDump(MENU *List)  {
  if (List->counter == 0) {
    printf("\n\nERRO, NENHUM ITEM EXISTENTE\n\n");
  }

  CADASTRO **p = &List->first;
  int contador = 0;

  // VAI PRINTANDO AS PESSOAS E MUDANDO O PONTEIRO PRA PROXIMA PESSOA
  do {
    printf("Primeiro Nome: %s\n", (*p)->firstName);
    printf("Ultimo Nome: %s\n", (*p)->lastName);
    printf("CPF: %011ld\n", (*p)->CPF);
    printf("Telefone: %s\n", (*p)->telefone);
    printf("-----------------------------\n");
    contador++;
  } while(contador < List->counter && (p = &(*p)->prev));

}

// REMOVE ALGUM CADASTRO ESPECIFICO
void makeRemove(MENU *List) {

  CADASTRO *p = List->first;
  long int buscado;
  int contador = 0;

  scanf("%ld", &buscado);

  // REALOCA OS PONTEIROS PRA MANTER A LINEARIDADE DA LISTA
  // E DA FREE NO ITEM REMOVIDO
  do {
    if (p->CPF == buscado) {
      if (p->prev)
    		p->prev->next = p->next;
    	else
    		List->last = p->next;

    	if (p->next)
    		p->next->prev = p->prev;
    	else
    		List->first = p->prev;
        List->counter--;
        free(p);
        break;
      }
      contador++;

    } while (contador < List->counter && (p = p->prev));


}

// DA FREE EM TUDO
int exitProgram(MENU *List)  {

  CADASTRO *p = List->last;

  // DA FREE NA PESSOA ANTERIOR E VAI PRA PROXIMA
  // ATÉ CHEGAR NA UNICA EXISTENTE
  while (p->next != NULL)  {
    p = p->next;
    free(p->prev);
  }
  // DA FREE NA ULTIMA PESSOA
  free(p);

  return 1;
}
