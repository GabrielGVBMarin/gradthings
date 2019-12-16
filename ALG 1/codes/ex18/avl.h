#ifndef _AVL_H_
#define _AVL_H_

#define SUCCESS		0
#define	FAILED		-1
#define INVALID_TREE	-2

struct avl_node {
	int key;
	int height;
	struct avl_node *left, *right;
};

struct avl {
	struct avl_node *root;
	int size;
};

typedef struct avl_node AVL_NODE;
typedef struct avl	AVL;

AVL *avl_create();
int avl_insert(AVL *, int);
int avl_remove(AVL *, int);
int avl_search(AVL *, int);
int avl_free(AVL *);

int avl_pre_order(AVL *);
int avl_in_order(AVL *);
int avl_pos_order(AVL *);

#endif
