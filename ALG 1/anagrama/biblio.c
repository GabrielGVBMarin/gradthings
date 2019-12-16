// Gabriel Guimarães Vilas Boas Marin NUSP: 11218521
#include <biblio.h>

// LE STRING ALOCANDO DINAMICAMENTE
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

// FAZ A ALOCAÇÃO DINÂMICA DA HASH
HASH* hashCreate()  {

  HASH *hash = (HASH*) calloc(1, sizeof(HASH));
  hash->vetor = (NODE**) calloc(REST, sizeof(NODE*));
  hash->quantasVezesMaisRepete = 1;

  return hash;

}

// GERA UMA CHAVE DE ACORDO COM A STRING PASSADA
unsigned int keyGerador(char *palavra)  {

  unsigned char i;
  unsigned int key = 1;

  for (i = 0; i < strlen(palavra); i++)  {
    switch (palavra[i]) {
      case 'a':
        key = key*P1;
      break;
      case 'b':
        key = key*P2;
      break;
      case 'c':
        key = key*P3;
      break;
      case 'd':
        key = key*P4;
      break;
      case 'e':
        key = key*P5;
      break;
      case 'f':
        key = key*P6;
      break;
      case 'g':
        key = key*P7;
      break;
      case 'h':
        key = key*P8;
      break;
      case 'i':
        key = key*P9;
      break;
      case 'j':
        key = key*P10;
      break;
      case 'k':
        key = key*P11;
      break;
      case 'l':
        key = key*P12;
      break;
      case 'm':
        key = key*P13;
      break;
      case 'n':
        key = key*P14;
      break;
      case 'o':
        key = key*P15;
      break;
      case 'p':
        key = key*P16;
      break;
      case 'q':
        key = key*P17;
      break;
      case 'r':
        key = key*P18;
      break;
      case 's':
        key = key*P19;
      break;
      case 't':
        key = key*P20;
      break;
      case 'u':
        key = key*P21;
      break;
      case 'v':
        key = key*P22;
      break;
      case 'x':
        key = key*P23;
      break;
      case 'w':
        key = key*P24;
      break;
      case 'y':
        key = key*P25;
      break;
      case 'z':
        key = key*P26;
      break;
    }
  }

  return key;
}

// RECEBE 2 PALAVRAS E SE FOR ANAGRAMA RETORNA 1 SE N 0
int anagramCompare(char *palavra1, char *palavra2)  {

  int *alfabetoPalavra1 = (int*) calloc(26, sizeof(int));
  int *alfabetoPalavra2 = (int*) calloc(26, sizeof(int));
  int i, tamanho1 = strlen(palavra1), tamanho2 = strlen(palavra2);

  if (tamanho1 != tamanho2) return 0;

  for (i = 0; i < tamanho1; i++)  {
    alfabetoPalavra1[((int)palavra1[i])-97]++;
  }

  for (i = 0; i < tamanho2; i++)  {
    alfabetoPalavra2[((int)palavra2[i])-97]++;
  }

  // SE OS 2 VETORES FOREM IGUAIS É ANAGRAMA
  for (i = 0; i < 26; i++)  {
    if (alfabetoPalavra1[i] != alfabetoPalavra2[i]) {
      free(alfabetoPalavra1);
      free(alfabetoPalavra2);
      return 0;
    }
  }

  free(alfabetoPalavra1);
  free(alfabetoPalavra2);
  return 1;
}

