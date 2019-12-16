#include <stdlib.h>
#include <dyn_list_double.h>

DYN_LIST_DOUBLE *dyn_list_double_create(int (*cmp)(void *, void *)) {
	DYN_LIST_DOUBLE *list; 
	list = (DYN_LIST_DOUBLE *) 
		calloc(1, sizeof(DYN_LIST_DOUBLE)); 
	list->cmp = cmp;
	return list;
}

int dyn_list_double_add(DYN_LIST_DOUBLE *list, int pos, void *elem) {
	if (!list) return INVALID_LIST;
	if (pos < 0 || pos > list->counter) return INVALID_POS;

	DYN_LIST_DOUBLE_ELEM *new; 
	new = (DYN_LIST_DOUBLE_ELEM *) 
		calloc(1, sizeof(DYN_LIST_DOUBLE_ELEM));
	new->elem = elem;

	int counter = 0; 
	DYN_LIST_DOUBLE_ELEM **p = &list->first;
	while (counter++ < pos && (p = &(*p)->next));

	if (*p) {
		new->prev = (*p)->prev;
		new->next = *p;
		(*p)->prev = new;
		*p = new;
	} else {
		*p = new;
		new->prev = list->last;
		list->last = new;
	}

	list->counter++;

	return SUCCESS;
}

int dyn_list_double_add_first(DYN_LIST_DOUBLE *list, void *elem) {
	return dyn_list_double_add(list, 0, elem);
}

int dyn_list_double_add_last(DYN_LIST_DOUBLE *list, void *elem) {
	if (!list) return INVALID_LIST;
	return dyn_list_double_add(list, list->counter, elem);
}

void *dyn_list_double_get(DYN_LIST_DOUBLE *list, 
		int pos, int *error) {
	if (!list) {
		*error = INVALID_LIST;
		return NULL;
	}

	if (pos < 0 || pos >= list->counter) {
		*error = INVALID_POS;
		return NULL;
	}

	int counter = 0;
	DYN_LIST_DOUBLE_ELEM *p = list->first;
	while (counter++ < pos && (p = p->next));

	*error = SUCCESS;

	return p->elem;
}

int dyn_list_double_free(DYN_LIST_DOUBLE *list) {
	if (!list) return INVALID_LIST;

	DYN_LIST_DOUBLE_ELEM *p = list->first;
	while (p && p->next != NULL) {
		p = p->next;
		free(p->prev);
	}
	free(p);
	free(list);

	return SUCCESS;
}

int dyn_list_double_remove(DYN_LIST_DOUBLE *list, int pos) {
	if (!list) return INVALID_LIST;
	if (pos < 0 || pos >= list->counter) return INVALID_POS;

	DYN_LIST_DOUBLE_ELEM *p = list->first;
	int counter = 0;
	while (counter++ < pos && (p = p->next));

	if (p->prev)
		p->prev->next = p->next;
	else
		list->first = p->next;

	if (p->next)
		p->next->prev = p->prev;
	else
		list->last = p->prev;
	free(p);
	list->counter--;

	return SUCCESS;
}

int dyn_list_double_sequential_search(
		DYN_LIST_DOUBLE *list, void *elem, int *error) {
	if (!list) {
		*error = INVALID_LIST;
		return -1;
	}

	int i;
	DYN_LIST_DOUBLE_ELEM *p = list->first;
	for (i = 0; i < list->counter; i++) {
		if (!list->cmp(p->elem, elem)) {
			*error = SUCCESS;
			return i;
		}
		p = p->next;
	}
	*error = ELEM_NOT_FOUND;
	return -1;
}

int dyn_list_double_size(DYN_LIST_DOUBLE *list) {
	if (!list) return INVALID_LIST;
	return list->counter;
}

int dyn_list_double_sort(DYN_LIST_DOUBLE *list) {
	if (!list) return INVALID_LIST;

	void *aux;
	int i, j, error;
	for (i = 0; i < list->counter; i++) {
		DYN_LIST_DOUBLE_ELEM *e0 =
			dyn_list_double_get(list, i, &error);
		for (j = i+1; j < list->counter; j++) {
			DYN_LIST_DOUBLE_ELEM *e1 =
				dyn_list_double_get(list, j, &error);
			if (list->cmp(e1->elem, e0->elem) < 0) {
				aux = e0->elem;
				e0->elem = e1->elem;
				e1->elem = aux;
			}
		}
	}

	return SUCCESS;
}

DYN_LIST_DOUBLE *dyn_list_double_copy(DYN_LIST_DOUBLE *list) {
	if (!list) return NULL;

	int i, error;
	DYN_LIST_DOUBLE *nlist = dyn_list_double_create(list->cmp);

	for (i = 0; i < list->counter; i++) {
		dyn_list_double_add(nlist, i, 
				dyn_list_double_get(list, i, &error));
	}

	return nlist;
}


