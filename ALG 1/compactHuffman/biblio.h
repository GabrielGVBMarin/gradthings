#ifndef _BIBLIO_H_
#define _BIBLIO_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define TAM 400

struct node {
  int symbol, freq;
  struct node *left, *right, *dad;
};
typedef struct node NODE;

struct heap {
	struct node **array;
	int end;
};
typedef struct heap HEAP;

/******************* HUFFMAN HEADER ****************/

struct binarie_tree {
	struct node *root;
};
typedef struct binarie_tree BINARIE_TREE;

struct huffman_table {
	struct binarie_tree *tree;
	char **code;
};
typedef struct huffman_table HUFFMAN_TABLE;

HEAP* heapCreate();
int full(HEAP*);
int empty(HEAP*);
int queue(HEAP*, NODE*);
NODE* dequeue(HEAP*);
int size(HEAP*);

/************* HUFFMAN *********************/

HUFFMAN_TABLE* huffmanCreate();
int huffmanCompact(char*, char**, HUFFMAN_TABLE**);
char* huffmanDescompact(char*, int, HUFFMAN_TABLE*);
void freeTree(BINARIE_TREE**);
void freeHuffman(HUFFMAN_TABLE**);

#endif
