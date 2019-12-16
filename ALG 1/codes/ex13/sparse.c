#include <stdlib.h>
#include <sparse.h>

SPARSE *sparse_create(void *constant) {
	SPARSE *sparse = (SPARSE *) calloc(1, sizeof(SPARSE));
	sparse->constant = constant;
	return sparse;
}

int sparse_add(SPARSE *sparse, int row, int col, void *elem) {
	if (!sparse) return INVALID_SPARSE;

	SPARSE_ELEM *p = sparse->first;
	while (p) {
		if (p->row == row && p->col == col) {
			p->elem = elem;
			return SUCCESS;
		}
		p = p->next;
	}

	// adding new element
	p = (SPARSE_ELEM *) malloc(sizeof(SPARSE_ELEM));
	p->row = row;
	p->col = col;
	p->elem = elem;
	p->next = sparse->first;
	sparse->first = p;
	sparse->counter++;

	return SUCCESS;
}

int sparse_remove(SPARSE *sparse, int row, int col) {
	if (!sparse) return INVALID_SPARSE;
	if (!sparse->counter) return EMPTY_SPARSE;

	SPARSE_ELEM **p = &sparse->first;
	SPARSE_ELEM *aux;
	while (*p) {
		if ((*p)->row == row && (*p)->col == col) {
			aux = *p;
			*p = (*p)->next;
			free(aux);
			sparse->counter--;
		}
		p = &(*p)->next;
	}

	return SUCCESS;
}

void *sparse_get(SPARSE *sparse, int row, int col, int *error) {
	if (!sparse) {
		*error = INVALID_SPARSE;
		return NULL;
	}

	SPARSE_ELEM *p = sparse->first;
	while (p) {
		if (p->row == row && p->col == col) {
			*error = SUCCESS;
			return p->elem;
		}
		p = p->next;
	}
	*error = NOT_FOUND;
	return sparse->constant;
}

int sparse_free(SPARSE *sparse) {
	if (!sparse) return INVALID_SPARSE;
	int i;
	SPARSE_ELEM *p;
	for (i = 0; i < sparse->counter; i++) {
		p = sparse->first;
		sparse->first = p->next;
		free(p);
	}
	free(sparse);

	return SUCCESS;
}

