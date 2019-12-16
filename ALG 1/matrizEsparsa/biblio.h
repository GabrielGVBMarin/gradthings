// Gabriel Guimarães Vilas Boas Marin 11218521
#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DEFINES PARA ERROS
#define SUCCESS			0
#define INVALID_SPARSE	-1
#define INVALID_POS		-2
#define NOT_FOUND		-3
#define INVALID_COMPLEX_SPARSE -4

// ELEMENTO
struct complex_sparse_elem {
	int row, col;
	double elem;
	struct complex_sparse_elem *right, *bottom;
};

// MATRIZ
struct complex_sparse {
	int nrows, ncols;
	double constant;
	struct complex_sparse_elem **row_index, **col_index;
};

typedef struct complex_sparse COMPLEX_SPARSE;
typedef struct complex_sparse_elem COMPLEX_SPARSE_ELEM;

COMPLEX_SPARSE* createSparse(int, int, double);
int putSparse(COMPLEX_SPARSE* , int, int, double);
double getSparse(COMPLEX_SPARSE* , int, int);
int removeSparse(COMPLEX_SPARSE*, int, int);
int freeSparse(COMPLEX_SPARSE*);
double addSparse(COMPLEX_SPARSE*, double, int, int);
COMPLEX_SPARSE* multiplySparse(COMPLEX_SPARSE*, COMPLEX_SPARSE*);
void plusSparse(COMPLEX_SPARSE*, COMPLEX_SPARSE*);
void printSparse(COMPLEX_SPARSE*);
int complex_sparse_free(COMPLEX_SPARSE*);

#endif
