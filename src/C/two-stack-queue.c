#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef int bool;
#define true  1
#define false 0
#define MAX_ELEMENTS 256


typedef struct Stack {
  int top;
  int items[MAX_ELEMENTS];
  int count;
} stack;

stack *gInStack;
stack *gOutStack;

void createStack(stack **s){

  *s = (stack *) malloc(sizeof(stack));
  ((stack*)*s)->top = 0;
  ((stack*)*s)->count = 0;
}
//- very important pre increment on push
void push(stack *s, int item) {
  if(s->top <= MAX_ELEMENTS) {
    s->items[s->top++] = item;
    s->count++;
    printf("Pused %d \n", item);
  }
}

//-- very important post decremtn after pop
int pop(stack *s) {
  if(s->top >= 0) {
    s->count--;
    printf("Popped %d", s->items[s->top]);
    return s->items[s->top--];
  }
  return -1;
}


void createStackQueue() {
  createStack(&gInStack);
  createStack(&gOutStack);
}

void enQueue(int item) {
  push(gInStack,item);
}


int  deQueue(){
 if(gOutStack->count   == 0){
   //-- transfer from the in stack to out stack
   while(gInStack->count > 0){
     int item = pop(gInStack);
     printf("deQueue popped %d \n",item);
    push(gOutStack, item);
   }
 }

 return pop(gOutStack);
}

int  main() {
  int item[] = {10,11,12,13,14,15,16,17,18,19};


 createStackQueue();
  for(int i = 0; i < (sizeof(item)/sizeof(int)); i++){
     enQueue(item[i]);
  }

  for(int i = 0; i < (sizeof(item)/sizeof(int)); i++){
     printf("Dequeued %d \n", deQueue());
  }
 return 0;
}