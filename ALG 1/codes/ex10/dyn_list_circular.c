#include <stdlib.h>
#include <stdio.h>
#include <dyn_list_circular.h>

DYN_LIST_CIRCULAR *dyn_list_circular_create(int (*cmp)(void *, void *)){
	DYN_LIST_CIRCULAR *list; // stack (8 bytes)

	// colocado na heap
	list = (DYN_LIST_CIRCULAR *) 
		calloc(1, sizeof(DYN_LIST_CIRCULAR));
	if (list) list->cmp = cmp;

	return list;
}

int dyn_list_circular_push_back(DYN_LIST_CIRCULAR *list, void *elem) {
	if (!list) return INVALID_LIST;

	DYN_LIST_CIRCULAR_ELEM *new;
	new = (DYN_LIST_CIRCULAR_ELEM *) 
		malloc(sizeof(DYN_LIST_CIRCULAR_ELEM));
	new->elem = elem;

	if (list->counter) {
		new->next = list->first;
		list->last->next = new;
	} else list->first = new->next = new;
	list->last = new;
	list->counter++;

	return SUCCESS;
}

void *dyn_list_circular_get(DYN_LIST_CIRCULAR *list,
		int pos, int *error) {
	if (!list) {
		*error = INVALID_LIST;
		return NULL;
	}

	if (pos < 0 || pos >= list->counter) {
		*error = INVALID_POS;
		return NULL;
	}

	DYN_LIST_CIRCULAR_ELEM *p = list->first;
	while (pos-- && (p = p->next));

	*error = SUCCESS;
	return p->elem;
}

int dyn_list_circular_size(DYN_LIST_CIRCULAR *list) {
	if (!list) return INVALID_LIST;
	return list->counter;
}

int dyn_list_circular_sequential_search(DYN_LIST_CIRCULAR *list,
		void *elem) {
	if (!list) return INVALID_LIST;
	int i;
	DYN_LIST_CIRCULAR_ELEM *p = list->first;

	for (i = 0; i < list->counter; i++, (p = p->next)) {
		if (!list->cmp(p->elem, elem)) {
			return i;
		}
	}
	return INVALID_POS;
}

/*
 
 	-------------
	| counter   |
	| cmp       |
	| first     |----
	| last      |------------------------------------
	-------------	|				|
			|                               |
			v                               v
		     ------- ------- ------- ------- -------
		     |void*| |     | |     | |     | |     |
		     |next*|>|     |>|     |>|     |>|     |>
		     ------- ------- ------- ------- -------
			0   	1	2	3	4
	Heap
	====
	DYN_LIST_CIRCULAR *list

	-----------
	|         | counter
	|         |
	|         |
	|         |
	-----------
	|         | cmp
	|         |
	|         |
	|         |
	|         |
	|         |
	|         |
	|         |
	-----------
0xaabb	|         | first
	|         |
	|         |
	|         |
	|         |
	|         |
	|         |
	|         |
	-----------
	|         | last
	|         |
	|         |
	|         |
	|         |
	|         |
	|         |
	|         |
	-----------


	DYN_LIST_CIRCULAR_ELEM
	
	-----------
	|         |void *
	|         |
	|         |
	|         |
	|         |
	|         |
	|         |
	|         |
	-----------
0xccdd	|         |next*
	|         |
	|         |
	|         |
	|         |
	|         |
	|         |
	|         |
	-----------
 */

int dyn_list_circular_remove(DYN_LIST_CIRCULAR *list, int pos) {
	if (!list) return INVALID_LIST;

	if (pos < 0 || pos >= list->counter)
		return INVALID_POS;

/*
 	-------------
	| counter   |
	| cmp       |
	| first     |----
	| last      |------------------------------------
	-------------	|				|
			|       |follow                 |
			v       v      aux              v
		     ------- ------- ------- ------- -------
		     |void*| |     | |     | |     | |     |
		     |next*|>|-> 3 |>|     |>|     |>|     |>
		     ------- -|----- ------- ------- -------
			0     |	1	2	3	4 aux
			      |
			      |
			**p ---
*/
	int position = pos;
	DYN_LIST_CIRCULAR_ELEM **p = &list->first;
	DYN_LIST_CIRCULAR_ELEM *aux, *follow = list->last;
	while (pos-- && (p = &(*p)->next) && (follow = follow->next));

	if (list->first == list->last) {
		free(list->first);
		list->first = list->last = NULL;
		list->counter--;
		return SUCCESS;
	}
	
	// antes
	//*p = follow->next->next;
	//free(follow->next);
	// depois
	aux = follow->next;
	*p = aux->next;
	free(aux);
	if (position == list->counter-1) list->last = follow;
	list->last->next = list->first;
	list->counter--;

	return SUCCESS;
}

DYN_LIST_CIRCULAR *dyn_list_circular_copy(DYN_LIST_CIRCULAR *list) {
	if (!list) return NULL;
	int i, error;
	DYN_LIST_CIRCULAR *nlist = dyn_list_circular_create(list->cmp);
	for (i = 0; i < list->counter; i++) {
		dyn_list_circular_push_back(nlist, 
			dyn_list_circular_get(list, i, &error));
	}
	return nlist;
}

int dyn_list_circular_free(DYN_LIST_CIRCULAR *list) {
	if (!list) return INVALID_LIST;
	DYN_LIST_CIRCULAR_ELEM *p = list->first;
	for (int i = 0; i < list->counter; i++) {
		list->first = p->next;
		free(p);
		p = list->first;
	}
	free(list);

	return SUCCESS;
}

