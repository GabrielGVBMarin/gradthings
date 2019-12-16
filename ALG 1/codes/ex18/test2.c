#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <avl.h>

int main(int argc, char *argv[]) {
	AVL *my_avl = avl_create();

	for (int key = 1; key <= 15; key++)
		avl_insert(my_avl, key);

	avl_pre_order(my_avl);
	printf("\n\nRemoving...\n");
	avl_remove(my_avl, 8);
	avl_remove(my_avl, 7);
	avl_remove(my_avl, 6);
	avl_pre_order(my_avl);

	avl_free(my_avl);

	return 0;
}
