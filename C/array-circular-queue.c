#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
//-- ring buffer or circular queue
typedef struct Queue {
  int tail;
  int head;
  int *items[MAX_ELEMENTS];
  int size;
} queue;

void enQueue(queue *q, void *item) {
  if(q->tail > MAX_ELEMENTS){
    //-- reset the tail
    q->tail = 0;
  }
  q->items[q->tail++] = item;
  q->size++ ;
}

void * deQueue(queue *q){
 void *item;
  if(q->head <= MAX_ELEMENTS){
   item =  q->items[q->head++];
  } else {
    q->head = 0;
  }
  q->size--;
}

void createQueue(queue **q) {

  *q = (queue *) malloc(sizeof(queue));
 ((queue *) *q)->size = ((queue *) *q)->tail =  ((queue *) *q)->head = 0;

}


int main(){

  return 0;
}
