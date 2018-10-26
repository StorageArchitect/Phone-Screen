#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//[x]  implement a queue with two stacks
//[x]  Animal shelter

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
    s->items[s->top++] = item;

    printf("Pused %d \n", item);
  }
}

int pop(stack *s) {
  if(s->top >= 0) {

    printf("Popped %d", s->items[s->top]);
    return s->items[--s->top];
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
 if(gOutStack->top   <= 0){
   //-- transfer from the in stack to out stack
   while(gInStack->top > 0){
     int item = pop(gInStack);
     printf("deQueue popped %d \n",item);
    push(gOutStack, item);
   }
 }

 return pop(gOutStack);
}


void twoStackQueue(){
 int item[] = {10,11,12,13,14,15,16,17,18,19};

 createStackQueue();
 for(int i = 0; i < (sizeof(item)/sizeof(int)); i++){
     enQueue(item[i]);
 }

 for(int i = 0; i < (sizeof(item)/sizeof(int)); i++){
     printf("Dequeued %d \n", deQueue());
 }

}


void animalShelter() {
  //-- animal shelter will have two queues with each animal having a time stamp
  //-- we need to compare head of both queues to figure out what to pop
typedef struct queue {
 int head;
 int tail;
 void *item[MAX_ELEMENTS];
}Queue;

typedef struct an {
  int time;
} Animal;

Animal *dog;
Animal *cat;

}

int  main() {
  twoStackQueue();
  animalShelter();
 return 0;
}