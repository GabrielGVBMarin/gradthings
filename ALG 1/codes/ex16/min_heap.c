#include <stdlib.h>
#include <min_heap.h>

MINHEAP *minheap_create() {
	return (MINHEAP *) calloc(1, sizeof(MINHEAP));
}

MINHEAP_NODE **minheap_search_parent(MINHEAP_NODE **root, 
				int position, int *value){
	if (position > 0) {
		MINHEAP_NODE **p = 
			minheap_search_parent(root, 
					(position - 1) / 2, value);
		if (*value < (*p)->key) {
			int temp = (*p)->key;
			(*p)->key = *value;
			*value = temp;
		}
		return (position % 2 == 0) ? 
				&(*p)->right : &(*p)->left;
	} else return root;
}

int minheap_add(MINHEAP *minheap, int value) {
	if (!minheap) return INVALID_MINHEAP;
	
	
	MINHEAP_NODE **node =
		minheap_search_parent(&minheap->root, 
				minheap->size++, &value);
	*node = (MINHEAP_NODE *) calloc(1, sizeof(MINHEAP_NODE));
	(*node)->key = value;

	return SUCCESS;
}

int minheap_minkey(MINHEAP *minheap, int *error) {
	if (!minheap) {
		*error = INVALID_MINHEAP;
		return 0;
	}

	if (!minheap->size) {
		*error = EMPTY_MINHEAP;
		return 0;
	}

	*error = SUCCESS;
	return minheap->root->key;
}

/*
 		5(0)

    10(1)		100(2)
11(3)	12(4)	    101(5)    107(6)
*/
MINHEAP_NODE *minheap_locate(MINHEAP_NODE *root, int position) {
	if (position > 0) {
		MINHEAP_NODE *p =
			minheap_locate(root, (position-1) / 2);
		return position % 2 == 0 ? p->right : p->left;
	} else return root;
}

int minheap_decrease_key(MINHEAP *minheap, int pos, int value) {
	if (!minheap) return INVALID_MINHEAP;
	if (pos < 0 || pos >= minheap->size) return INVALID_POS;

	MINHEAP_NODE *node =
		minheap_locate(minheap->root, pos);
	
	if (value < node->key) {
		node = 
		  *minheap_search_parent(&minheap->root, pos, &value);
		node->key = value;
		return SUCCESS;
	}

	return INVALID_KEY;
}

MINHEAP_NODE *minheap_remove_last(MINHEAP *minheap, 
				int position, int *lastkey) {
	if (position > 0) {
		MINHEAP_NODE *p = 
			minheap_remove_last(minheap,
					(position-1)/2, lastkey);
		if (position == minheap->size - 1) {
			if (position % 2 == 0) {
				*lastkey = p->right->key;
				free(p->right);
				p->right = NULL;
			} else {
				*lastkey = p->left->key;
				free(p->left);
				p->left = NULL;
			}
			minheap->size--;
			return NULL;
		} else return position % 2 == 0 ? p->right : p->left;
	} else return minheap->root;
}

void minheap_build(MINHEAP_NODE *node) {
/*
			10(0)
	    11(1)		100(2)
	13(3)	12(4)	    101(5)    107(6)
   14(7) 15(8) 17(9)


			-7(0)
	    11(1)		100(2)
	13(3)	12(4)	    101(5)    107(6)
   14(7) 15(8) 170(9) 18(10)
*/
	int min = node->key;
	MINHEAP_NODE *next = NULL;
	if (node->right && node->right->key < min) {
		min = node->right->key;
		next = node->right;
	}
	if (node->left && node->left->key < min) {
		min = node->left->key;
		next = node->left;
	}

	if (next) {
		// swapping
		next->key = node->key;
		node->key = min;
		minheap_build(next);
	}
}

/*
			5(0)
	    10(1)		100(2)
	11(3)	12(4)	    101(5)    107(6)
   13(7) 15(8) 17(9) 14(10)
*/
int minheap_remove_key(MINHEAP *minheap, int *error) {
	if (!minheap) {
		*error = INVALID_MINHEAP;
		return 0;
	}

	if (!minheap->size) {
		*error = EMPTY_MINHEAP;
		return 0;
	}

	int key = minheap->root->key;

	// remoção
	int lastkey;
	minheap_remove_last(minheap, 
				minheap->size-1, &lastkey);
	if (minheap->size > 0) {
		// 1. colocar lastkey na root
		minheap->root->key = lastkey;
		// 2. busca em profundidade para 
		// atualizar os elementos à partir da raiz
		minheap_build(minheap->root);
	}

	*error = SUCCESS;
	return key;
}

/*
			5(0)
	    10(1)		100(2)
	11(3)	12(4)	    101(5)    107(6)
   13(7) 15(8) 17(9) 14(10)
*/
void minheap_order(MINHEAP_NODE *node) {
	if (node->left) minheap_order(node->left);
	if (node->right) minheap_order(node->right);
	free(node);
}

int minheap_free(MINHEAP *minheap) {
	if (!minheap) return INVALID_MINHEAP;
	if (minheap->root) minheap_order(minheap->root);
	free(minheap);
	return SUCCESS;
}





