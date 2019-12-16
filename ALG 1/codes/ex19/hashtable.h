#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#include <huffman.h>

struct hashtable {
	HUFFMAN_NODE **slots;
	int size;
};

typedef struct hashtable HASHTABLE;

#endif
