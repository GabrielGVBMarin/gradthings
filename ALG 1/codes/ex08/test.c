#include <stdlib.h>
#include <stdio.h>
#include <dyn_list_double.h>

int compare(int *e0, int *e1) {
	if (*e0 == *e1) return 0;
	else if (*e0 < *e1) return -1;
	else return +1;
}
/*
int compare(void *e0, void *e1) {

	if (*((int *) e0) == *((int *) e1)) return 0;
	else  if (*((int *) e0) < *((int *) e1)) return -1;
	else return +1;

	//int *i0, *i1;
	//
	//i0 = (int *) e0;
	//i1 = (int *) e1;
	//
	//if (*i0 == *i1) return 0;
	//else if (*i0 < *i1) return -1;
	//else return +1;
}*/

int main(int argc, char *argv[]) {
	DYN_LIST_DOUBLE *mylist;
	int i, error, elem0 = 5, elem1=2, elem2 = 3;

	mylist = (DYN_LIST_DOUBLE *) 
		dyn_list_double_create((int (*)(void*, void*))&compare);

	printf("size: %d\n", dyn_list_double_size(mylist));

	dyn_list_double_add(mylist, 0, &elem0); // 2 5 3
	dyn_list_double_add(mylist, 0, &elem1);
	dyn_list_double_add(mylist, 2, &elem2);

	for (i = 0; i < dyn_list_double_size(mylist); i++) {
		int *v = (int *) dyn_list_double_get(mylist, i, &error);
		printf("Valor %d na posicao %d\n", *v, i);
	}

	printf("size: %d\n", dyn_list_double_size(mylist));

	dyn_list_double_free(mylist);

	return 0;
}






