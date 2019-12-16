#ifndef _MINHEAP_H_
#define _MINHEAP_H_

#define SUCCESS		 0
#define INVALID_MINHEAP -1
#define INVALID_KEY	-2
#define INVALID_POS	-3
#define EMPTY_MINHEAP	-4

struct minheap_node {
	int key;
	struct minheap_node *right, *left;
};

struct minheap {
	struct minheap_node *root;
	int size;
};

typedef struct minheap_node MINHEAP_NODE;
typedef struct minheap	    MINHEAP;

MINHEAP *minheap_create();
int minheap_add(MINHEAP *, int);
int minheap_minkey(MINHEAP *, int *);
int minheap_decrease_key(MINHEAP *, int, int);
int minheap_remove_key(MINHEAP *, int *);
int minheap_free(MINHEAP *);

#endif
