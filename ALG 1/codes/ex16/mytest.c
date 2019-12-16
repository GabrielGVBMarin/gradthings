#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <min_heap.h>

int main(int argc, char *argv[]) {

	int i, error;
	MINHEAP *myheap = minheap_create();

	srand(time(NULL));
	for (i = 0; i < 100; i++) 
		minheap_add(myheap, rand() % 10000);

	for (i = 0; i < 100; i++) 
		printf("Key: %d\n", minheap_remove_key(myheap, &error));

	minheap_free(myheap);

	return 0;
}
