#include <stdio.h>
#include <string.h>

int main () {

  int vet[100], vetsafe[100];

  for ( int i = 0; i < 16; i++) {
    scanf("%d", &vet[i]);
    vetsafe[i] = vet[i];
  }

for ( int i = 0; i < 16; i++)  {
  if ( i < 8) {
  //save = vet[i];
  vet[i] = vetsafe[i+8];
  }
  else {
    //save = vet[i];
    vet[i] = vetsafe[i - 8];
  }
}



for( int i = 0; i < 16; i++){
  if ( vet[i] >= 0 ) {
  printf("%d ", vet[i]);
}
 else {
  printf("0 ");
  }
}
  return 0;
}
