#include <stdlib.h>
#include <stdio.h>
#include <queue.h>

int main(int argc, char *argv[]) {
	int error;
	int a=1,b=2,c=3;

	printf("Creating queue...\n");
	QUEUE *myqueue = queue_create();

	queue_enqueue(myqueue, &a);
	queue_enqueue(myqueue, &b);
	queue_enqueue(myqueue, &c);
	printf("Counter = %d\n", queue_size(myqueue));

	void *elem;
	while (elem = queue_dequeue(myqueue, &error)) {
		printf("%d\n", *((int *) elem));
	}

	printf("Freeing queue...\n");
	queue_free(myqueue);

	return 0;
}
