//---[x] binary tree
//---[x] horizontal distance
//---[x] vertical sum
//---[x] horizontal suming
//-- [x]  lowest common ansestor in binary tree
//-- [x] Left view of tree
//-- []  Bottom view of the binary tree
//-- [x] Top view of the binary tree
//-- []  distance between nodes in a binary tree
//-- [x] invert a binary tree ..
//-- []  level order traversal
//-- []  Boundary traversal of all nodes in the binary tree anti clock wise ..
//-- [x] zig zag tree traversal
//-- [x]  path in binary tree with backtracking ..
// --- when using a for loop, have a seperate variable to increment the index of array
// specially when you have to jump items. for ex array[i] and array[i+1] will repeate
//-- values in a for loop, best use a while loop or use index++

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

void recurse(node *item, int *rA, int *lA) {
  if(item == NULL)
    return;
  if(item->distance >= 0){
    printf("value %d, distance %d \n", item->data, item->distance);
    rA[item->distance] += item->data;
  } else {
    printf("value %d, distance %d \n", item->data, item->distance);
    lA[abs(item->distance)] += item->data;
  }
  recurse(item->left, rA, lA);
  recurse(item->right, rA, lA);
}
void getVSum(node *root, int *rightA, int *leftA){
  recurse(root, rightA, leftA);
}

void getHSum( node *root) {
  //-- a breadth first search ..
  node *currNode ;
  queue *myQueue;
  int level = 0;
  int sum = 0;
  createQueue(&myQueue);
  enQueue(myQueue, (node *) root);
  //-- get the root node
  while((currNode = (node *) deQueue(myQueue)) != NULL) {
    if(level != currNode->level){
      printf("Level %d, total is %d \n",level, sum);
      printf(" %d ", currNode->data);
      level = currNode->level;
      sum = 0;
    } else {
     printf(" %d ", currNode->data);
    }
    sum +=currNode->data;
    enQueue(myQueue, (node *) currNode->left);
    enQueue(myQueue, (node *) currNode->right);
  }
  printf("Level %d, total is %d \n", level, sum);

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

void invertTree(node *root) {
  node *currNode ;
  queue *myQueue;
  node *tmp;
  createQueue(&myQueue);
  enQueue(myQueue, (node *) root);
  while((currNode = (node *) deQueue(myQueue)) != NULL) {
    enQueue(myQueue, currNode->left);
    enQueue(myQueue,currNode->right);
    //-- swap right with left ..
    tmp = currNode->left;
    currNode->left = currNode->right;
    currNode->right = tmp;
  }

}

//-- Find the distance between two keys in a binary tree, no parent pointers are given.
//-- Distance between two nodes is the minimum number of edges to be traversed to reach one node from other.
int distance(node *first, node *second) {
  //-- The distance between two nodes can be obtained in terms of lowest common ancestor.
  //-- Following is the formula is for distance.
  //-- Dist(n1, n2) = Dist(root, n1) + Dist(root, n2) - 2*Dist(root, lca)
  /************************************************************************
  *
  *                                1
  *                              /   \
  *                             2      3
  *                           /   \  /   \
  *                          4     5 6    7
  *                                   \
  *                                    8
  *
  * Dist(4,5) = 2, Dist(4,6) = 4, Dist(3,4) = 3 ...
  */

}

void maxWidth(node *root ) {

  //-- alternate answer use level order traversal
  //-- count the number of nodes in the queue ..
  node *currNode ;
  int posArray[8] = {0,0,0,0,0,0,0,0};
  int negArray[8] = {0,0,0,0,0,0,0,0};
  queue *myQueue;
  createQueue(&myQueue);
  enQueue(myQueue, (node *) root);
  while((currNode = (node *) deQueue(myQueue)) != NULL) {
    if(currNode->distance >= 0){

       posArray[currNode->distance] = currNode->distance;
    } else {

       negArray[abs(currNode->distance)] = abs(currNode->distance);
    }
    enQueue(myQueue, currNode->left);
    enQueue(myQueue,currNode->right);
  }
  int max = 0;
  for(int i=0; i < 8; i++){
    if(negArray[i] + posArray[i] > max) {
      max = negArray[i] + posArray[i];
    }
  }
  printf("max distance %d \n", max);


}

void topView(node *root) {
  //-- should really use a hash table, but we have known values of levels
  int posArray[8] = {0,0,0,0,0,0,0,0};
  int negArray[8] = {0,0,0,0,0,0,0,0};
/*
             1
         /      \
       12         13
      /   \      /  \
     4     5    6    7
    / \   / \  / \  / \
  18  19 0   2 3 16 11 23

  Top view of the above binary tree is  18 4 12 1 13 7 23, this means you only walk the left and right edges
  1) use standard BFS
  2) some means to check if this is the first node at that level (use horizontal distance) ..
  3) print the value
*/

  node *currNode ;
  queue *myQueue;
  createQueue(&myQueue);
  enQueue(myQueue, (node *) root);
  printf("Top View Nodes are: \n");
  while((currNode = (node *) deQueue(myQueue)) != NULL) {
    if(currNode->distance >= 0){
     if(posArray[currNode->distance] ==0 ) {
       printf(" %d", currNode->data);
       posArray[currNode->distance] +=1;
     }
    } else {
     if(negArray[abs(currNode->distance)] ==0 ) {
       printf(" %d", currNode->data);
       negArray[abs(currNode->distance)] +=1;
     }
    }
    enQueue(myQueue, currNode->left);
    enQueue(myQueue,currNode->right);

  }
  printf("\n");

}


void leftView(node *root) {
  int negArray[8] = {0,0,0,0,0,0,0,0};
/**
 Input :
                 1
               /   \
              2     3
             / \     \
            4   5     6
 Output : 1 2 4
**/
   node *currNode ;
  queue *myQueue;
  createQueue(&myQueue);
  enQueue(myQueue, (node *) root);
  printf("Left View Nodes are: \n");
  while((currNode = (node *) deQueue(myQueue)) != NULL) {
    if(currNode->distance <= 0){
     if(negArray[abs(currNode->distance)] ==0 ) {
       printf(" %d", currNode->data);
       negArray[abs(currNode->distance)] +=1;
     }
    }
    enQueue(myQueue, currNode->left);

  }
  printf("\n");

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
/*
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
*/

void backtrackPath(node * root, int value) {
  int path[256];
  int pos = 0;
  printf("Backtracking path to find %d\n", value);
  recursePath(root, value, &path[0], &pos);
  printf("The path to %d is: \n", value);
  printf("\n");
  for(int i =0; i < pos; i++){
      printf(" %d", path[i]);
  }
  printf("\n");

}


void bottomView(node *root){

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
  getVSum(root, &posArray[0], &negArray[0]);
  for(int i= 0; i< 8; i++ ) {
    printf("%d: ", i);
    printf(" %d", posArray[i]);
    printf(" %d", negArray[i]);
    printf("\n");
  }

  getHSum(root);
  BreadthFirstTraversal(root);
  topView(root);
  leftView(root);
  maxWidth(root);
  zigZagBinaryTraversal(root);
  backtrackPath(root,18);
  backtrackPath(root,0);
  printf("Find the LCA \n");
  printLCA(root,18, 21);
  printf("LCA of 18 and 21 is %d\n", LCA(root, 18, 21));

  printf("Caution inverting tree");
  invertTree(root);
  BreadthFirstTraversal(root);
  return 0;
}

