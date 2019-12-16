#include <stdlib.h>
#include <stdio.h>
#include <binary_tree.h>

BINARY_TREE *binary_tree_create() {
	return (BINARY_TREE *) calloc(1, sizeof(BINARY_TREE));
}

int __binary_tree_insert(BINARY_TREE_NODE **node, int key) {

	if (*node == NULL) {
		*node = (BINARY_TREE_NODE *)
				calloc(1, sizeof(BINARY_TREE_NODE));
		(*node)->key = key;
		return SUCCESS;
	}

	if ((*node)->key == key) {
		return FAILED;
	} else if (key < (*node)->key) {
		return __binary_tree_insert(&(*node)->left, key);
	} else {
		return __binary_tree_insert(&(*node)->right, key);
	}
}

int binary_tree_insert(BINARY_TREE *tree, int key) {
	if (!tree) return INVALID_TREE;
	int ret = __binary_tree_insert(&tree->root, key);
	if (ret == SUCCESS) tree->size++;
	return ret;
}

int __binary_tree_search(BINARY_TREE_NODE *node, int key) {
	if (!node) return FAILED;

	if (node->key == key) {
		return SUCCESS;
	} else if (key < node->key) {
		return __binary_tree_search(node->left, key);
	} else {
		return __binary_tree_search(node->right, key);
	}
}

int binary_tree_search(BINARY_TREE *tree, int key) {
	if (!tree) return INVALID_TREE;
	return __binary_tree_search(tree->root, key);
}

int __binary_tree_free(BINARY_TREE_NODE *node) {
	if (node) {
		__binary_tree_free(node->left);
		__binary_tree_free(node->right);
		free(node);
	}
}

int binary_tree_free(BINARY_TREE *tree) {
	if (!tree) return INVALID_TREE;
	__binary_tree_free(tree->root);
	free(tree);
}

void __binary_tree_pre_order(BINARY_TREE_NODE *node) {
	if (node) {
		printf("%d\n", node->key);
		__binary_tree_pre_order(node->left);
		__binary_tree_pre_order(node->right);
	}
}

void __binary_tree_in_order(BINARY_TREE_NODE *node) {
	if (node) {
		__binary_tree_in_order(node->left);
		printf("%d\n", node->key);
		__binary_tree_in_order(node->right);
	}
}

void __binary_tree_pos_order(BINARY_TREE_NODE *node) {
	if (node) {
		__binary_tree_pos_order(node->left);
		__binary_tree_pos_order(node->right);
		printf("%d\n", node->key);
	}
}

int binary_tree_pre_order(BINARY_TREE *tree) {
	if (!tree) return INVALID_TREE;
	__binary_tree_pre_order(tree->root);
	return SUCCESS;
}

int binary_tree_in_order(BINARY_TREE *tree) {
	if (!tree) return INVALID_TREE;
	__binary_tree_in_order(tree->root);
	return SUCCESS;
}

int binary_tree_pos_order(BINARY_TREE *tree) {
	if (!tree) return INVALID_TREE;
	__binary_tree_pos_order(tree->root);
	return SUCCESS;
}









