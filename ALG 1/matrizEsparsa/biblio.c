// Gabriel Guimarães Vilas Boas Marin 11218521
#include <biblio.h>

// CRIA A MATRIZ ESPARSA COM SUAS DIMENSÕES
COMPLEX_SPARSE *createSparse(int nrows, int ncols, double constant) {
	COMPLEX_SPARSE *sparse = (COMPLEX_SPARSE *) malloc(sizeof(COMPLEX_SPARSE));
	sparse->nrows = nrows;
	sparse->ncols = ncols;
	sparse->constant = constant;

	sparse->row_index = (COMPLEX_SPARSE_ELEM **) calloc(nrows, sizeof(COMPLEX_SPARSE_ELEM *));
	sparse->col_index = (COMPLEX_SPARSE_ELEM **) calloc(ncols, sizeof(COMPLEX_SPARSE_ELEM *));

	return sparse;
}

// INSERE UM NOVO ELEMENTO SE JÁ EXISTIR ALTERA O VALOR PARA O DESEJADOO
int putSparse(COMPLEX_SPARSE *sparse,int row, int col, double elem) {
	if (!sparse) return INVALID_SPARSE;
	if (row < 0 || col < 0 || row >= sparse->nrows || col >= sparse->ncols) {
		return INVALID_POS;
	}

	COMPLEX_SPARSE_ELEM **rp = &sparse->row_index[row];
	COMPLEX_SPARSE_ELEM **cp = &sparse->col_index[col];

	// PERCORRE LINHA E COLUNA
	while (*rp && ((*rp)->col < col)) rp = &(*rp)->right;
	while (*cp && ((*cp)->row < row)) cp = &(*cp)->bottom;

	if (*rp && *cp && (*rp)->col == col && (*cp)->row == row) {
		(*rp)->elem = elem;
	} else {
		COMPLEX_SPARSE_ELEM *new = (COMPLEX_SPARSE_ELEM *) malloc(sizeof(COMPLEX_SPARSE_ELEM));
		new->row = row;
		new->col = col;
		new->elem = elem;
		new->right = *rp;
		new->bottom = *cp;
		*rp = *cp = new;
	}

	return SUCCESS;
}

// BUSCA O VALOR DO ELEMENTO DESEJADO
double getSparse(COMPLEX_SPARSE *sparse, int row, int col) {
	if (!sparse) {
		return -1;
	} else if (row < 0 || col < 0 ||
		row >= sparse->nrows || col >= sparse->ncols) {
		return -1;
	}

	COMPLEX_SPARSE_ELEM **rp = &sparse->row_index[row];
	COMPLEX_SPARSE_ELEM **cp = &sparse->col_index[col];

	while (*rp && ((*rp)->col < col)) rp = &(*rp)->right;
	while (*cp && ((*cp)->row < row)) cp = &(*cp)->bottom;

	if (*rp && *cp && (*rp)->col == col && (*cp)->row == row) {
		return (*rp)->elem;
	}

	return sparse->constant;
}

// ADICIONA O VALOR PASSADO NO ELEMENTO INDICADO
// SE NÃO EXISTIR ELE CRIA O ELEMENTO COM O VALOR PASSADO
double addSparse(COMPLEX_SPARSE *sparse, double elem, int row, int col)  {

	if (!sparse) return INVALID_SPARSE;

	COMPLEX_SPARSE_ELEM **rp = &sparse->row_index[row];
	COMPLEX_SPARSE_ELEM **cp = &sparse->col_index[col];

	while (*rp && ((*rp)->col < col)) rp = &(*rp)->right;
	while (*cp && ((*cp)->row < row)) cp = &(*cp)->bottom;

	if (*rp && *cp && (*rp)->col == col && (*cp)->row == row) {
		if ((*rp)->elem+elem == 0)	{
			// SE A SOMA FOR 0, RETIRA O ELEMENTO POIS 0 É A CONSTANTE
			removeSparse(sparse, (*rp)->row, (*rp)->col);
		}	else (*rp)->elem = (*rp)->elem+elem;
	} else {
		COMPLEX_SPARSE_ELEM *new = (COMPLEX_SPARSE_ELEM *) malloc(sizeof(COMPLEX_SPARSE_ELEM));
		new->row = row;
		new->col = col;
		new->elem = elem;
		new->right = *rp;
		new->bottom = *cp;
		*rp = *cp = new;
	}

	return SUCCESS;
}

// REMOVE O ELEMENTO INDICADO
int removeSparse(COMPLEX_SPARSE *sparse, int row, int col) {
	if (!sparse) return INVALID_SPARSE;
	if (row < 0 || row >= sparse->nrows || col < 0 || col >= sparse->ncols) return INVALID_POS;

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

// FAZ O FREE DA MATRIZ E SEUS ELEMENTOS
int freeSparse(COMPLEX_SPARSE *sparse) {
	if (!sparse) return INVALID_SPARSE;

	int i;
	COMPLEX_SPARSE_ELEM *p = sparse->row_index[0];

	for (i = 0; i < sparse->nrows; i++) {
		while (p && (p = sparse->row_index[i])) {
			sparse->row_index[i] = p->right;
			free(p);
		}
	}
	free(sparse->row_index);
	free(sparse->col_index);
	free(sparse);

  return SUCCESS;
}

COMPLEX_SPARSE* multiplySparse(COMPLEX_SPARSE *sparse, COMPLEX_SPARSE *secondSparse) {

	COMPLEX_SPARSE_ELEM *elem;
	COMPLEX_SPARSE *new = createSparse(sparse->nrows, secondSparse->ncols, 0);
	double aux;
	int i, j;

		for (i = 0; i < new->nrows; i++)	{
			for (j = 0; j < new->ncols; j++)	{
				elem = sparse->row_index[i];
				aux = 0;
				while (elem)	{
					aux += getSparse(secondSparse, elem->col, j)*(elem->elem);
					elem = elem->right;
				}
				putSparse(new, i, j, aux);
			}
		}

	return new;
}

void plusSparse(COMPLEX_SPARSE *sparse, COMPLEX_SPARSE *secondSparse) {
	if (!sparse || !secondSparse) printf("ERROR INVALID SPARSE");

	COMPLEX_SPARSE_ELEM **rp;
	int i;

	for (i = 0; i < sparse->nrows; i++)	{
		rp = &sparse->row_index[i];
		while(*rp)	{
			addSparse(secondSparse, (*rp)->elem, (*rp)->row, (*rp)->col);
			rp = &(*rp)->right;
		}
	}

}

void printSparse(COMPLEX_SPARSE *sparse)	{
	if (!sparse) printf("ERROR INVALID SPARSE");

	COMPLEX_SPARSE_ELEM **rp;
	int i;

	printf("-1 %d %d\n", sparse->nrows, sparse->ncols);
	for (i = 0; i < sparse->nrows; i++)	{
		rp = &sparse->row_index[i];
		while(*rp)	{
			printf("%d %d %d\n",(*rp)->row, (*rp)->col, (int)(*rp)->elem);
			rp = &(*rp)->right;
		}
	}

}

int complex_sparse_free(COMPLEX_SPARSE *sparse) {
	if (!sparse) return INVALID_COMPLEX_SPARSE;

	int i;
	COMPLEX_SPARSE_ELEM *p;

	for (i = 0; i < sparse->nrows; i++) {
		while ((p = sparse->row_index[i])) {
			sparse->row_index[i] = p->right;
			free(p);
		}
	}
	free(sparse->row_index);
	free(sparse->col_index);
	free(sparse);

	return SUCCESS;
}
