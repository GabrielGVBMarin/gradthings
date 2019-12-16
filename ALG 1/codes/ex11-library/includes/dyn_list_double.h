#ifndef _DYN_LIST_DOUBLE_
#define _DYN_LIST_DOUBLE_

#include <defines.h>

struct dyn_list_double_elem {
	void *elem;
	struct dyn_list_double_elem* prev;
	struct dyn_list_double_elem* next;
};
typedef struct dyn_list_double_elem DYN_LIST_DOUBLE_ELEM;

struct dyn_list_double {
	DYN_LIST_DOUBLE_ELEM *first;
	DYN_LIST_DOUBLE_ELEM *last;
	int (*cmp)(void *, void *);
	int counter;
};
typedef struct dyn_list_double DYN_LIST_DOUBLE;

DYN_LIST_DOUBLE *dyn_list_double_create(int (*)(void *, void *));
int dyn_list_double_add(DYN_LIST_DOUBLE *, int, void *);
int dyn_list_double_add_first(DYN_LIST_DOUBLE *, void *);
int dyn_list_double_add_last(DYN_LIST_DOUBLE *, void *);
void *dyn_list_double_get(DYN_LIST_DOUBLE *, int, int *);
int dyn_list_double_free(DYN_LIST_DOUBLE *);
int dyn_list_double_remove(DYN_LIST_DOUBLE *, int);
int dyn_list_double_sequential_search(DYN_LIST_DOUBLE *, void *, int *);
int dyn_list_double_size(DYN_LIST_DOUBLE *);
int dyn_list_double_sort(DYN_LIST_DOUBLE *);
DYN_LIST_DOUBLE *dyn_list_double_copy(DYN_LIST_DOUBLE *);

#endif
