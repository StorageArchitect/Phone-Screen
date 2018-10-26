#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//[x]  implement a sorted Stack

typedef int bool;
#define true  1
#define false 0
#define MAX_ELEMENTS 256


typedef struct Stack {
  int top;
  int items[MAX_ELEMENTS];
} stack;

stack *gInStack;
stack *gOutStack;

void createStack(stack **s){

  *s = (stack *) malloc(sizeof(stack));
  ((stack*)*s)->top = 0;
}

void push(stack *s, int item) {
  if(s->top <= MAX_ELEMENTS) {
    s->items[++s->top] = item;
  }
}

int pop(stack *s) {
  if(s->top > 0) {
    return s->items[s->top--];
  }
  return -1;
}

int peek(stack *s){
  if(s->top > 0) {
    return s->items[s->top];
  }

  return -1;
}

bool isEmpty(stack *s) {
  if(s->top >0){
    return false;
  }
  return true;

}
void sortedStack(){
   int item[] = {20,11,22,33,14,25,36,17,8,19};
   stack *sortedStack;
   stack *uSortedStack;
   int tmp = 0;
  //-- approach is to have two stack, put the elements in the first stack
  //-- pop the element and check if it greater than element in the second stack
  //-- smallest element on top
  createStack(&sortedStack);
  createStack(&uSortedStack);

  for(int i = 0; i < sizeof(item)/sizeof(int); i++){
    push(sortedStack, item[i]);
  }

   while(!isEmpty(sortedStack)) {
     tmp = pop(sortedStack);
     while(!isEmpty(uSortedStack) && peek(uSortedStack) > tmp){
       push(sortedStack, pop(uSortedStack));
     }
     push(uSortedStack, tmp);
   }

  while(!isEmpty(uSortedStack) ){
    push(sortedStack,pop(uSortedStack));
  }

  printf("Sorted Stack: \n");
  for(int i = 0; i < sizeof(item)/sizeof(int); i++){
    printf("%d ", pop(sortedStack));
  }
  printf("\n");
}



void testStack(){
   int item[] = {20,11,22,33,14,25,36,17,8,19};
   stack *sortedStack;
   stack *uSortedStack;
   createStack(&sortedStack);
   createStack(&uSortedStack);
  for(int i = 0; i < sizeof(item)/sizeof(int); i++){
    push(sortedStack, item[i]);
  }
  printf("Test Stack: \n");
  for(int i = 0; i < sizeof(item)/sizeof(int); i++){
    printf("%d ", pop(sortedStack));
  }

}

int  main() {
  sortedStack();
  testStack();
 return 0;
}