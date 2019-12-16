#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAIOR 100

int main(void) {

int num1,num2,num3;

scanf("%d", &num1);
scanf("%d", &num2);

num3 = num1 + num2;
char string[9] = {0};
sprintf(string, "%d", num3);
//printf("%s\n", str);
int tam = strlen(string);
int i;

for(i=tam;i>=0;i--){
if(string[i] == '2'){
    string[i] = '0';
    string[i-1] += 1;
}

if(string[i]=='3'){
    string[i] = '1';
    string[i-1] += 1;
}

if(string[i]=='1' || string[i]=='0'){
    continue;
}

}
if(string[0] =='0'){
printf("1");
}
printf("%s\n", string);
return 0;
}
