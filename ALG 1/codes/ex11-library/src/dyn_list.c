#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dyn_list.h>

DYN_LIST *dyn_list_create(int (*cmp)(void *, void *)) {
	DYN_LIST *list = (DYN_LIST *) calloc(1, sizeof(DYN_LIST)); 
	list->cmp = cmp;
	return list;
}

int dyn_list_add(DYN_LIST *list, void *new) {
	if (!list) { return INVALID_LIST; }
	list->first = (DYN_LIST_ELEM *) realloc(list->first,
			sizeof(DYN_LIST_ELEM)*(list->counter+1));
	list->first[list->counter].elem = new;
	list->counter++;
	return SUCCESS;
}

int dyn_list_remove(DYN_LIST *list, int pos) {
	if (!list) { return INVALID_LIST; }
	if (pos >= 0 && pos < list->counter) {
		memcpy(&list->first[pos], &list->first[pos+1],
				sizeof(DYN_LIST_ELEM)*(list->counter-pos-1));
		list->counter--;
		list->first = (DYN_LIST_ELEM *) realloc(list->first,
				sizeof(DYN_LIST_ELEM)*list->counter);
		return SUCCESS;
	} 
	return REMOVE_ERROR;
}

int dyn_list_sort(DYN_LIST *list) {
	void *aux;
	int i, j;
	if (!list) { return INVALID_LIST; }
	for (i = 0; i < dyn_list_size(list)-1; i++) {
		for (j = i+1; j < dyn_list_size(list); j++) {
			if (list->cmp(list->first[i].elem, 
						list->first[j].elem) > 0) {
				aux = list->first[j].elem;
				list->first[j].elem = 
					list->first[i].elem;
				list->first[i].elem = aux;
			}
		}
	}
	return SUCCESS;
}

int dyn_list_size(DYN_LIST *list) {
	if (!list) { return INVALID_LIST; }
	return list->counter;
}

DYN_LIST_ELEM *dyn_list_get(DYN_LIST *list, int pos, int *error) {
	if (!list) { *error = INVALID_LIST; return NULL; }
	if (pos >= 0 && pos < list->counter) return &list->first[pos];
	*error = GET_ERROR;
	return NULL;
}

int dyn_list_sequential_search(DYN_LIST *list, void *elem, 
		int *error) {
	int i;
	if (!list) {
		*error = INVALID_LIST;
		return INVALID_POS;
	}

	for (i = 0; i < list->counter; i++) {
		if (list->cmp(list->first[i].elem, elem) == 0) {
			return i;
		}
	}
	return INVALID_POS;
}

int binary_search(DYN_LIST *list, void *key, int start, int end){ 
	int middle, r;

	if (start > end) { 
		return -1;
	}
	middle = (start + end) / 2; 
	r = list->cmp(key, list->first[middle].elem); 
	if (r == 0) { 
		return middle; 
	} else if (r < 0) { 
		return binary_search(list, key, start, middle-1); 
	} else { 
		return binary_search(list, key, middle+1, end); 
	}
}

int dyn_list_binary_search(DYN_LIST *list, void *key) {
	if (!list) return INVALID_POS;
	return binary_search(list, key, 0, list->counter-1);
}

DYN_LIST *dyn_list_copy(DYN_LIST *list, int *error) {
	if (!list) {
		*error = INVALID_LIST;
		return NULL;
	}

	DYN_LIST *newlist = (DYN_LIST *) malloc(sizeof(DYN_LIST));
	memcpy(newlist, list, sizeof(DYN_LIST));

	newlist->first = (DYN_LIST_ELEM *) malloc(
			sizeof(DYN_LIST_ELEM)*list->counter
			);
	memcpy(&newlist->first[0], &list->first[0],
			sizeof(DYN_LIST_ELEM)*list->counter);
	*error = SUCCESS;
	return newlist;
}

int dyn_list_reverse(DYN_LIST *list) {
	int i;
	DYN_LIST_ELEM aux;

	if (!list) return INVALID_LIST;

	for (i = 0; i < list->counter / 2; i++) {
		memcpy(&aux,&list->first[i],sizeof(DYN_LIST_ELEM));
		memcpy(&list->first[i],
				&list->first[list->counter-i-1],
				sizeof(DYN_LIST_ELEM));
		memcpy(&list->first[list->counter-i-1], &aux,
				sizeof(DYN_LIST_ELEM));
	}

	return SUCCESS;
}

int dyn_list_insert(DYN_LIST *list, int pos, void *new) {
	if (!list) return INVALID_LIST;

	if (pos >= 0 && pos < list->counter) {
		list->first = (DYN_LIST_ELEM *) realloc(
				list->first, sizeof(DYN_LIST_ELEM)*
				(list->counter+1));
		memcpy(&list->first[pos+1], &list->first[pos],
				sizeof(DYN_LIST_ELEM) * list->counter - pos);
		list->first[pos].elem = new;
		list->counter++;
		return SUCCESS;
	}
	return INVALID_POS;
}

void dyn_list_free(DYN_LIST *list) {
	if (list) {
		free(list->first);
		free(list);
	}
}
