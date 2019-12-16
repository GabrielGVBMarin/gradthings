// Gabriel Guimarães Vilas Boas Marin 11218521
#include <biblio.h>

// LE A STRING ALOCANDO DINAMICAMENTE
char *leString()  {
  char *string = NULL;
  int i = 0;
  do {
    string = (char*) realloc(string, (i+1)*sizeof(char));
    scanf("%c", &string[i]);
  } while(string[i] != '\n' && string[i] != ' '  && (i = i + 1));
  string[i] = '\0';

  return string;
}

// CRIA UM NOVO ARRAYLIST
ArrayList *new_arrayList()  {

  ArrayList *list = (ArrayList*) calloc(1, sizeof(ArrayList));

  return list;

}

// ADICIONA UM NOVO ELEMENTO, INDEPENDENTE DA SITUAÇÃO DO ARRAYLIST
int add_arrayList(ArrayList *arrayList, int *element, int *key)  {
  if (!arrayList) return INVALID_ARRAYLIST;

  if (!arrayList->begin) {
    NO *start = (NO*) calloc(1, sizeof(NO));
    start->list = (int**) calloc(2, sizeof(int*));
    start->list[0] = (int*) calloc(10, sizeof(int));
    start->list[1] = (int*) calloc(10, sizeof(int));
    start->next = NULL;
    start->globalBeginIndex = 0;
    start->fimvet = 0;
    start->length = 10;
    arrayList->begin = start;
  }

  NO *pointer = arrayList->begin;
  int whereNextBegin = 0;
  while(pointer->next)  {
    whereNextBegin = whereNextBegin + pointer->length;
    pointer = pointer->next;
  }
  pointer->globalBeginIndex = whereNextBegin;

  if (pointer->fimvet == pointer->length) {
    NO *new = (NO*) calloc(1, sizeof(NO));
    new->list = (int**) calloc(2, sizeof(int*));
    new->list[0] = (int*) calloc((pointer->length*2), sizeof(int*));
    new->list[1] = (int*) calloc((pointer->length*2), sizeof(int*));
    new->globalBeginIndex = pointer->globalBeginIndex + pointer->length;
    new->length = (pointer->length*2);
    pointer = pointer->next = new;
  }
  pointer->list[0][pointer->fimvet] = *key;
  pointer->list[1][pointer->fimvet] = *element;
  pointer->fimvet++;

  return 1;

}

// PROCURA SE UM ELEMENTO POSSUI A CHAVE INFORMADA
int contains_arrayList(ArrayList *arrayList, int chave) {
  if (!arrayList) return INVALID_ARRAYLIST;

  int i;
  NO *pointer = arrayList->begin;

  do {
    for (i = 0; i < pointer->fimvet; i++) {
      if (pointer->list[0][i] == chave) {
        return 1;
      }
    }
  } while(pointer->next && (pointer = pointer->next));

  return 0;

}

// VAI NA POSIÇÃO PASSADA E PRINTA A CHAVE E O ELEMENTO
int get_arrayList(ArrayList *arrayList, int pos)  {

  NO *pointer = arrayList->begin;

  while (pos > pointer->length && pointer->next)  {
    pos = pos - pointer->length;
    pointer = pointer->next;
  }

  if (pos > pointer->length || pos > pointer->fimvet)  {
    return INVALID_POS;
  } else  {
    printf("%d/%d\n", pointer->list[0][pos], pointer->list[1][pos]);
  }
  return SUCCESS;

}

// PROCURA O ELEMENTO COM A CHAVE E RETORNA SUA POSIÇÃO
int indexOf_arrayList(ArrayList *arrayList, int chave)  {
  if (!arrayList) return INVALID_ARRAYLIST;

  int i, aux = 0;
  NO *pointer = arrayList->begin;

  do {
    for (i = 0; i < pointer->fimvet; i++, aux++) {
      if (pointer->list[0][i] == chave) {
        return aux;
      }
    }
  } while(pointer->next && (pointer = pointer->next));

  return INVALID_POS;

}

// VERIFICA SE O ARRAYLIST ESTÁ VAZIO
int isEmpty_arrayList(ArrayList *arrayList) {

  if (arrayList->begin == NULL)
  return 1;
  else if (arrayList->begin->fimvet == 0) return 1;

  return 0;

}

