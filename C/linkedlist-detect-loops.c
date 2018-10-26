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

void createLLLoop(linkedList *curr, linkedList *node, int count){
  if(curr->next == NULL){
    printf("Create loop connecting %d and %d \n", curr->data, node->data);
    curr->next = node;
    return;
  }

  if(count == 8){
    createLLLoop(curr->next,curr,count+1);
  }
  else
    createLLLoop(curr->next,node,count+1);
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
 linkedList *fast;
 linkedList *slow;
 node.next = NULL;
 node.data = 999;
 head = &node;
 allocateNodes(head, 16);
 printLL(head);
 printf("\n");
 slow = head;
 fast = head;
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

 return 0;
}