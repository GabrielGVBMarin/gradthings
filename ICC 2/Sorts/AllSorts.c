#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void BubbleSort(int*, int);
void BubbleSortSent(int*, int);
void HeapSort(int, int*);
void fazHeap(int*, int);
void ordena(int, int*);
void insertionSort(int*, int);
void MergeSort(int*, int);
void quickSort(int*, int, int);
void selectionSort(int*, int);
void ShellSort(int*, int);

long int trocas = 0;
long int cmp = 0;

int main(void)  {

  int tamanho, i;
  scanf("%d\n", &tamanho);

  int *v = (int*) malloc(tamanho*sizeof(int));

  for (i = 0; i < tamanho; i++) {
    scanf("%d", &v[i]);
  }


  ShellSort(v, tamanho);

  for (i = 0; i < tamanho; i++) {
    printf("%d ", v[i]);
  }

  printf("\n\nTROCAS : %ld\nCOMPARES : %ld", trocas, cmp);

  return 0;
}

void BubbleSort(int *array, int size) {

	int i,j,aux;
	for(i = size-1 ; i > 0 ; i--)  {
		for(j = 0 ; j < i ; j++)  {
      cmp++;
			if(array[j] > array[j+1])  {
				aux = array[j];
				array[j] = array[j+1];
				array[j+1] = aux;
        trocas++;
			}
		}
	}
}

void BubbleSortSent(int *vet, int size) {

  int i = size - 1, aux, sent, j;
	while(i > 0) {
		sent = -1;
		for(j = 0; j < i; j++)
      cmp++;
			if(vet[j] > vet[j+1]) {
        aux = vet[j];
        vet[j] = vet[j+1];
        vet[j+1] = aux;
				sent = j;
        trocas++;
			}
		i = sent;
	}

}

void HeapSort(int size, int *v)  {

  int aux, m;

  fazHeap(v, size);
  for (m = size; m >= 2; --m) {
    aux = v[1];
    v[1] = v[m];
    v[m] = aux;
    trocas++;
    ordena(m-1, v);
  }
}

void fazHeap(int *v, int size) {

  int aux, i, f;

  for (i = 1; i < size; ++i) {
    f = i+1;
    while ((cmp = cmp + 1) && f > 1 && v[f/2] < v[f]) {
      aux = v[f/2];
      v[f/2] = v[f];
      v[f] = aux;
      trocas++;
      f /= 2;
    }
  }
}

void ordena(int size, int *v)  {

  int p = 1, f = 2, x = v[1];

  while ((cmp = cmp + 1) && f <= size) {
    if (f < size && v[f] < v[f+1])  {
      f++;
    }
    if (x >= v[f])  {
      break;
    }
    v[p] = v[f];
    trocas++;
    p = f, f = 2*p;
  }
   v[p] = x;
   trocas++;
}

void insertionSort(int *vetor, int tamanho)  {
 int i, j, aux;

   for ( i = 1; i < tamanho; i++) {
     aux = vetor[i];
     j = i - 1;
     while ((cmp = cmp + 1) && j >= 0 && vetor[j] > aux) {
       vetor[j+1] = vetor[j];
       j--;
       trocas++;
     }
     vetor[j+1] = aux;
   }
}

void mergeSort(int *vet, int size) {
	int *vetAux = (int *) malloc(size * sizeof(int));

	for(int length = 1; length < size; length *= 2) {
		int posAux = 0;
		while(posAux < size) {
			int start1 = posAux;
			int start2 = posAux + length;
			int end1 = start1 + length;
			int end2 = start2 + length;

			if(end1 > size) end1 = size;
			if(end2 > size) end2 = size;

			while(start1 < end1 && start2 < end2) {
        cmp++;
				if(vet[start1] <= vet[start2]) {
					vetAux[posAux++] = vet[start1++];
          trocas++;
				} else {
					vetAux[posAux++] = vet[start2++];
          trocas++;
				}
			}

			while((cmp = cmp + 1) && start1 < end1) {
				vetAux[posAux++] = vet[start1++];
        trocas++;
			}

			while((cmp = cmp + 1) && start2 < end2) {
				vetAux[posAux++] = vet[start2++];
        trocas++;
			}
		}

		for(int i = 0; i < size; i++, cmp++)  {
      vet[i] = vetAux[i];
      trocas++;
    }
	}

	free(vetAux);
}

void quickSort(int *vet, int start, int end) {

  int aux;

	if(start < end) {
    srand(time(NULL));
		int p = start + rand() % (end - start + 1);
		int pivo = vet[p], left = start + 1, right = end;
		vet[p] = vet[start];
		vet[start] = pivo;
    trocas++;

		while(left <= right) {
			while(left <= right && vet[left] <= pivo) {
				left++;
			}

			while(left <= right && vet[right] >= pivo) {
				right--;
			}

      cmp++;
			if(left < right) {
        aux = vet[left];
        vet[left] = vet[right];
        vet[right] = aux;
        trocas++;
      }
		}
    aux = vet[right];
    vet[right] = vet[start];
    vet[start] = aux;
    trocas++;
		quickSort(vet, start, right - 1);
		quickSort(vet, right + 1, end);
	}
}

void selectionSort(int *ptr, int tamanho) {

  printf("\n\n ENTROU \n\n");
  printf("%d\n\n", tamanho);
  int i, j, aux, min;

  for(i = 0; i < tamanho; i++) {
    min = i;
    for ( j = i + 1; j < tamanho; j++)  {
      cmp++;
      if ( ptr[j] < ptr[min])  {
        min = j;
      }
    }
    if ( i != min ) {
      aux = ptr[i];
      ptr[i] = ptr[min];
      ptr[min] = aux;
      trocas++;
    }
  }
}

void ShellSort(int *vet, int size) {

  int k = 0, gap, i, new, j;

  while((pow(2, k) -1) < size) k++;
  for(gap = pow(2, k) - 1; gap >= 1; gap/=2)  {
    for(i = 0; i < size-gap; i++) {
      new = vet[i+gap], j= i;
      while((cmp = cmp + 1) && j >= 0 && vet[j] > new) {
        vet[j+gap] = vet[j];
        trocas++;
        j -= gap;
      }
      vet[j+gap] = new;
      trocas++;
    }
  }
}
