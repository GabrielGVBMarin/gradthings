#include <stdio.h>
#include <string.h>

#define MAX 100

int main()  {
  char user[MAX];
  int tamanho, veri = 0, veri1 = 0, veri2 = 0, trueveri = 0, trueveri1 = 0, trueveri2= 0;
 fgets(user, MAX, stdin);
 tamanho = strlen(user);
 //for ( int y = 0; y < tamanho + 1; y++) {
//   printf("%c", user[y]);
 //}
 for ( int i = 0; i < tamanho; i++) {
   veri = 0;
   veri1 = 0;
   veri2 = 0;
   for ( int minu = 97; minu < 123; minu++)  {
     if ( user[i] == minu)  {
       veri = 1;
     }
   }
   for ( int maiu = 65; maiu < 91; maiu++)  {
     if ( user[i] == maiu)  {
       veri1 = 1;
     }
   }
   for ( int num = 48; num < 58; num++) {
     if ( user[i] == num) {
       veri2 = 1;
     }
   }
   if (veri != 0)  {
     trueveri = trueveri + 1;
   }
   else if ( veri1 != 0) {
     trueveri1 = trueveri1 + 1;
   }
   else if (veri2 != 0)  {
     trueveri2 = trueveri2 + 1;
   }
   else if ( veri == 0 && veri1 == 0 && veri2 == 0) {
     printf("Username invalido\nPossui caracter especial\nNao possui os tres tipos de caracteres");
     return 0;
   }
 }

 if ( trueveri == 0)  {
   printf("Username invalido\nNao possui os tres tipos de caracteres");
   return 0;
 }
 else if ( trueveri1 == 0)  {
   printf("Username invalido\nNao possui os tres tipos de caracteres");
   return 0;
 }
 else if ( trueveri2 == 0)  {
   printf("Username invalido\nNao possui os tres tipos de caracteres");
   return 0;
 }


   printf("Username OK");


  return 0;
}
