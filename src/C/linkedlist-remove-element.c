#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef enum {false, true} bool;

void swap(int *x, int *y){
  if(*x != *y ){
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
  }
}

typedef struct ll {
  void *next;
  int data;
} linkedList;

void allocateNodes(linkedList *head, int num){
  //--set even nodes to 666
  linkedList *node, *curr;
  curr = head;
  for(int i = 0; i < num; i++){
    node = (linkedList *)malloc(sizeof(linkedList));
    node->next = NULL;
    node->data = i;
    curr->next = (void *) node;
    curr = node;
  }

}

/**
-- remove the 8th element from the end
**/

int recurseRemove(linkedList *node, int downCount){
  if(node->next == NULL){
    printf("Reached end recurse back to 8the element from %d\n", downCount);
    return 8;
  }
  int upCount = recurseRemove(node->next, downCount+1);
  if(--upCount < 0){
    printf("remove  %d \n", ((linkedList *) node->next)->data );
    node->next = (void *) ((linkedList *) node->next)->next;
    upCount = downCount;
  }
  return upCount;
}


void printLL(linkedList *curr){
  if(curr== NULL){
    return;
  }
  printf("%d ", curr->data);
  printLL(curr->next);
}


int main(){
 linkedList *head;
 linkedList node;
 node.next = NULL;
 node.data = 999;
 head = &node;
 allocateNodes(head, 16);
 printLL(head);
 printf("\n");
 recurseRemove(head,0);
 printLL(head);
 printf("\n");
 return 0;
}