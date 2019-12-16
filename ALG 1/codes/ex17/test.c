#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <binary_tree.h>

int main(int argc, char *argv[]) {
	int key;
	clock_t start, end;
	double max;

	max = 10;
	//for (max = 10; max <=10 /*pow(2, 30)*/; max *= 2) {
		BINARY_TREE *mytree = binary_tree_create();

		for (key = 0; key < max; key++)
			binary_tree_insert(mytree, key);

		start = clock();
		for (key = 0; key < max; key++)
			printf("%d\n", binary_tree_search(mytree, key));
		end = clock();

		printf("%lf\t%lf\n", max,
			(end - start) / (CLOCKS_PER_SEC * 1.0));

		printf("%d\n", binary_tree_search(mytree, 100));
		printf("%d\n", binary_tree_search(mytree, -100));
		binary_tree_free(mytree);
	//}


	return 0;
}
