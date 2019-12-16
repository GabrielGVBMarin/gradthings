#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

#define SUCCESS		0
#define	FAILED		-1
#define INVALID_TREE	-2

struct binary_tree_node {
	int key;
	struct binary_tree_node *left, *right;
};

struct binary_tree {
	struct binary_tree_node *root;
	int size;
};

typedef struct binary_tree_node BINARY_TREE_NODE;
typedef struct binary_tree	BINARY_TREE;

BINARY_TREE *binary_tree_create();
int binary_tree_insert(BINARY_TREE *, int);
//int binary_tree_remove(BINARY_TREE *, int);
int binary_tree_search(BINARY_TREE *, int);
int binary_tree_free(BINARY_TREE *);

int binary_tree_pre_order(BINARY_TREE *);
int binary_tree_in_order(BINARY_TREE *);
int binary_tree_pos_order(BINARY_TREE *);

#endif
