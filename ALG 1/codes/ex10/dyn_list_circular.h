#ifndef _DYN_LIST_CIRCULAR_
#define _DYN_LIST_CIRCULAR_

/*
union data_type {
	unsigned char flag:1;	// 1 byte (1 bit)
	char type_char; 	// 1 byte
	int  type_int;		// 4 bytes
	void *type_pvoid;	// 8 bytes
};*/

#define SUCCESS		0
#define INVALID_LIST	-1
#define INVALID_POS	-2

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












