#include <stdlib.h>
#include <stdio.h>
#include <huffman.h>
#include <hashtable.h>

HASHTABLE *hashtable_create(int size) {
	HASHTABLE *table = (HASHTABLE *) calloc(1, sizeof(HASHTABLE));
	table->size = size;
	table->slots = (HUFFMAN_NODE **) 
			calloc(size, sizeof(HUFFMAN_NODE *));
	return table;
}

void hashtable_increment(HASHTABLE *table, 
				DATA *symbol, int symbol_size) {
	// put (inserção na tabela)
	// symbol
	//   |
	//   v
	//  -------------------------
	//  |  |  |  |  |  |  |  |  |
	//  -------------------------
	//
	//  str -> "abc joão bla lah lah lah :)"
	//          012345678...
	// 
	//  a = 2
	//  b = 3
	//  c = 5 ...
	//
	//  key1 = 2 * 3 * 5 * ...
	//  key2 = 2 * (0+1) * ...
	//  key3 = 2 * 256^0 + 3 * 256^1 + ...
}

DATA *hashtable_get(HASHTABLE *table, DATA *symbol, int *nbits) {

}

HUFFMAN_NODE **hashtable_get_all_values(
		HASHTABLE *table, int *nsymbols) {

}
