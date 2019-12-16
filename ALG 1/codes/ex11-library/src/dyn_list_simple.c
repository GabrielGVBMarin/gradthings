#include <stdlib.h>
#include <dyn_list_simple.h>

DYN_LIST_SIMPLE *dyn_list_simple_create(int (*cmp)(void *, void *)) {
	DYN_LIST_SIMPLE *list; 

	list = (DYN_LIST_SIMPLE *) calloc(1, sizeof(DYN_LIST_SIMPLE));
	list->cmp = cmp;
	
	return list;
}

int dyn_list_simple_add(DYN_LIST_SIMPLE *list, int pos, void *elem) {
	if (!list) return INVALID_LIST;
	if (pos < 0 || pos > list->counter) return INVALID_POS;

	DYN_LIST_SIMPLE_ELEM **p;
	int ct = 0;
	
	DYN_LIST_SIMPLE_ELEM *new;
	new = (DYN_LIST_SIMPLE_ELEM *) 
		malloc(sizeof(DYN_LIST_SIMPLE_ELEM));
	new->elem = elem;
	
	p = &list->first;
	while (ct++ < pos && (p = &((*p)->next)));
	
	new->next = *p;
	*p = new;
	
	if (pos == list->counter) list->last = new;
	
	list->counter++;

	return SUCCESS;
}

int dyn_list_simple_add_first(DYN_LIST_SIMPLE *list, void *elem) {
	return dyn_list_simple_add(list, 0, elem);
}

int dyn_list_simple_add_last(DYN_LIST_SIMPLE *list, void *elem) {
	if (!list) return INVALID_LIST;
	return dyn_list_simple_add(list, list->counter, elem);
}

void *dyn_list_simple_get(DYN_LIST_SIMPLE *list, int pos, int *error) {
	if (!list) {
		*error = INVALID_LIST;
		return NULL;
	}
	if (pos < 0 || pos >= list->counter) {
		*error = INVALID_POS;
		return NULL;
	}
	
	DYN_LIST_SIMPLE_ELEM *aux = list->first;
	while (pos-- && (aux = aux->next));
	return aux->elem;
}

int dyn_list_simple_free(DYN_LIST_SIMPLE *list) {
	if (!list) return INVALID_LIST;

	DYN_LIST_SIMPLE_ELEM *p, *aux;
	p = list->first;

	while (p) {
		aux = p->next;
		free(p);
		p = aux;
	}
	free(list);

	return SUCCESS;
}

int dyn_list_simple_remove(DYN_LIST_SIMPLE *list, int pos) {
	if (!list) return INVALID_LIST;
	if (pos < 0 || pos >= list->counter)
		return INVALID_POS;

	DYN_LIST_SIMPLE_ELEM *p, *prev;
	int counter = 0;

	prev = NULL;
	p = list->first;
	while (counter < pos) {
		prev = p;
		p = p->next;
		counter++;
	}
	if (prev) {
		prev->next = p->next;
		if (list->last == p) list->last = prev;
	} else list->first = p->next;
	free(p);
	list->counter--;

	return SUCCESS;
}

int dyn_list_simple_sequential_search(DYN_LIST_SIMPLE *list, 
			void *elem, int *error) {
	if (!list) {
		*error = INVALID_LIST;
		return -1;
	}

	DYN_LIST_SIMPLE_ELEM *p;
	int i = 0;

	p = list->first;
	while (p && list->cmp(p->elem, elem) && (p = p->next)) {
		i++;
	}
	if (p) {
		*error = SUCCESS;
		return i;
	} else {
		*error = INVALID_POS;
		return -1;
	}
}

int dyn_list_simple_size(DYN_LIST_SIMPLE *list) {
	if (!list) return INVALID_LIST;
	return list->counter;
}


