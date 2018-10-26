#include <stdio.h>
#include <memory.h>
#include <stdlib.h>



typedef enum {false, true} bool;

typedef struct ll {
  void *next;
  int data;
} linkedList;


void allocate(linkedList *list, int num) {
  linkedList *node, *curr;
  curr = list;
  for(int i = 0; i < num; i++){
    node = (linkedList *) malloc(sizeof(linkedList));
    node->next = NULL;
    node->data = i+1;
    curr->next = node;
    curr = curr->next;
  }

}


void printLL(linkedList *curr){

  while(curr != NULL){
    printf("%d ", curr->data);
    curr = curr->next;
  }
  printf("\n");

}


void recurse(linkedList **head, linkedList *node){

  // base case
  if(node->next == NULL){
    *head = node;
    return;
  }

   recurse(head, node->next);
   linkedList *p = node->next;
   node->next = NULL;
   p->next = node;
}

int main() {
  linkedList *head;
  linkedList node;
  head = &node;
  head->data = 0;
  head->next = NULL;
  allocate(&node, 16);
  printLL(&node);
  recurse(&head, &node);
  printLL(head);

  return 0;


}
