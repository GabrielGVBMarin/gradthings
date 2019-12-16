#ifndef _DYN_LIST_CIRCULAR_
#define _DYN_LIST_CIRCULAR_

#include <defines.h>

struct dyn_list_circular_elem {
	void *elem;
	struct dyn_list_circular_elem *next;
};

struct dyn_list_circular {
	int counter;
	int (*cmp)(void *, void *);
	struct dyn_list_circular_elem *first;
	struct dyn_list_circular_elem *last;
};

typedef struct dyn_list_circular_elem DYN_LIST_CIRCULAR_ELEM;
typedef struct dyn_list_circular DYN_LIST_CIRCULAR;

DYN_LIST_CIRCULAR *dyn_list_circular_create(int (*)(void *, void *));
int dyn_list_circular_push_back(DYN_LIST_CIRCULAR *, void *);
void *dyn_list_circular_get(DYN_LIST_CIRCULAR *, int, int *);
int dyn_list_circular_size(DYN_LIST_CIRCULAR *);
int dyn_list_circular_sequential_search(DYN_LIST_CIRCULAR *, void *);
int dyn_list_circular_remove(DYN_LIST_CIRCULAR *, int);
DYN_LIST_CIRCULAR *dyn_list_circular_copy(DYN_LIST_CIRCULAR *);
int dyn_list_circular_free(DYN_LIST_CIRCULAR *);

#endif












