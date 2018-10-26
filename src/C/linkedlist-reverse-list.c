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

/*****************************************
Input : Head of following linked list
       1->2->3->4->NULL
Output : Linked list should be changed to,
       4->3->2->1->NULL

Input : Head of following linked list
       1->2->3->4->5->NULL
Output : Linked list should be changed to,
       5->4->3->2->1->NULL
********************************************/

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

void reverseList(linkedList **head, linkedList *curr, linkedList *prev){

   /* If last node mark it head*/
    if (!curr->next)
    {
        *head = curr;
        /* Update next to prev node */
        curr->next = prev;
        return;
    }

    /* Save curr->next node for recursive call */
    linkedList *next = curr->next;
    /* and update next ..*/
    curr->next = prev;
    reverseList(head, next, curr);
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
 allocateNodes(head, 5);
 printLL(head);
 printf("\n");
 reverseList(&head,head, NULL);
 printLL(head);
 printf("\n");
 return 0;
}