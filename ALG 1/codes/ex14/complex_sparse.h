#ifndef _COMPLEX_SPARSE_H_
#define _COMPLEX_SPARSE_H_

#define SUCCESS			0
#define INVALID_COMPLEX_SPARSE	-1
#define INVALID_POS		-2
#define NOT_FOUND		-3

struct complex_sparse_elem {
	int row, col;
	double elem;
	struct complex_sparse_elem *right, *bottom;
};

struct complex_sparse {
	int nrows, ncols;
	double constant;
	struct complex_sparse_elem **row_index, **col_index;
};

typedef struct complex_sparse COMPLEX_SPARSE;
typedef struct complex_sparse_elem COMPLEX_SPARSE_ELEM;

COMPLEX_SPARSE *complex_sparse_create(int, int, double);
int complex_sparse_put(COMPLEX_SPARSE *, int, int, double);
double complex_sparse_get(COMPLEX_SPARSE *, int, int, int *);
int complex_sparse_remove(COMPLEX_SPARSE *, int, int);
int complex_sparse_free(COMPLEX_SPARSE *);

#endif
