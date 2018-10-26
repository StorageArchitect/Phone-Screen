#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

/********
For example, the following two linked lists:

A:       a1 --> a2
                      -->
                            c1  -->   c2 --> c3
                      -->
B b1 -->  b2 -->  b3

begin to intersect at node c1.

******************/

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

void intersect(linkedList *l1, linkedList *l2, linkedList *l3){
  linkedList *curr1, *curr2;
  curr1 = l1;
  curr2 = l2;
  while(curr1->next != NULL){
    curr1 = curr1->next;
    curr2 = curr2->next;
  }

  //-- merge the two lists by pointing the last nodes to l3
  //-- data at intersection
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



void printLL(linkedList *curr){
  if(curr== NULL){
    return;
  }
  printf("%d ", curr->data);
  printLL(curr->next);
}


int main(){
 intersectionOfLL();
 return 0;
}