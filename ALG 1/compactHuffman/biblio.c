#include <biblio.h>

// FAZ ALOC DA HEAP
HEAP *heapCreate() {
	// printf("entrou heapcreate\n\n");

	HEAP *heap = (HEAP*) malloc(sizeof(HEAP));
	heap->array = (NODE**) calloc(TAM, sizeof(NODE*));
  	if (heap != NULL) {
    	heap->end = -1;
  	}

	// printf("saiu heap create\n\n");
	return heap;

}

// RETORNA SE TA CHEIA
int full(HEAP *heap) {
	// printf("entrou heap full\n\n");
	if (heap->end == TAM-1) {
		return 1;
	} else {
		return 0;
	}
	// printf("saiu heapfull\n\n");
}

// RETORNA SE TA VAZIA
int empty(HEAP *heap) {
	// printf("entrou heap empty\n\n");
	if (heap->end == -1)  {
    	return 1;
  	} else {
    	return 0;
  	}
	// printf("saiu heap empty\n\n");
}

// FAZ A TROCA ENTRE OS NOS
void swap(HEAP *h, int i, int j) {

	// printf("entrou swap\n\n");
	NODE *aux = h->array[j];
	h->array[j] = h->array[i];
	h->array[i] = aux;
	// printf("saiu swap\n\n");
}

// ARRUMA OS NODES COM OS PAIS
void fix_up(HEAP *h) {
	// printf("entrou fix_up\n\n");
	int pos = h->end;
	int dad = (pos - 1) / 2;
  	NODE *aux;

	while (pos > 0 && h->array[pos]->freq < h->array[dad]->freq) {

		// FAZ A TROCA
    	aux = h->array[pos];
  		h->array[pos] = h->array[dad];
  		h->array[dad] = aux;
		pos = dad;
		dad = (dad - 1) / 2;

	}

	// printf("saiu fix up\n\n");

}

// ADICIONA UM NODE AO FIM E ARRUMA OS DEMAIS PAIS
int queue(HEAP *h, NODE *node) {

	// printf("entrou queue\n\n");
	if (!full(h)) {

		h->end++;
		h->array[h->end] = node;
		fix_up(h);
		// printf("saiu queue\n\n");
		return 1;
	}
	// printf("saiu queue\n\n");
	return 0;
}

// ARRUMA OS NODES COM OS FILHOS
void fix_down(HEAP *h) {
	// printf("entrou fix_down\n\n");
	int pos = 0, left, right, bigestNode;
  	NODE *aux;

	while (pos <= h->end*2 / 4) {

		left = 2*pos + 1;
		right = 2*pos + 2;

		if (right <= h->end && h->array[left]->freq > h->array[right]->freq) bigestNode = right;
		else bigestNode = left;

		if (h->array[pos]->freq <= h->array[bigestNode]->freq) break;

		// FAZ A TROCA
    	aux = h->array[pos];
  		h->array[pos] = h->array[bigestNode];
  		h->array[bigestNode] = aux;
		pos = bigestNode;
	}
	// printf("saiu fix_down\n\n");
}

// PEGA O ULTIMO ELEMENTO E REPOSICIONA NO COMEÇO
NODE *dequeue(HEAP *h) {
	// printf("entrou dequeue\n\n");
  	NODE *node = NULL;

	if (!empty(h)) {

		node = h->array[0];
		h->array[0] = h->array[h->end];
		h->end--;
		fix_down(h);
		// printf("saiu dequeue\n\n");
		return node;

	}
	// printf("saiu dequeue\n\n");
	return NULL;
}

// RETORNA O TAMANHO DA HEAP
int size(HEAP *h) {
	// printf("funfou size\n\n");
	return (h->end+1);
}

// DA FREE NA HEAP E NOS SEUS FILHOS
void heapFree(HEAP **h) {
	// printf("entrou heapfree\n\n");
	int i;

	for (i = 0; i < (*h)->end; i++) {

		if ((*h)->array[i]->left != NULL) free((*h)->array[i]->left);
		if ((*h)->array[i]->right != NULL) free((*h)->array[i]->right);
		free((*h)->array[i]);

	}
	free((*h)->array);
	free(*h);
	// printf("saiu heapfree\n\n");
}

/************* HUFFMAN ***************************/

// CIRA O HUFFMAN
HUFFMAN_TABLE* huffmanCreate() {
	// printf("entrou huffmancreate\n\n");
	// ALOCAÇÕES
	HUFFMAN_TABLE *newTable = (HUFFMAN_TABLE*) malloc(sizeof(HUFFMAN_TABLE));
	int i;
	newTable->code = (char**) calloc(TAM, sizeof(char*));
  	for (i = 0; i < TAM; i++) {
    	newTable->code[i] = (char*) calloc(TAM, sizeof(char));
  	}

	if (newTable) {

		for (i = 0; i < TAM; i++) newTable->code[i][0] = ' ';
		newTable->tree = NULL;

	}

	// printf("saiu huffman create\n\n");
	return newTable;

}

// CRIA ARVORE
BINARIE_TREE* createTree() {
	// printf("entrou create tree\n\n");
	BINARIE_TREE *tree = (BINARIE_TREE*) malloc(sizeof(BINARIE_TREE));
  	tree->root = NULL;
	// printf("saiu create tree\n\n");
	return tree;

}

