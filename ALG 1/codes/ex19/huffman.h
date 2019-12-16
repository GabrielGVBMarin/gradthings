#ifndef _HUFFMAN_H_
#define _HUFFMAN_H_

/* msg = "araraquara"
 
	a = 5/10
	r = 3/10
	q = 1/10
	u = 1/10

	Shannon's entropy (incerteza):
	==============================

		H(S) = -sum(p_i * log2(p_i))
		     = -(5/10*log2(5/10) + 
		         3/10*log2(3/10) +
		         1/10*log2(1/10) +
		         1/10*log2(1/10)) = 1.685475

  msg = "araraquara"
	a	1/5
	ra	3/5
	qua	1/5

		H(S) = 1.370951
*/

#define symbol_size(power) ((int) pow(2, power))

typedef unsigned char DATA;

struct huffman_node {
	DATA *symbol;
	int frequency;
	struct huffman_node *left, *right;
};

typedef struct huffman_node HUFFMAN_NODE;

struct huffman_buffer {
	DATA *buffer;
	int nbits;
	HUFFMAN_NODE *tree;
};

typedef struct huffman_buffer HUFFMAN_BUFFER;

BYTE *huffman_read(FILE *);
BYTE *huffman_encode(BYTE *, int);
BYTE *huffman_decode(BYTE *, int);
int huffman_write(FILE *, BYTE *);

#endif
