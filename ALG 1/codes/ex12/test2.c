#include <stdlib.h>
#include <stdio.h>
#include <stack.h>

int main(int argc, char *argv[]) {
	int error;
	int a=1,b=2,c=3;

	printf("Creating mystack...\n");
	STACK *mystack = stack_create();

	stack_push(mystack, &a);
	stack_push(mystack, &b);
	stack_push(mystack, &c);
	printf("Size = %d\n", stack_size(mystack));

	void *elem;
	while (elem = stack_pop(mystack, &error)) {
		printf("%d\n", *((int *) elem));
	}

	printf("Freeing mystack...\n");
	stack_free(mystack);

	return 0;
}
