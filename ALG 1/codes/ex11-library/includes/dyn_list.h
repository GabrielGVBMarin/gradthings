#ifndef _dyn_list_
#define _dyn_list_

#include <defines.h>

struct dyn_list_elem {
	void *elem;
};
typedef struct dyn_list_elem DYN_LIST_ELEM;

struct dyn_list {
	DYN_LIST_ELEM *first;
	int (*cmp)(void *, void *);
	int counter;
};
typedef struct dyn_list DYN_LIST;

DYN_LIST *dyn_list_create(int (*)(void *, void *));
int dyn_list_add(DYN_LIST *, void *);
int dyn_list_remove(DYN_LIST *, int);
DYN_LIST_ELEM *dyn_list_get(DYN_LIST *, int, int *);
int dyn_list_sort(DYN_LIST *);
int dyn_list_sequential_search(DYN_LIST *, void *, int *);
int dyn_list_binary_search(DYN_LIST *, void *);
DYN_LIST *dyn_list_copy(DYN_LIST *, int *);
int dyn_list_reverse(DYN_LIST *);
int dyn_list_insert(DYN_LIST *, int, void *);
int dyn_list_size(DYN_LIST *);
void dyn_list_free(DYN_LIST *);

#endif
