#include <stdlib.h>
#include <stdio.h>
#include <complex_sparse.h>

int main(int argc, char *argv[]) {
	COMPLEX_SPARSE *mysparse =
		complex_sparse_create(4, 5, 0.0);

	complex_sparse_put(mysparse, 0, 0, 1);
	complex_sparse_put(mysparse, 0, 2, 2);
	complex_sparse_put(mysparse, 0, 4, 3);
	complex_sparse_put(mysparse, 3, 0, 4);
	complex_sparse_put(mysparse, 3, 2, 5);
	complex_sparse_put(mysparse, 3, 4, 6);
	complex_sparse_put(mysparse, 2, 0, 7);
	complex_sparse_put(mysparse, 2, 2, 8);
	complex_sparse_put(mysparse, 2, 4, 9);

	int i, j, e;
	for (i = 0; i < mysparse->nrows; i++) {
		for (j = 0; j < mysparse->ncols; j++) {
			printf("%lf\t", 
				complex_sparse_get(mysparse, i, j, &e));
		}
		printf("\n");
	}

	complex_sparse_free(mysparse);

	return 0;
}
