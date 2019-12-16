#ifndef _SPARSE_H_
#define _SPARSE_H_

#define SUCCESS		0
#define INVALID_SPARSE	-1
#define EMPTY_SPARSE	-2
#define NOT_FOUND	-3

/*
 --------------
 | first      |
 | counter    |
 | void *const|
 --------------
 
 	-----------	-----------
	| int row |     | int row |
	| int col |     | int col |
	| void *  |---> | void *  |---|
	-----------     -----------
*/

struct sparse_elem {
	int row;
	int col;
	void *elem;
	struct sparse_elem *next;
};

struct sparse {
	struct sparse_elem *first;
	int counter;
	void *constant;
};

typedef struct sparse_elem SPARSE_ELEM;
typedef struct sparse SPARSE;

SPARSE *sparse_create(void *);
int sparse_add(SPARSE *, int, int, void *);
int sparse_remove(SPARSE *, int, int);
void *sparse_get(SPARSE *, int, int, int *);
int sparse_free(SPARSE *);

#endif
