#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LEN 256
#define MAX_ELEMENTS 256

typedef struct Node {
  int data;
  void *left;
  void *right;
  int distance;
  int level;
}node;

typedef struct Queue {
  int tail;
  int head;
  int * items[MAX_ELEMENTS];
} queue;

void enQueue(queue *q, void *item) {
  if(item == NULL)
      return;
  if(q->tail <= MAX_ELEMENTS) {
    q->items[q->tail++] = item;
    //--TODO since the head moves down, have to move valid entries up
  }
}

void * deQueue(queue *q){
 void *item;

 if(q->head < q->tail) {
   item =  q->items[q->head++];
   if(q->head >= q->tail){
     q->head = q->tail = 0;
   }
   return item;
 }
  return NULL;
}

void createQueue(queue **q) {

  *q = (queue *) malloc(sizeof(queue));
  ((queue *) *q)->tail =  ((queue *) *q)->head = 0;

}


node *createNode(){

  node *newNode = (node *) malloc(sizeof(node));
  newNode->right = NULL;
  newNode->left = NULL;
  newNode->data = -1;
  newNode->distance = 0;
  newNode->level = 0;

  return newNode;
}

//-- horizontal distance is like a number line, root is zero, left -ve, right +ve
node *addNode(node *tree, int data){
 node *newNode = createNode();
  newNode->data = data;
  if(tree->left == NULL) {
    tree->left = (void *) newNode;
    newNode->distance = tree->distance - 1;
    newNode->level = tree->level + 1;
    printf("value %d, distance %d level %d\n", newNode->data, newNode->distance, newNode->level);
  } else {
    tree->right =(void *) newNode;
    newNode->distance = tree->distance + 1;
    newNode->level = tree->level + 1;
    printf("value %d, distance %d level %d\n", newNode->data, newNode->distance, newNode->level);
  }
  return newNode;

}


void zigZagBinaryTraversal(node *root) {
/*
             1
         /      \
       12         13
      /   \      /  \
     4     5    6    7
    / \   / \  / \  / \
  18  19 0   2 3 16 11 23

  output

  1,12,13,7,6,5,4, 18,19,0,2,3,16,11,23
 Standard binary tree BFS traversal, except at alternate levels flip
*/

  node *currNode ;
  queue *myQueue;
  createQueue(&myQueue);
  enQueue(myQueue, (node *) root);
  printf("ZigZagNodes are: \n");
  while((currNode = (node *) deQueue(myQueue)) != NULL) {
    printf(" %d", currNode->data);
    //-- this should flip for alternate levels
    if(currNode->level %2 == 0){
      enQueue(myQueue, currNode->left);
      enQueue(myQueue,currNode->right);
    } else {
      enQueue(myQueue,currNode->right);
      enQueue(myQueue, currNode->left);
    }


  }
  printf("\n");

}


int main() {
queue *myQueue;
  node *currNode;
  node *root;
  int data[MAX_LEN] = { 99, 62, 1, 3, 4, 23, 22, 123, 21, 90, 44, 12, 46, 5, 7, 18};
  createQueue(&myQueue);
  int posArray[8]={0,0,0,0,0,0,0,0};
  int negArray[8]={0,0,0,0,0,0,0,0};
  int value;
  int index = 1;

  currNode = root = createNode();
  root->data = data[0];
  root->distance = 0;
  root->level = 0;
  enQueue(myQueue, root);

  //-- better to use while index < 16 and increment the index, rather than for
  //-- also the last value will be added eventhough there is nothing in the array ..
   while (index < 16) {
    currNode =(node *) deQueue(myQueue);
    value = data[index++];
    enQueue(myQueue, (void *)addNode(currNode, value));
    value = data[index++];
    enQueue(myQueue, (void *)addNode(currNode, value));
  }

   printf("\n done \n");
   zigZagBinaryTraversal(root);

}

