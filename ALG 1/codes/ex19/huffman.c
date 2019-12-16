#include <stdlib.h>
#include <stdio.h>
#include <huffman.h>

DATA *huffman_read(FILE *fp) {
	fseek(fp, 0L, SEEK_END);
	long fsize = ftell(fp);
	fseek(fp, 0L, SEEK_SET);
	DATA *buffer = (DATA *) malloc(fsize * sizeof(DATA));
	fread(buffer, sizeof(DATA), fsize, fp);
	return buffer;
}

int huffman_write(FILE *fp, DATA *buffer, int bufsize) {
	return fwrite(buffer, sizeof(DATA), bufsize, fp);
}

void swap(HUFFMAN_NODE **all_symbols, int i, int j) {
	HUFFMAN_NODE *aux = all_symbols[i];
	all_symbols[i]  = all_symbols[j];
	all_symbols[j] = aux;
}

int huffman_node_compare(HUFFMAN_NODE *n0, HUFFMAN_NODE *n1) {
	return n0->frequency - n1->frequency;
}

HUFFMAN_BUFFER *huffman_encode(DATA *buffer, int bufsize, int power) {
	if (!buffer) return INVALID_BUFFER;
	if (bufsize <= 0) return INVALID_BUFFER;
	if (power < 0) return INVALID_POWER;

	DATA *symbol = 
		(DATA *) malloc(sizeof(DATA) * symbol_size(power));
	HASHTABLE *myhash = 
		hashtable_create(bufsize / symbol_size(power));

	for (int i = 0; i < bufsize; i+=symbol_size(power)) {
		memcpy(symbol, &buffer[i], symbol_size(power));
		hashtable_increment(myhash, symbol);
	}

	/*
	 all_symbols
	  |
	  V
	 ----------------------------------------
	 |  |  |  |  |  |  |  |  |  |  |  |  |  |
	 -|--|-----------------------------------
	  v  v
	  o  x

	  		huf_node
			|      |
			v      v
			o      x

	 */
	int nsymbols = 0;
	HUFFMAN_NODE **all_symbols =
		hashtable_get_all_values(myhash, &nsymbols);

	while (nsymbols > 1) {
		qsort(all_symbols, nsymbols, sizeof(HUFFMAN_NODE *), 
			(int (*) (const void *, const void *)) 
				&huffman_node_compare);

		// novo elemento
		HUFFMAN_NODE *new = 
			(HUFFMAN_NODE *)
				calloc(1, sizeof(HUFFMAN_NODE));
		new->left = all_symbols[0];
		new->right = all_symbols[1];
		all_symbols[1] = new;
		all_symbols[1]->frequency = 
			all_symbols[1]->left->frequency +
				all_symbols[1]->right->frequency;

		swap(all_symbols, 0, nsymbols-1);
		nsymbols--;
	}

	HUFFMAN_BUFFER *out_buffer =
		(HUFFMAN_BUFFER *) calloc(1, sizeof(HUFFMAN_BUFFER));
	out_buffer->tree = all_symbols[0];

	int nbits;
	HASHTABLE *symbol_table = 
		huffman_symbol_table(out_buffer->tree);
	for (int i = 0; i < bufsize; i+=symbol_size(power)) {
		memcpy(symbol, &buffer[i], symbol_size(power));
		DATA *encoded = 
			hashtable_get(symbol_table, symbol, &nbits);
		huffman_buffer_bit_concat(out_buffer, encoded, nbits);
	}

	return out_buffer;
}

DATA *huffman_decode(DATA *, int);







