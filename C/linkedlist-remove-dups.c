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
    if(i%2){
     node->data = 666;
    } else {
      node->data = i;
    }
    curr->next = (void *) node;
    curr = node;
  }

}

void removeDups(linkedList *head){
  int dupsTable[1000] = {0};
  linkedList *curr , *prev;
  curr = prev = head;
  while(curr != NULL){
    if(dupsTable[curr->data] == 1){
      prev->next = curr->next;
    } else {
      dupsTable[curr->data] = 1;
      prev = curr;
    }
    curr = curr->next;
  }

}

void printLL(linkedList *head){
  if(head == NULL){
    return;
  }
  printf("%d ", head->data);
  printLL(head->next);
}


int main(){
 linkedList head;
 head.next = NULL;
 head.data = 999;
 allocateNodes(&head, 16);
 printLL(&head);
 printf("\n");
 removeDups(&head);
 printLL(&head);
 printf("\n");
 return 0;
}