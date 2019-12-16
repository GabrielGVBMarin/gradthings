#include <stdlib.h>
#include <stdio.h>
#include <dyn_list_circular.h>

int compare(double *e0, double*e1) {
	if (*e0 == *e1) return 0;
	else if (*e0 < *e1) return -1;
	else return +1;
}

int main(int argc, char *argv[]) {
	int error, i;
	double d0=1,d1=2,d2=3;
	DYN_LIST_CIRCULAR *mylist;

	printf("Creating mylist\n");
	mylist = dyn_list_circular_create((int (*)(void*,void*)) 
						&compare);
	printf("Inserting into mylist\n");
	dyn_list_circular_push_back(mylist, (void *) &d0);
	dyn_list_circular_push_back(mylist, (void *) &d1);
	dyn_list_circular_push_back(mylist, (void *) &d2);

	printf("Listing mylist\n");
	for (i = 0; i < dyn_list_circular_size(mylist); i++) {
		printf("Elem %d = %lf\n", i,
		*((double *) dyn_list_circular_get(mylist, i, &error)));
	}

	double key = 2;
	printf("Searching for mylist %lf\n", key);
	printf("Found at %d\n",
			dyn_list_circular_sequential_search(
				mylist, &key
				));

	printf("Removing element at pos 1\n");
	dyn_list_circular_remove(mylist, 1);

	printf("Listing mylist\n");
	for (i = 0; i < dyn_list_circular_size(mylist); i++) {
		printf("Elem %d = %lf\n", i,
		*((double *) dyn_list_circular_get(mylist, i, &error)));
	}

	printf("Removing element at pos 1\n");
	dyn_list_circular_remove(mylist, 1);

	printf("Listing mylist\n");
	for (i = 0; i < dyn_list_circular_size(mylist); i++) {
		printf("Elem %d = %lf\n", i,
		*((double *) dyn_list_circular_get(mylist, i, &error)));
	}

	printf("Removing element at pos 0\n");
	dyn_list_circular_remove(mylist, 0);

	printf("Listing mylist\n");
	for (i = 0; i < dyn_list_circular_size(mylist); i++) {
		printf("Elem %d = %lf\n", i,
		*((double *) dyn_list_circular_get(mylist, i, &error)));
	}

	printf("Freeing mylist\n");
	dyn_list_circular_free(mylist);

	return 0;
}
