#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <binary_tree.h>

int main(int argc, char *argv[]) {
	int key;
	clock_t start, end;

	BINARY_TREE *mytree = binary_tree_create();
	binary_tree_insert(mytree, 5);
	binary_tree_insert(mytree, 3);
	binary_tree_insert(mytree, 7);
	binary_tree_insert(mytree, 2);
	binary_tree_insert(mytree, 4);
	binary_tree_insert(mytree, 6);
	binary_tree_insert(mytree, 8);

	printf("Caminhamento em ordem\n");
	binary_tree_in_order(mytree);

	printf("Caminhamento pré-ordem\n");
	binary_tree_pre_order(mytree);

	printf("Caminhamento pós-ordem\n");
	binary_tree_pos_order(mytree);

	binary_tree_free(mytree);

	return 0;
}
