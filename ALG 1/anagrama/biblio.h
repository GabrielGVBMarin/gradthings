// Gabriel Guimarães Vilas Boas Marin NUSP: 11218521
#ifndef _BIBLIO_H_
#define _BIBLIO_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define P1 2
#define P2 3
#define P3 5
#define P4 7
#define P5 11
#define P6 13
#define P7 17
#define P8 19
#define P9 23
#define P10 29
#define P11 31
#define P12 37
#define P13 41
#define P14 43
#define P15 47
#define P16 53
#define P17 59
#define P18 61
#define P19 67
#define P20 71
#define P21 73
#define P22 79
#define P23 83
#define P24 89
#define P25 97
#define P26 101
#define REST 50000

// NODE DA HASH
struct node {
  char **palavra;
  unsigned int key;
  unsigned char quantidade;
  struct node *next;
};
typedef struct node NODE;

// DESCRITOR DA HASH
struct hashHeader {
  struct node **vetor;
  int quantasVezesMaisRepete, quantosMaioresRepetidoresTem, counter;
};
typedef struct hashHeader HASH;

// FUNÇÕES
char* leStringsAlocaDin();
HASH* hashCreate();
unsigned int keyGerador(char*);
int anagramCompare(char*, char*);
void printAnagramas(NODE*);
void printMaisRepetidas(HASH*);
void addPalavra(HASH*, char*);
void sortWords(char**, int);
void nodeSort(NODE**, int);
void freeAll(HASH*);

#endif
