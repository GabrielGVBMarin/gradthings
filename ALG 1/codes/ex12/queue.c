#include <stdlib.h>
#include <queue.h>

QUEUE *queue_create() {
	return (QUEUE *) calloc(1, sizeof(QUEUE));
}

int queue_enqueue(QUEUE *queue, void *elem) {
	if (!queue) return INVALID_QUEUE;

	QUEUE_ELEMENT *qelem = (QUEUE_ELEMENT *)
		malloc(sizeof(QUEUE_ELEMENT));
	qelem->elem = elem;
	qelem->next = NULL;

	if (!queue->counter) queue->first = qelem;
	else queue->last->next = qelem;
	queue->last = qelem;
	queue->counter++;
	return SUCCESS;
}

void *queue_dequeue(QUEUE *queue, int *error) {
	if (!queue) {
		*error = INVALID_QUEUE;
		return NULL;
	}

	if (!queue->counter) {
		*error = EMPTY_QUEUE;
		return NULL;
	}

	void *e;
	QUEUE_ELEMENT *elem = queue->first;
	queue->first = elem->next;
	queue->counter--;
	e = elem->elem;
	free(elem);
	if (!queue->counter) queue->last = NULL;

	*error = SUCCESS;
	return e;
}

void *queue_first(QUEUE *queue, int *error) {
	if (!queue) {
		*error = INVALID_QUEUE;
		return NULL;
	}

	if (!queue->counter) {
		*error = EMPTY_QUEUE;
		return NULL;
	}

	*error = SUCCESS;
	return queue->first->elem;
}

int queue_size(QUEUE *queue) {
	if (!queue) return  INVALID_QUEUE;
	return queue->counter;
}

int queue_free(QUEUE *queue) {
	if (!queue) return INVALID_QUEUE;
	int i;
	QUEUE_ELEMENT *elem;
	for (i = 0; i < queue->counter; i++) {
		elem = queue->first;
		queue->first = elem->next;
		free(elem);
	}
	free(queue);

	return SUCCESS;
}