// CRIA A TABELA
void tableCreate(HUFFMAN_TABLE *table, char *text) {
	// printf("entrou table create\n\n");
	int i, len, *freq = NULL;
  	HEAP *heap;
  	NODE *node, *mrg;
	len = strlen(text);
	freq = (int*) calloc(TAM, sizeof(int));

	for (i = 0; i < len; i++) freq[(int) text[i]]++;

	heap = heapCreate();

	for (i = 0; i < TAM; i++) {

		if (freq[i] > 0) {

			node = (NODE*) malloc(sizeof(NODE));
			node->symbol = i;
			node->freq = freq[i];
      		node->left = NULL;
			node->right = NULL;
			queue(heap, node);

		}

	}

	while (size(heap) > 1) {

		mrg = (NODE*) malloc (sizeof(NODE));
		mrg->symbol = 90 + (rand()%30);
		mrg->left = dequeue(heap);
		mrg->right = dequeue(heap);
    	mrg->freq = mrg->left->freq + mrg->right->freq;
		queue(heap, mrg);

	}

	table->tree = createTree();
	table->tree->root =  dequeue(heap);
	free(freq);
	// printf("saiu table create\n\n");
}

// ATRIBUI O CODIGO AUXILIAR RECURSIVAMENTE PARA OS NOS
void createKeyAux(HUFFMAN_TABLE *table, NODE *node, char *cod, int end) {
	// printf("entrou create key aux\n\n");
  	int i;

	if (node) {

		if (node->left == NULL && node->right == NULL) {

			for (i = 0; i <= end; i++) table->code[(int) node->symbol][i] = cod[i];
			table->code[(int) node->symbol][end+1] = '\0';

		} else {

			if (node->left != NULL) {
				end++;
				cod[end] = '0';
				createKeyAux(table, node->left, cod, end);
				end--;
			}
			if (node->right != NULL) {
				end++;
				cod[end] = '1';
				createKeyAux(table, node->right, cod, end);
				end--;
			}

		}

	}
	// printf("saiu create key aux\n\n");

}

// CRIA O CODIGO PARA O HUFFMAN TODO
void createKey(HUFFMAN_TABLE *table) {
	// printf("entrou create key\n\n");
	char *code = (char*) malloc(TAM*sizeof(char));
	createKeyAux(table, table->tree->root, code, -1);
	// printf("saiu create key\n\n");
}

// FAZ A COMPACTAÇÃO DE HUFFMAN COM O TEXTO
int huffmanCompact(char *text, char **text_c, HUFFMAN_TABLE **table) {
	// printf("entrou huffman compact\n\n");
	int i, j, cod_end;
	char *cod = NULL, *pch;
	tableCreate(*table, text);
	createKey(*table);
	cod_end = -1;

	for (i = 0; text[i] != '\0'; i++) {

		pch = (*table)->code[(int) text[i]];
		for (j = 0; pch[j] != '\0'; j++) {

			cod_end++;
			cod = (char*) realloc(cod, (cod_end+1)*sizeof(char));
			cod[cod_end] = pch[j];

		}

	}

	cod_end++;
	cod = (char*) realloc(cod, (cod_end+1)*sizeof(char));
	cod[cod_end] = '\0';

	*text_c = (char*) malloc(cod_end*sizeof(char));
	strcpy(*text_c, cod);
  	double return_ceil = ceil(cod_end/8.0)+1*1/1;
	free(cod);

	// printf("saiu huffman compact\n\n");
	return return_ceil;

}

// FAZ A DESCOMPACTAÇÃO
char* huffmanDescompact(char *text_c, int size_c, HUFFMAN_TABLE *table) {
	// printf("entrou huffman descompact\n\n");
	int i, decod_end = -1;
	char *decod = NULL;
	NODE *to = table->tree->root;

	for (i = 0; text_c[i] != '\0'; i++) {

		if (text_c[i] == 48) to = to->left;
		else if (text_c[i] == 49) to = to->right;
		else return NULL;

		if (to->left == NULL && to->right == NULL) {

			decod_end++;
			decod = (char*) realloc(decod, (decod_end+1)*sizeof(char));
			decod[decod_end] = to->symbol;
			to = table->tree->root;

		}

	}

	decod[decod_end+1] = '\0';
	// printf("saiu huffman descompact\n\n");
	return decod;

}

// FREE DA ARVORE
void freeTree(BINARIE_TREE **tree) {
	// printf("entrou free tree\n\n");
	if ((*tree))	{
		free((*tree)->root);
		free(*tree);
	} else {
		printf("ERRO NO FREE DA ARVORE, INEXISTENTE");
	}
	// printf("saiu free tree\n\n");
}

// FREE DO HUFFMAN
void freeHuffman(HUFFMAN_TABLE **table) {
	// printf("entrou free huffman\n\n");
	if ((*table))	{
		freeTree(&((*table)->tree));
		free(*table);
	} else {
		printf("ERRO NO FREE DO HUFFMAN, INEXISTENTE");
	}
	// printf("saiu free huffman\n\n");
}
