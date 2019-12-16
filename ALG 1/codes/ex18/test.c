#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <avl.h>

enum {
	PROGNAME,
	NKEYS,
	NARGS
};

int main(int argc, char *argv[]) {

	if (argc != NARGS) {
		printf("usage: %s nkeys\n", argv[PROGNAME]);
		exit(0);
	}

	AVL *my_avl = avl_create();

	//for (int key = 0; key < 100; key++) avl_insert(my_avl, key);
	//avl_pre_order(my_avl);
	
	srand(time(NULL));
	for (int key = 0; key < atoi(argv[NKEYS]); key++) {
		avl_insert(my_avl, rand());
	}

	avl_free(my_avl);

	return 0;
}
