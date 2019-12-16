#include <stdlib.h>
#include <stdio.h>
#include <avl.h>

#define max(a,b) (a > b ? a : b)
#define height(child) (child ? child->height : 0)

AVL *avl_create() {
	return (AVL *) calloc(1, sizeof(AVL));
}

void __set_height(AVL_NODE *node) {
	node->height = 1 + max(height(node->left), height(node->right));
}

void rotate_right(AVL_NODE **node) {
	AVL_NODE *n = (*node)->left;
	(*node)->left = n->right;
	n->right = *node;
	*node = n;
	__set_height((*node)->right);
	__set_height(*node);
}

void rotate_left(AVL_NODE **node) {
	AVL_NODE *n = (*node)->right;
	(*node)->right = n->left;
	n->left = *node;
	*node = n;
	__set_height((*node)->left);
	__set_height(*node);
}

void __avl_balance(AVL_NODE **node) {

	int balance_factor =
		height((*node)->left) - height((*node)->right);

	if (balance_factor == 2) {
		int bf = height((*node)->left->left) - 
				height((*node)->left->right);
		if (bf == 1) {
			rotate_right(node);
		} else if (bf == -1) {
			rotate_left(&(*node)->left);
			rotate_right(node);
		} else if (bf == 0) { // remoção de elementos
			//printf("Resolver caso de remoção\n");
			rotate_right(node);
		}
	} else if (balance_factor == -2) {
		int bf = height((*node)->right->left) - 
				height((*node)->right->right);
		if (bf == 1) {
			rotate_right(&(*node)->right);
			rotate_left(node);
		} else if (bf == -1) {
			rotate_left(node);
		} else if (bf == 0) { // remoção de elementos
			//printf("Resolver caso de remoção\n");
			rotate_left(node);
		}
	}
}

int __avl_insert(AVL_NODE **node, int key) {

	if (*node == NULL) {
		*node = (AVL_NODE *)
				calloc(1, sizeof(AVL_NODE));
		(*node)->key = key;
		(*node)->height = 1;
		return SUCCESS;
	}

	int ret;
	if ((*node)->key == key) {
		return FAILED;
	} else if (key < (*node)->key) {
		ret = __avl_insert(&(*node)->left, key);
	} else {
		ret = __avl_insert(&(*node)->right, key);
	}

	// setting the height
	__set_height(*node);

	// balancing the tree
	__avl_balance(node);

	return ret;
}

int avl_insert(AVL *tree, int key) {
	if (!tree) return INVALID_TREE;
	int ret = __avl_insert(&tree->root, key);
	if (ret == SUCCESS) tree->size++;
	return ret;
}

int __avl_search(AVL_NODE *node, int key) {
	if (!node) return FAILED;

	if (node->key == key) {
		return SUCCESS;
	} else if (key < node->key) {
		return __avl_search(node->left, key);
	} else {
		return __avl_search(node->right, key);
	}
}

int avl_search(AVL *tree, int key) {
	if (!tree) return INVALID_TREE;
	return __avl_search(tree->root, key);
}

int __avl_free(AVL_NODE *node) {
	if (node) {
		__avl_free(node->left);
		__avl_free(node->right);
		free(node);
	}
}

int avl_free(AVL *tree) {
	if (!tree) return INVALID_TREE;
	__avl_free(tree->root);
	free(tree);
}

void __avl_pre_order(AVL_NODE *node) {
	if (node) {
		printf("%d (%d)\n", node->key, node->height);
		__avl_pre_order(node->left);
		__avl_pre_order(node->right);
	}
}

void __avl_in_order(AVL_NODE *node) {
	if (node) {
		__avl_in_order(node->left);
		printf("%d\n", node->key);
		__avl_in_order(node->right);
	}
}

void __avl_pos_order(AVL_NODE *node) {
	if (node) {
		__avl_pos_order(node->left);
		__avl_pos_order(node->right);
		printf("%d\n", node->key);
	}
}

int avl_pre_order(AVL *tree) {
	if (!tree) return INVALID_TREE;
	__avl_pre_order(tree->root);
	return SUCCESS;
}

int avl_in_order(AVL *tree) {
	if (!tree) return INVALID_TREE;
	__avl_in_order(tree->root);
	return SUCCESS;
}

int avl_pos_order(AVL *tree) {
	if (!tree) return INVALID_TREE;
	__avl_pos_order(tree->root);
	return SUCCESS;
}

void __avl_max_min(AVL_NODE **subroot, AVL_NODE **node) {
	if (*node && (*node)->right) {
		__avl_max_min(subroot, &(*node)->right);
		__set_height(*node);
		__avl_balance(node);
	} else if (*node && (*node)->left) {
		rotate_right(node);
		__avl_max_min(subroot, &(*node)->right);
		__set_height(*node);
	} else {
		(*subroot)->key = (*node)->key;
		free(*node);
		*node = NULL;
	}
}

int __avl_remove(AVL_NODE **node, int key) {
	if (*node == NULL) return FAILED;

	int ret;
	if ((*node)->key == key) {
		// procurar à esquerda desta raiz de sub-árvore
		// até encontrar a maior das menores chaves
		__avl_max_min(node, &(*node)->left);
		__avl_balance(node);
		ret = SUCCESS;
	} else if (key < (*node)->key) {
		ret = __avl_remove(&(*node)->left, key);
	} else {
		ret = __avl_remove(&(*node)->right, key);
	}

	__set_height(*node);
	__avl_balance(node);

	return ret;
}

int avl_remove(AVL *tree, int key) {
	if (!tree) return INVALID_TREE;
	__avl_remove(&tree->root, key);
	return SUCCESS;
}







