#ifndef _STACK_H_
#define _STACK_H_

#define SUCCESS		0
#define INVALID_STACK	-1
#define EMPTY_STACK	-2

struct stack_element {
	void *elem;
	struct stack_element *next;
};

struct stack {
	struct stack_element *top;
	int counter;
};

typedef struct stack STACK;
typedef struct stack_element STACK_ELEMENT;

STACK *stack_create();
int stack_push(STACK *, void *);
void *stack_pop(STACK *, int *);
void *stack_top(STACK *, int *);
int stack_size(STACK *);
int stack_free(STACK *);

#endif
