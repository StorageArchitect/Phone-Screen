#include <stdio.h>
#include <stdlib.h>
#include <math.h>
https://www.geeksforgeeks.org/print-common-nodes-path-root-common-ancestors/
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

int recursePath(node *root, int value, int *array, int *pos) {
   if(root == NULL){
     printf("\ncould not find value %d reached pos %d\n", value, *pos);
     return 0;
   }
  array[*pos] = root->data;
  *pos +=1;
  printf("pos %d = %d ",*pos, root->data);
  if(root->data == value) {
    printf("found %d\n", value);
    return 1;
  }

   if(recursePath(root->left, value, array, pos) == 1) {
     return 1;
    }
    *pos -=1;
   if(recursePath(root->right, value, array, pos) == 1) {
     return 1;
   }
}

int LCA(node *root, int val1, int val2){

  if(root == NULL) {
    return -1;
  }
    // If either n1 or n2 matches with root's key, report
    // the presence by returning root (Note that if a key is
    // ancestor of other, then the ancestor key becomes LCA

  if(root->data == val1 || root->data == val2)
    return root->data;
  // Look for keys in left and right subtrees
  int left = LCA(root->left, val1, val2);
  int right = LCA(root->right, val1, val2);
  // If both of the above calls return Non-NULL, then one key
  // is present in once subtree and other is present in other,
  // So this node is the LCA
  if(left != -1 && right != -1) {
    return root->data;
  }
  if(left == -1 && right == -1 ) {
    return -1;
  }
      // Otherwise check if left subtree or right subtree is LCA
  return  (left != -1) ? left: right;
}


void printLCA(node *root, int val1, int val2) {

  /*
             1
         /      \
       12         13
      /   \      /  \
     4     5    6    7
    / \   / \  / \  / \
  18  19 0   2 3 16 11 23

  Lowest common ansestor of, if you start from the root (backtrack) then the
  location where it diverges is the common ansestor

  (12,2) is 12, search path from root {1,12,5,2}  and {1,12}
  (1,18) is 1, sedarch path from root {1,12,4,18} and {1}
  (3,23) is 13
  (18, 23) is 1
  backtracing path to the target and check to see where two arrays diverge
*/
  node *currNode;
  int posA = 0;
  int pathA[256];
  int pathB[256];
  int posB = 0;
  recursePath(root, val1, &pathA[0], &posA);
  recursePath(root, val2, &pathB[0], &posB);
  printf("The path to %d is: \n", val1);
  printf("\n");
  for(int i =0; i < posA-1; i++){
      printf(" %d", pathA[i]);
  }
  printf("The path to %d is: \n", val2);
  printf("\n");
  for(int i =0; i < posB; i++){
      printf(" %d", pathB[i]);
  }
  printf("\n");


}


void BreadthFirstTraversal(node *root) {
  node *currNode ;
  queue *myQueue;
  createQueue(&myQueue);
  enQueue(myQueue, (node *) root);
  printf("Breadth First Search Nodes are: \n");
  while((currNode = (node *) deQueue(myQueue)) != NULL) {
    printf(" %d", currNode->data);
    enQueue(myQueue, currNode->left);
    enQueue(myQueue,currNode->right);
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
   printf("Find the LCA \n");
   printLCA(root,18, 21);
   printf("LCA of 18 and 21 is %d\n", LCA(root, 18, 21));


}

