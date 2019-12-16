#include <stdlib.h>
#include <stdio.h>
#include <dyn_list.h>

int cmp(int *a, int *b) {
	if (*a == *b) return 0;
	else if (*a < *b) return -1;
	else return +1;
}

int main(int argc, char *argv[]) {
	DYN_LIST *mylist;

	printf("Creating the list...\n");
	mylist = dyn_list_create((int (*) (void *, void *)) &cmp);

	printf("Freeing the list...\n");
	dyn_list_free(mylist);

	return 0;
}
