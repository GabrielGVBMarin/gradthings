#include <stdlib.h>
#include <stdio.h>
#include <sparse.h>

int main(int argc, char *argv[]) {
	int constant = 0, error;
	int a=1,b=2,c=3;

	printf("Creating the sparse matrix...\n");
	SPARSE *mysparse = sparse_create(&constant);

	printf("Value = %d\n",
			*((int *) sparse_get(mysparse, 0, 0, &error)));
	printf("Value = %d\n",
			*((int *) sparse_get(mysparse, 0, 1, &error)));
	printf("Value = %d\n",
			*((int *) sparse_get(mysparse, 1, 1, &error)));

	sparse_add(mysparse, 0, 1, &a);
	sparse_add(mysparse, 0, 20, &b);
	sparse_add(mysparse, 10, 10, &c);

	sparse_remove(mysparse, 0, 20);

	printf("Value = %d\n",
			*((int *) sparse_get(mysparse, 0, 1, &error)));
	printf("Value = %d\n",
			*((int *) sparse_get(mysparse, 0, 20, &error)));
	printf("Value = %d\n",
			*((int *) sparse_get(mysparse, 10, 10, &error)));

	printf("Freeing the sparse matrix...\n");
	sparse_free(mysparse);

	return 0;
}
