#include <stdlib.h>
#include <complex_sparse.h>

COMPLEX_SPARSE *complex_sparse_create(int nrows, int ncols, 
					double constant) {
	COMPLEX_SPARSE *sparse = 
		(COMPLEX_SPARSE *) malloc(sizeof(COMPLEX_SPARSE));
	sparse->nrows = nrows;
	sparse->ncols = ncols;
	sparse->constant = constant;

	// malloc for indices
	sparse->row_index = (COMPLEX_SPARSE_ELEM **)
		calloc(nrows, sizeof(COMPLEX_SPARSE_ELEM *));
	sparse->col_index = (COMPLEX_SPARSE_ELEM **)
		calloc(ncols, sizeof(COMPLEX_SPARSE_ELEM *));

	return sparse;
}

int complex_sparse_put(COMPLEX_SPARSE *sparse, 
			int row, int col, double elem) {

	if (!sparse) return INVALID_COMPLEX_SPARSE;
	if (row < 0 || col < 0 || 
		row >= sparse->nrows || col >= sparse->ncols) {
		return INVALID_POS;
	}

	COMPLEX_SPARSE_ELEM **rp = &sparse->row_index[row];
	COMPLEX_SPARSE_ELEM **cp = &sparse->col_index[col];

	while (*rp && ((*rp)->col < col)) rp = &(*rp)->right;
	while (*cp && ((*cp)->row < row)) cp = &(*cp)->bottom;

	if (*rp && *cp && (*rp)->col == col && (*cp)->row == row) {
		(*rp)->elem = elem;
	} else {
		COMPLEX_SPARSE_ELEM *new = 
			(COMPLEX_SPARSE_ELEM *) 
				malloc(sizeof(COMPLEX_SPARSE_ELEM));
		new->row = row;
		new->col = col;
		new->elem = elem;
		new->right = *rp;
		new->bottom = *cp;
		*rp = *cp = new;
	}

	return SUCCESS;
}

double complex_sparse_get(COMPLEX_SPARSE *sparse, 
			int row, int col, int *error) {
	if (!sparse) {
		*error = INVALID_COMPLEX_SPARSE;
		return -1;
	}
	if (row < 0 || col < 0 || 
		row >= sparse->nrows || col >= sparse->ncols) {
		*error = INVALID_POS;
		return -1;
	}

	COMPLEX_SPARSE_ELEM **rp = &sparse->row_index[row];
	COMPLEX_SPARSE_ELEM **cp = &sparse->col_index[col];

	while (*rp && ((*rp)->col < col)) rp = &(*rp)->right;
	while (*cp && ((*cp)->row < row)) cp = &(*cp)->bottom;

	if (*rp && *cp && (*rp)->col == col && (*cp)->row == row) {
		*error = SUCCESS;
		return (*rp)->elem;
	}

	*error = NOT_FOUND;
	return sparse->constant;
}

int complex_sparse_remove(COMPLEX_SPARSE *sparse, int row, int col) {
	if (!sparse) return INVALID_COMPLEX_SPARSE;
	if (row < 0 || row >= sparse->nrows ||
		col < 0 || col >= sparse->ncols) return INVALID_POS;

	COMPLEX_SPARSE_ELEM **rp = &sparse->row_index[row];
	COMPLEX_SPARSE_ELEM **cp = &sparse->col_index[col];
	COMPLEX_SPARSE_ELEM *aux;

	while(*rp && (*rp)->col < col && (rp = &(*rp)->right));
	while(*cp && (*cp)->row < row && (cp = &(*cp)->bottom));

	if (*rp && *cp && (*rp)->col == col && (*cp)->row == row) {
		aux = *rp;
		*rp = (*rp)->right;
		*cp = (*cp)->bottom;
		free(aux);
	}

	return SUCCESS;
}

int complex_sparse_free(COMPLEX_SPARSE *sparse) {
	if (!sparse) return INVALID_COMPLEX_SPARSE;

	int i;
	COMPLEX_SPARSE_ELEM *p;

	for (i = 0; i < sparse->nrows; i++) {
		while (p = sparse->row_index[i]) {
			sparse->row_index[i] = p->right;
			free(p);
		}
	}
	free(sparse->row_index);
	free(sparse->col_index);
	free(sparse);
}












