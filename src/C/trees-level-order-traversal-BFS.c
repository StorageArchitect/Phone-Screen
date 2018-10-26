#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <math.h>

/**
* Binary Tree implementation example
* use this example to practice traversal
**/

#define MAX_NODES 6
#define MAX_LEN 256
#define MAX_Q_SIZE 256

typedef struct node{
int *left;
int *right;
char data[MAX_LEN];
} Node;

/* frunction prototypes */
struct node** createQueue(int *, int *);
void enQueue(struct node **, int *, struct node *);
struct node *deQueue(struct node **, int *);



typedef struct list {
  int *next;
  Node *e;
} Queue;

Node * createNewNode(char *data ) {
  Node *currNode;
  currNode = (Node *) malloc(sizeof (Node));
  currNode->left = NULL;
  currNode->right = NULL;
  sprintf(currNode->data,"%s\n", data);

  return currNode;
}


void traverseLevelOrder(Node *tree) {
  printf("Traversal Breadth First \n");
  int rear, front;
  struct node **queue = createQueue(&front, &rear);
  Node *currRoot = tree;
  while( currRoot ) {
    printf("%s \n", currRoot->data);
    //-- enqueue the left
    if(currRoot->left) {
      enQueue(queue, &rear,(Node *) currRoot->left);
    }
    //--- enqueue the right
    if(currRoot->right) {
      enQueue(queue, &rear,(Node *) currRoot->right);
    }

    //--dequeue and print
    currRoot = deQueue(queue,&front);

  }

}


/*UTILITY FUNCTIONS*/
struct node** createQueue(int *front, int *rear)
{
    struct node **queue =
        (struct node **)malloc(sizeof(struct node*)*MAX_Q_SIZE);

    *front = *rear = 0;
    return queue;
}

void enQueue(struct node **queue, int *rear, struct node *new_node)
{
    queue[*rear] = new_node;
    (*rear)++;
}

struct node *deQueue(struct node **queue, int *front)
{
    (*front)++;
    return queue[*front - 1];
}

Node * addToTree(Node *currRoot, int i) {

    Node *newNode;
    char str[MAX_LEN];
    sprintf(&str[0], "%d",i);
    newNode = createNewNode(&str[0]);
    if(currRoot->left == NULL)  {
      currRoot->left = (int *) newNode;
      printf("Added %d to left of %s \n", i, currRoot->data);
    } else {
      currRoot->right = (int *) newNode;
      printf("Added %d to right of %s \n", i, currRoot->data);
    }

    return newNode;
}

// To execute C, please define "int main()"

int main() {

  Node *rootNode,*currRoot;
  int id = 0;
  int rear, front;
  struct node **queue = createQueue(&front, &rear);

  printf("Added  %d to Root \n\n", id);
  currRoot = rootNode = createNewNode("0");
  enQueue(queue, &rear, currRoot);
  id++;

  for (int i = 0; i < MAX_NODES/2; i++) {
    currRoot = deQueue(queue, &front);
    enQueue(queue, &rear, addToTree(currRoot, id++));
    enQueue(queue, &rear, addToTree(currRoot, id++));
  }

  traverseLevelOrder(rootNode);
  return 0;
}
