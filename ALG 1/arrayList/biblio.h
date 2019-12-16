// Gabriel Guimarães Vilas Boas Marin 11218521
#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

// #include "item.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define INVALID_ARRAYLIST -4
#define INVALID_POS -3

typedef struct NO {
  int **list;//lista interna de void
  int globalBeginIndex;
  int fimvet;//tamanho ocupado na lista
  int length;//tamanho da lista interna
  struct NO *next;
} NO;

struct ArrayList{
  NO *begin;
};
typedef struct ArrayList ArrayList;

//Cria a ArrayList e aloca toda memória necessaria
ArrayList *new_arrayList();
//adiciona elemento ao arraylist
int add_arrayList(ArrayList *arrayList, int *element, int *key);
//verifica no arraylist se existe um elemento com a chave informada
int contains_arrayList(ArrayList *arrayList, int chave);
//recupera um int na posicao informada
int get_arrayList(ArrayList *arrayList, int pos);
//retorna qual a posicao do primeiro elemento com a chave informada
int indexOf_arrayList(ArrayList *arrayList, int chave);
//verifica se o arraylist esta vazio
int isEmpty_arrayList(ArrayList *arrayList);
//remove um elemento do arraylist
int remove_arrayList(ArrayList **arrayList, int pos);
//modifica um elemento do arraylist
int set_arrayList(ArrayList *arrayList, int pos, int *element, int*);
//retorna o tamanho total do arraylist
int size_arrayList(ArrayList *arrayList);
//recupera um novo subarray no intervalo [beginIndex, endIndex[
ArrayList *subArray_arrayList(ArrayList *arrayList, int beginIndex, int endIndex);
// desaloca memoria alocada pelo arraylist
int free_arrayList(ArrayList *arrayList);
//imprime toda a lista
void print_arrayList(ArrayList *arrayList);
// minhas funcoes :D
char *leString();
int sort_arrayList(ArrayList*);
#endif
