#ifndef _DYN_LIST_SIMPLE_
#define _DYN_LIST_SIMPLE_

#include <defines.h>

struct dyn_list_simple_elem {
	void *elem;
	struct dyn_list_simple_elem* next;
};
typedef struct dyn_list_simple_elem DYN_LIST_SIMPLE_ELEM;

struct dyn_list_simple {
	DYN_LIST_SIMPLE_ELEM *first;
	DYN_LIST_SIMPLE_ELEM *last;
	int (*cmp)(void *, void *);
	int counter;
};
typedef struct dyn_list_simple DYN_LIST_SIMPLE;

DYN_LIST_SIMPLE *dyn_list_simple_create(int (*)(void *, void *));
int dyn_list_simple_add(DYN_LIST_SIMPLE *, int, void *);
int dyn_list_simple_add_first(DYN_LIST_SIMPLE *, void *);
int dyn_list_simple_add_last(DYN_LIST_SIMPLE *, void *);
void *dyn_list_simple_get(DYN_LIST_SIMPLE *, int, int *);
int dyn_list_simple_free(DYN_LIST_SIMPLE *);
int dyn_list_simple_remove(DYN_LIST_SIMPLE *, int);
int dyn_list_simple_sequential_search(DYN_LIST_SIMPLE *, void *, int *);
int dyn_list_simple_size(DYN_LIST_SIMPLE *);

#endif