// ADICIONA A PALAVRA NA HASH PASSADA COMO REFERENCIA
void addPalavra(HASH *hash, char *palavra) {

  int palavraTamanho = strlen(palavra);
  unsigned int theKey = keyGerador(palavra);
  unsigned int place = (unsigned int) theKey%REST;


  if (hash->vetor[place] == NULL) {

    NODE *new = (NODE*) calloc(1, sizeof(NODE));
    new->palavra = (char**) malloc(1*sizeof(char*));
    new->palavra[0] = (char*) malloc(palavraTamanho*sizeof(char));
    strcpy(new->palavra[0], palavra);
    new->key = theKey;
    new->quantidade++;

    hash->vetor[place] = new;

  } else if (anagramCompare(hash->vetor[place]->palavra[0], palavra)) {

    NODE *pointer = hash->vetor[place];

    pointer->quantidade++;
    pointer->palavra = (char**) realloc(pointer->palavra, pointer->quantidade*sizeof(char*));
    pointer->palavra[pointer->quantidade-1] = (char*) malloc(palavraTamanho*sizeof(char));
    strcpy(pointer->palavra[pointer->quantidade-1], palavra);

    // ATUALIZA VARIAVEIS PARA PRINTAR SÓ AS MAIS REPETIDAS
    if (pointer->quantidade > hash->quantasVezesMaisRepete)  {
      hash->quantosMaioresRepetidoresTem = 1;
      hash->quantasVezesMaisRepete = pointer->quantidade;
    } else if (pointer->quantidade == hash->quantasVezesMaisRepete)  {
      hash->quantosMaioresRepetidoresTem++;
    }
  } else {

    NODE **pointer = &hash->vetor[place];

    while ((*pointer)->next && !anagramCompare((*pointer)->palavra[0], palavra)) pointer = &(*pointer)->next;

    if (anagramCompare((*pointer)->palavra[0], palavra))  {

      (*pointer)->quantidade++;

      (*pointer)->palavra = (char**) realloc((*pointer)->palavra, (*pointer)->quantidade*sizeof(char*));
      (*pointer)->palavra[(*pointer)->quantidade-1] = (char*) malloc(palavraTamanho*sizeof(char));
      strcpy((*pointer)->palavra[(*pointer)->quantidade-1], palavra);

      // ATUALIZA VARIAVEIS PARA PRINTAR SÓ AS MAIS REPETIDAS
      if ((*pointer)->quantidade > hash->quantasVezesMaisRepete)  {
        hash->quantosMaioresRepetidoresTem = 1;
        hash->quantasVezesMaisRepete = (*pointer)->quantidade;
      } else if ((*pointer)->quantidade == hash->quantasVezesMaisRepete)  {
        hash->quantosMaioresRepetidoresTem++;
      }

    } else  {

      NODE *new = (NODE*) calloc(1, sizeof(NODE));
      new->palavra = (char**) malloc(1*sizeof(char*));
      new->palavra[0] = (char*) malloc(palavraTamanho*sizeof(char));
      strcpy(new->palavra[0], palavra);
      new->key = theKey;
      new->quantidade++;

      (*pointer)->next = new;
    }

  }
}

// PRINTA OS ANAGRAMAS DO NODE PASSADO
void printAnagramas(NODE *anagrams)  {

  int i;
  for (i = 0; i < anagrams->quantidade-1; i++)  {
    printf("%s, ", anagrams->palavra[i]);
  }
  printf("%s", anagrams->palavra[i]);
  printf("\n");

}

// PRINTA AS PALAVRAS COM MAIS ANAGRAMAS
void printMaisRepetidas(HASH *hash) {

  NODE **dPointer = hash->vetor;
  NODE *pointer = NULL;
  NODE **printar = (NODE**) calloc(hash->quantosMaioresRepetidoresTem, sizeof(NODE*));
  int i, counter = 0;

  printf("%d\n", hash->quantosMaioresRepetidoresTem);
  for (i = 0; i < REST; i++)  {
    if (dPointer[i])  {
      pointer = dPointer[i];
      do {

        if (pointer->quantidade == hash->quantasVezesMaisRepete) {
          // PONTEIRO APONTA PARA AONDE VAI TER QUE PRINTAR
          printar[counter] = pointer;
          counter++;

        }
      } while(pointer->next && (pointer = pointer->next));
    }
  }

  // ORDENA OS NODES
  nodeSort(printar, hash->quantosMaioresRepetidoresTem);
  for (i = 0; i < hash->quantosMaioresRepetidoresTem; i++)  {
    // ORDENA A MATRIZ PRA PRINTAR
    sortWords(printar[i]->palavra, printar[i]->quantidade);
    printAnagramas(printar[i]);
  }

}

// DA FREE EM TUDO DA HASH
void freeAll(HASH* hash) {

  NODE *next, *auxNode;
  int i;

  for (i = 0; i < REST; i++)  {

    if (hash->vetor[i]) {

      next = hash->vetor[i]->next;
      while (next)  {
        auxNode = next->next;
        free(next->palavra);
        free(next);
        next = auxNode;
      }
      free(hash->vetor[i]->palavra);
      free(hash->vetor[i]);
    }

  }

  free(hash->vetor);
  free(hash);

}

// ORDENA A MATRIZ DE ANAGRAMAS https://stackoverflow.com/questions/44982737/sort-word-in-alphabet-order-in-c
void sortWords(char *words[], int count) {

    int i, j;
    char *x;

    for (i = 0; i<count; i++) {
        for (j = i + 1; j<count; j++) {
            if (strcmp(words[i], words[j]) > 0) {
                x = words[j];
                words[j] = words[i];
                words[i] = x;
            }
        }
    }

}

// ORDENA OS NODES PELA 1 PALAVRA
void nodeSort(NODE **pointer, int size) {

  int i, j;
  NODE *aux;

  for (i = 0; i < size; i++) {
      for (j = i + 1; j < size; j++) {
          if (strcmp(pointer[i]->palavra[0], pointer[j]->palavra[0]) > 0) {
              aux = pointer[j];
              pointer[j] = pointer[i];
              pointer[i] = aux;
          }
      }
  }

}
