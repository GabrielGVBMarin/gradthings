#ifndef _BIBLIO_
#define _BIBLIO_

#include <stdio.h>
#include <stdlib.h>

// Gabriel Guimarães Vilas Boas Marin NUSP: 11218521

typedef struct cadastro CADASTRO;

typedef struct menu MENU;

// LISTA
struct menu {
  CADASTRO *first;
  CADASTRO *last;
  int counter;
};

// ESTRUTURA DA PESSOA
struct cadastro {
  char *firstName;
  char *lastName;
  long int CPF;
  char *telefone;
  CADASTRO *next;
  CADASTRO *prev;
};

// FUNÇÕES
char leOperation();
char* leStringsAlocaDin();
void makeCadastro(MENU*);
void buscaCPF(MENU*);
void makeDump(MENU*);
void makeRemove(MENU*);
int exitProgram(MENU*);

#endif
