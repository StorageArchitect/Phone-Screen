#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


// [x] removeDups in linked list
// [x] removeElement in linked list
// [x] removeMiddle element from linked list
// [x] intersectionOfLL
// [x] detectLoop


typedef int bool;
#define true  1
#define false 0

typedef struct ll {
  void *next;
  int data;
} linkedList;

void swapChar(char *x, char *y) {
  if(*x == *y)
     return;
  char tmp = *x;
  *x = *y;
  *y = tmp;
}

void swap(int *x, int *y){
  if(*x == *y)
     return;
  *x = *x ^ *y;
  *y = *x ^ *y;
  *x = *x ^ *y;
}


void allocateNodes(linkedList *head, int num){
  //--even nodes are zero
  linkedList *node, *curr;
  curr = head;
  for(int i = 0; i < num; i++){
    node = (linkedList *)malloc(sizeof(linkedList));
    node->next = NULL;
    if(i%2 == 0)
      node->data = 44;
    else
      node->data = i;
    curr->next = (void *) node;
    curr = node;
  }

}

printLL(linkedList *curr){
  while(1){
    if(curr->next == NULL){
      break;
    }
    printf(" %d ", curr->data);
    curr = (void *)curr->next;
  }

  printf("\n");

}

void removeDups(){
  int num = 16;
  linkedList *curr, *prev;
  int table[10000] ={ false };
  linkedList head;
  allocateNodes(&head, num);
  curr = &head;
  prev = curr;
  while(curr != NULL){
    if(table[curr->data] == true){
      prev->next =(void *)  curr->next;
    } else {
      table[curr->data] = true;
      prev = curr;
    }
    curr = curr->next;
  }
  curr = &head;
  printLL(curr);
}

int recurseRemove(linkedList *node, int downCount){
  if(node->next == NULL){
    printf("Recurse back to 6 from %d\n", downCount);
    return 6;
  }
  int upCount = recurseRemove(node->next, downCount+1);
  if(--upCount < 0){
    printf("remove  @ pos %d \n",  downCount);
    node->next = (void *) ((linkedList *) node->next)->next;
    upCount = downCount;
  }
  return upCount;
}
int recurseMiddle(linkedList *node, int downCount){
  if(node->next == NULL){
    printf("Middle node is %d \n", downCount/2);
    return downCount/2+1;
  }
  int upCount = recurseMiddle(node->next, downCount+1);
  if(--upCount < 0){
    printf("middle remove  @ pos %d \n",  downCount);
    node->next = (void *) ((linkedList *) node->next)->next;
    upCount = downCount;
  }
  return upCount;
}
/**
-- remove the 4th element from the end
**/
void removeElement(){
  int num = 16;
  linkedList *curr;
  linkedList head;
  allocateNodes(&head, num);
  curr = &head;
  printf("Original LL\n");
  printLL(curr);
  recurseRemove((linkedList *) curr->next,0 );
  printLL(curr);

}

void removeMiddle() {
  int num = 16;
  linkedList *curr;
  linkedList head;
  allocateNodes(&head, num);
  curr = &head;
  printf("Original LL remove middle\n");
  printLL(curr);
  recurseMiddle((linkedList *) curr->next,0 );
  printLL(curr);

}

int intersect(linkedList *l1, linkedList *l2, linkedList *l3){
  linkedList *curr1, *curr2;
  curr1 = l1;
  curr2 = l2;
  while(curr1->next != NULL){
    curr1 = curr1->next;
    curr2 = curr2->next;
  }

  l3->data = 999999;
  curr1->next = curr2->next = l3;


}
void intersectionOfLL() {
  int num = 8;
  linkedList *curr1, *curr2;
  linkedList l1,l2,l3;
  allocateNodes(&l1, num);
  allocateNodes(&l2, num);
  allocateNodes(&l3, num);
  intersect(&l1,&l2,&l3);

  //--find the intersection
  curr1 = &l1;
  curr2 = &l2;
  //if the two lists are not same size then skip the first n nodes
  while(curr1 != NULL){
    if(curr1 == curr2){
      printf("found intersection %d \n", curr2->data);
      return;
    }
    curr1 = curr1->next;
    curr2 = curr2->next;
  }

}


void createLLLoop(linkedList *curr, linkedList *node, int count){
  if(curr->next == NULL){
    printf("Create loop @ %d and %d \n", curr->data, node->data);
    curr->next = node;
    return;
  }

  if(count == 8){
    createLLLoop(curr->next,curr,count+1);
  }
  else
    createLLLoop(curr->next,node,count+1);
}

void detectLoop(){
  int num = 16;
  linkedList *fast;
  linkedList *slow;
  linkedList head;
  allocateNodes(&head, num);
  slow = &head;
  fast = &head;
  createLLLoop(slow, NULL, 0);
  while(1) {
    slow = slow->next;
    fast = ((linkedList *)fast->next)->next;
    if((fast->next== NULL) || (slow == fast ) || (slow == NULL)){
      if(slow == fast)
         printf("found a loop terminating @ %d\n", slow->data);
      break;
    }
  }

}

int  main() {

  removeDups();
  removeElement();
  removeMiddle();
  intersectionOfLL();
  detectLoop();
  return 0;
}