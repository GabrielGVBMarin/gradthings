#include <stdio.h>
#include <stdlib.h>
#define CAP 10

struct stack{
int top;
int capacity;
float *pElement;
};


void createStack(struct stack *, int );
void push(struct stack *, float );
float pop(struct stack *);
float returnTop(struct stack *);
int isEmpty(struct stack *);
int isFull(struct stack *);


int main(void) {

  int op;
  float newTop, lastTop, value;
  struct stack myStack;
  createStack(&myStack, CAP);

  printf("Ol·! Vamos criar uma pilha. \n \n");
  printf("************* MENU *******************\n");
  printf("********* 1- Empilhar. \n");
  printf("********* 2- Desempilhar. \n");
  printf("********* 3- Retornar o topo. \n");
  printf("********* 4- Verificar se pilha est· cheia. \n");
  printf("********* 5- Verificar se pilha est· vazia. \n");
  
do{

  printf("\n\n Introduza a opcao! \n");

  scanf("%d",&op);

    switch(op){
          case 1:
            printf("Which value you want at the top? \n");
            scanf("%f",&value);
            push(&myStack,value);
          break;
          case 2:
            pop(&myStack);
          break;
          case 3:
            newTop = returnTop(&myStack);
            printf("The top is %f \n",newTop);
           break;
          case 4:
            printf("Is the Stack full? %s", isFull(&myStack) == 1 ? "Yes  \n" : "No  \n");
          break;
          case 5:
            printf("Is the Stack empty? %s", isEmpty(&myStack) == 1 ? "Yes" : "No  \n");
          break;
          default:
          printf("Invalid operation.  \n");
          exit(0);
    }
  }while(1);

  return 0;
}


void createStack(struct stack *myStack, int cap)  {
  myStack->top = -1;
  myStack->capacity = cap;
  myStack->pElement = (float *) malloc(sizeof(float)*cap);
}

void push(struct stack *myStack, float value) {
  if(!isFull(myStack)){
    myStack->top++;
    myStack->pElement[myStack->top] = value;
  }
  else{
      printf("Stack Overflow.");
  }
}



float pop(struct stack *myStack)  {
  float aux= -1;
  if(!isEmpty(myStack)){
    aux = myStack->pElement[myStack->top];
    myStack->top--;
  }
  else{
      printf("Stack is empty!");
  }
  return aux;
}

int isEmpty(struct stack *myStack)  {
  return myStack->top == -1 ? 1 : 0;
}

int isFull(struct stack *myStack) {
  return myStack->top == myStack->capacity -1 ? 1 : 0;
}


float returnTop(struct stack *myStack)  {
  return myStack->pElement[myStack->top];
}