// REMOVE O ELEMENTO DA POSIÇÃO PASSADA E LIBERA O ESPAÇO
int remove_arrayList(ArrayList **arrayList, int pos) {

  NO *pointer = (*arrayList)->begin;
  int i, aux = 0;

  do {
    for (i = 0; i < pointer->fimvet; i++, aux++) {
      if (aux == pos) {

        pointer->list[0][i] = -1;

        aux = aux - i + 1;
        do {
          aux = aux + pointer->fimvet;
        } while(pointer->next && (pointer = pointer->next));

        *arrayList = subArray_arrayList((*arrayList), 1, aux+1);

        return SUCCESS;
      }
    }
  } while(pointer->next && (pointer = pointer->next));

  return INVALID_POS;

}

// ALTERA OS VALORES DO ELEMENTO E CHAVE DA POSIÇÃO INFORMADA
int set_arrayList(ArrayList *arrayList, int pos, int *element, int *key) {
  if (!arrayList) return INVALID_ARRAYLIST;
  //altera os valroes de chave e valor na posicao pos
  NO *pointer = arrayList->begin;
  int aux = 0, i;
  do {
    for (i = 0; i < pointer->fimvet; i++, aux++) {
      if (aux == pos) {
        pointer->list[0][i] = *key;
        pointer->list[1][i] = *element;
        return 0;
      }
    }
  } while(pointer->next && (pointer = pointer->next));

  return INVALID_POS;

}

// INFORMA O TAMANHO DA ARRAYLIST
int size_arrayList(ArrayList *arrayList)  {
  int size = 0;
  NO *pointer = arrayList->begin;

  do {
    size = size + pointer->fimvet;
  } while(pointer->next && (pointer = pointer->next));

  return size;
}

// CRIA OUTRO ARRAYLIST CONTENDO OS DADOS DO INTERVALO SELECIONADO
ArrayList *subArray_arrayList(ArrayList *arrayList, int beginIndex, int endIndex) {
  if (!arrayList) return NULL;
  if (beginIndex > endIndex) return NULL;

  sort_arrayList(arrayList);

  ArrayList *new = (ArrayList*) calloc(1, sizeof(ArrayList));
  NO *pointer = arrayList->begin;
  int index = 0, j;

  do {
    for (j = 0; j < pointer->fimvet; j++, index++)  {
      if (index >= beginIndex && index < endIndex)  {
        add_arrayList(new, &pointer->list[1][j], &pointer->list[0][j]);
      }
    }
  } while(index < endIndex && pointer->next && (pointer = pointer->next));

  return new;

}

// DA FREE NO ARRAYLIST
int free_arrayList(ArrayList *arrayList) {
  if (!arrayList->begin) return INVALID_ARRAYLIST;

  NO *pointer = arrayList->begin;

  do {
    arrayList->begin = pointer->next;
    free(pointer->list[0]);
    free(pointer->list[1]);
    free(pointer->list);
    free(pointer);
  } while(arrayList->begin && (pointer = arrayList->begin));

  free(arrayList);

  return 1;
}

// PRINTA OS INDICES, CHAVES E ELEMENTOS DO ARRAYLIST INTEIRO
void print_arrayList(ArrayList *arrayList)  {

  NO *pointer = arrayList->begin;
  int i, aux = 0;

  do {
    for (i = 0; i < pointer->fimvet; i++, aux++) {
      printf("%d: %d/%d\n", aux, pointer->list[0][i], pointer->list[1][i]);
    }
    printf("\n\n");
  } while(pointer->next && (pointer = pointer->next));


}

// ORDENA TODO O ARRAYLIST COM INSERTION SORT
int sort_arrayList(ArrayList *arrayList) {
  if (!arrayList) return INVALID_ARRAYLIST;
  // ordenar elementos pela chave
  NO *pointer = arrayList->begin;
  int aux = 0, auxKey, i, j, size  = size_arrayList(arrayList);;
  int *vetor = (int*) malloc(size*sizeof(int));
  int *keys = (int*) malloc(size*sizeof(int));

  do {
    for (i = 0; i < pointer->fimvet; i++, aux++)  {
      keys[aux] = pointer->list[0][i];
      vetor[aux] = pointer->list[1][i];
    }
  } while(pointer->next && (pointer = pointer->next));

  // Insertion Sort
  for ( i = 1; i < size; i++) {
    aux = vetor[i];
    auxKey = keys[i];
    j = i - 1;
    while (j >= 0 && keys[j] > auxKey) {
      vetor[j+1] = vetor[j];
      keys[j+1] = keys[j];
      j--;
    }
    keys[j+1] = auxKey;
    vetor[j+1] = aux;
  }

  pointer = arrayList->begin;
  aux = 0;

  do {
    for (i = 0; i < pointer->fimvet; i++, aux++) {
      pointer->list[0][i] = keys[aux];
      pointer->list[1][i] = vetor[aux];
    }
  } while(pointer->next && (pointer = pointer->next));

  return SUCCESS;

}
