#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ELEMENTS 256
//-- binary search tree
//-- left is less (rule of thumb) for binary search tree
// -- the left node is smaller than the root node
// -- the root node itself is smaller than the right node
//-- ask if the problem is for binary search tree vs just binary tree
//-- clarify if the tree is balanced or not
typedef struct Node {
  int data;
  void *left;
  void *right;
} node;

int g_size;

node * recurseSearch(node *n, int data) {

  if(n == NULL){
   printf("returned null while searching %d \n", data);
   return NULL;
  } else if (data == n->data) {
    return n;
  }

  if(data < n->data){
    return recurseSearch((node *) n->left, data);
  } else {
    return recurseSearch((node *) n->right, data);
  }

}


void recurseInsert(node *n, node *newNode) {
    // -- remember in a binary search tree smaller element is on left ...
    if(newNode->data <= n->data ) {
     if(n->left == NULL) {
      n->left = (void*) newNode;
     } else {
      recurseInsert((node *) n->left, newNode);
     }
    } else {
      if(n->right == NULL) {
        n->right = (void *) newNode;
      } else {
        recurseInsert((node *) n->right,newNode);
      }
    }

}

void addElement(node *n, int data) {

  node *newNode = (node *) malloc(sizeof(node));
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->data = data;
  recurseInsert(n,newNode);

}

node * findElement(node *node, int data) {
  return recurseSearch(node, data);
}

void  recurseInOrder(node *n) {
  if(n == NULL)
    return;
  recurseInOrder(n->left);
  printf("%d ", n->data);
  recurseInOrder(n->right);
}

//-- in order taversal is left myself Right
void traverseInOrder(node *n) {
  recurseInOrder(n);
}


int main() {

  int array[MAX_ELEMENTS] = { 99, 62, 1, 3, 4, 23, 22, 123, 21, 90, 44, 12, 46, 5, 7, 18};
  node *rootNode = (node*) malloc(sizeof(node));
  rootNode->left = NULL;
  rootNode->right = NULL;
  rootNode->data = 812;

  for(int i=1; i < 16; i++){
    addElement(rootNode,array[i]);
  }

  //-- in order traversal will print the values in order ..
  traverseInOrder(rootNode);
  node *found;
  found = findElement(rootNode, 123);
  if(found != NULL){
    printf("\n find element 123 returned %d \n", found->data);
  } else {
    printf("\n find element did not return valid value \n");
  }
  return 0;
}